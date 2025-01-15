/*
    Solution by: Srihari Vishnu
    Created: January 14 2025

    ccc2019s3
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
typedef vector<int> vi;

const ll MOD = 1e9 + 7;
const ll INF = 1e9;

const int N = 3;

struct Grid {
    int vals[N][N] = {0};
    bool filled[N][N] = {0};

    int numFilledCol(int j) const {
        return filled[0][j] + filled[1][j] + filled[2][j];
    }
    int numFilledRow(int i) const {
        return filled[i][0] + filled[i][1] + filled[i][2];
    }
    void fill(int i, int j, int val) {
        assert(BTWN(i, 0, 2) && BTWN(j, 0, 2));
        vals[i][j] = val;
        filled[i][j] = 1;
    }

    friend istream& operator>>(istream& is, Grid& grid) {
        FOR(i, 0, N) {
            FOR(j, 0, N) {
                string s;
                cin >> s;
                grid.filled[i][j] = s != "X";
                if (s != "X") grid.vals[i][j] = stoi(s);
            }
        }
        return is;
    }
    friend ostream& operator<<(ostream& os, const Grid& grid) {
        FOR(i, 0, N) {
            FOR(j, 0, N) { cout << grid.vals[i][j] << ' '; }
            cout << endl;
        }
        return os;
    }
};

struct Generator {
    int basis, cur = 0, diff = 1;
    Generator(int basis_) : basis{basis_} {}
    int next() {
        int res = cur;
        if (diff & 1)
            cur += diff;
        else
            cur -= diff;
        diff++;
        return res;
    }

    int hasNext() { return abs(cur) <= 2000000; }
};

void solve() {
    Grid initial;
    cin >> initial;
    auto check = [&](const Grid& grid) {
        bool ok = 1;
        FOR(i, 0, N) {
            if (grid.numFilledCol(i) == 3) {
                ok &= grid.vals[2][i] - grid.vals[1][i] ==
                      grid.vals[1][i] - grid.vals[0][i];
            }

            if (grid.numFilledRow(i) == 3) {
                ok &= grid.vals[i][2] - grid.vals[i][1] ==
                      grid.vals[i][1] - grid.vals[i][0];
            }
        }
        return ok;
    };

    auto fill = [&](Grid& grid) {
        bool found = 0;
        FOR(i, 0, N) {
            // try down
            if (grid.numFilledCol(i) == 2) {
                if (!grid.filled[0][i]) {
                    grid.fill(
                        0, i,
                        grid.vals[1][i] - (grid.vals[2][i] - grid.vals[1][i]));
                }
                if (!grid.filled[1][i]) {
                    grid.fill(1, i,
                              grid.vals[0][i] +
                                  (grid.vals[2][i] - grid.vals[0][i]) / 2);
                }
                if (!grid.filled[2][i]) {
                    grid.fill(
                        2, i,
                        grid.vals[1][i] + (grid.vals[1][i] - grid.vals[0][i]));
                }
                found = 1;
            }

            // try across
            if (grid.numFilledRow(i) == 2) {
                if (!grid.filled[i][0]) {
                    grid.fill(
                        i, 0,
                        grid.vals[i][1] - (grid.vals[i][2] - grid.vals[i][1]));
                }
                if (!grid.filled[i][1]) {
                    grid.fill(i, 1,
                              grid.vals[i][0] +
                                  (grid.vals[i][2] - grid.vals[i][0]) / 2);
                }
                if (!grid.filled[i][2]) {
                    grid.fill(
                        i, 2,
                        grid.vals[i][1] + (grid.vals[i][1] - grid.vals[i][0]));
                }
                found = 1;
            }
        }
        return found;
    };

    // Case 1: All X's -> can just return
    if (initial.numFilledRow(0) + initial.numFilledRow(1) +
            initial.numFilledRow(2) ==
        0) {
        cout << initial;
        return;
    }

    // Case 2: There is at least 1 2X's in a row/col
    // Case 3: 1X in a row (just fill immediately)

    Grid ans;
    auto find = [&](Grid& grid, auto&& self) -> bool {
        bool res;
        do {
            res = fill(grid);
        } while (res);
        if (!check(grid)) return false;
        if (grid.numFilledRow(0) + grid.numFilledRow(1) +
                grid.numFilledRow(2) ==
            9) {
            ans = grid;
            return true;
        }
        for (int i = 0; i < N; ++i) {
            if (grid.numFilledRow(i) == 1) {
                int j = grid.filled[i][0] ? 0 : (grid.filled[i][1] ? 1 : 2);

                Generator gen{grid.vals[i][j]};
                while (gen.hasNext()) {
                    Grid copy = grid;
                    copy.fill(i, (j + 1) % N, gen.next());
                    if (self(copy, self)) return true;
                }
            }

            if (grid.numFilledCol(i) == 1) {
                int j = grid.filled[0][i] ? 0 : (grid.filled[1][i] ? 1 : 2);
                Generator gen{grid.vals[j][i]};
                while (gen.hasNext()) {
                    Grid copy = grid;
                    copy.fill((j + 1) % N, i, gen.next());
                    if (self(copy, self)) return true;
                }
            }
        }
        return false;
    };
    assert(find(initial, find) == 1);
    cout << ans;
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