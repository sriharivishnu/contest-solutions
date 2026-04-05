#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#endif

#define FOR(i, L, R) for (int i = L; i < R; ++i)

typedef long long ll;

const int MAXN = 2e5 + 5;

template <typename cmp> struct Lazy {
  void push(int p) {
    if (!p)
      return;
    if (!ma) {
      ma = p;
    } else if (c(ma, p)) {
      pq.push(ma);
      ma = p;
    } else {
      pq.push(p);
    }
  }
  void remove(int p) {
    if (!p)
      return;
    if (p == ma) {
      if (pq.empty())
        ma = 0;
      else {
        ma = pq.top();
        pq.pop();
      }
    } else {
      deleted.push(p);
    }
    update();
  }
  int top() { return ma; }
  int snd_top() {
    if (pq.empty())
      return 0;
    return pq.top();
  }

private:
  int ma = 0;
  priority_queue<int, vector<int>, cmp> pq, deleted;
  cmp c;
  void update() {
    if (!deleted.empty() && ma == deleted.top()) {
      deleted.pop();
      ma = 0;
    }

    while (!pq.empty() && !deleted.empty() && pq.top() == deleted.top()) {
      pq.pop();
      deleted.pop();
    }
    if (!ma && !pq.empty()) {
      ma = pq.top();
      pq.pop();
    }
  }
};

int cols[MAXN], prefs[MAXN];
Lazy<greater<int>> firsts;
Lazy<less<int>> secs;
Lazy<less<int>> per_col[MAXN];

ll s = 0;

void sync(Lazy<less<int>> &col, int initial_top, int initial_snd) {
  if (col.top() != initial_top) {
    firsts.remove(initial_top);
    firsts.push(col.top());
    s = s - initial_top + col.top();
  }

  if (col.snd_top() != initial_snd) {
    secs.remove(initial_snd);
    secs.push(col.snd_top());
  }
}

int read_int() {
  int ch, res = 0;
  while ((ch = getchar_unlocked()) != -1 && '0' <= ch && ch <= '9') {
    res = res * 10 + (ch - '0');
  }
  return res;
}

void write_long(long x) {
  // pre x != 0
  char buf[20];
  buf[19] = 0;
  buf[18] = '\n';
  int i = 17;
  while (x) {
    buf[i--] = '0' + (x % 10);
    x /= 10;
  }
  puts(buf + (i + 1));
}

int main() {
  int n = read_int(), m = read_int(), q = read_int();

  FOR(i, 1, n + 1) {
    cols[i] = read_int();
    prefs[i] = read_int();
    per_col[cols[i]].push(prefs[i]);
  }

  FOR(i, 1, m + 1) {
    firsts.push(per_col[i].top());
    s += per_col[i].top();
    secs.push(per_col[i].snd_top());
  }

  write_long(max(s, s - firsts.top() + secs.top()));

  FOR(_, 0, q) {
    int x = read_int(), i = read_int(), l = read_int();
    if (x == 1) {
      auto &col = per_col[cols[i]];
      int og1 = col.top(), og2 = col.snd_top();
      col.remove(prefs[i]);
      sync(col, og1, og2);

      auto &col2 = per_col[l];
      og1 = col2.top(), og2 = col2.snd_top();
      col2.push(prefs[i]);
      sync(col2, og1, og2);
      cols[i] = l;
    } else {
      auto &col = per_col[cols[i]];
      int og1 = col.top(), og2 = col.snd_top();
      col.remove(prefs[i]);
      col.push(l);
      sync(col, og1, og2);
      prefs[i] = l;
    }

    write_long(max(s, s - firsts.top() + secs.top()));
  }
}
