#include <bits/stdc++.h>
using namespace std;

int ox[] = {0, 1, 0, -1};
int oy[] = {1, 0, -1, 0};

bool viz[1002][1002][4];

string s;
int n;

char mat[1002][1002];
struct str
{
    int L, C, dir;
};
int main()
{
    ifstream cin("input.in");
    
    while(cin >> s)
    {
        n++;
        for(int j = 0; j < (int) s.size(); j++)
            mat[n][j+1] = s[j];
    }
    
    
    viz[1][0][0] = 1;
    queue<str> q;
    q.push({1, 0, 0});
    while(!q.empty())
    {
        str nod = q.front();
        q.pop();
        
        for(int dir = 0; dir <= 3; dir++)
        {
            if(dir != nod.dir)
                continue;
            int nxtL = nod.L + ox[dir];
            int nxtC = nod.C + oy[dir];
            if(nxtL == 0 || nxtL == n+1 || nxtC == 0 || nxtC == n+1)
                continue;
            if(mat[nxtL][nxtC] == '.' && viz[nxtL][nxtC][dir] == 0)
            {
                viz[nxtL][nxtC][dir] = 1;
                q.push({nxtL, nxtC, dir});
            }
            // r->u, u->r, l->d, d->l
            if(mat[nxtL][nxtC] == '/')
            {
                if(viz[nxtL][nxtC][(dir ^ 3)] == 0)
                {
                    viz[nxtL][nxtC][(dir ^ 3)] = 1;
                    q.push({nxtL, nxtC, (dir ^ 3)});
                }
            }
            // r->d, d->r, u->l, l->u 
            if(mat[nxtL][nxtC] == 92) // char = backslash
            {
                if(viz[nxtL][nxtC][(dir ^ 1)] == 0)
                {
                    viz[nxtL][nxtC][(dir ^ 1)] = 1;
                    q.push({nxtL, nxtC, (dir ^ 1)});
                }
            }
            if((mat[nxtL][nxtC] == '-' && dir % 2 == 0) || (mat[nxtL][nxtC] == '|' && dir % 2 == 1))
            {
                if(viz[nxtL][nxtC][dir] == 0)
                {
                    viz[nxtL][nxtC][dir] = 1;
                    q.push({nxtL, nxtC, dir});
                }
            }
            if((mat[nxtL][nxtC] == '-' && dir % 2 == 1) || (mat[nxtL][nxtC] == '|' && dir % 2 == 0))
            {
                if(viz[nxtL][nxtC][(3 + dir) % 4] == 0)
                {
                    viz[nxtL][nxtC][(3 + dir) % 4] = 1;
                    q.push({nxtL, nxtC, (3 + dir) % 4});
                }
                if(viz[nxtL][nxtC][(1 + dir) % 4] == 0)
                {
                    viz[nxtL][nxtC][(1 + dir) % 4] = 1;
                    q.push({nxtL, nxtC, (1 + dir) % 4});
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(viz[i][j][0] || viz[i][j][1] || viz[i][j][2] || viz[i][j][3])
                ans++;
        
    cout << ans << '\n';
    return 0;
}
