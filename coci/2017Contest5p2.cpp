/*
    Solution by: Srihari Vishnu
    Created: January 22 2025

    2017Contest5p2
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

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

const int moves[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Spiral {
    int i, j;

    void next() {
        if (steps >= cur_max) {
            steps = 0;
            if (cur_max == last) {
                cur_max++;
            } else {
                last = cur_max;
            }
            cur_dir = (cur_dir + spiral_direction + 4) % 4;
        }
        i += moves[cur_dir][0];
        j += moves[cur_dir][1];
        ++steps;
    }

    friend istream& operator>>(istream& is, Spiral& obj) {
        is >> obj.i >> obj.j >> obj.spiral_direction;
        obj.i--;
        obj.j--;
        obj.spiral_direction = obj.spiral_direction == 0 ? 1 : -1;
        obj.cur_dir = -1 * obj.spiral_direction;
        return is;
    }

   private:
    int steps = 0;
    int last = 0, cur_max = 0;
    int spiral_direction;
    int cur_dir;
};

void solve() {
    int m, n, k;
    cin >> m >> n >> k;

    vector<vi> ans(m, vi(n));
    vector<Spiral> spirals(k);
    FOR(i, 0, k) cin >> spirals[i];

    FOR(t, 1, m * n * 4 + 2) {
        FOR(i, 0, k) {
            if (BTWN(spirals[i].i, 0, m - 1) && BTWN(spirals[i].j, 0, n - 1) &&
                ans[spirals[i].i][spirals[i].j] == 0) {
                ans[spirals[i].i][spirals[i].j] = t;
            }
            spirals[i].next();
        }
    }

    FOR(i, 0, m) {
        FOR(j, 0, n) { cout << ans[i][j] << ' '; }
        cout << endl;
    }
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