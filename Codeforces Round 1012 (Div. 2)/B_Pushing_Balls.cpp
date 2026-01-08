#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (grid[i][j] == '1') {
                int x = i;
                int y = j;
                bool bandx = true;
                bool bandy = true;
                while (y >= 0) {
                    if (grid[x][y] == '0') {
                        bandy = false;
                        break;
                    }
                    y--;
                }
                y = j;
                while (x >= 0) {
                    if (grid[x][y] == '0') {
                        bandx = false;
                        break;
                    }
                    x--;
                }
                if (!bandx && !bandy) {
                    cout << "NO" << edl;
                    return;
                }
            }
        }
    }
    cout << "YES" << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int q = 1;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}

// By KaarLarax