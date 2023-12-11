#include <bits/stdc++.h>
using namespace std;

char mat[141][141];
bool emptyLine[141], emptyCol[141];

int spLine[141], spCol[141];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 139;
    
    for(int i = 0; i <= n; i++)
        cin >> (mat[i]);
    
    for(int i = 0; i <= n; i++)
        emptyCol[i] = emptyLine[i] = 1;
        
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            if(mat[i][j] == '#')
                emptyCol[j] = emptyLine[i] = 0;
        
    for(int i = 0; i <= n; i++)
    {
        spLine[i] = emptyLine[i];
        spCol[i] = emptyCol[i];
        if(i)
        {
            spLine[i] += spLine[i-1];
            spCol[i] += spCol[i-1];
        }
    }
    
    long long ans = 0;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
        {
            if(mat[i][j] == '#')
            {
                for(int i2 = 0; i2 <= n; i2++)
                {
                    for(int j2 = 0; j2 <= n; j2++)
                    {
                        if(mat[i2][j2] == '#')
                        {
                            long long dist = abs(i2 - i) + abs(j2 - j);
                            dist += 999999LL * (spLine[max(i, i2)] - spLine[min(i, i2)]);
                            dist += 999999LL * (spCol[max(j, j2)] - spCol[min(j, j2)]);
                            ans += dist;
                        }
                    }
                }
            }
        }
    
    cout << ans/2;
    return 0;
}
