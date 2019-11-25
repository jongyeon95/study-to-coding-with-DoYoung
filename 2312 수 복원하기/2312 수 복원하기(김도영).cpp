#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int array[100001] = {0};
        int input;
        cin >> input;

        int i = 2;
        while(input != 1){
            if(input % i == 0){
                array[i]++;
                input = input / i;
            }
            else{
                i++;
            }
        }

        for(int i = 0 ; i<100001; i++){
            if(array[i] != 0){
                cout << i << " " << array[i] << endl;
            }
        }
    }
}