#include <iostream>
#include <queue>
using namespace std;
int box[1001][1001];
queue<pair<int, int>> tomato;
pair<int, int> moveDir[4] = {{1,0}, {-1,0}, {0,1},{0,-1}};
int notomato = 0;
int n, m;

bool all(){
    for(int i= 0; i<m; i++){
        for(int j=0; j<n; j++){
            if(box[i][j] == 0){
                return false;
            }
        }
    }

    return true;
}


int bfs(){
    int day = 0;

    if(tomato.empty()){
        return -1;
    }

    while(!tomato.empty()){       
        int currentsize = tomato.size();

        for(int i= 0; i<currentsize; i++){
            pair<int, int> temp = tomato.front();
            tomato.pop();
            int y = temp.first;
            int x = temp.second;
            for (int i= 0; i<4; i++){
                int nextY = y+moveDir[i].first;
                int nextX = x+moveDir[i].second;

                if (0 <= nextY && nextY < m && 0 <= nextX && nextX < n && box[nextY][nextX] == 0){
                    box[nextY][nextX] = 1;
                    tomato.push(make_pair(nextY, nextX));
                }
            }

            if(tomato.size() == 0 && all()){
                return day;
            }
            else if(tomato.size() == 0 && !all()){
                return -1;
            }
        }
        day++;
    }
}

int main(){
    
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        for(int j =0; j<n; j++){
            cin >> box[i][j];
            if(box[i][j] == 1){
                tomato.push(make_pair(i,j));
            }
            else if(box[i][j] == -1){
                notomato++;
            }
        }
    }

    if(tomato.size() == n*m - notomato){
        //처음부터 다 익은 케이스
        cout << "0" << endl;
    }
    else{
        int result = bfs();
        cout << result << endl;
    }
    
}