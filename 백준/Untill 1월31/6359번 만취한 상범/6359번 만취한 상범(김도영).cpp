#include <iostream>
using namespace std;

int main(){
    int dp[101] = {0};
    for(int i= 1; i<101; i++){
        for(int j=i; j<101; j+=i){
            if(dp[j] == 0){
                dp[j] = 1;
            }
            else{
                dp[j] = 0;
            }
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int answer = 0;
        for(int i= 1; i<=n; i++){
            if(dp[i] == 1){
                answer++;
            }
        }
        cout << answer << endl;
    }
}