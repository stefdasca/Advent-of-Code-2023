#include <bits/stdc++.h>
using namespace std;

long long n, initial[100002], cnt[8];
struct ranges
{
    long long La, Lb, len;
};
ranges v[8][100002];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> initial[i];
    
    for(int i = 0; i <= 6; i++)
    {
        cin >> cnt[i];
        for(int j = 1; j <= cnt[i]; j++)
            cin >> v[i][j].La >> v[i][j].Lb >> v[i][j].len;
    }
    
    long long smallest_location = (1LL<<60);
    for(int i = 1; i <= n; i += 2)
    {
        long long min_diff = 0;
        for(int j = 0; j < initial[i+1]; j += min_diff)
        {
            long long poz = initial[i] + j;
            min_diff = (1LL<<60);
            for(int step = 0; step <= 6; step++)
            {
                for(int j = 1; j <= cnt[step]; j++)
                {
                    if(v[step][j].Lb <= poz && v[step][j].Lb + v[step][j].len - 1 >= poz)
                    {
                        min_diff = min(min_diff, (v[step][j].La + v[step][j].len) - (v[step][j].La + (poz - v[step][j].Lb)));
                        poz = v[step][j].La + (poz - v[step][j].Lb);
                        break;
                    }
                }
            }
            smallest_location = min(smallest_location, poz);
        }
    }
    cout << smallest_location;
    return 0;
}
