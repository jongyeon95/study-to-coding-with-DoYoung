#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    string room;
    cin >> room;
    int temp = 0;
    int answer = 0;
    int set[10] = { 0 };

    for(int i = 0; i<room.length(); i++){
        set[room[i] - '0']++;
    }
    temp = (max(set[6], set[9]) - min(set[6], set[9]))/2;

    if(set[6] > set[9]){
        set[6] -= temp;
    }
    else if( set[6] < set[9]){
        set[9] -= temp;
    }
    

    for(int i = 0; i<10; i++){
        answer = max(set[i], answer);
    }
    
    cout << answer;

}