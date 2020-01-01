#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        string ac ;
        string input;
        deque<int> de;
        int n;
        cin >> ac; 
        cin >> n ;
        cin >> input;

        int sum = 0;
        for(int i = 1; i<input.size(); i++){
            if(n != 0){
                if(input[i] == ',' || input[i] == ']'){
                    de.push_back(sum);
                    sum = 0;
                }
                else{
                    sum = sum * 10 + (input[i]-'0');
                }
            }
        }

        bool flag = false;
        bool R = false;
        for(int i= 0; i<ac.size(); ++i){
            if(ac[i] == 'R'){
                R = !R;
            }

            else{
                if(de.empty()){
                    flag = true;
                    break;
                }
                else{
                    if(R){
                        de.pop_back();
                    }
                    else{
                        de.pop_front();
                    }
                }
            }
        }

#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        string ac ;
        string input;
        deque<int> de;
        int n;
        cin >> ac; 
        cin >> n ;
        cin >> input;

        int sum = 0;
        for(int i = 1; i<input.length(); i++){
            if(input[i] != ',' && input[i] != ']'){
                sum = sum * 10 + (input[i]-'0');
            }
            else if(sum != 0){
                de.push_back(sum);
                sum = 0;
            }
        }

        bool flag = false;
        bool R = false;
        for(int i= 0; i<ac.length(); i++){
            if(ac[i] == 'R'){
                if(de.size()!=0&&de.size()!=1){
					R= !R;	
				}
            }

            else{
                if(de.empty()){
                    flag = true;
                    break;
                }
                if(R){
                    de.pop_back();
                }
                else{
                    de.pop_front();
                }
            }
        }


         if(flag)
			cout << "error" <<endl;
		else if(de.size()==0)
			cout <<"[]"<<endl;
        else{
            cout << "[" ;

            if(R){
                for(int i = de.size() -1; i>0; i--){
                    cout << de[i] << "," ;
                }
                cout << de[0] << "] \n";
            }
            else{
                for(int i = 0; i<de.size()-1; ++i){
                    cout << de[i] << "," ;
                }
                cout << de[de.size()-1] << "] \n";
            }   
        }
    }
}
