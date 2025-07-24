#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int V;
vector<pair<int, int>> adj[100001]; // u: {v,w}

pair<int, int> find_farthest_from(int node, int prev);

int main()
{
    cin >> V;

    for (int i = 0; i < V; i++)
    {
        int node;
        cin >> node;

        int input1 = 0;
        cin >> input1;
        while (input1 != -1)
        {
            int input2;

            cin >> input2;

            adj[node].push_back({input1, input2});

            cin >> input1;
        }
    }

    auto [node_u, _] = find_farthest_from(1, 0);
    auto [node_v, dist] = find_farthest_from(node_u, 0);

    cout << dist << "\n";

    return 0;
}

pair<int, int> find_farthest_from(int node, int prev)
{
    int farthest_node;
    int max_dist = INT_MIN;

    for (pair<int, int> edge : adj[node])
    {
        auto [v, w] = edge;
        if (prev != v)
        {
            auto [far_node, dist] = find_farthest_from(v, node);
            if (max_dist < w + dist)
            {
                max_dist = w + dist;
                farthest_node = far_node;
            }
        }
    }

    if (max_dist == INT_MIN)
    {
        return {node, 0};
    }

    return {farthest_node, max_dist};
}