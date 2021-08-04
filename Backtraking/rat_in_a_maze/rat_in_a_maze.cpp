// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// in progress

#include <bits/stdc++.h>
using namespace std;

vector<string> fresult;

void findAns(string ans, int dir, vector<vector<int>> &m, int n, int row, int col, vector<vector<bool>>& visited)
{
    // cout << row << " " << col << endl;
    if (row == n - 1 && col == n - 1)
    {
        fresult.push_back(ans);
        return;
    }
    bool isSafe = false;

    if (dir == 0)
    {
        ans += 'L';
        row++;
    }
    else if (dir == 1)
    {
        ans += 'D';
        col++;
    }
    else if (dir == 2)
    {
        ans += 'R';
        row--;
    }
    else if (dir == 3)
    {
        ans += 'U';
        col--;
    }
    for (int i = 0; i < 4; i++)
    {
        int urow = row;
        int ucol = col;
        bool isSafe = false;

        // if (i == 0 && col < n - 1)
        // {
        //     isSafe = true;
        //     ucol = col + 1;
        // }
        // else if (i == 1 && row < n - 1)
        // {
        //     isSafe = true;
        //     urow = row + 1;
        // }
        // else if (i == 2 && col > 0)
        // {
        //     isSafe = true;
        //     ucol = col - 1;
        // }
        // else if (i == 3 && row > 0)
        // {
        //     isSafe = true;
        //     urow = row - 1;
        // }
        cout<<urow<<" "<<ucol<<endl;
        if (m[urow][ucol] && !visited[urow][ucol]) 
        {
            visited[urow][ucol] = true;
            findAns(ans, i, m, n, urow, ucol, visited);
            visited[urow][ucol] = false;
        }
    }
    cout << "ans " << ans << endl;
    if (ans.size())
        ans.pop_back();


    if (dir == 0)
    {
        row--;
    }
    else if (dir == 1)
    {
        col--;
    }
    else if (dir == 2)
    {
        row++;
    }
    else if (dir == 3)
    {
        col++;
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string ans = "";
    if (m[0][0] && m[0][1])
        findAns(ans, 0, m, n, 0, 0, visited);
    // ans = "D";
    if (m[0][0] && m[1][0])
        findAns(ans, 1, m, n, 0, 0, visited);
    return fresult;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }

        vector<string> result = findPath(m, n);

        if (result.size())
        {
            for (int i = 0; i < n; i++)
            {
                cout << fresult[i] << endl;
            }
        }
        else
        {
            cout << "No result found" << endl;
        }
    }
}
