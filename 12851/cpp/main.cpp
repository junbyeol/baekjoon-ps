#include <iostream>
#include <queue>
#include <climits>
using namespace std;

#define MAX 100000

int N, K;
int dist[100001];
int avail_path[1000001];
bool visited[100001];

queue<int> q;

int main()
{
    cin >> N >> K;

    for (int i = 0; i <= MAX; i++)
    {
        dist[i] = INT_MAX;
        avail_path[i] = 0;
    }

    dist[N] = 0;
    avail_path[N] = 1;
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
            avail_path[togo_1] += avail_path[now];
            q.push(togo_1);
        }

        int togo_2 = now + 1;
        if (togo_2 <= MAX && dist[togo_2] >= dist[now] + 1)
        {
            dist[togo_2] = dist[now] + 1;
            avail_path[togo_2] += avail_path[now];
            q.push(togo_2);
        }

        int togo_3 = now - 1;
        if (togo_3 >= 0 && dist[togo_3] >= dist[now] + 1)
        {
            dist[togo_3] = dist[now] + 1;
            avail_path[togo_3] += avail_path[now];
            q.push(togo_3);
        }
    }

    cout << dist[K] << "\n"
         << avail_path[K] << "\n";

    return 0;
}