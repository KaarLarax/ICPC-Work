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
    int n, q;
    cin >> n >> q;
    vvll grid(1001, vll(1001, 0));
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        grid[x][y] += x * y;
    }
    for (int i = 1; i < 1001; i++) {
        for (int j = 1; j < 1001; j++) {
            grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
        }
    }
    while (q--) {
        ll hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        cout << grid[hb - 1][wb - 1] - grid[hb - 1][ws] - grid[hs][wb - 1] + grid[hs][ws] << endl;
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