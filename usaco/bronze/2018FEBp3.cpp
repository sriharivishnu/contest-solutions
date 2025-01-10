/*
    Solution by: Srihari Vishnu
    Created: January 08 2025

    2018FEBp3
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

/// 0 1 -1 -1 -1

void solve() {
    int n;
    cin >> n;

    vi arr(n);
    FOR(i, 0, n) cin >> arr[i];
    if (arr[0] > 0) {
        cout << -1 << endl;
        return;
    }
    arr[0] = 0;

    RFOR(i, n - 2, 0) {
        if (arr[i + 1] > 0 && arr[i] >= 0 && arr[i + 1] - 1 != arr[i]) {
            cout << -1 << endl;
            return;
        }
        if (arr[i + 1] > 0 && arr[i] == -1) arr[i] = arr[i + 1] - 1;
    }
    int mi = 0, ma = 0;
    FOR(i, 0, n) {
        if (arr[i] <= 0) ma++;
        if (arr[i] == 0) mi++;
    }

    cout << mi << ' ' << ma << endl;
}

int main() {
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}