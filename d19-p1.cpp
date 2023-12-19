#include <bits/stdc++.h>
using namespace std;

vector<string> conditions;
map<string, int> positions;
int main()
{
    ifstream cin("input.in");
    
    int n;
    cin >> n;
    
    int startpos = 0;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        conditions.push_back(s);
        if(s[0] == 'i' && s[1] == 'n' && s[2] == '{')
            startpos = i;
        string ss;
        for(int i = 0; i < (int) s.size(); i++)
            if(s[i] >= 'a' && s[i] <= 'z')
                ss += s[i];
            else
                break;
        positions[ss] = i;
    }
    
    int ans = 0;
    
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        string xpr;
        cin >> xpr;
        
        map<char, int> mp;
        int nr = 0;
        char lit;
        for(int j = 0; j < (int) xpr.size(); j++)
        {
            if(xpr[j] >= 'a' && xpr[j] <= 'z')
                lit = xpr[j];
            else
            {
                if(xpr[j] >= '0' && xpr[j] <= '9')
                    nr = nr * 10 + (xpr[j] - '0');
                else
                {
                    if(nr != 0)
                    {
                        mp[lit] = nr;
                        lit = 0;
                        nr = 0;
                    }
                }
            }
        }
        int pos = startpos - 1;
        int ok = 0;
        while(ok == 0)
        {
            int i = 0;
            while(conditions[pos][i] != '{')
                i++;
            for( ; i < (int) conditions[pos].size(); i++)
            {
                if(conditions[pos][i] == 'A')
                {
                    ok = 1;
                    break;
                }
                if(conditions[pos][i] == 'R')
                {
                    ok = -1;
                    break;
                }
                if(conditions[pos][i] == '{' || conditions[pos][i] == '}' || conditions[pos][i] == ',')
                    continue;
                if(conditions[pos][i+1] == '>' || conditions[pos][i+1] == '<')
                {
                    char lit = conditions[pos][i];
                    char sgn = conditions[pos][i+1];
                    nr = 0;
                    i += 2;
                    while(conditions[pos][i] >= '0' && conditions[pos][i] <= '9')
                    {
                        nr = nr * 10 + (conditions[pos][i] - '0');
                        i++;
                    }
                    i++;
                    string xx;
                    while(conditions[pos][i] != ',')
                    {
                        xx += conditions[pos][i];
                        i++;
                    }
                    if(sgn == '>')
                    {
                        if(mp[lit] > nr)
                        {
                            if(xx[0] == 'A')
                            {
                                ok = 1;
                                break;
                            }
                            if(xx[0] == 'R')
                            {
                                ok = -1;
                                break;
                            }
                            pos = positions[xx] - 1;
                            break;
                        }
                    }
                    if(sgn == '<')
                    {
                        if(mp[lit] < nr)
                        {
                            if(xx[0] == 'A')
                            {
                                ok = 1;
                                break;
                            }
                            if(xx[0] == 'R')
                            {
                                ok = -1;
                                break;
                            }
                            pos = positions[xx] - 1;
                            break;
                        }
                    }
                    continue;
                }
                string ss;
                while(conditions[pos][i] != '}')
                {
                    ss += conditions[pos][i];
                    i++;
                }
                if(ss[0] == 'A')
                    ok = 1;
                if(ss[0] == 'R')    
                    ok = -1;
                pos = positions[ss] - 1;
                break;
            }
        }
        if(ok == 1)
        {
            for(auto x : mp)
                ans += x.second;
        }
    }
    
    cout << ans;
    return 0;
}
