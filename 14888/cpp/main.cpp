#include <iostream>
#include <climits>
using namespace std;

struct MAX_MIN
{
    int max;
    int min;
};

int N;
int num[100];
MAX_MIN get_max_min(int depth, int picked_ops[], int remain_ops[]);

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    int op_max[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> op_max[i];
    }

    auto [max_val, min_val] = get_max_min(0, {}, op_max);
    cout << max_val << "\n"
         << min_val << "\n";

    return 0;
}

MAX_MIN get_max_min(int depth, int picked_ops[], int remain_ops[])
{
    if (depth == N - 1)
    {
        int result = num[0];
        for (int i = 0; i < N - 1; i++)
        {
            if (picked_ops[i] == 0)
            {
                result += num[i + 1];
            }
            else if (picked_ops[i] == 1)
            {
                result -= num[i + 1];
            }
            else if (picked_ops[i] == 2)
            {
                result *= num[i + 1];
            }
            else
            {
                result /= num[i + 1];
            }
        }
        return {result, result};
    }

    int candd_cnt = 0;
    MAX_MIN candd[4];

    for (int op = 0; op < 4; op++)
    {
        if (remain_ops[op] > 0)
        {
            int picked_opst[100];
            for (int i = 0; i < depth; i++)
            {
                picked_opst[i] = picked_ops[i];
            }
            picked_opst[depth] = op;

            int remain_opst[100];
            for (int i = 0; i < 4; i++)
            {
                if (i != op)
                    remain_opst[i] = remain_ops[i];
                else
                    remain_opst[i] = remain_ops[i] - 1;
            }
            candd[candd_cnt++] = get_max_min(depth + 1, picked_opst, remain_opst);
        }
    }

    int max_val = INT_MIN;
    int min_val = INT_MAX;
    for (int i = 0; i < candd_cnt; i++)
    {
        max_val = max(candd[i].max, max_val);
        min_val = min(candd[i].min, min_val);
    }
    return {max_val, min_val};
}
