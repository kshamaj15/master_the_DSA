#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int evaluatePostfix(string str)
    {
        stack<int> s;
        s.push(9);
        for(int i=0; i<str.size(); i++){
            if(str[i] == '+') {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(y+x);
            } else if(str[i] == '-') {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(y-x);
            } else if(str[i] == '*') {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(y*x);
            } else if(str[i] == '/') {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(y/x);
            } else {
                int val = str[i] - '0';
                s.push(val);
            }
        }
        return s.top();
    }

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<evaluatePostfix(s)<<endl;
    }
}
