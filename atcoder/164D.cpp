/*
    Solution by: Srihari Vishnu
    Created: July 27 2025

    164D
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

const ll MOD = 1000000007;
const ll INF = 1e9;
const ld EPS = 1e-9;

const int MAXN = 200005;

void solve() {
	string num;
	cin >> num;

	int n = num.size();

	unordered_map<int, int> counts;
	counts[0] = 1;
	int pow = 1, s = 0;
	long long ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		pow = (pow * 10) % 2019;
		s = ((num[i] - '0') * pow + s) % 2019;
		ans += counts[s];
		counts[s]++;
	}

	cout << ans << endl;
}

int main() {
	// freopen("", "r", stdin);
	// freopen("", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc = 1;
	// cin >> tc;
	for (int t = 1; t <= tc; t++) { solve(); }
}
