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
const int MAX_N = 2 * 1e5 + 1;
int arr[MAX_N];

// IMPLEMENTATION
int solve() {
    int n, s = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        s += arr[i];
    }
    if (s % n) return -1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += arr[i] > (s / n);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
}
