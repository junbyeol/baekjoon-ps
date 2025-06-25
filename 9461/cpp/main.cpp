#include <iostream>
using namespace std;

int main()
{
    int N;
    long long wave[101];

    cin >> N;

    wave[0] = wave[1] = wave[2] = 1;
    wave[3] = wave[4] = 2;
    for (int i = 5; i < 101; i++)
    {
        wave[i] = wave[i - 1] + wave[i - 5];
    }

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        cout << wave[x - 1] << "\n";
    }

    return 0;
}
