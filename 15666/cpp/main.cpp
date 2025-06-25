#include <iostream>
#include <algorithm>
using namespace std;

void dfs(int M, int nums, int depth, int path[]);
int numt[8];
int num[8];

int main()
{
    int M, N;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> numt[i];
    }
    sort(numt, numt + N);

    int uniq_nums = 0;

    num[0] = numt[0];
    uniq_nums++;

    for (int i = 1; i < N; i++)
    {
        if (numt[i] != num[uniq_nums - 1])
        {
            num[uniq_nums++] = numt[i];
        }
    }

    dfs(M, uniq_nums, 0, {});

    return 0;
}

void dfs(int M, int nums, int depth, int path[])
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

    int from = depth == 0 ? 0 : path[depth - 1];

    for (int togo = from; togo < nums; togo++)
    {
        int tmp[8] = {0};
        for (int t = 0; t < depth; t++)
        {
            tmp[t] = path[t];
        }
        tmp[depth] = togo;
        dfs(M, nums, depth + 1, tmp);
    }
}
