#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;
    cin >> input;

    int Answer = 0;
    for(int i = 0; i<input.length(); i++){
        if(input[i] == 's' || input[i] == 'z')
            if(input[i+1] == '=')
                i++;
          
        if(input[i] == 'c')
            if(input[i+1] == '=' || input[i+1] == '-')
                i++;
            
        if(input[i] == 'n' || input[i] == 'l')
            if(input[i+1] == 'j')
                i++;
        
        //'d'�� �κ��� 3������ �κ��� �־� else if�� ���
        if(input[i] == 'd'){
            if(input[i+1] == '-')
                i++;
            else if(input[i+1] == 'z' && input[i+2] == '=')
                i += 2;
        }

        Answer++;

    }
    cout << Answer;
}