#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

char treasure[50][50];
bool check[50][50];
int location[50][50];
queue<pair<int, int>> q;
pair<int, int> moveDir[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int n, m;
int answer = 1;


void bfs(int y, int x){
    check[y][x] = false;
    q.push(make_pair(y,x));

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i= 0; i<4; i++){
            int nexty = y+moveDir[i].first;
            int nextx = x+moveDir[i].second;

            if(nexty < 0 || n <= nexty || nextx < 0 || m <= nextx)
                continue;

            if(treasure[nexty][nextx] == 'L' && check[nexty][nextx]){
                check[nexty][nextx] = false;
                q.push(make_pair(nexty, nextx));

                location[nexty][nextx] = location[y][x] + 1;
                if(answer < location[nexty][nextx]){
                    answer = location[nexty][nextx];
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i= 0; i<n; i++){
        for(int j= 0; j<m; j++){
            cin >> treasure[i][j];
        }
    }

    for(int i= 0; i<n; i++){
        for(int j=0; j<m; j++){
            if(treasure[i][j] == 'L'){
                check[i][j] = false;
                bfs(i,j);
                memset(check, true, sizeof(check));
                memset(location, 0, sizeof(location));
            }
            
        }
    }

    cout << answer << endl;
}