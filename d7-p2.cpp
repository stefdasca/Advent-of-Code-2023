#include <bits/stdc++.h>
using namespace std;

struct hand
{
    string x;
    int val;
};
hand v[100002];

int val(string s)
{
    sort(s.begin(), s.end());
    map<char, int> m;
    for(int i = 0; i < 5; i++)
        m[s[i]]++;
    int cntJokers = m['0'];
    
    for(int i = 0; i < 5; i++)
        if(s[i] != '0' && m[s[i]] + cntJokers >= 5)
            return 7;
    if(cntJokers == 5)
        return 7;
    
    for(int i = 0; i < 5; i++)
        if(s[i] != '0' && m[s[i]] + cntJokers >= 4)
            return 6;
    if(cntJokers == 4)
        return 6;

    if(cntJokers)
    {
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                if(s[i] != s[j] && s[i] != '0' && s[j] != '0' && m[s[i]] + m[s[j]] + cntJokers == 5)
                    return 5;
    }
    else
    {
        if(m[s[0]] == 3 && m[s[3]] == 2)
            return 5;
        if(m[s[0]] == 2 && m[s[3]] == 3)
            return 5;
    }
    for(int i = 0; i < 5; i++)
        if(s[i] != '0' && m[s[i]] + cntJokers >= 3)
            return 4;
    if(cntJokers == 3)
        return 4;
    
    if(cntJokers)
    {
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                if(s[i] != s[j] && s[i] != '0' && s[j] != '0' && m[s[i]] + m[s[j]] + cntJokers == 4)
                    return 3;
    }
    else
    {
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                if(s[i] != s[j] && m[s[i]] == 2 && m[s[j]] == 2)
                    return 3;
    }
    for(int i = 0; i < 5; i++)
        if(m[s[i]] + cntJokers == 2)
            return 2;
            
    return 1;
}
map<char, char> mp;
bool cmp(hand a, hand b)
{
    if(val(a.x) == val(b.x))
        return a.x < b.x;
    return val(a.x) < val(b.x);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    mp['T'] = 'i'; mp['J'] = '0'; mp['Q'] = 'k';
    mp['K'] = 'l'; mp['A'] = 'm';
    
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        cin >> v[i].x >> v[i].val;
        for(int j = 0; j < (int) v[i].x.size(); j++)
        {
            if(v[i].x[j] >= '2' && v[i].x[j] <= '9')
                v[i].x[j] = 'a' + (v[i].x[j] - '2');
            else
                v[i].x[j] = mp[v[i].x[j]];
        }
    }
        
    sort(v + 1, v + n + 1, cmp);
    long long ans = 0;
    
    for(int i = 1; i <= n; i++)
        ans += v[i].val * i;
    cout << ans;
    return 0;
}
