/*
    Solution by: Srihari Vishnu
    Created: January 10 2025

    2017JANp3
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
    int n;
    cin >> n;
    vector<vi> arr(n, vi(n));
    FOR(i, 0, n) FOR(j, 0, n) {
        char c;
        cin >> c;
        arr[i][j] = c - '0';
    }

    bool ok = 0;
    int ans = 0;
    while (!ok) {
        ok = 1;
        RFOR(i, n - 1, 0) {
            RFOR(j, n - 1, 0) {
                if (arr[i][j] == 1) {
                    FOR(ii, 0, i + 1) {
                        FOR(jj, 0, j + 1) { arr[ii][jj] = 1 - arr[ii][jj]; }
                    }
                    ok = 0;
                    ++ans;
                    break;
                }
            }
            if (!ok) break;
        }
    }

    cout << ans << endl;
}

int main() {
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}