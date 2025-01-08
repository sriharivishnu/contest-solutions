/*
    Solution by: Srihari Vishnu
    Created: January 06 2025

    1808B
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
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> arr(m, vector<ll>(n));

    FOR(i, 0, n) { FOR(j, 0, m) cin >> arr[j][i]; }
    FOR(j, 0, m) sort(all(arr[j]));
    ll ans = 0;

    FOR(j, 0, m) {
        ll cur = 0;
        FOR(i, 0, n) {
            cur += arr[j][i];
            ans += (arr[j][i] * (i + 1)) - cur;
        }
    }
    cout << ans << endl;
}

int main() {
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}