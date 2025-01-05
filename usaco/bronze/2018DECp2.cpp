/*
    Solution by: Srihari Vishnu
    Created: January 02 2025

    2018DECp2
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

const int MAXN = 1001;

int arr[MAXN] = {0};
void solve() {
    int n;
    cin >> n;

    FOR(i, 0, n) {
        int s, t, b;
        cin >> s >> t >> b;
        arr[s] += b;
        arr[t] -= b;
    }
    int ans = 0, cur = 0;
    FOR(i, 0, MAXN) {
        cur += arr[i];
        ans = max(ans, cur);
    }
    cout << ans << endl;
}

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}