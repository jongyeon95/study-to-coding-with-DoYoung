#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    //dp[4] = 2까지 할당 
    //dp[5] 부터는 dp[n-1] +dp[n-5] 공식 사용
    long long dp[101] = {1,1,1,2,2};
    //Bottom-up 방식
    for(int i= 5; i<101; i++){
        dp[i] = dp[i-1] + dp[i-5];
    }

    while(T--){
        int input;
        cin >> input;
        cout << dp[input-1] << endl;
    }
}