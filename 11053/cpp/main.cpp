#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int num[1000];
    int dp[1000] = {1};
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    for (int i = 1; i < N; i++)
    {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++)
        {
            if (num[j] < num[i])
                max_val = max(max_val, dp[j] + 1);
        }
        dp[i] = max_val > 0 ? max_val : 1;
    }

    int max_val = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        max_val = max(max_val, dp[i]);
    }
    cout << max_val << "\n";
    return 0;
}
