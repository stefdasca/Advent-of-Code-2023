#include <bits/stdc++.h>
using namespace std;

char mat[200][200];

bool dp[200][200][100];

int n;

int ox[] = {-1, 0, 1, 0};
int oy[] = {0, 1, 0, -1};

struct str
{
    int L, C, d;
};

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
    
    dp[L][C][0] = 1;
    queue<str> q;
    q.push({L, C, 0});
    
    while(!q.empty())
    {
        str nod = q.front();
        q.pop();
        
        if(nod.d > 64)  
            break;
        for(int i = 0; i <= 3; i++)
        {
            int nxtX = nod.L + ox[i];
            int nxtY = nod.C + oy[i];
            if(nxtX >= 1 && nxtX <= n && nxtY >= 1 && nxtY <= n)
            {
                if(dp[nxtX][nxtY][nod.d + 1] == 0 && mat[nxtX][nxtY] != '#')
                {
                   dp[nxtX][nxtY][nod.d + 1] = 1;
                   q.push({nxtX, nxtY, nod.d + 1}); 
                }
            }
        }
    }
    
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cnt += dp[i][j][64];
    
    cout << cnt;
    return 0;
}
