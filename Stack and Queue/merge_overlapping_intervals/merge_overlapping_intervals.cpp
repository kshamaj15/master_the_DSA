// https://leetcode.com/problems/merge-intervals/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool compareInterval(vector<int> i1, vector<int> i2)
{
    return (i1[0] < i2[0]);
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), compareInterval);
    stack<vector<int>> s;
    vector<int> inter(2);
    vector<vector<int>> ans;
    for (int i=0; i<intervals.size(); i++) {
        if(s.empty()){
            s.push(intervals[i]);
        } else if(s.top()[1] >= intervals[i][0]) {
            if(s.top()[1] < intervals[i][1])
            s.top()[1] = intervals[i][1];
        } else {
            ans.push_back(s.top());
            s.pop();
            s.push(intervals[i]);
        }
    }
    if(!s.empty()) ans.push_back(s.top());
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int>(2));
        for (int i=0; i<n; i++) {
            for (int j=0; j<2; j++) {
                cin>>arr[i][j];
            }
        }
        vector<vector<int>> ans = merge(arr);
        for(auto v: ans) {
            for(auto el: v) {
                cout<<el<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
