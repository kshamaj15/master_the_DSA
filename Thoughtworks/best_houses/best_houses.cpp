#include<bits/stdc++.h>
using namespace std;

// tle

int solve (int N, vector<vector<int> > G) {
   int n = N*N;
   int maxH = INT_MIN;
   for(int i=0; i<n; i++){
       int i1 = i/N;
       int j1 = i%N;
       for(int j=i+1; j<n; j++){
            int i2 = j/N;
            int j2 = j%N;
            int currH = G[i1][j1] + G[i2][j2] - abs(i1-i2) - abs(j1-j2);
            cout<<i<<" "<<j<<" "<<currH<<endl;
           maxH = max(maxH, currH);
       }
   }
   return maxH;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        vector<vector<int> > G(N, vector<int>(N));
        for (int i_G = 0; i_G < N; i_G++)
        {
        	for(int j_G = 0; j_G < N; j_G++)
        	{
        		cin >> G[i_G][j_G];
        	}
        }

        int out_;
        out_ = solve(N, G);
        cout << out_;
        cout << "\n";
    }
}