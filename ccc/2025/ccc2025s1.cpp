#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#endif

void solve() {
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  cout << min(2 * max(a, x) + 2 * (b + y), 2 * (a + x) + 2 * max(b, y)) << endl;
}

int main() {
  // freopen("", "r", stdin);
  // freopen("", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  // cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
