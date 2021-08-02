// https://practice.geeksforgeeks.org/problems/knight-walk4521/1

// in progress
  
#include<bits/stdc++.h>
using namespace std;

unordered_set<int> visited;

vector<int> getPosition(int dir, vector<int> KnightPos, int N) {

    vector<int> newPos;
    int i = KnightPos[1];
    int j = KnightPos[0];
    switch (dir)
    {
    case 0: j-=2; i++; break;
    case 1: j--; i+=2; break;
    case 2: j++; i+=2; break;
    case 3: j+=2; i++; break;
    case 4: j+=2; i--; break;
    case 5: j++; i-=2; break;
    case 6: j--; i-=2; break;
    case 7: j-=2; i--; break;
    default:
        break;
    }

    int num = j*N + i;
    if(j > 0 && j <= N && i > 0 && i <=N && visited.find(num) == visited.end()){
        cout<<j<<" "<<i<<endl;
        visited.insert(num);
        newPos.push_back(j);
        newPos.push_back(i);
    }
 
    return newPos;
}

int knightWalk(vector<int> KnightPos, vector<int> TargetPos, int N, int steps, int minSteps){
    if(KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1]) {
        minSteps = min(minSteps, steps);
        cout<<"steps"<<steps<<" "<<minSteps<<endl;
        return minSteps;
    }

    for(int i=0; i<8; i++){
        vector<int> newPos = getPosition(i, KnightPos, N);
        // cout<<steps<<" "<<i<<endl;
        // if(newPos.size() == 2) cout<<newPos[0]<<" "<<newPos[1]<<endl;
        if(newPos.size() == 2) {
            minSteps = knightWalk(newPos, TargetPos, N, steps+1, minSteps);
            visited.erase(newPos[0]*N + newPos[1]);
            steps--;
        }
    }
    return minSteps;

}

int minStepToReachTarget(vector<int> KnightPos, vector<int> TargetPos, int N){
    // int* minS;
    // *minS = 9;
    int ans = knightWalk(KnightPos, TargetPos, N, 0, INT_MAX);
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;

    vector<int> knightPos(2);
    vector<int> targetPos(2);
    
    cin>>knightPos[0]>>knightPos[1]>>targetPos[0]>>targetPos[1];

    cout<<minStepToReachTarget(knightPos, targetPos, n)<<endl;
    
}
