#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

vector<pii> go_adj[1001]; // index: u, value: {v,w}
int go_dist[1001];
bool go_visited[1001];
priority_queue<pii, vector<pii>, greater<pii>> go_pq; // value { w, node }

vector<pii> come_adj[1001]; // index: u, value: {v,w}
int come_dist[1001];
bool come_visited[1001];
priority_queue<pii, vector<pii>, greater<pii>> come_pq; // value { w, node }

int main()
{
    int V, E, X;
    cin >> V >> E >> X;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        go_adj[v].push_back({u, w});
        come_adj[u].push_back({v, w});
    }

    for (int i = 1; i <= V; i++)
    {
        go_dist[i] = INT_MAX;
        come_dist[i] = INT_MAX;
    }

    go_dist[X] = 0;
    go_pq.push({0, X});

    while (!go_pq.empty())
    {
        auto [w, node] = go_pq.top();
        go_pq.pop();

        if (go_visited[node])
        {
            continue;
        }
        go_visited[node] = true;

        for (pii info : go_adj[node])
        {
            auto [v, weight] = info;
            if (go_dist[v] > w + weight)
            {
                go_dist[v] = w + weight;
                go_pq.push({go_dist[v], v});
            }
        }
    }

    come_dist[X] = 0;
    come_pq.push({0, X});

    while (!come_pq.empty())
    {
        auto [w, node] = come_pq.top();
        come_pq.pop();

        if (come_visited[node])
        {
            continue;
        }
        come_visited[node] = true;

        for (pii info : come_adj[node])
        {
            auto [v, weight] = info;
            if (come_dist[v] > w + weight)
            {
                come_dist[v] = w + weight;
                come_pq.push({come_dist[v], v});
            }
        }
    }

    int max_val = INT_MIN;
    for (int i = 1; i <= V; i++)
    {
        max_val = max(go_dist[i] + come_dist[i], max_val);
    }

    cout << max_val << "\n";

    return 0;
}
