// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vii = vector<ii>;
using vvll = vector<vll>;
using vs = vector<string>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'
#define vsCode cout << flush, system("Pause")

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 1e3 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    int n = 8;
    vs grid(n, string(n, '.'));
    for (auto &i : grid) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    for (int i = 0; i < n; i++) {
        if (grid[i].find('B') == string::npos) {
            cout << "R" << edl;
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        bool found = false;
        bool nofilled = false;
        for (int j = 0; j < n; j++) {
            found |= grid[j][i] == 'R';
            nofilled |= grid[j][i] == '.';
            if (nofilled) {
                break;
            }
        }
        if (nofilled) {
            continue;
        }
        if (!found) {
            cout << "B" << edl;
            return;
        }
    }
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // Fast I/O Setup
    int q = 1;
    cin >> q;
    while (q--) {
        solve();
    }
    // vsCode;
    return 0;
}
// By KaarLarax