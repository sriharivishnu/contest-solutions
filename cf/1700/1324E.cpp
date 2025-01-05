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

const int NH = 2001;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

// dp(i, j) = max(
// (l <= j + ai <= r) + dp(i + 1, (j + ai) % h),
// (l <= j + ai - 1 <= r) + dp(i + 1, (j + ai - 1) % h)
// Which ai to pick next, with current time being j

int dp[NH][NH] = {0};
int a[NH];
void solve() {
    int n, h, l, r;
    cin >> n >> h >> l >> r;

    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = n - 1; i >= 0; --i) {
        for (int j = h - 1; j >= 0; --j) {
            dp[i][j] =
                max((l <= (a[i] + j) % h && (a[i] + j) % h <= r) +
                        dp[i + 1][(a[i] + j) % h],
                    (l <= (a[i] - 1 + j) % h && (a[i] - 1 + j) % h <= r) +
                        dp[i + 1][(a[i] - 1 + j) % h]);
        }
    }

    cout << dp[0][0] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}