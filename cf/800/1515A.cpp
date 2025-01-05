#include <assert.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<std::pair<int, int>> vii;
typedef vector<vector<int>> vvi;

// IMPLEMENTATION

int a[101];

void solve() {
    int n, x, s = 0;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }

    if (s == x) {
        cout << "NO" << endl;
    } else {
        s = 0;
        for (int i = 0; i < n; ++i) {
            s += a[i];
            if (s == x) {
                s = s - a[i] + a[i + 1];
                swap(a[i], a[i + 1]);
            }
        }

        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) cout << a[i] << ' ';
        cout << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
}