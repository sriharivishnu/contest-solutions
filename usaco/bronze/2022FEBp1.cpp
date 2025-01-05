/*
    Solution by: Srihari Vishnu
    Created: January 03 2025

    2022FEBp1
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
    int n, s = 0;
    cin >> n;
    vector<int> a(n);

    FOR(i, 0, n) cin >> a[i], s += a[i];

    int i = 0;
    for (; i < n; ++i) {
        if (s % (n - i) != 0) continue;

        int num = 0, lo = 0, cur = 0, ok = 1, target = s / (n - i);
        for (int j = 0; j < n && ok; ++j) {
            cur += a[j];
            if (cur == target) {
                num += (j - lo);
                lo = j + 1;
                cur = 0;
            } else if (cur > target)
                ok = 0;
        }

        if (cur == 0 && ok && num == i) {
            break;
        }
    }
    cout << i << endl;
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