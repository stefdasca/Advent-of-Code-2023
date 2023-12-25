import numpy as np
from sympy import Symbol
from sympy import solve_poly_system

handle = open("input.txt","r")

shards = []
for line in handle:
  pos, vel = line.strip().split(" @ ")
  px,py,pz = pos.split(", ")
  vx,vy,vz = vel.split(", ")
  shards.append((int(px),int(py),int(pz),int(vx),int(vy),int(vz)))

count = 0
for adx in range(len(shards)-1):
  shard_a = shards[adx]
  ma = shard_a[4]/shard_a[3]
  ba = shard_a[1] - ma * shard_a[0]
  for bdx in range(adx+1,len(shards)):
    shard_b = shards[bdx]
    mb = shard_b[4]/shard_b[3]
    bb = shard_b[1] -mb * shard_b[0]
    if ma == mb: 
      continue
    ix = (bb - ba)/(ma - mb)
    iy = ma*ix + ba

    ta = (ix - shard_a[0])/shard_a[3]
    tb = (ix - shard_b[0])/shard_b[3]

    if ta >= 0 and tb >= 0 and ix >= 200000000000000 and ix <= 400000000000000 and iy >= 200000000000000 and iy <= 400000000000000:
      count+=1

print(count)

x = Symbol('x')
y = Symbol('y')
z = Symbol('z')
vx = Symbol('vx')
vy = Symbol('vy')
vz = Symbol('vz')

equations = []
t_syms = []
for idx,shard in enumerate(shards[:3]):
  x0,y0,z0,xv,yv,zv = shard
  t = Symbol('t'+str(idx))

  eqx = x + vx*t - x0 - xv*t
  eqy = y + vy*t - y0 - yv*t
  eqz = z + vz*t - z0 - zv*t

  equations.append(eqx)
  equations.append(eqy)
  equations.append(eqz)
  t_syms.append(t)

result = solve_poly_system(equations,*([x,y,z,vx,vy,vz]+t_syms))
print(result[0][0]+result[0][1]+result[0][2]) 
