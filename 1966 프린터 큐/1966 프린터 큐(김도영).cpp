#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct{
    int x;
    int y;
} Q;


int main(){
    int T;
    cin >> T;
    while(T--){
        queue<Q> q;
        int n, m ;
        cin >> n >> m;
        priority_queue<int> pri;

        for(int i = 0; i<n; i++){
            int x;
            cin >> x;
            q.push({i,x});
            pri.push(x);
        }

        int cnt = 1;
        while(!q.empty()){
            if(pri.top() == q.front().y){
                if(q.front().x == m){
                    cout << cnt << endl;
                    break;
                }
                else{
                    q.pop();
                    pri.pop();
                    cnt++;
                }
            }
            else{
                q.push({q.front().x , q.front().y});
                q.pop();
            }
        }
    }
}