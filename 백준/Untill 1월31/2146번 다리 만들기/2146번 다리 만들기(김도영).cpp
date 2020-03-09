#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n;
int map[100][100];
bool check[100][100];
pair<int, int> movedir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int y, int x, int land)
{
    check[y][x] = false;
    map[y][x] = land;

    for (int i = 0; i < 4; i++)
    {
        int nexty = y + movedir[i].first;
        int nextx = x + movedir[i].second;

        if (nexty < 0 || n <= nexty || nextx < 0 || n <= nextx)
            continue;

        if (check[nexty][nextx] && map[nexty][nextx])
        {
            dfs(nexty, nextx, land);
        }
    }
}

int bfs(int land)
{
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == land)
            {
                q.push(make_pair(i, j));
            }
        }
    }
    int result = 0;
    while (!q.empty())
    {
        int current = q.size();
        for (int cur = 0; cur < current; cur++)
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nexty = y + movedir[i].first;
                int nextx = x + movedir[i].second;

                if (nexty < 0 || n <= nexty || nextx < 0 || n <= nextx)
                    continue;

                if (map[nexty][nextx] && map[nexty][nextx] != land){
                    return result;
                }

                if (check[nexty][nextx] && !map[nexty][nextx])
                {
                    check[nexty][nextx] = false;
                    q.push(make_pair(nexty, nextx));
                }

            }
        }
        result++;
    }
}

int main()
{
    cin >> n;
    memset(map, -1, sizeof(map));
    memset(check, true, sizeof(check));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    int land = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] && check[i][j])
            {
                dfs(i, j, land);
                land++;
            }
        }
    }

    int answer = 999;
    for (int i = 1; i < land; i++)
    {
        memset(check, true, sizeof(check));
        answer = min(answer, bfs(i));
    }

    cout << answer << endl;
}