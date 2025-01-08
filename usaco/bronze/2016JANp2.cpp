/*
    Solution by: Srihari Vishnu
    Created: January 06 2025

    2016JANp2
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#endif

#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

#define pb push_back
#define fi first
#define se second
#define mt make_tuple
#define FOR(i, L, R) for (int i = L; i < R; ++i)
#define RFOR(i, L, R) for (int i = L; i >= R; --i)
#define BTWN(i, l, r) ((l) <= (i) && (i) <= (r))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef tuple<int, int, int> tiii;

const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

const int MAXN = 2e5 + 5;

void solve() {
    ll n;
    cin >> n;

    vector<ll> arr(n);
    FOR(i, 0, n) cin >> arr[i];
    sort(all(arr));
    ll ans = 0;
    FOR(i, 0, n) {
        ll j = i, k = i;

        for (ll t = 1; j - 1 >= 0 && arr[j] - arr[j - 1] <= t; ++t) {
            ll jj = j;
            while (j - 1 >= 0 && arr[jj] - arr[j - 1] <= t) --j;
        }
        for (ll t = 1; k + 1 < n && arr[k + 1] - arr[k] <= t; ++t) {
            ll kk = k;
            while (k + 1 < n && arr[k + 1] - arr[kk] <= t) ++k;
        }
        ans = max(ans, k - j + 1);
    }
    cout << ans << endl;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}