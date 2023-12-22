#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

using T = array<int, 3>;
using Brick = pair<T, T>;

int main() 
{
    string line;
    vector<Brick> bricks;
    int MX = 0;
    while (getline(cin, line)) 
    {
        if(line.size() == 1)
            break;
        replace(all(line), '~', ' ');
        replace(all(line), ',', ' ');
        stringstream ss(line);
        Brick brick;
        string x;
        for (auto& y: brick.first) {
            ss >> y;
            if(y + 1 > MX)
                MX = y + 1;
        }
        for (auto& y: brick.second) {
            ss >> y;
            if(y + 1 > MX)
                MX = y + 1;
        }
        if (brick.first[2] > brick.second[2]) 
            swap(brick.first, brick.second);
        bricks.push_back(brick);
    }
    int N = bricks.size();
    vector<vector<int>> ht(MX, vector<int>(MX, 0));
    vector<vector<int>> id(MX, vector<int>(MX, -1));

    sort(all(bricks), [&](auto a, auto b) {
        return a.first[2] < b.first[2];
    });

    set<int> CANNOT;
    vector<vector<int>> adj(N);

    for(int i = 0; i < bricks.size(); i++)
    {
        auto [p1, p2] = bricks[i];
        auto [x1, y1, z1] = p1;
        auto [x2, y2, z2] = p2;
        int mx = 0;

        for (int x = min(x1, x2); x <= max(x1, x2); x++) 
            for (int y = min(y1, y2); y <= max(y1, y2); y++) 
                if(mx < ht[x][y])
                    mx = ht[x][y];

        set<int> s;
        for (int x = min(x1, x2); x <= max(x1, x2); x++) {
            for (int y = min(y1, y2); y <= max(y1, y2); y++) {
                if (ht[x][y] == mx && id[x][y] != -1) {
                    if (id[x][y] != -1) 
                        s.insert(id[x][y]);
                }
                ht[x][y] = mx + (z2 - z1 + 1);
                id[x][y] = i;
            }
        }
        if (s.size() == 1) 
            CANNOT.insert(*s.begin());
        for (auto j: s) 
            adj[j].push_back(i);
    }

    int part1 = N - CANNOT.size();
    cout << "Part 1: " << part1 << '\n';
    return 0;
}
