#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    //k배수가 아니면 뒤로 보내기
    queue<int> q;
    for(int i = 0; i<n; i++){
        q.push(i+1);
    }

    cout << "<";
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<k-1; j++){
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">";

}