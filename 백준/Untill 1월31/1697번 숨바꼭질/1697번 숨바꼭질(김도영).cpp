#include <iostream>
#include <queue>
using namespace std;
queue<pair<int, int>> q;
int array[100001] = {0};
int n, k;

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(0>x || x>100000) continue;

        if(array[x] == 1){
            continue;
        }
        array[x] = 1;

        if(x == k){
            array[k] = cnt;
            break;
        }

        q.push(make_pair(2*x, cnt+1));
        q.push(make_pair(x+1, cnt+1));
        q.push(make_pair(x-1, cnt+1));
    }
}


int main(){
    cin >> n >> k;

    q.push(make_pair(n,0));

    bfs();

    cout << array[k] << endl;

    
}