#include <iostream>
#include <string>
using namespace std;

int main(){
    char alpa[26] = {'a','b','c','d','e','f','g','h','i',
    'j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    string S;
    cin >> S;

    //S에 알파벳이 없을 때만 -1를 출력하기 위해 flag를 만들었습니다.
    bool flag;
    for(int i = 0; i<26; i++){
        for(int j= 0; j<S.length(); j++){
            flag = true;
            if(alpa[i] == S[j]){
                cout << j << " " ;
                flag = false;
                //처음에 나온 알파벳만 검사하기 위해 break사용
                //이를 통해 예제에서 알파벳 "oo" 부분에서 처음에 나온
                //'o'의 위치 출력
                break;
            }
        }
        if(flag)
            cout << "-1 " ;
    }
}