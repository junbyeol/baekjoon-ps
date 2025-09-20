#include <climits>
#include <iostream>
using namespace std;

#define MAX_LEN 1000001
long long arr[MAX_LEN];
pair<int, long long> segtree[MAX_LEN * 4];  // index, val

void build(int start, int end, int now) {
  //   cout << start << " " << end << " " << now << "\n";
  if (start == end) {
    segtree[now] = {start, arr[start]};
    return;
  }

  int mid = (start + end) / 2;
  build(start, mid, now * 2);
  build(mid + 1, end, now * 2 + 1);
  segtree[now] = segtree[now * 2].second <= segtree[now * 2 + 1].second
                     ? segtree[now * 2]
                     : segtree[now * 2 + 1];
}

void update(int start, int end, int idx, long long val, int now) {
  if (start == end) {
    arr[idx] = val;
    segtree[now] = {idx, val};
    // cout << "'" << val << "'" << "\n";
    return;
  }

  int mid = (start + end) / 2;
  if (idx <= mid)
    update(start, mid, idx, val, now * 2);
  else
    update(mid + 1, end, idx, val, now * 2 + 1);
  segtree[now] = segtree[now * 2].second <= segtree[now * 2 + 1].second
                     ? segtree[now * 2]
                     : segtree[now * 2 + 1];
}

pair<int, long long> query(int start, int end, int l, int r, int now) {
  //   cout << start << " " << end << "\n";
  if (r < start || end < l) return {-1, INT_MAX};
  if (l <= start && end <= r) return segtree[now];
  int mid = (start + end) / 2;
  pair<int, long long> left = query(start, mid, l, r, now * 2);
  pair<int, long long> right = query(mid + 1, end, l, r, now * 2 + 1);
  return left.second <= right.second ? left : right;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  build(0, N - 1, 1);
  int Q;
  cin >> Q;

  //   cout << "\n";
  //   for (int i = 0; i < 4 * N; i++) {
  //     cout << segtree[i].second << " ";
  //   }

  for (int q = 0; q < Q; q++) {
    long long a, b, c;
    cin >> a;
    if (a == 1) {
      cin >> b >> c;
      update(0, N - 1, b - 1, c, 1);
    } else /* a == 2 */ {
      cout << query(0, N - 1, 0, N - 1, 1).first + 1 << "\n";
    }
    // cout << "\n";
    // for (int i = 0; i < 4 * N; i++) {
    //   cout << segtree[i].second << " ";
    // }
  }

  return 0;
}
