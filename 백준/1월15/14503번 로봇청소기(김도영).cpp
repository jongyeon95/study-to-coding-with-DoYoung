#include <iostream>
#include <queue>
using namespace std;
int robot[51][51] = {0};
pair<int, int> moveDir[4] = {{-1,0}, {0,-1}, {1,0}, {0,1} };
pair<int, int> back[4] = {{1,0}, {0,1},{-1,0}, {0,-1}};
queue<pair<int, int>> q;
int n, m;
int r, c, location;
int d;
int clean = 1;

void Bfs()
{

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int count = 0;
        int d = location;

        if(d == 3){
            d = -1;
        }
        for (int i = d+1; 0 <= i && i < 4; i++)
        {
            if (count == 4)
            {
                break;
            }
            int nextX = x + moveDir[i].first;
            int nextY = y + moveDir[i].second;

            if (nextY < m && 0 <= nextY && nextX < n && 0 <= nextX && robot[nextX][nextY] == 0)
            {
                q.push(make_pair(nextX, nextY));
                robot[nextX][nextY] = 2;
                clean++;
                location = i;
                break;
            }

            if (i == 3 && count < 3)
            {
                i = -1;
                count++;
                continue;
            }
            count++;
        }

        if (q.empty())
        {
           
            int backX = x + back[location].first;
            int backY = y + back[location].second;
            if(backY < m && 0 <= backY && backX < n && 0 <= backX){
                if(robot[backX][backY] == 2){
                    q.push(make_pair(backX, backY));
                    continue;
                }
                else if(robot[backX][backY] == 1){
                    break;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    cin >> r >> c >> location;

    if(location == 3){
        location = 1;
    }
    else if(location == 1){
        location = 3;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> robot[i][j];

    robot[r][c] = 2;
    q.push(make_pair(r, c));
    Bfs();

    cout << clean << endl;
}