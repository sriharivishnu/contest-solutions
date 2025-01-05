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
    int x, y;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int a;
            cin >> a;
            if (a) {
                x = i;
                y = j;
            }
        }
    }
    cout << abs(x - 2) + abs(y - 2) << endl;
}

int main() { solve(); }
