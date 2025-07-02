#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;

    int start;
    cin >> start;

    vector<pair<int, int>> graph[20001];
    bool visited[20001];
    int dist[20001];

    for (int i = 1; i <= V; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
    }

    for (int i = 0; i < E; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        auto [dist_now, now] = pq.top();
        pq.pop();

        if (visited[now])
        {
            continue;
        }

        visited[now] = true;

        for (int i = 0; i < graph[now].size(); i++)
        {
            auto [v, w] = graph[now][i];
            if (!visited[v] && dist[v] > dist_now + w)
            {
                dist[v] = dist_now + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}
