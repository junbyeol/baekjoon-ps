#include <iostream>
#include <queue>
#include <climits>
using namespace std;

#define MAX 100000

int N, K;
int dist[100001];
bool visited[100001];

queue<int> q;

int main()
{
    cin >> N >> K;

    for (int i = 0; i <= MAX; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[N] = 0;
    q.push(N);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (visited[now])
        {
            continue;
        }

        if (now == K)
        {
            break;
        }

        visited[now] = true;

        int togo_1 = now * 2;
        if (togo_1 <= MAX && dist[togo_1] >= dist[now] + 1)
        {
            dist[togo_1] = dist[now] + 1;
            q.push(togo_1);
        }

        int togo_2 = now + 1;
        if (togo_2 <= MAX && dist[togo_2] >= dist[now] + 1)
        {
            dist[togo_2] = dist[now] + 1;
            q.push(togo_2);
        }

        int togo_3 = now - 1;
        if (togo_3 >= 0 && dist[togo_3] >= dist[now] + 1)
        {
            dist[togo_3] = dist[now] + 1;
            q.push(togo_3);
        }
    }

    cout << dist[K] << "\n";

    int tmp[100001];

    int now = K;
    for (int i = dist[K]; i >= 0; i--)
    {
        tmp[i] = now;
        if (i == 0)
        {
            continue;
        }
        if (now > 0 && dist[now - 1] == i - 1)
        {
            now = now - 1;
            continue;
        }
        if (now < MAX && dist[now + 1] == i - 1)
        {
            now = now + 1;
            continue;
        }
        if (now % 2 == 0 && dist[now / 2] == i - 1)
        {
            now = now / 2;
            continue;
        }
    }

    for (int i = 0; i <= dist[K]; i++)
    {
        cout << tmp[i] << " ";
    }
    cout << "\n";

    return 0;
}