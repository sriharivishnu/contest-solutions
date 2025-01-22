/*
    Solution by: Srihari Vishnu
    Created: January 21 2025

    2022JANp3
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

// a,b,c

// a < b,
// if b < c, b -= b - a, c -= b - a
// if b > c, b -= b - a, c -= b - a
ll solve() {
    int n;
    cin >> n;

    vector<ll> h(n);
    FOR(i, 0, n) cin >> h[i];

    ll mi = h[0], ans = 0;

    FOR(i, 0, n - 2) {
        if (h[i] <= h[i + 1]) {
            ans += h[i + 1] - h[i];
            h[i + 2] -= h[i + 1] - h[i];
            h[i + 1] = h[i];
        }

        mi = min({mi, h[i + 1], h[i + 2]});
    }
    if (mi < 0) return -1;

    for (int i = 0; i < n; ++i) {
        if (h[i] != mi) {
            if (i == n - 1 || h[i + 1] != h[i]) return -1;
            ans += h[i] - mi;
            ++i;
        }
    }

    return ans * 2;
}

int main() {
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << solve() << endl;
    }
}