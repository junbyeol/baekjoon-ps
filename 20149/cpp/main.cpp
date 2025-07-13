#include <iostream>
using namespace std;

typedef pair<int, int> crd;
typedef pair<crd, crd> line;
typedef crd vect;

bool is_crossing(line f1, line f2);
bool is_parallel(line f1, line f2);
pair<long double, long double> get_cross_point(line f1, line f2);

int main()
{
    int x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    line f1 = {{x1, y1}, {x2, y2}}, f2 = {{x3, y3}, {x4, y4}};

    bool is_crossed = is_crossing(f1, f2);

    cout << (is_crossed ? 1 : 0) << "\n";

    if (is_crossed)
    {
        if (is_parallel(f1, f2))
        {
            if (x1 > x2)
            {
                swap(x1, x2);
                swap(y1, y2);
            }
            if (x3 > x4)
            {
                swap(x3, x4);
                swap(y3, y4);
            }

            if (x2 == x3 && y2 == y3)
                cout << x2 << " " << y2 << "\n";
        }
        else
        {
            auto [x, y] = get_cross_point(f1, f2);
            cout << fixed;
            cout.precision(16);
            cout << x << " "
                 << y << "\n";
        }
    }
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

bool is_parallel(line f1, line f2)
{
    long long y2y1 = f1.second.second - f1.first.second;
    long long x2x1 = f1.second.first - f1.first.first;
    long long y4y3 = f2.second.second - f2.first.second;
    long long x4x3 = f2.second.first - f2.first.first;

    return y2y1 * x4x3 == y4y3 * x2x1;
}

pair<long double, long double> get_cross_point(line f1, line f2)
{
    long long y2y1 = f1.second.second - f1.first.second;
    long long x2x1 = f1.second.first - f1.first.first;
    long long y4y3 = f2.second.second - f2.first.second;
    long long x4x3 = f2.second.first - f2.first.first;

    if (x2x1 == 0)
    {
        long double m3 = (long double)y4y3 / x4x3;
        return {(long double)f1.first.first, m3 * (f1.first.first - f2.first.first) + f2.first.second};
    }
    if (x4x3 == 0)
    {
        long double m1 = (long double)y2y1 / x2x1;
        return {(long double)f2.first.first, m1 * (f2.first.second - f1.first.first) + f2.first.first};
    }

    long double m1 = (long double)y2y1 / x2x1;
    long double m3 = (long double)y4y3 / x4x3;

    long double x = (m1 * f1.first.first - m3 * f2.first.first + f2.first.second - f1.first.second) / (m1 - m3);
    long double y = (m1 * m3 * (f2.first.first - f1.first.first) - m1 * f2.first.second + m3 * f1.first.second) / (m3 - m1);

    return {x, y};
}