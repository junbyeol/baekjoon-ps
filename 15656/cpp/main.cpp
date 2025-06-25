#include <iostream>
#include <algorithm>
using namespace std;

void dfs(int M, int N, int depth, int path[]);
int num[8];

int main()
{
    int M, N;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    sort(num, num + N);

    dfs(M, N, 0, {});

    return 0;
}

void dfs(int M, int N, int depth, int path[])
{
    if (depth == M)
    {
        for (int i = 0; i < depth; i++)
        {
            cout << num[path[i]] << " ";
        }
        cout << "\n";
        return;
    }

    for (int togo = 0; togo < N; togo++)
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
