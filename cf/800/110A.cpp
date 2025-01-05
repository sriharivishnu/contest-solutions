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

bool solve() {
    ll x;
    cin >> x;
    ll lucky = 0;
    while (x) {
        lucky += ((x % 10 == 4) || (x % 10 == 7));
        x /= 10;
    }
    if (lucky == 0) return false;
    while (lucky) {
        if (((lucky % 10) != 4) && ((lucky % 10) != 7)) return false;
        lucky /= 10;
    }
    return true;
}

int main() { cout << (solve() ? "YES" : "NO") << endl; }