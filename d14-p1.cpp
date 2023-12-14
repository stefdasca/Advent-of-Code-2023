#include <bits/stdc++.h>
using namespace std;

char mat[502][502];
int main()
{
    ifstream cin("input.in");
    ofstream cout("output.out");
    
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        cin >> mat[i];
    
    for(int iter = 1; iter <= 100; iter++)
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
    
    int ans = 0;
    for(int lin = 1; lin <= n; lin++)
        for(int col = 0; col < 200; col++)
            if(mat[lin][col] == 'O')
                ans += (n - lin + 1);
    
    cout << ans;
    return 0;
}
