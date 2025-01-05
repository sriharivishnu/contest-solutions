/*
    Solution by: Srihari Vishnu
    Created: January 03 2025

    2020OPENp3
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
    int N, T;
    cin >> N >> T;
    string s;
    cin >> s;

    vector<bool> fin(N + 1);
    FOR(i, 1, N + 1) fin[i] = s[i - 1] == '1';

    vector<tiii> hs;
    FOR(i, 0, T) {
        int t, x, y;
        cin >> t >> x >> y;
        hs.pb({t, x, y});
    }
    sort(all(hs));

    int ans = 0, kLoAns = 2e9, kHiAns = -1;
    FOR(i, 1, N + 1) {
        if (!fin[i]) continue;
        bool found = 0;
        FOR(k, 0, T + 2) {
            vector<bool> inf(N + 1);
            vector<int> shakes(N + 1, 0);
            inf[i] = 1;

            for (const auto& [t, x, y] : hs) {
                if (inf[x] && !inf[y] && shakes[x] < k) {
                    inf[y] = 1, shakes[x]++;
                } else if (!inf[x] && inf[y] && shakes[y] < k) {
                    inf[x] = 1, shakes[y]++;
                } else if (inf[x] && inf[y]) {
                    shakes[x]++, shakes[y]++;
                }
            }
            if (inf == fin) {
                found = 1;
                kLoAns = min(kLoAns, k);
                kHiAns = max(kHiAns, k);
            }
        }
        ans += found;
    }

    if (kHiAns == T + 1) {
        cout << ans << ' ' << kLoAns << ' ' << "Infinity" << endl;
    } else {
        cout << ans << ' ' << kLoAns << ' ' << kHiAns << endl;
    }
}

int main() {
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}