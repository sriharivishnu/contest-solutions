#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#endif

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e6 + 3;
const ll MAXN = 1048576;

struct Node {
  ll sum, end;
};

Node tree[MAXN * 2] = {};
int starts[MAXN], durs[MAXN];

void update(ll i, ll delta) {
  i += MAXN;

  tree[i].sum += delta;
  tree[i].end = tree[i].sum ? (i - MAXN) + tree[i].sum - 1 : 0;

  while (i > 1) {
    i >>= 1;
    ll l = i * 2, r = i * 2 + 1;
    tree[i].sum = tree[l].sum + tree[r].sum;
    tree[i].end = max(tree[r].end, tree[l].end + tree[r].sum);
  }
}

int read_int() {
  int ch, res = 0;
  while ((ch = getchar_unlocked()) != -1 && '0' <= ch && ch <= '9') {
    res = res * 10 + (ch - '0');
  }
  return res;
}

char buf[20];
void write_long(long long x) {
  // pre x != 0
  buf[19] = 0;
  buf[18] = 0;
  int i = 17;
  while (x) {
    buf[i--] = '0' + (x % 10);
    x /= 10;
  }
  puts(buf + (i + 1));
}

int main() {
  ll q = read_int(), cur = 1;

  while (q--) {
    char ch = getchar_unlocked();
    getchar_unlocked();
    ll ans = tree[1].end;
    if (ch == 'A') {
      int s = read_int();
      int t = read_int();
      s = (s + ans) % MOD;
      t = (t + ans) % MOD;
      update(s, t);
      starts[cur] = s, durs[cur] = t;
      ++cur;
    } else {
      ll i = read_int();
      i = (i + ans) % MOD;
      update(starts[i], -durs[i]);
    }
    write_long(tree[1].end);
  }
}
