#include <iostream>
using namespace std;

int main(){

    //소수인게 false가 된다.
    bool decimal[10001] = {true, true, false};
    for(int i = 2; i*i<= 10000; i++){
        if(decimal[i] == false ){
            for(int j = i*i; j<=10000; j+=i){
                decimal[j] = true;
            }
        }
    }

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int answer = 9999;
        int a, b, x;
        for(int i = 2; i <= n/2; i++){
            x = n;
            if(!decimal[i]){
                x -= i;
                if(!decimal[x] && answer > (max(x,i) - min(x,i))){
                    answer = (max(x,i) - min(x,i));
                    a = min(x,i); b = max(x,i);
                }
            }
        }
        cout << a << " " << b << endl;
    }
}