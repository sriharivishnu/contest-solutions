#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<std::pair<int, int>> vii;
typedef vector<vector<int>> vvi;

int par[2001], vis[2001];

int dfs(int node) {
    if (vis[node] == -1) vis[node] = 1 + dfs(par[node]);
    return vis[node];
}
// IMPLEMENTATION
void solve() {
    int n, ans = 1;
    cin >> n;
    memset(vis, -1, sizeof(int) * (n + 1));
    for (int i = 1; i <= n; ++i) {
        cin >> par[i];
        if (par[i] == -1) vis[i] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;
}

int main() { solve(); }
