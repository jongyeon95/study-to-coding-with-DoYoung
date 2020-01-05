#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int dp[n];
	dp[0]=3;
	dp[1]=7;
	for (int i = 2; i < n; ++i)
	{
		dp[i]=dp[i-1]*2+dp[i-2];
		dp[i]=dp[i]%9901;
	}
	cout << dp[n-1];
}