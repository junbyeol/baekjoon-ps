#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    int N;
    int num[100000];
    int sum[100000];

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
            sum[i] = num[i];
        else
            sum[i] = max(num[i] + sum[i - 1], num[i]);
    }

    int max = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        if (max < sum[i])
            max = sum[i];
    }

    cout << max << "\n";

    return 0;
}
