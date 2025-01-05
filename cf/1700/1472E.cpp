#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#endif

#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> friends;

    for (int i = 0; i < n; ++i) {
        int h, w;
        cin >> h >> w;
        friends.push_back({h, w, i});
    }

    sort(all(friends), greater<tuple<int, int, int>>());
    vector<int> mins(n);
    mins[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        if (get<1>(friends[i]) < get<1>(friends[mins[i + 1]])) {
            mins[i] = i;
        } else {
            mins[i] = mins[i + 1];
        }
    }
    vector<int> ans(n);
    auto solve = [&](int h, int w) {
        auto res = upper_bound(all(friends), make_tuple(h, -INF, -1),
                               greater<tuple<int, int, int>>());

        if (res == friends.end()) {
            return -1;
        } else {
            if (get<1>(friends[mins[res - friends.begin()]]) >= w) return -1;
            return get<2>(friends[mins[res - friends.begin()]]) + 1;
        }
    };
    for (int i = 0; i < n; ++i) {
        ans[get<2>(friends[i])] = solve(get<0>(friends[i]), get<1>(friends[i]));
        if (ans[get<2>(friends[i])] == -1) {
            ans[get<2>(friends[i])] =
                solve(get<1>(friends[i]), get<0>(friends[i]));
        }
    }

    for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}