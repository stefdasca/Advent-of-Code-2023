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

int ox[] = {0, 1, 0, -1};
int oy[] = {1, 0, -1, 0};

int viz[3002][3002];

pair<long long, long long> coord[1001];
int main()
{
    ifstream cin("input.in");
    
    int n;
    cin >> n;
    int x = 0, y = 0;
    long long vx = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> v[i].dir >> v[i].val >> v[i].s;
        v[i].td = (v[i].s[7] - '0');
        v[i].val = 0;
        for(int j = 2; j <= 6; j++)
        {
            v[i].val = v[i].val * 16;
            if(v[i].s[j] <= '9')
                v[i].val += (v[i].s[j] - '0');
            else
                v[i].val += 10 + (v[i].s[j] - 'a');
        }
        if(v[i].td == 0)
            y += v[i].val;
        if(v[i].td == 1)
            x += v[i].val;
        if(v[i].td == 2)
            y -= v[i].val;
        if(v[i].td == 3)
            x -= v[i].val;
        coord[i] = {x, y};
        vx += v[i].val;
    }
    
    coord[n+1] = coord[1];
    
    long long area = 0;
    for(int i = 1; i <= n; i++)
        area += 1LL * (coord[i].first * coord[i+1].second - coord[i+1].first * coord[i].second);
        
    cout << abs(area) / 2 + vx / 2 + 1;
    return 0;
}
