/*
    Solution by: Srihari Vishnu
    Created: January 04 2025

    2023JANp2
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

struct Cow {
    int s, t, c;
};

struct AC {
    int a, b, p, m;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Cow> cows(n);
    vector<AC> acs(m);

    FOR(i, 0, n) cin >> cows[i].s >> cows[i].t >> cows[i].c;
    FOR(i, 0, m) cin >> acs[i].a >> acs[i].b >> acs[i].p >> acs[i].m;

    int best = 2e9;
    FOR(i, 1, 1 << m) {
        int stalls[101] = {0};
        int money = 0;
        FOR(j, 0, m) {
            if (i & (1 << j)) {
                money += acs[j].m;
                FOR(k, acs[j].a, acs[j].b + 1) { stalls[k] += acs[j].p; }
            }
        }

        bool ok = 1;
        FOR(j, 0, n) {
            FOR(k, cows[j].s, cows[j].t + 1) {
                if (stalls[k] < cows[j].c) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok) best = min(best, money);
    }
    cout << best << endl;
}

int main() {
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}