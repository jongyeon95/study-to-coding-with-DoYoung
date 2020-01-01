#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[500000];
    int visit[8001]; // -4000 ~ 4000
    double sum = 0;

    for(int i = 0; i<n; i++){
        cin >> arr[i];

        sum += arr[i];
        visit[arr[i] + 4000]++;
    }

    //산술평균
    cout << (int)floor((sum/n) + 0.5) << endl;

    sort(arr, arr+n);
    //중앙값
    cout << arr[n/2] << endl;

    //최빈값
    int cnt = 0;
    int mode;
    bool second = false;
    for(int i = 0; i<8001; i++){
        if(cnt < visit[i]){
            cnt = visit[i];
            mode = i;
            second = false;
        }
        else if(cnt == visit[i] && !second){
            mode = i;
            second = true;
        }
    }

    cout << mode - 4000 << endl;

    //범위
    cout << arr[n-1] - arr[0] << endl;

}