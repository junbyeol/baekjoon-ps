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

    return 0;
}