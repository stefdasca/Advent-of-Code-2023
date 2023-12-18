#include <bits/stdc++.h>
using namespace std;

struct data
{
    char dir;
    int td;
    int val;
    string s;
};
data v[100002];

int ox[] = {-1, 0, 1, 0};
int oy[] = {0, 1, 0, -1};

int viz[3002][3002];
int main()
{
    ifstream cin("input.in");
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> v[i].dir >> v[i].val >> v[i].s;
        if(v[i].dir == 'R')
            v[i].td = 1;
        if(v[i].dir == 'U')
            v[i].td = 0;
        if(v[i].dir == 'L')
            v[i].td = 3;
        if(v[i].dir == 'D')
            v[i].td = 2;
    }
    
    int x = 1000, y = 1000;
    viz[x][y] = 2;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= v[i].val; j++)
        {
            x += ox[v[i].td];
            y += oy[v[i].td];
            viz[x][y] = 2;
        }
    }
    queue<pair<int, int> > q;
    for(int i = 0; i <= 3000; i++)
    {
        if(viz[0][i] == 0)
        {
            q.push({0, i});
            viz[0][i] = 1;
        }
        if(viz[3000][i] == 0)
        {
            q.push({3000, i});
            viz[3000][i] = 1;
        }
        if(viz[i][0] == 0)
        {
            q.push({i, 0});
            viz[i][0] = 1;
        }
        if(viz[i][3000] == 0)
        {
            q.push({i, 3000});
            viz[i][3000] = 1;
        }
    }
    
    while(!q.empty())
    {
        pair<int, int> x = q.front();
        q.pop();
        for(int i = 0; i <= 3; i++)
        {
            int nxtX = x.first + ox[i];
            int nxtY = x.second + oy[i];
            if(nxtX >= 0 && nxtX <= 3000 && nxtY >= 0 && nxtY <= 3000)
            {
                if(viz[nxtX][nxtY] == 0)
                {
                    viz[nxtX][nxtY] = 1;
                    q.push({nxtX, nxtY});
                }
            }
        }
    }
    
    int cnt = 0;
    for(int i = 0; i <= 3000; i++)
        for(int j = 0; j <= 3000; j++)
            if(viz[i][j] != 1)
                cnt++;
    
    cout << cnt;
    return 0;
}
