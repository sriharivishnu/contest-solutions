#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#endif

#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int col[MAX_N], dp[MAX_N] = {0}, ans[MAX_N] = {0};
int n;
vector<vector<int>> adj;

void dfs(int node, int par = -1) {
    dp[node] = (col[node] ? 1 : -1);
    for (auto ne : adj[node]) {
        if (ne != par) {
            dfs(ne, node);
            dp[node] += max(0, dp[ne]);
        }
    }
}

void dfs2(int node, int par = -1) {
    ans[node] = dp[node];
    for (auto ne : adj[node]) {
        if (ne != par) {
            dp[node] -= max(0, dp[ne]);
            dp[ne] += max(0, dp[node]);
            dfs2(ne, node);
            dp[ne] -= max(0, dp[node]);
            dp[node] += max(0, dp[ne]);
        }
    }
}

void solve() {
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n; ++i) cin >> col[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    dfs(0);
    dfs2(0);

    for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}