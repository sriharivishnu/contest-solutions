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
    string a, b;
    cin >> a >> b;

    for (int i = 0; i < a.size(); ++i) a[i] = tolower(a[i]);
    for (int i = 0; i < a.size(); ++i) b[i] = tolower(b[i]);
    if (a < b)
        cout << -1 << endl;
    else if (a == b)
        cout << 0 << endl;
    else
        cout << 1 << endl;
}

int main() { solve(); }
