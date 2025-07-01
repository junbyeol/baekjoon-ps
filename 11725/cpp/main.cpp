#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> graph[100001];
void dfs(int now, int before);
int parent[100001];

int main()
{
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1, 0);

    for (int i = 2; i <= N; i++)
    {
        cout << parent[i] << "\n";
    }
    return 0;
}

void dfs(int now, int before)
{
    for (int i = 0; i < graph[now].size(); i++)
    {
        int next = graph[now][i];
        if (before != next)
        {
            parent[next] = now;
            dfs(next, now);
        }
    }
}
