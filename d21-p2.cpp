#include <bits/stdc++.h>
using namespace std;

char mat[200][200];

bool dp[1001][1001][401];

int n;

int ox[] = {-1, 0, 1, 0};
int oy[] = {0, 1, 0, -1};

struct str
{
    int L, C, d;
};

char trueval(int x, int y)
{
    x %= n;
    y %= n;
    if(x < 0)
        x += n;
    if(y < 0)
        y += n;
    if(x == 0)
        x = n;
    if(y == 0)
        y = n;
    return mat[x][y];
}

int main()
{
    ifstream cin("input.in");
    
    while(cin >> (mat[n+1] + 1))
        n++;
    
    int L = 0, C = 0;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(mat[i][j] == 'S')
                L = i, C = j;
    
    dp[L + 400][C + 400][0] = 1;
    queue<str> q;
    q.push({L, C, 0});
    
    while(!q.empty())
    {
        str nod = q.front();
        q.pop();
        
        if(nod.d > 400)  
            break;
        for(int i = 0; i <= 3; i++)
        {
            int nxtX = nod.L + ox[i];
            int nxtY = nod.C + oy[i];
            if(dp[nxtX + 400][nxtY + 400][nod.d + 1] == 0 && trueval(nxtX, nxtY) != '#')
            {
               dp[nxtX + 400][nxtY + 400][nod.d + 1] = 1;
               q.push({nxtX, nxtY, nod.d + 1}); 
            }
        }
    }
    
    // 3719 + 14808 x + 14663 x^2
    
    long long ratio = 26501365 / 131;
    
    long long ans = 1LL * 3719 + 14808 * ratio + 14663 * ratio * ratio;
    
    for(int d = 1; d <= 400; d++)
    {
        int cnt = 0;
        for(int i = 0; i <= 1000; i++)
            for(int j = 0; j <= 1000; j++)
                cnt += dp[i][j][d];
        
        cout << d << " " << cnt << '\n';
    }
     
    cout << ans;
    return 0;
}
