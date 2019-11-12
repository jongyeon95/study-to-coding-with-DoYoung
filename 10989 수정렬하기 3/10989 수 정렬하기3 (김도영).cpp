#include <iostream>
using namespace std;

int n, x, array[10001] = {0};

int main() {
	cin >> n;

    //cout, cin 속도를 빠르게 해주는 코드
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //cout , cin 은 printf, scanf보다 속도가 느리다

	for (int i = 0; i < n; i++) {
		cin >> x;
		array[x]++;
	}

	for (int i = 1; i < 10001; i++) {
		while (array[i] != 0) {
            //endl 보다 \n이 더 빠르다.
			cout << i << "\n";
			array[i]--;
		}
	}
}