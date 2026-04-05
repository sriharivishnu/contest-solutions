/*
    Solution by: Srihari Vishnu
    C++
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#endif

void solve() {
  int n, c, p;

  cin >> n >> c >> p;

  if (n <= c * p) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
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
