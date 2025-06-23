#include <iostream>
using namespace std;

struct FIB
{
    int zero = -1;
    int one = -1;
};

FIB mem[100] = {{1, 0}, {0, 1}};

FIB run(int N)
{
    if (mem[N].zero != -1)
    {
        return mem[N];
    }
    mem[N] = {run(N - 1).zero + run(N - 2).zero,
              run(N - 1).one + run(N - 2).one};
    return mem[N];
}

int main()
{
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int N;
        cin >> N;

        FIB result = run(N);

        cout << result.zero << " " << result.one << endl;
    }

    return 0;
}
