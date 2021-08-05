// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <bits/stdc++.h>
using namespace std;

vector<string> fresult;

void findPath(int dir, int row, int col, int n, string ans, vector<vector<int>>&m, vector<vector<bool>>&visited) {
    if(row < 0 || col < 0 || row >= n || col >= n)
    return;
    else if(!m[row][col])
    return;

    visited[row][col] = true;

    if(row == n-1 && col == n-1){
        // cout<<"ans "<<ans<<endl;
        if(!fresult.size() || fresult[fresult.size() - 1] != ans)
            fresult.push_back(ans);
            return;
    }
    
    switch (dir)
    {
        case 0: ans += 'R'; col++; break;
        case 1: ans += 'D'; row++; break;
        case 2: ans += 'L'; col--; break;       
        case 3: ans += 'U'; row--; break;
    }

    if(row >= 0 && col >= 0 && row < n && col < n) {
        if(!m[row][col] && visited[row][col]) ans.pop_back();
        if(!visited[row][col]) {
        for (int i = 0; i < 4; i++) {
            findPath(i, row, col, n, ans, m, visited);
        }
        visited[row][col] = false;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outpu.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }

        // m = {{1,0}, {1,1}};

        string ans = "";

       findPath(0,0,0, n, ans, m, visited);
       findPath(1,0,0, n, ans, m, visited);

        if (fresult.size())
        {
            for (int i = 0; i < n; i++)
            {
                cout << fresult[i] << endl;
            }
            cout<<endl;
        }
        else
        {
            cout << "No result found" << endl;
        }

    }

}
