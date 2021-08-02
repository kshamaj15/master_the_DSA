// https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/

#include <bits/stdc++.h>
using namespace std;

unordered_set<int> visited;

int getPosition(int dir, int postion, int n)
{

    int i = postion % n;
    int j = postion / n;
    switch (dir)
    {
    case 0:
        j -= 2;
        i++;
        break;
    case 1:
        j--;
        i += 2;
        break;
    case 2:
        j++;
        i += 2;
        break;
    case 3:
        j += 2;
        i++;
        break;
    case 4:
        j += 2;
        i--;
        break;
    case 5:
        j++;
        i -= 2;
        break;
    case 6:
        j--;
        i -= 2;
        break;
    case 7:
        j -= 2;
        i--;
        break;
    default:
        break;
    }

    int num = j * n + i;
    if (j >= 0 && j < n && i >= 0 && i < n && visited.find(num) == visited.end())
    {
        visited.insert(num);
        return num;
    }
    return -1;
}

int getPath(int n, vector<vector<int>> &path, int steps, int position)
{

    if (steps == n * n - 1 && path[0][0] == 0)
    {
        
        return 1;
    }

    for (int i = 0; i < 8; i++)
    {
        int newPos = getPosition(i, position, n);
        if (newPos != -1)
        {
            int a = newPos / n;
            int b = newPos % n;
            path[a][b] = steps + 1;
            if(getPath(n, path, steps + 1, newPos) == 1) return 1;
            visited.erase(newPos);
            path[a][b] = 0;
        }
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<vector<int>> path(n, vector<int>(n, 0));

    if(!getPath(n, path, 0, 0)) cout<<"Solution Does not exist!"<<endl;
    else
    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
}
