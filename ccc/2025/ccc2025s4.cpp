#include <bits/stdc++.h>
#include <queue>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#endif

#define pb push_back
#define FOR(i, L, R) for (int i = L; i < R; ++i)

typedef long long ll;
typedef pair<int, int> pii;

const ll INF = numeric_limits<ll>::max();

const int MAXN = 2e5 + 2;

struct Edge {
  int a, b, c;

  bool operator<(const Edge &other) const { return c < other.c; }
};

struct Node {
  int edge_id;
  ll best;
  Node(int e, ll b) : edge_id{e}, best{b} {}
  bool operator<(const Node &other) const { return best > other.best; }
};

ll best[MAXN];

Edge edges[MAXN];

vector<pii> adj[MAXN];
vector<int> adj2[MAXN];

int read_int() {
  int ch, res = 0;
  while ((ch = getchar_unlocked()) != -1 && '0' <= ch && ch <= '9') {
    res = res * 10 + (ch - '0');
  }
  return res;
}

ll solve() {
  int n = read_int(), m = read_int();

  edges[0] = {0, 1, 0};
  adj[0].emplace_back(0, 0);
  adj[1].emplace_back(0, 0);

  FOR(i, 1, m + 1) {
    int a = read_int(), b = read_int(), c = read_int();
    adj[a].emplace_back(c, i);
    adj[b].emplace_back(c, i);
    best[i] = INF;
    edges[i] = {a, b, c};
  }

  FOR(i, 1, n + 1) {
    sort(adj[i].begin(), adj[i].end());
    FOR(j, 0, ((int)adj[i].size()) - 1) {
      adj2[adj[i][j].second].emplace_back(adj[i][j + 1].second);
      adj2[adj[i][j + 1].second].emplace_back(adj[i][j].second);
    }
  }
  best[0] = 0;

  priority_queue<Node, vector<Node>> pq;
  pq.emplace(0, 0);

  while (!pq.empty()) {
    Node node = pq.top();
    pq.pop();
    if (best[node.edge_id] != node.best) {
      continue;
    }
    if (edges[node.edge_id].a == n || edges[node.edge_id].b == n) {
      return node.best;
    }

    for (const auto &e : adj2[node.edge_id]) {
      ll new_best = abs((ll)edges[node.edge_id].c - edges[e].c) + (ll)node.best;
      if (new_best < best[e]) {
        best[e] = new_best;
        pq.emplace(e, new_best);
      }
    }
  }
  return -1;
}

int main() {
  // freopen("", "r", stdin);
  // freopen("", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cout << solve() << endl;
}
