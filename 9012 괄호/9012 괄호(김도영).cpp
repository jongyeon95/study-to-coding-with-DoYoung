#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        queue<int> q;
        string s;
        cin >> s;
        bool flag = true;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                q.push(s[i]);
            }
            if(s[i] == ')'){
                if(!q.empty()){
                    q.pop();
                }
                else{
                    flag = false;
                    break;
                }
            }
        }
        if(!q.empty()){
            flag = false;
        }

        if(flag){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        
    }
}