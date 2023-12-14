#include <bits/stdc++.h>
using namespace std;

char mat[502][502];

int sol[10002];
int main()
{
    ifstream cin("input.in");
    ofstream cout("output.out");
    
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        cin >> mat[i];
    
    // find some periods and at least for me, the period was 78 
    
    for(int orzie = 1; orzie <= 5000; orzie++)
    {
        for(int iter = 1; iter <= 200; iter++)
        {
            for(int col = 0; col < 200; col++)
            {
                for(int lin = 1; lin <= n; lin++)
                {
                    if(mat[lin][col] == 'O' && mat[lin-1][col] == '.')
                        swap(mat[lin][col], mat[lin-1][col]);
                }
            }
        }
        for(int iter = 1; iter <= 200; iter++)
        {
            for(int lin = 1; lin <= n; lin++)
            {
                for(int col = 1; col <= 199; col++)
                {
                    if(mat[lin][col] == 'O' && mat[lin][col-1] == '.')
                        swap(mat[lin][col], mat[lin][col-1]);
                }
            }
        }
        for(int iter = 1; iter <= 200; iter++)
        {
            for(int col = 0; col < 200; col++)
            {
                for(int lin = n; lin >= 1; lin--)
                {
                    if(mat[lin][col] == 'O' && mat[lin+1][col] == '.')
                        swap(mat[lin][col], mat[lin+1][col]);
                }
            }
        }
        for(int iter = 1; iter <= 200; iter++)
        {
            for(int lin = 1; lin <= n; lin++)
            {
                for(int col = 199; col >= 0; col--)
                {
                    if(mat[lin][col] == 'O' && mat[lin][col+1] == '.')
                        swap(mat[lin][col], mat[lin][col+1]);
                }
            }
        }
        int ans = 0;
        for(int lin = 1; lin <= n; lin++)
            for(int col = 0; col < 200; col++)
                if(mat[lin][col] == 'O')
                    ans += (n - lin + 1);
        sol[orzie] = ans;
                
    }
    
    bool oki = 1;
    int ans = 0;
    for(int i = 1000; i <= 5000; i++)
    {
        if(sol[i] == sol[i-78]);
        else
            oki = 0;
        if((1000000000 - i) % 78 == 0)
            ans = sol[i];
    }
    
    for(int i = 1; i <= 5000; i++)
        cout << sol[i] << '\n';
        
    cout << oki << " " << ans << '\n';
    return 0;
}
