/*
    Solution by: Srihari Vishnu
    Created: January 03 2025

    2019JANp3
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

    vector<vector<string>> atrs(n);

    FOR(i, 0, n) {
        string s;
        cin >> s;
        int x;
        cin >> x;

        FOR(j, 0, x) {
            cin >> s;
            atrs[i].push_back(s);
        }
        sort(all(atrs[i]));
    }

    int ans = 0;

    FOR(a, 0, n) {
        FOR(b, a + 1, n) {
            int cur = 0;
            int i = 0, j = 0;
            while (i < sz(atrs[a]) && j < sz(atrs[b])) {
                if (atrs[a][i] < atrs[b][j])
                    ++i;
                else if (atrs[a][i] > atrs[b][j])
                    ++j;
                else
                    ++cur, ++i, ++j;
            }
            ans = max(ans, cur);
        }
    }

    cout << ans + 1 << endl;
}

int main() {
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}