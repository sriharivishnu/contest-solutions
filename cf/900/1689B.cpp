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

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int arr[1001], ans[1001];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        ans[i] = i + 1;
    }
    if (n == 1) {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (ans[i] == arr[i]) swap(ans[i], ans[i + 1]);
    }
    if (ans[n - 1] == arr[n - 1]) swap(ans[n - 1], ans[n - 2]);
    for (int i = 0; i < n; ++i) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}