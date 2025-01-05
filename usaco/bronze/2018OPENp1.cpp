/*
    Solution by: Srihari Vishnu
    Created: January 03 2025

    2018OPENp1
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
    string arr[3];
    FOR(i, 0, 3) cin >> arr[i];

    auto checkIndividual = [&](char target, char a, char b, char c) {
        return target == a && a == b && b == c;
    };

    auto checkTeam = [&](char targetA, char targetB, char a, char b, char c) {
        char tmp[3] = {a, b, c};
        sort(tmp, tmp + 3);
        if ((tmp[0] == tmp[1] && tmp[1] != tmp[2]) ||
            (tmp[1] == tmp[2] && tmp[0] != tmp[1])) {
            return (tmp[0] == targetA && tmp[2] == targetB) ||
                   (tmp[0] == targetB && tmp[2] == targetA);
        }
        return false;
    };

    int s = 0, g = 0;
    for (char c = 'A'; c <= 'Z'; ++c) {
        bool found = false;
        FOR(i, 0, 3) {
            found |= checkIndividual(c, arr[i][0], arr[i][1], arr[i][2]);
            found |= checkIndividual(c, arr[0][i], arr[1][i], arr[2][i]);
        }
        found |= checkIndividual(c, arr[0][0], arr[1][1], arr[2][2]);
        found |= checkIndividual(c, arr[2][0], arr[1][1], arr[0][2]);
        s += found;

        for (char c2 = c + 1; c2 <= 'Z'; ++c2) {
            bool found2 = false;
            FOR(i, 0, 3) {
                found2 |= checkTeam(c, c2, arr[i][0], arr[i][1], arr[i][2]);
                found2 |= checkTeam(c, c2, arr[0][i], arr[1][i], arr[2][i]);
            }
            found2 |= checkTeam(c, c2, arr[0][0], arr[1][1], arr[2][2]);
            found2 |= checkTeam(c, c2, arr[2][0], arr[1][1], arr[0][2]);
            g += found2;
        }
    }
    cout << s << endl << g << endl;
}

int main() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}