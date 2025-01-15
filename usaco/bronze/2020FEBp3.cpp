/*
    Solution by: Srihari Vishnu
    Created: January 14 2025

    2020FEBp3
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

    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    vi trans(n);
    iota(all(trans), 1);

    std::reverse(trans.begin() + a1 - 1, trans.begin() + a2);
    std::reverse(trans.begin() + b1 - 1, trans.begin() + b2);

    vi ans(n);
    FOR(i, 0, n) {
        int len = 0, cur = i + 1;
        do {
            cur = trans[cur - 1];
            ++len;
        } while (cur != i + 1);

        int pos = (k % len);
        cur = i + 1;
        FOR(j, 0, len - pos) { cur = trans[cur - 1]; }
        ans[cur - 1] = i + 1;
    }

    FOR(i, 0, n) { cout << ans[i] << endl; }
}

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}