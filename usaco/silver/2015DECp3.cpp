/*
    Solution by: Srihari Vishnu
    Created: February 05 2025

    2015DECp3
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
    int n, q;
    cin >> n >> q;

    vi arr(n, 0);
    FOR(i, 0, n) cin >> arr[i];

    vi p1(n + 1, 0), p2(n + 1, 0), p3(n + 1, 0);
    FOR(i, 0, n) {
        p1[i + 1] = p1[i] + (arr[i] == 1);
        p2[i + 1] = p2[i] + (arr[i] == 2);
        p3[i + 1] = p3[i] + (arr[i] == 3);
    }

    FOR(i, 0, q) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        cout << p1[b + 1] - p1[a] << " " << p2[b + 1] - p2[a] << " "
             << p3[b + 1] - p3[a] << endl;
    }
}

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}