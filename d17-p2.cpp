#include <bits/stdc++.h>
using namespace std;

long long dp[1002][1002][14][14];
bool viz[1002][1002][14][14];

int n, m;
char mat[1002][1002];

struct str
{
    int L, C, dir, consec;
};

int ox[] = {0, 1, 0, -1};
int oy[] = {1, 0, -1, 0};

int main()
{
    ifstream cin("input.in");
    
    while(cin >> mat[n])
        n++;
    m = strlen(mat[0]);
    
    queue<str> q;
    for(int i = 0; i <= 3; i++)
    {
        viz[0][0][i][0] = 1;
        q.push({0, 0, i, 0});
    }
    
    while(!q.empty())
    {
        str nod = q.front();
        q.pop();
        for(int dir = 0; dir <= 3; dir++)
        {
            int nxtX = nod.L + ox[dir];
            int nxtY = nod.C + oy[dir];
            if(dir == (nod.dir ^ 2))
                continue;
            if(dir != nod.dir && nod.consec < 4)
                continue;
            if(nxtX >= 0 && nxtX < n && nxtY >= 0 && nxtY < m)
            {
                int cntt = (dir == nod.dir ? nod.consec + 1 : 1);
                if(cntt <= 10 && !viz[nxtX][nxtY][dir][cntt])
                {
                    viz[nxtX][nxtY][dir][cntt] = 1;
                    dp[nxtX][nxtY][dir][cntt] = dp[nod.L][nod.C][nod.dir][nod.consec] + (mat[nxtX][nxtY] - '0');
                    q.push({nxtX, nxtY, dir, cntt});
                }
                else
                {
                    if(cntt <= 10 && dp[nxtX][nxtY][dir][cntt] > dp[nod.L][nod.C][nod.dir][nod.consec] + (mat[nxtX][nxtY] - '0'))
                    {
                        viz[nxtX][nxtY][dir][cntt] = 1;
                        dp[nxtX][nxtY][dir][cntt] = dp[nod.L][nod.C][nod.dir][nod.consec] + (mat[nxtX][nxtY] - '0');
                        q.push({nxtX, nxtY, dir, cntt});
                    }
                }
            }
        }
    }
    
    long long ans = (1LL<<60);
    for(int i = 0; i <= 10; i++)
        for(int j = 4; j <= 10; j++)
            if(viz[n-1][m-1][i][j])
                ans = min(ans, dp[n-1][m-1][i][j]);
    
    cout << ans;
    return 0;
}
