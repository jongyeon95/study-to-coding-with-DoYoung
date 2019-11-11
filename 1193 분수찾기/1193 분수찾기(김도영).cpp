#include <iostream>
using namespace std;

int main(){
    int input;
    cin >> input;
    int x , y;
    int temp = 0;
    int skip = 0;
    bool flag = true;
    
    for(int i = 0; flag; i++){
        temp += i;
        if(input<=temp){
            flag = false;
            skip = input - (temp - i);
            temp = i+1;
        }
    }

    //짝수
    if(temp % 2 == 0){
        x = temp - skip;
        y = temp - x;
    }
    //홀수
    else{
        y = temp - skip;
        x = temp - y;
    }

    cout << x << "/" << y ;
}