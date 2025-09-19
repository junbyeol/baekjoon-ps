#include <iostream>
#include <climits>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    int num[100000];
    int sum[100000];

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
        sum[i] = (i != 0 ? sum[i - 1] : 0) + num[i] - (i >= K ? num[i - K] : 0);
    }

    int max_val = INT_MIN;
    for (int i = K - 1; i < N; i++)
    {
        max_val = max(sum[i], max_val);
    }

    cout << max_val << "\n";

    return 0;
}
