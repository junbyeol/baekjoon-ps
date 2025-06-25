#include <iostream>
using namespace std;

void print_stars(int N);
bool should_print_star(int row, int col, int mod);

int main()
{
    int N;
    cin >> N;

    print_stars(N);

    return 0;
}

void print_stars(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << (should_print_star(i, j, N) ? "*" : " ");
        }
        for (int j = 0; j < N - i; j++)
        {
            cout << " ";
        }
        cout << " \n";
    }
}

bool should_print_star(int row, int col, int mod)
{
    // cout << row << " " << col << " " << mod << "\n";
    if (mod == 3)
    {
        if (row == 1 && col == 1)
            return false;
        return true;
    }

    int half = mod / 2;

    if ((row >= half) && (col < mod) && (2 * row - col < 2 * half))
    {
        // cout << "!!!" << row << " " << col << " " << mod << "\n";
        return false;
    }
    return should_print_star(row % half, col % half, half);
}
