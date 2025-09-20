#include <climits>
#include <iostream>
using namespace std;

#define MAX_LEN 1000001
int arr[MAX_LEN];
pair<int, int> segtree[MAX_LEN * 4];

void build(int start, int end, int now) {
  //   cout << start << " " << end << " " << now << "\n";
  if (start == end) {
    segtree[now] = {arr[start], arr[start]};
    return;
  }

  int mid = (start + end) / 2;
  build(start, mid, now * 2);
  build(mid + 1, end, now * 2 + 1);

  segtree[now] = {min(segtree[now * 2].first, segtree[now * 2 + 1].first),
                  max(segtree[now * 2].second, segtree[now * 2 + 1].second)};
}

pair<int, int> query(int start, int end, int l, int r, int now) {
  //   cout << start << " " << end << "\n";
  if (r < start || end < l) return {INT_MAX, INT_MIN};
  if (l <= start && end <= r) return segtree[now];
  int mid = (start + end) / 2;

  pair<int, int> left = query(start, mid, l, r, now * 2);
  pair<int, int> right = query(mid + 1, end, l, r, now * 2 + 1);

  return {min(left.first, right.first), max(left.second, right.second)};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, Q;
  cin >> N >> Q;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  build(0, N - 1, 1);
  //   for (int i = 0; i < 4 * N; i++) {
  //     cout << segtree[i] << " ";
  //   }
  //   cout << "\n";
  //   for (int i = 0; i < 4 * N; i++) {
  //     cout << segtree[i] << " ";
  //   }

  for (int q = 0; q < Q; q++) {
    int a, b;
    cin >> a >> b;
    pair<int, int> answer = query(0, N - 1, a - 1, b - 1, 1);
    cout << answer.first << " " << answer.second << "\n";

    // cout << "\n";
    // for (int i = 0; i < 4 * N; i++) {
    //   cout << segtree[i] << " ";
    // }
  }

  return 0;
}
