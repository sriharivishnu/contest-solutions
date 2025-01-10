/*
    Solution by: Srihari Vishnu
    Created: January 08 2025

    2017OPENp3
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

    vector<int> minI(10, 1e9), minJ(10, 1e9), maxI(10, -1), maxJ(10, -1);

    vector<string> arr(n);
    FOR(i, 0, n) cin >> arr[i];

    set<int> poss;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            int x = arr[i][j] - '0';
            minI[x] = min(minI[x], i);
            maxI[x] = max(maxI[x], i);
            minJ[x] = min(minJ[x], j);
            maxJ[x] = max(maxJ[x], j);
            poss.insert(x);
        }
    }
    poss.erase(0);
    FOR(i, 1, 10) {
        if (minI[i] == 1e9) continue;

        FOR(x, minI[i], maxI[i] + 1) {
            FOR(y, minJ[i], maxJ[i] + 1) {
                if (arr[x][y] - '0' != i) {
                    poss.erase(arr[x][y] - '0');
                }
            }
        }
    }
    cout << sz(poss) << endl;
}

int main() {
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}