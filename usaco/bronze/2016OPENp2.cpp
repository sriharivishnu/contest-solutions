/*
    Solution by: Srihari Vishnu
    Created: January 04 2025

    2016OPENp2
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
    int n, k;
    cin >> n >> k;

    vector<string> target(n);
    FOR(i, 0, n) cin >> target[i];

    vector<vector<string>> pieces(k, vector<string>(n));

    FOR(i, 0, k) {
        FOR(j, 0, n) { cin >> pieces[i][j]; }
    }

    auto shift = [&](const vector<string>& og, vector<string>& p, int dx,
                     int dy) {
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                if (og[i][j] == '#') {
                    if (i + dx < 0 || i + dx >= n || j + dy < 0 || j + dy >= n)
                        return false;
                    p[i + dx][j + dy] = og[i][j];
                }
            }
        }
        return true;
    };

    auto tryFit = [&](int p1, int p2) {
        FOR(di1, -(n - 1), n) {
            FOR(dj1, -(n - 1), n) {
                FOR(di2, -(n - 1), n) {
                    FOR(dj2, -(n - 1), n) {
                        vector<string> piece1(n, string(n, '.')),
                            piece2(n, string(n, '.'));
                        if (!shift(pieces[p1], piece1, di1, dj1) ||
                            !shift(pieces[p2], piece2, di2, dj2)) {
                            continue;
                        }

                        bool ok = 1;
                        for (int i = 0; i < n && ok; ++i) {
                            for (int j = 0; j < n && ok; ++j) {
                                if (piece1[i][j] == '#' &&
                                    piece2[i][j] == '#') {
                                    ok = 0;
                                } else if ((target[i][j] == '.' &&
                                            (piece1[i][j] == '#' ||
                                             piece2[i][j] == '#')) ||
                                           (target[i][j] == '#' &&
                                            (piece1[i][j] == '.' &&
                                             piece2[i][j] == '.'))) {
                                    ok = 0;
                                }
                            }
                        }
                        if (ok) return true;
                    }
                }
            }
        }
        return false;
    };
    auto tryAll = [&]() -> pii {
        FOR(i, 0, k) {
            FOR(j, i + 1, k) {
                if (tryFit(i, j)) {
                    return {i + 1, j + 1};
                }
            }
        }
        return {-1, -1};
    };
    auto res = tryAll();
    cout << res.first << ' ' << res.second << endl;
}

int main() {
    freopen("bcs.in", "r", stdin);
    freopen("bcs.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}