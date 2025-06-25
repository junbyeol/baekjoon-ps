#include <iostream>
using namespace std;

int w[21][21][21];

int main()
{
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        if (w[a][b][c] != -1)
        {
            cout << "w(" << a << ", " << b << ", " << c << ") = " << w[a][b][c] << endl;
            continue;
        }

        if (a == -1 && b == -1 && c == -1)
            break;

        if (a <= 0 || b <= 0 || c <= 0)
        {
            cout << "w(" << a << ", " << b << ", " << c << ") = " << 1 << endl;
            continue;
        }

        if (a > 20 || b > 20 || c > 20)
        {
            cout << "w(" << a << ", " << b << ", " << c << ") = " << 1048576 << endl;
            continue;
        }

        for (int i = 0; i <= a; i++)
        {
            for (int j = 0; j <= b; j++)
            {
                for (int k = 0; k <= c; k++)
                {
                    if (i <= 0 || j <= 0 || k <= 0)
                        w[i][j][k] = 1;
                    else if (i > 20 || j > 20 || k > 20)
                        w[i][j][k] = 1048576;
                    else if (i < j && j < k)
                    {
                        w[i][j][k] = w[i][j][k - 1] + w[i][j - 1][k - 1] - w[i][j - 1][k];
                    }
                    else
                    {
                        w[i][j][k] = w[i - 1][j][k] + w[i - 1][j - 1][k] + w[i - 1][j][k - 1] - w[i - 1][j - 1][k - 1];
                    }
                }
            }
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w[a][b][c] << endl;
    }

    return 0;
}
