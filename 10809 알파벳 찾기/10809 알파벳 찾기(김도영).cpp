#include <iostream>
#include <string>
using namespace std;

int main(){
    char alpa[26] = {'a','b','c','d','e','f','g','h','i',
    'j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    string S;
    cin >> S;

    //S�� ���ĺ��� ���� ���� -1�� ����ϱ� ���� flag�� ��������ϴ�.
    bool flag;
    for(int i = 0; i<26; i++){
        for(int j= 0; j<S.length(); j++){
            flag = true;
            if(alpa[i] == S[j]){
                cout << j << " " ;
                flag = false;
                //ó���� ���� ���ĺ��� �˻��ϱ� ���� break���
                //�̸� ���� �������� ���ĺ� "oo" �κп��� ó���� ����
                //'o'�� ��ġ ���
                break;
            }
        }
        if(flag)
            cout << "-1 " ;
    }
}