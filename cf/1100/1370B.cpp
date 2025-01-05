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

    int lastOdd = -1, lastEven = -1, outputted = 0;
    for (int i = 0; i < 2 * n; ++i) {
        int x;
        cin >> x;
        if (outputted < n - 1) {
            if (x & 1) {
                if (lastOdd != -1) {
                    cout << lastOdd << ' ' << i + 1 << endl;
                    lastOdd = -1;
                    ++outputted;
                } else
                    lastOdd = i + 1;
            } else {
                if (lastEven != -1) {
                    cout << lastEven << ' ' << i + 1 << endl;
                    lastEven = -1;
                    ++outputted;
                } else
                    lastEven = i + 1;
            }
        }
    }
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