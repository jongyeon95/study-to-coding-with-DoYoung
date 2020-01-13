#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int dp[41] = {1,1};
    for(int i= 2; i<=n; i++){
        dp[i] = dp[i-1] +dp[i-2];
    }

    int sum = 1;
    int temp=0;

    for(int i=0; i<m; i++){
        int k;
        cin >> k;
        sum *= dp[k-temp-1];
        temp = k;
    }

    sum *= dp[n-temp];
    
    cout << sum << endl;
}