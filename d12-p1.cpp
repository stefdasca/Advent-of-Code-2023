#include <bits/stdc++.h>
using namespace std;

int numbers[101], dp[101][102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; 
    cin >> t; // read number of strings first
    
    long long ans = 0;
    
    for(; t; t--)
    {
        string a, b;
        cin >> a >> b;
        
        int cnt = 0;
        int nr = 0;
        int lstwall = 0;
        for(int i = 0; i < b.size(); i++)
        {
            if(b[i] >= '0' && b[i] <= '9')
                nr = nr * 10 + b[i] - '0';
            else
            {
                if(nr > 0)
                {
                    cnt++;
                    numbers[cnt] = nr;
                    nr = 0;
                }
            }
        }
        for(int i = 0; i < a.size(); i++)
            if(a[i] == '#')
                lstwall = i+1;
        if(nr > 0)
        {
            cnt++;
            numbers[cnt] = nr;
            nr = 0;
        }
        
        a = ' ' + a;
        dp[0][0] = 1;
        for(int i = 1; i < a.size(); i++)
        {   
            for(int j = 1; j <= cnt; j++)
            {
                bool ok = 1;
                for(int x = i - numbers[j] + 1; x <= i; x++)
                {
                    if(x < 0)
                        ok = 0;
                    else
                    {
                        if(a[x] == '.')
                            ok = 0;
                    }
                }
                if(ok)
                {
                    if(i - numbers[j] >= 0 && a[i - numbers[j]] == '#')
                        ok = 0;
                }
                if(ok)
                {
                    for(int x = i - numbers[j]; x >= 0; x--)
                    {
                        if(x == i - numbers[j] && j > 1);
                        else
                            dp[i][j] += dp[x][j-1];
                        if(a[x] == '#')
                            break;
                    }
                }
            }
            if(i >= lstwall)
                ans += dp[i][cnt];
        }
        memset(dp, 0, sizeof(dp));
    }
    
    cout << ans << '\n';
    return 0;
}
