#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct MOVE
{
    int src;
    int dst;
};

queue<MOVE> q;

void hanoi(int N, int src, int dst, int via);
string to_string(MOVE move);

int main()
{
    int N;
    cin >> N;

    hanoi(N, 1, 3, 2);

    cout << q.size() << endl;
    while (!q.empty())
    {
        cout << to_string(q.front()) << "\n";
        q.pop();
    }

    return 0;
}

void hanoi(int N, int src, int dst, int via)
{
    if (N == 1)
    {
        q.push({src, dst});
        return;
    }

    hanoi(N - 1, src, via, dst);
    q.push({src, dst});
    hanoi(N - 1, via, dst, src);
    return;
}

string to_string(MOVE move)
{
    return std::to_string(move.src) + " " + std::to_string(move.dst);
}