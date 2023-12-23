#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m, ans;

char mat[202][202];
bool viz[202][202];

int ox[] = {-1, 0, 1, 0};
int oy[] = {0, 1, 0, -1};

int len = 0;
void dfs(int L, int C, int dir)
{
    len++;
    if(L == n-1)
        ans = max(ans, len);
    int mandatory = -1;
    if(mat[L][C] == '>')
        mandatory = 1;
    if(mat[L][C] == '^')
        mandatory = 0;
    if(mat[L][C] == 'v')
        mandatory = 2;
    if(mat[L][C] == '<')
        mandatory = 3;
    for(int nxt = 0; nxt <= 3; nxt++)
    {
        int X = L + ox[nxt];
        int Y = C + oy[nxt];
        if(mandatory != -1 && nxt != mandatory)
            continue;
        if(X >= 0 && X < n && Y >= 0 && Y < m)
        {
            if(!viz[X][Y] && mat[X][Y] != '#')
            {
                viz[X][Y] = 1;
                dfs(X, Y, nxt);
                viz[X][Y] = 0;
            }
        }
    }
    len--;
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
