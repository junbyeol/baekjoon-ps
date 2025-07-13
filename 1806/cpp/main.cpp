#include <iostream>
#include <climits>
using namespace std;

int N, S;
int num[100000];
int min_length = INT_MAX;

int main()
{
    cin >> N >> S;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    int sum = 0, start = 0, end;
    for (int i = 0; i < N; i++)
    {
        sum += num[i];
        end = i;
        if (sum >= S)
        {
            while (sum - num[start] >= S && start < end)
            {
                sum -= num[start];
                start++;
            }
            min_length = min(min_length, end - start + 1);
        }
    }

    cout << (min_length == INT_MAX ? 0 : min_length) << "\n";

    return 0;
}
