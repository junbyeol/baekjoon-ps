#include <iostream>
#include <queue>
#include <climits>
using namespace std;

#define MAX 100000

int N, K;
bool sptSet[100001];
int dist[100001];

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main()
{
    cin >> N >> K;

    for (int i = 0; i <= MAX; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[N] = 0;
    pq.push({0, N});

    while (!pq.empty())
    {
        auto [dist_now, now] = pq.top();
        pq.pop();

        if (sptSet[now])
            continue;

        if (now == K)
            break;

        sptSet[now] = true;

        if (now * 2 <= MAX && !sptSet[now * 2] && dist[now * 2] > dist_now)
        {
            dist[now * 2] = dist_now;
            pq.push({dist_now, now * 2});
        }
        if (now + 1 <= MAX && !sptSet[now + 1] && dist[now + 1] > dist_now + 1)
        {
            dist[now + 1] = dist_now + 1;
            pq.push({dist_now + 1, now + 1});
        }
        if (now - 1 >= 0 && !sptSet[now - 1] && dist[now - 1] > dist_now + 1)
        {
            dist[now - 1] = dist_now + 1;
            pq.push({dist_now + 1, now - 1});
        }
    }

    cout << dist[K] << "\n";

    return 0;
}
