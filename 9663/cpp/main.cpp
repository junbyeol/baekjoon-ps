#include <iostream>
using namespace std;

struct QUEEN
{
    int row;
    int col;
};

void queen(int N, int count, QUEEN placed[]);

int answer = 0;

int main()
{
    int N;

    cin >> N;

    QUEEN placed[16] = {{-1, -1}};
    queen(N, 0, placed);

    cout << answer << "\n";

    return 0;
}

void queen(int N, int count, QUEEN placed[])
{
    if (N == count)
    {
        answer += 1;
        return;
    }

    int row = count;
    for (int col = 0; col < N; col++)
    {
        bool is_placable = true;
        for (int q = 0; q < count; q++)
        {
            if ((placed[q].col == col) || (placed[q].row + placed[q].col == row + col) || (placed[q].row - placed[q].col == row - col))
            {
                is_placable = false;
                break;
            }
        }

        if (is_placable)
        {
            QUEEN tmp[15];
            for (int t = 0; t < count; t++)
            {
                tmp[t] = placed[t];
            }
            tmp[count] = {row, col};
            queen(N, count + 1, tmp);
        }
    }
}