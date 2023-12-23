#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m, ans;

char mat[202][202];
bool viz[202][202];
int mx[202][202];

int ox[] = {1, 0, -1, 0};
int oy[] = {0, 1, 0, -1};

int len = 0;
int cnt = 0;
inline void dfs(int L, int C, int dir)
{
    if(L == n-1)
    {
        cnt++;
        if(dir < ans)
            return;
        if(cnt >= 10000000)
            exit(0);
        ans = max(ans, dir);
        return;
    }
    for(int nxt = 0; nxt <= 3; nxt++)
    {
        int X = L + ox[nxt];
        int Y = C + oy[nxt];
        if(X >= 0 && X < n && Y >= 0 && Y < m)
        {
            if(!viz[X][Y] && mat[X][Y] != '#')
            {
                viz[X][Y] = 1;
                dfs(X, Y, dir + 1);
                viz[X][Y] = 0;
            }
        }
    }
}
int main()
{
    ifstream cin("input.in");
    
    while(cin >> mat[n])
        n++;
    
    m = strlen(mat[0]);
    
    for(int i = 0; i < m; i++)
    {
        if(mat[0][i] == '.')
        {
            viz[0][i] = 1;
            dfs(0, i, -1);
            viz[0][i] = 0;
        }
    }
    
    cout << ans-1;
    return 0;
}
