/*
    Solution by: Srihari Vishnu
    Created: January 03 2025

    2019DECp1
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
    int k, n;
    cin >> k >> n;

    vector<vi> arr(k, vi(n));

    FOR(i, 0, k) { FOR(j, 0, n) cin >> arr[i][j]; }

    int ans = 0;
    FOR(i, 1, n + 1) {
        FOR(j, i + 1, n + 1) {
            int x = find(all(arr[0]), i) - arr[0].begin(),
                y = find(all(arr[0]), j) - arr[0].begin();

            bool ok = 1;
            FOR(a, 1, k) {
                int x1 = find(all(arr[a]), i) - arr[a].begin(),
                    y1 = find(all(arr[a]), j) - arr[a].begin();
                if ((x < y && x1 > y1) || (x > y && x1 < y1)) {
                    ok = 0;
                    break;
                }
            }
            ans += ok;
        }
    }
    cout << ans << endl;
}

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}