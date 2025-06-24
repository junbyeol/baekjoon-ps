#include <iostream>
using namespace std;

void dfs(int M, int N, int depth, int path[]);

int main()
{
    int M, N;

    cin >> M >> N;

    dfs(M, N, 0, {});

    return 0;
}

void dfs(int M, int N, int depth, int path[])
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

    for (int togo = 1; togo <= M; togo++)
    {
        int tmp[8] = {0};
        for (int t = 0; t < depth; t++)
        {
            tmp[t] = path[t];
        }
        tmp[depth] = togo;
        dfs(M, N, depth + 1, tmp);
    }
}
