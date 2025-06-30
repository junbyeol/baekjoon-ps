#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int num[1000];
    int increase_dp[1000];
    int decrease_dp[1000];

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    increase_dp[0] = 1;
    for (int i = 1; i < N; i++)
    {
        int max_val = INT_MIN;

        for (int j = 0; j < i; j++)
        {
            if (num[j] < num[i])
                max_val = max(max_val, increase_dp[j] + 1);
        }
        increase_dp[i] = max(max_val, 1);
    }

    decrease_dp[N - 1] = 1;
    for (int i = N - 2; i >= 0; i--)
    {
        int max_val = INT_MIN;
        for (int j = i + 1; j < N; j++)
        {
            if (num[j] < num[i])
                max_val = max(max_val, decrease_dp[j] + 1);
        }
        decrease_dp[i] = max(max_val, 1);
    }

    int max_val = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        max_val = max(max_val, increase_dp[i] + decrease_dp[i] - 1);
    }
    cout << max_val << "\n";
    return 0;
}
