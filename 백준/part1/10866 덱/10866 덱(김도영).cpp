#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    int T;
    cin >> T;
    deque<int> dq;

    while(T--){
        string s;
        int x;
        cin >> s;
        //front
        if(s[0] == 'f'){
            if(dq.empty()) 
                cout << -1 << endl;
            else
                cout << dq.front() << endl;
            
        }

        //back
        else if(s[0] == 'b'){
            if(dq.empty()) 
                cout << -1 << endl;
            else
                cout << dq.back() << endl;
        }
        //push
        else if(s[1] == 'u'){
            cin >> x;
            if(s[5] == 'f'){
                dq.push_front(x);
            }
            if(s[5] == 'b'){
                dq.push_back(x);
            }
        }

        //pop
        else if(s[1] == 'o'){
            if(s[4] == 'f'){
                if(dq.empty()) 
                    cout << -1 << endl;
                else{
                    cout << dq.front() << endl;
                    dq.pop_front();
                }
            }
            if(s[4] == 'b'){
                if(dq.empty()) 
                    cout << -1 << endl;
                else{
                    cout << dq.back() << endl;
                    dq.pop_back();
                }
            }
        }

        //size
        else if(s == "size"){
            cout << dq.size() << endl;
        }

        //empty
        else if(s == "empty"){
            if(dq.empty())
                cout << -1 << endl;
            else
                cout << 0 << endl;
        }

    }
}