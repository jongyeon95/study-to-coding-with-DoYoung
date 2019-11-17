#include <iostream>
using namespace std;

int main(){
    bool decimal[246913] = {false };

    //에라토스테네스의 체 알고리즘 사용
    //루트 i 까지만 검사를 해도 됨
    for(int i = 2; i*i<246913; i++){
        if(decimal[i] == false){
            for(int j = i*i; j<246913; j+=i){
                decimal[j] = true;
            }
        }
    }

    while(1){
        int input, cnt = 0;
        cin >> input;
        if(input == 0) break;

        for(int i = input+1; i<=2*input; i++){
            if(decimal[i] == false){
                cnt++;
            }
        }
        
        cout << cnt << endl;
    }
}