#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int min;
struct crd
{
    int x, y, z;
};
crd planets[100000];
bool visited[100000];

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> pq; // {distance, index}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        planets[i] = {x, y, z};
        visited[i] = false;
    }

    pq.push({0, 0});

    while (!pq.empty())
    {
        auto [w, now] = pq.top();
        pq.pop();

        if (visited[now])
        {
            continue;
        }
        visited[now] = true;
        min += w;

        for ()
    }

    return 0;
}
