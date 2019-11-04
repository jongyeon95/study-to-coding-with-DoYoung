#include <iostream>
using namespace std;

int check(int array[3]){
    int num[2] = {0};
    for(int i =0; i<2; i++){
        num[i] = array[i+1] - array[i];
    }
    if(num[0] == num[1]){
        return 1;
    }
    return 0;
}

int main(){
    int input;
    cin >> input;
    int array[3] = {0};
    int cnt = 99;

    //두자리 숫자인 경우는 다 한수이다.
    if(input <100){
        cnt = input;
    }
    
    else{
        for(int i = 100; i<=input; i++){
            if(i == 1000){
                break;
            }
            else{
                array[0] = i/100;
                array[1] = (i%100)/10;
                array[2] = (i%100)%10;
                if(check(array)){
                    cnt++;
                }
            }
        }
    }

    cout << cnt;
    
}