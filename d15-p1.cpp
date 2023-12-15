#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream cin("input.in");
    
    string s;
    cin >> s;
    
    int sum = 0;
    int hsh = 0;
    for(int i = 0; i < (int) s.size(); i++)
    {
        if(s[i] == ',')
        {
            sum += hsh;
            hsh = 0;
        }
        else
        {
            hsh += s[i];
            hsh *= 17;
            hsh %= 256;
        }
    }
    
    sum += hsh;
    cout << sum;
    
    return 0;
}
