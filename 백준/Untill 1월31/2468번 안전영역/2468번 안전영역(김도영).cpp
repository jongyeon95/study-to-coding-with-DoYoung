#include <iostream>
#include <string.h>
using namespace std;
int n;
int location[100][100];
bool check[100][100];
pair<int, int> moveDir[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void dfs(int y, int x, int height){
    for(int i=0; i<4; i++){
        int nexty = y+moveDir[i].first;
        int nextx = x+moveDir[i].second;

        if(nexty < 0 || n <= nexty || nextx < 0 || n <= nextx)
            continue;

        if(location[nexty][nextx] <= height || !check[nexty][nextx])
            continue;

        check[nexty][nextx] = false;
        dfs(nexty, nextx, height);
    }
}


int main(){
    cin >> n;
    int Max = 0;
    int Min = 100;
    for(int i= 0; i< n; i++){
        for(int j= 0; j<n; j++){
            cin >> location[i][j];
            Max = max(location[i][j], Max);
            Min = min(location[i][j], Min);
        }
    }

    int answer = 1;
    for(int i = Min; i<= Max; i++){
       memset(check, true, sizeof(check));
       int cnt = 0;
       for(int j= 0; j<n; j++){
           for(int k=0; k<n; k++){
               if(location[j][k] > i && check[j][k]){
                   check[j][k] = false;
                   cnt++;
                   dfs(j,k,i);
               }
           }
       }
        answer = max(answer, cnt);
    }

    cout << answer << endl;


}