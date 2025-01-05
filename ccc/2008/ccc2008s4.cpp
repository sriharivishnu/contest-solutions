/*
    Solution by: Srihari Vishnu
    Created: January 04 2025

    ccc2008s4
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
    vector<int> initial(4);
    FOR(i, 0, 4) cin >> initial[i];

    int ans = 0;
    auto recur = [&](vector<int>& hand, auto&& self) {
        if (sz(hand) == 1) {
            if (hand[0] <= 24) ans = max(ans, hand[0]);
            return;
        }

        FOR(i, 0, sz(hand)) {
            FOR(j, i + 1, sz(hand)) {
                vector<int> h2;
                FOR(k, 0, sz(hand)) if (k != i && k != j) h2.pb(hand[k]);

                auto tryOp = [&](int newVal) {
                    h2.pb(newVal);
                    self(h2, self);
                    h2.pop_back();
                };

                tryOp(hand[i] + hand[j]);
                tryOp(hand[i] - hand[j]);
                tryOp(hand[j] - hand[i]);
                tryOp(hand[i] * hand[j]);
                if (hand[j] != 0 && (hand[i] % hand[j] == 0))
                    tryOp(hand[i] / hand[j]);

                if (hand[i] != 0 && (hand[j] % hand[i] == 0))
                    tryOp(hand[j] / hand[i]);
            }
        }
    };

    recur(initial, recur);

    cout << ans << endl;
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