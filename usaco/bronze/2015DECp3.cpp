/*
    Solution by: Srihari Vishnu
    Created: January 03 2025

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
    int N, M, D, S;
    cin >> N >> M >> D >> S;
    vector<tiii> drinks;
    FOR(i, 0, D) {
        int p, m, t;
        cin >> p >> m >> t;
        drinks.pb({p, m, t});
    }

    vector<pii> sick(S);
    FOR(i, 0, S) { cin >> sick[i].fi >> sick[i].se; }

    set<int> infected;
    FOR(i, 1, M + 1) {
        bool ok = 1;
        FOR(j, 0, S) {
            bool f = 0;
            FOR(k, 0, D) {
                if (get<0>(drinks[k]) == sick[j].fi && get<1>(drinks[k]) == i &&
                    get<2>(drinks[k]) < sick[j].se) {
                    f = 1;
                    break;
                }
            }

            if (!f) ok = 0;
        }

        if (ok) {
            FOR(k, 0, D) {
                if (get<1>(drinks[k]) == i) {
                    infected.insert(get<0>(drinks[k]));
                }
            }
        }
    }
    cout << infected.size() << endl;
}

int main() {
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}