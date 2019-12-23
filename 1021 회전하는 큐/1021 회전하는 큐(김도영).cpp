#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int cnt = 0;
    int n, k;
    cin >> n >> k;

    deque<int> q;
    for (int i = 1; i <= n; i++)
        q.push_back(i);

    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;

        int location;
        for (int i = 0; i < n; i++)
        {
            if (q[i] == temp)
            {
                location = i;
                break;
            }
        }

        if (q.size() / 2 >= location)
        {
            for (int i = 0; i < location; i++)
            {
                q.push_back(q.front());
                q.pop_front();
                cnt++;
            }
            q.pop_front();
        }
        else
        {
            for (int i = q.size(); i > location; i--)
            {
                q.push_front(q.back());
                q.pop_back();
                cnt++;
            }
            q.pop_front();
        }
    }

    if (cnt)
        cout << cnt << endl;

    else
        cout << 0;
}