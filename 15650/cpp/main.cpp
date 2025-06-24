#include <iostream>
using namespace std;

void dfs(int M, int N, int depth, int path[], char visited);

int main()
{
    int M, N;

    cin >> M >> N;

    dfs(M, N, 0, {}, 0);

    return 0;
}

void dfs(int M, int N, int depth, int path[], char visited)
{
    if (depth == N)
    {
        int i = 0;
        while (path[i])
        {
            cout << path[i++] << " ";
        }
        cout << "\n";
        return;
    }

    int now = depth == 0 ? 0 : path[depth - 1];

    for (int togo = now + 1; togo <= M; togo++)
    {
        if (!(visited & (1 << (togo - 1))))
        {
            int tmp[8] = {0};
            for (int t = 0; t < depth; t++)
            {
                tmp[t] = path[t];
            }
            tmp[depth] = togo;
            dfs(M, N, depth + 1, tmp, visited | (1 << (togo - 1)));
        }
    }
}
