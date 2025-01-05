/*
    Solution by: Srihari Vishnu
    Created: January 04 2025

    2023OPENp2
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
    int n, c, p;
    cin >> n >> c >> p;

    vector<string> nouns, intrans, trans, conj;
    FOR(i, 0, n) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s2 == "noun")
            nouns.pb(s1);
        else if (s2 == "intransitive-verb")
            intrans.pb(s1);
        else if (s2 == "transitive-verb")
            trans.pb(s1);
        else
            conj.pb(s1);
    }

    vector<string> bestAns;
    int best = 0;

    FOR(t1, 0, sz(intrans) + 1) {
        if (sz(nouns) < t1) break;
        int t2 =
            min({(sz(nouns) - t1) / 2, sz(trans), min(p, sz(conj)) + p - t1});
        if (t2 < 0) continue;

        int rem = t2 > 0 ? min(c, sz(nouns) - t1 - t2 * 2) : 0;
        int con = min({(t1 + t2) / 2, sz(conj), p});

        int numWords = t1 * 2 + t2 * 3 + rem + con;

        if (numWords > best) {
            best = numWords;
            vector<string> cur;

            int nIdx = 0, conjIdx = 0;
            for (int i = 0; i < t1; ++i, nIdx++) {
                string res = nouns[i] + " " + intrans[i];

                if (i & 1 && con > 0) {
                    cur.back() += " " + conj[conjIdx++] + " " + res;
                    --con;
                } else
                    cur.pb(res);
            }

            for (int i = 0; i < t2; ++i, nIdx += 2) {
                string res =
                    nouns[nIdx] + " " + trans[i] + " " + nouns[nIdx + 1];

                if ((((t1 & 1) && (t2 & 1) && !(i & 1)) ||
                     ((!(t1 & 1) || !(t2 & 1)) && (i & 1))) &&
                    con > 0) {
                    cur.back() += " " + conj[conjIdx++] + " " + res;
                    --con;
                } else
                    cur.pb(res);
            }

            while (rem--) {
                cur.back() += ", " + nouns[nIdx];
                nIdx += 1;
            }
            bestAns = cur;
        }
    }

    cout << best << endl;
    FOR(i, 0, sz(bestAns)) {
        cout << bestAns[i] << '.';
        if (i != sz(bestAns) - 1) cout << ' ';
    }
    cout << endl;
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