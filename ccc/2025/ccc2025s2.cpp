#include "stdio.h"

#ifdef LOCAL
#include "debug.h"
#endif

#define FOR(i, L, R) for (int i = L; i < R; ++i)

typedef long long ll;

const int MAXN = 100001;

ll lengths[MAXN];
int chars[MAXN];

void solve() {
  ll idx = 0;
  int ch = getchar_unlocked();

  while (ch != '\n') {
    chars[idx] = ch;
    ll x = 0;
    while (((ch = getchar_unlocked()) != '\n') && (ch >= '0' && ch <= '9')) {
      x = x * 10 + (ch - '0');
    }

    lengths[idx] = (idx ? lengths[idx - 1] : 0) + x;
    ++idx;
  }

  ll c;
  scanf(" %lld", &c);

  c %= lengths[idx - 1];

  int lo = 0, hi = idx - 1;
  while (lo < hi) {
    int mi = lo + (hi - lo) / 2;

    if (c < lengths[mi]) {
      hi = mi;
    } else {
      lo = mi + 1;
    }
  }
  printf("%c\n", chars[lo]);
}

int main() {
  // freopen("", "r", stdin);
  // freopen("", "w", stdout);
  int tc = 1;
  // cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
