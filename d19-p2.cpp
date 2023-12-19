#include <bits/stdc++.h>
using namespace std;

vector<string> conditions;
map<string, int> positions;

long long ans = 0;

void solve(int pos, int Lx, int Rx, int Lm, int Rm, int La, int Ra, int Ls, int Rs) 
{
    // cout << conditions[pos] << '\n';
    // cout << "XX " << pos << " " << Lx << " " << Rx << " " << Lm << " " << Rm << " " << La << " " << Ra << " " << Ls << " " << Rs << '\n';
    int i = 0;
    while(conditions[pos][i] != '{')
        i++;
    for( ; i < (int) conditions[pos].size(); i++)
    {
        if(conditions[pos][i] == 'A')
        {
            ans += 1LL * (Rx - Lx + 1) * (Rm - Lm + 1) * (Ra - La + 1) * (Rs - Ls + 1);
            return;
        }
        if(conditions[pos][i] == 'R')
            return;
        if(conditions[pos][i] == '{' || conditions[pos][i] == '}' || conditions[pos][i] == ',')
            continue;
       // cout << "cb " << conditions[pos][i] << '\n';
        if(conditions[pos][i+1] == '>' || conditions[pos][i+1] == '<')
        {
            char lit = conditions[pos][i];
            char sgn = conditions[pos][i+1];
            int nr = 0;
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
           // cout << lit << " " << sgn << " " << nr << " " << xx << '\n';
            if(sgn == '>')
            {
                if(lit == 'x')
                {
                    if(Rx > nr)
                    {
                        if(xx[0] == 'A')
                            ans += 1LL * (Rx - max(Lx, nr + 1) + 1) * (Rm - Lm + 1) * (Ra - La + 1) * (Rs - Ls + 1);
                        else
                            if(xx[0] == 'R');
                            else
                                solve(positions[xx] - 1, max(Lx, nr + 1), Rx, Lm, Rm, La, Ra, Ls, Rs);
                        Rx = max(nr + 1, Lx) - 1;
                    }
                }
                if(lit == 'm')
                {
                    if(Rm > nr)
                    {
                        if(xx[0] == 'A')
                            ans += 1LL * (Rx - Lx + 1) * (Rm - max(Lm, nr + 1) + 1) * (Ra - La + 1) * (Rs - Ls + 1);
                        else
                            if(xx[0] == 'R');
                            else
                                solve(positions[xx] - 1, Lx, Rx, max(Lm, nr + 1), Rm, La, Ra, Ls, Rs);
                        Rm = max(nr + 1, Lm) - 1;
                    }
                }
                if(lit == 'a')
                {
                    if(Ra > nr)
                    {
                        if(xx[0] == 'A')
                            ans += 1LL * (Rx - Lx + 1) * (Rm - Lm + 1) * (Ra - max(La, nr + 1) + 1) * (Rs - Ls + 1);
                        else
                            if(xx[0] == 'R');
                            else
                                solve(positions[xx] - 1, Lx, Rx, Lm, Rm, max(La, nr + 1), Ra, Ls, Rs);
                        Ra = max(nr + 1, La) - 1;
                    }
                }
                if(lit == 's')
                {
                    if(Rs > nr)
                    {
                        if(xx[0] == 'A')
                            ans += 1LL * (Rx - Lx + 1) * (Rm - Lm + 1) * (Ra - La + 1) * (Rs - max(Ls, nr + 1) + 1);
                        else
                            if(xx[0] == 'R');
                            else
                                solve(positions[xx] - 1, Lx, Rx, Lm, Rm, La, Ra, max(Ls, nr + 1), Rs);
                        Rs = max(nr + 1, Ls) - 1;
                    }
                }
            }
            if(sgn == '<')
            {
                if(lit == 'x')
                {
                    if(Lx < nr)
                    {
                        if(xx[0] == 'A')
                            ans += 1LL * (min(Rx, nr - 1) - Lx + 1) * (Rm - Lm + 1) * (Ra - La + 1) * (Rs - Ls + 1);
                        else
                            if(xx[0] == 'R');
                            else
                                solve(positions[xx] - 1, Lx, min(Rx, nr - 1), Lm, Rm, La, Ra, Ls, Rs);
                        Lx = min(nr - 1, Rx) + 1;
                    }
                }
                if(lit == 'm')
                {
                    if(Lm < nr)
                    {
                        if(xx[0] == 'A')
                            ans += 1LL * (Rx - Lx + 1) * (min(Rm, nr - 1) - Lm + 1) * (Ra - La + 1) * (Rs - Ls + 1);
                        else
                            if(xx[0] == 'R');
                            else
                                solve(positions[xx] - 1, Lx, Rx, Lm, min(Rm, nr - 1), La, Ra, Ls, Rs);
                        Lm = min(nr - 1, Rm) + 1;
                    }
                }
                if(lit == 'a')
                {
                    if(La < nr)
                    {
                        if(xx[0] == 'A')
                            ans += 1LL * (Rx - Lx + 1) * (Rm - Lm + 1) * (min(Ra, nr - 1) - La + 1) * (Rs - Ls + 1);
                        else
                            if(xx[0] == 'R');
                            else
                                solve(positions[xx] - 1, Lx, Rx, Lm, Rm, La, min(Ra, nr - 1), Ls, Rs);
                        La = min(nr - 1, Ra) + 1;
                    }
                }
                if(lit == 's')
                {
                    if(Ls < nr)
                    {
                        if(xx[0] == 'A')
                            ans += 1LL * (Rx - Lx + 1) * (Rm - Lm + 1) * (Ra - La + 1) * (min(Rs, nr - 1) - Ls + 1);
                        else
                            if(xx[0] == 'R');
                            else
                                solve(positions[xx] - 1, Lx, Rx, Lm, Rm, La, Ra, Ls, min(Rs, nr - 1));
                        Ls = min(nr - 1, Rs) + 1;
                    }
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
        {
            ans += 1LL * (Rx - Lx + 1) * (Rm - Lm + 1) * (Ra - La + 1) * (Rs - Ls + 1);
            return;
        }
        if(ss[0] == 'R')    
            return;
        solve(positions[ss] - 1, Lx, Rx, Lm, Rm, La, Ra, Ls, Rs);
        return;
    }
}
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
    
    solve(startpos - 1, 1, 4000, 1, 4000, 1, 4000, 1, 4000);
    cout << ans << '\n';
    
    return 0;
}
