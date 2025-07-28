#include <iostream>
#include <vector>

#define INF 1e9
using namespace std;

int TC;
vector<bool> answers;

struct Edge
{
    int u, v, w;
};

bool bf(int V, int E, const vector<Edge> &edges);

int main()
{
    cin >> TC;

    for (int i = 0; i < TC; i++)
    {
        int N, M, W;
        vector<Edge> edges;
        cin >> N >> M >> W;

        for (int i = 0; i < M; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w}); // 양방향 도로
        }
        for (int i = 0; i < W; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, -w});
        }

        answers.push_back(bf(N, M * 2 + W, edges));
    }

    for (int i = 0; i < TC; i++)
    {
        cout << (answers[i] ? "YES" : "NO") << "\n";
    }

    return 0;
}

bool bf(int V, int E, const vector<Edge> &edges)
{
    vector<int> dist(V + 1, 0); // 모든 정점을 0으로 초기화

    for (int i = 0; i < V; i++)
    {
        for (const Edge e : edges)
        {
            if (dist[e.v] > dist[e.u] + e.w)
            {
                dist[e.v] = dist[e.u] + e.w;
                if (i == V - 1)
                    return true;
            }
        }
    }

    return false;
}
