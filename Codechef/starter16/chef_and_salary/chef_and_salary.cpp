#include <iostream>
#include <string>
using namespace std;

int main() {
    
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--){
	    int x, y;
	    cin>>x>>y;
	    string s;
	    cin>>s;
	    int i = 0;
	    int streak = 0;
	    int mx = 0;
	    int days = 0;
	    do{
	        if(s[i] == '1') {
	            days++;
	            streak++;
	        } else {
	            streak = 0;
	        }
	        mx = max(mx, streak);
	    } while (s[i++] != '\0');
	    cout<<x*days + mx*y<<"\n";
	}
	return 0;
}
