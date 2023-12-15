#include <bits/stdc++.h>
using namespace std;

vector<pair<string, int> >hsh[256];

void work(int hash, string s)
{
    int nr = -1;
    for(int i = 0; i < (int) s.size(); i++)
        if(s[i] >= '0' && s[i] <= '9')
        {
            if(nr == -1)
                nr = 0;
            nr = nr * 10 + (s[i] - '0');
        }
    while(!(s.back() >= 'a' && s.back() <= 'z'))
        s.pop_back();
    if(nr == -1)
    {
        int poz = 0;
        while(poz < hsh[hash].size() && hsh[hash][poz].first != s)
            poz++;
        if(poz < hsh[hash].size())
            hsh[hash].erase(hsh[hash].begin() + poz);
    }
    else
    {
        for(int i = 0; i < hsh[hash].size(); i++)
            if(hsh[hash][i].first == s)
            {
                hsh[hash][i].second = nr;
                nr = -1;
            }
        if(nr != -1)
            hsh[hash].push_back({s, nr});
    }
}
int main()
{
    ifstream cin("input.in");
    
    string s;
    cin >> s;
    
    int hash = 0;
    
    string ss;
    for(int i = 0; i < (int) s.size(); i++)
    {
        if(s[i] == ',')
        {
            work(hash, ss);
            hash = 0;
            ss.clear();
        }
        else
        {
            if(s[i] >= 'a' && s[i] <= 'z')
            {
                hash += s[i];
                hash *= 17;
                hash %= 256;
            }
            ss += s[i];
        }
    }
    
    work(hash, ss);
    
    int sum = 0;
    for(int i = 0; i <= 255; i++)
    {
        for(int j = 0; j < hsh[i].size(); j++)
            sum += 1LL * hsh[i][j].second * (j + 1) * (i + 1);
    }
    
    cout << sum;
    return 0;
}
