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

bool isPrime[3001] = {0};
void solve() {
    int n;
    cin >> n;
    memset(isPrime, 1, n * sizeof(bool));
    for (int i = 2; i * i <= n; ++i) {
        for (int j = i + i; j <= n; j += i) isPrime[j] = false;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int num = 0;
        for (int j = 2; j < sqrt(i); ++j) {
            if (i % j == 0) {
                num += isPrime[j];
                num += isPrime[i / j];
            }
        }
        if (((int)sqrt(i)) * ((int)sqrt(i)) == i) {
            num += isPrime[(int)sqrt(i)];
        }
        if (num == 2) {
            ++ans;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}