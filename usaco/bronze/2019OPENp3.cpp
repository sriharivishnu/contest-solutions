/*
    Solution by: Srihari Vishnu
    Created: January 15 2025

    2019OPENp3
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

/*
A 1 3
B 2 3
C 3

BD
ABC
C

  B

A: 2
B: 1, 2
C: 2, 3
D: 1

1 2
  2 3
*/

bool solve() {
    int n;
    cin >> n;

    map<string, set<int>> m;

    FOR(i, 0, n) {
        int k;
        cin >> k;

        FOR(j, 0, k) {
            string s;
            cin >> s;
            m[s].insert(i);
        }
    }

    vector<string> keys;
    for (const auto& [key, _] : m) keys.pb(key);

    FOR(i, 0, sz(keys)) {
        FOR(j, i + 1, sz(keys)) {
            bool both = 0, a = 0, b = 0;
            for (auto idx : m[keys[i]]) {
                if (m[keys[j]].count(idx)) {
                    both = 1;
                } else {
                    a = 1;
                }
            }

            for (auto idx : m[keys[j]]) {
                if (!m[keys[i]].count(idx)) b = 1;
            }

            if (both && a && b) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << (solve() ? "yes" : "no") << endl;
        ;
    }
}