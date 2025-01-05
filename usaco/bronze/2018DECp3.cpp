/*
    Solution by: Srihari Vishnu
    Created: January 04 2025

    2018DECp3
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
    vector<int> a(101, 0), b(101, 0);
    FOR(i, 0, 10) {
        int x;
        cin >> x;
        ++a[x];
    }
    FOR(i, 0, 10) {
        int x;
        cin >> x;
        ++b[x];
    };

    set<int> readings;

    auto recur = [&](int day, int am, int bm, auto&& self) {
        if (day == 4) {
            readings.insert({am});
            return;
        }

        if (day & 1) {
            for (int i = 1; i < 101; ++i) {
                if (a[i]) {
                    a[i]--;
                    b[i]++;
                    self(day + 1, am - i, bm + i, self);
                    a[i]++;
                    b[i]--;
                }
            }
        } else {
            for (int i = 1; i < 101; ++i) {
                if (b[i]) {
                    b[i]--;
                    a[i]++;
                    self(day + 1, am + i, bm - i, self);
                    b[i]++;
                    a[i]--;
                }
            }
        }
    };

    recur(0, 1000, 1000, recur);
    cout << sz(readings) << endl;
}

int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}