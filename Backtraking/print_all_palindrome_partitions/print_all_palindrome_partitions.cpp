// https://www.geeksforgeeks.org/given-a-string-print-all-possible-palindromic-partition/

#include <bits/stdc++.h>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(string str, int low, int high)
{
    while (low < high)
    {
        if (str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}

void allPalPartitionsHelper(string str, string palin, int sindex){
    if(sindex == str.length()) {
        if(palin.length() > 1)
        cout<<palin.substr(0, palin.length()-1)<<endl;
    }
    for (int i=sindex; i<str.length(); i++) {
        string sub = str.substr(sindex, i - sindex + 1);
        if(isPalindrome(str, sindex, i)) {
            // cout<<sub<<endl;
            palin += sub + ' ';
            allPalPartitionsHelper(str, palin, i+1);
            palin = palin.substr(0, palin.length() - sub.length() - 1);
        }
    }
}

void allPalPartitions(string str) {
    string palin = "";
    allPalPartitionsHelper(str, palin, 0);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while (t--) {
        string str;
        cin>>str;
        allPalPartitions(str);
        cout<<endl;
    }
}
