#include <iostream>
using namespace std;

int value(int N, int r, int c);

int main()
{
    int N, r, c;
    cin >> N >> r >> c;

    cout << value(N, r, c) << "\n";

    return 0;
}

int value(int N, int r, int c)
{
    // cout << N << " " << r << " " << c << "\n";
    if (N == 1)
    {
        if (r == 0 && c == 0)
            return 0;
        if (r == 0 && c == 1)
            return 1;
        if (r == 1 && c == 0)
            return 2;
        return 3;
    }

    int half = 1 << (N - 1);
    int half_square = half * half;

    if (r < half && c < half)
        return value(N - 1, r, c);
    if (r >= half && c < half)
        return 2 * half_square + value(N - 1, r % half, c);
    if (r < half && c >= half)
        return half_square + value(N - 1, r, c % half);
    return 3 * half_square + value(N - 1, r % half, c % half);
}
