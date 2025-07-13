#include <iostream>
using namespace std;

typedef pair<int, int> crd;
typedef pair<crd, crd> line;
typedef crd vect;

bool is_crossing(line f1, line f2);

int main()
{
    int x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    cout << (is_crossing({{x1, y1}, {x2, y2}}, {{x3, y3}, {x4, y4}}) ? 1 : 0) << "\n";
    // TODO: 문제 풀이 코드 작성
    return 0;
}

int ccw(vect v1, vect v2)
{
    long long val = (long long)v1.first * (long long)v2.second - (long long)v1.second * (long long)v2.first;
    if (val == 0)
        return 0;
    return val > 0 ? 1 : -1;
}

vect to_vect(crd a, crd b)
{
    return {b.first - a.first, b.second - a.second};
}

bool is_crossing(line f1, line f2)
{
    int ccw1 = ccw(to_vect(f1.first, f1.second), to_vect(f1.first, f2.first));
    int ccw2 = ccw(to_vect(f1.first, f1.second), to_vect(f1.first, f2.second));
    int ccw3 = ccw(to_vect(f2.first, f2.second), to_vect(f2.first, f1.first));
    int ccw4 = ccw(to_vect(f2.first, f2.second), to_vect(f2.first, f1.second));

    int for_f1 = ccw1 * ccw2;
    int for_f2 = ccw3 * ccw4;

    if (for_f1 == 0 && for_f2 == 0)
    {
        crd p1 = f1.first < f1.second ? f1.first : f1.second;
        crd p2 = f1.first < f1.second ? f1.second : f1.first;
        crd p3 = f2.first < f2.second ? f2.first : f2.second;
        crd p4 = f2.first < f2.second ? f2.second : f2.first;

        return p4 >= p1 && p2 >= p3;
    }

    return for_f1 <= 0 && for_f2 <= 0;
}