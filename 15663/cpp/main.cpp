#include <iostream>
#include <algorithm>
using namespace std;

void dfs(int M, int nums, int depth, int path[], int remain_visits[8]);
int numt[8];
int num[8];
int avail_visits[8] = {0};

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
    avail_visits[0]++;
    uniq_nums++;

    for (int i = 1; i < N; i++)
    {
        if (numt[i] == num[uniq_nums - 1])
        {
            avail_visits[uniq_nums - 1]++;
        }
        else
        {
            num[uniq_nums] = numt[i];
            avail_visits[uniq_nums++]++;
        }
    }

    dfs(M, uniq_nums, 0, {}, avail_visits);

    return 0;
}

void dfs(int M, int nums, int depth, int path[], int remain_visits[8])
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

    for (int togo = 0; togo < nums; togo++)
    {
        if (remain_visits[togo] > 0)
        {
            int tmp[8] = {0};
            int visitt[8] = {0};
            for (int t = 0; t < depth; t++)
            {
                tmp[t] = path[t];
            }
            for (int t = 0; t < nums; t++)
            {
                visitt[t] = remain_visits[t];
            }
            tmp[depth] = togo;
            visitt[togo]--;
            dfs(M, nums, depth + 1, tmp, visitt);
        }
    }
}
