// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool isSafe(bool graph[101][101], vector<int> &colorsOfNodes, int index, int color, int n) {
    for (int i=0; i<n; i++) {
        if(graph[i][index] && colorsOfNodes[i] == color && i != index)
        return false;
    }
    return true;
}

bool graphColoringRecur(bool graph[101][101], vector<int> &colorsOfNodes, int index, int m, int n) {
    if(index == n)
    return true;

    for(int i=0; i<m; i++){
        colorsOfNodes[index] = i;
        if(isSafe(graph, colorsOfNodes, index, i, n)){
            if(graphColoringRecur(graph, colorsOfNodes, index+1, m, n)) return true;
        }
        colorsOfNodes[index] = -1;
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int> colorsOfNodes(V, -1);
    return graphColoringRecur(graph, colorsOfNodes, 0, m, V);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--) {
      int n,m,e;
      cin>>n>>m>>e;
      int i;
      bool graph[101][101];
      memset(graph, false, sizeof(graph));
      for (int i = 0; i<e; i++) {
        int a, b;
        cin>>a>>b;
        graph[a-1][b-1] = true;
        graph[b-1][a-1] = true;
      }     
      cout<<graphColoring(graph, m, n)<<endl;
  }
}
