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

int a[101];

// IMPLEMENTATION
int solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int b = 1;
    for (int i = 0; i < n; ++b, ++i) {
        if (b == a[i]) ++b;
    }
    return b - 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
}
