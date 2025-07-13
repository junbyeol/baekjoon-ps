#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int V, E;

struct Edge
{
    int u, v, w;
};

int kruskal();
int prim();

int main()
{
    cin >> V >> E;

    int answer = V * V >= E ? prim() : kruskal();

    cout << answer << "\n";

    return 0;
}

int parent[10001];

bool comp(Edge a, Edge b)
{
    return a.w < b.w;
}

int get_root(int i)
{
    int root = i;
    while (parent[root] != root)
    {
        root = parent[root];
    }
    return root;
}

void make_union(int a, int b)
{
    parent[get_root(b)] = a;
}

int kruskal()
{
    int tot = 0;

    vector<Edge> edges;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    for (int i = 1; i <= V; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end(), comp);

    for (Edge e : edges)
    {
        if (get_root(e.u) != get_root(e.v))
        {
            make_union(e.u, e.v);
            tot += e.w;
        }
    }

    return tot;
}

int prim()
{
    int tot = 0;

    typedef pair<int, int> pii;
    vector<pii> adj[10001];                            // index: 정점 src, value: {정점 dst, weight}
    priority_queue<pii, vector<pii>, greater<pii>> pq; // {weight, 정점}
    int visited[10001];

    for (int i = 1; i <= V; i++)
    {
        visited[i] = -1;
    }

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [weight, u] = pq.top();
        pq.pop();

        if (visited[u] == 1)
            continue;
        visited[u] = true;
        tot += weight;

        for (auto [v, w] : adj[u])
        {
            if (visited[v] == -1)
                pq.push({w, v});
        }
    }

    return tot;
}
