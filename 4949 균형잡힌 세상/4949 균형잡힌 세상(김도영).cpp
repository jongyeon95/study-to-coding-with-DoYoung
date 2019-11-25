#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    while(1){
        string s;
        getline(cin, s);
        stack<int> st;

        if(s.length() == 1 && s[0] == '.')
            break;

        bool flag = true;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                st.push('(');
            }
            else if(s[i] == '['){
                st.push('[');
            }
            else if(s[i] == ']'){
                if(!st.empty() && st.top()=='['){
                    st.pop();
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            else if(s[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else{
                    flag = false;
                    break;
                }
            }
        }

        if(flag && st.empty()){
            cout << "yes" << endl;;
        }
        else
        {
            cout << "no" << endl;
        }
        
    }

    return 0;
}