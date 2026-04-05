#include <bits/stdc++.h>
#include <climits>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#endif

#define FOR(i, L, R) for (int i = L; i < R; ++i)

const int MAXN = 20001;

int row[MAXN] = {0};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int r, c, m;
  cin >> r >> c >> m;

  row[c] = INT_MAX;

  int cur = 1;
  FOR(i, 0, r) {
    int last = INT_MAX;
    FOR(j, 0, c) {
      int tmp = row[j];
      row[j] = cur + min(row[j + 1], min(tmp, last));
      last = tmp;
      if (++cur == m + 1)
        cur = 1;
    }
  }
  cout << *min_element(row, row + c) << endl;
}
