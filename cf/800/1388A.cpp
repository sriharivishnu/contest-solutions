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
void solve() {
    int n;
    cin >> n;
    if (n < 31) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << 6 << " " << 10 << " ";
        if (n == 36 || n == 40 || n == 44) {
            cout << 15 << " " << (n - 31) << endl;
        } else {
            cout << 14 << " " << (n - 30) << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
