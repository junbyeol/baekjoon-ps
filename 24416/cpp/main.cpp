#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int fib[40];

    fib[0] = fib[1] = 1;
    for (int i = 2; i <= N; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    cout << fib[N - 1] << " " << N - 2 << "\n";

    return 0;
}
