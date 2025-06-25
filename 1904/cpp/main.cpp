#include <iostream>
using namespace std;

int main()
{
    int N;
    int fib[1000000];

    cin >> N;
    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i < N; i++)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 15746;
    }
    cout << fib[N - 1] << "\n";

    return 0;
}
