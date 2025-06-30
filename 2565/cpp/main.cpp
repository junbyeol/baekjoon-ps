#include <iostream>
#include <queue>
#include <climits>
#define PII pair<int, int>
using namespace std;

class Compare
{
public:
    bool operator()(PII a, PII b)
    {
        return a.first > b.first;
    }
};

int main()
{
    int N;
    priority_queue<PII, vector<PII>, Compare> pq;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        pq.push({a, b});
    }

    int num[100];
    int dp[100];
    for (int i = 0; i < N; i++)
    {
        num[i] = pq.top().second;
        pq.pop();
    }

    dp[0] = 1;
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
    cout << N - max_val << "\n";

    return 0;
}
