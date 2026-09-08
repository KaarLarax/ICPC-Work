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

using vs = vector<string>;

vs mirror(const vs &grid, const int &n , const int &m) {
    vs ans = grid;
    for (auto &i : ans) {
        reverse(i.begin(), i.end());
    }
    return ans;
}


vs rotate(const vs &grid, const int &n, const int& m) {
    vs ans(m, string(n, '.'));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int dy = n - 1 - j;
            ans[i][j] = grid[dy][i];
        }
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vs ori(n);
    for (auto &i : ori) {
        cin >> i;
    }
    int ans = 1 + (ori == mirror(ori, n, m));
    vs aux = ori;
    for (int i = 0; i < 3; i++) {

        auto tmp = rotate(aux, sz(aux), sz(aux[0]));

        ans += (ori == tmp) + (ori == mirror(tmp, sz(tmp), sz(tmp[0])));

        aux = tmp;
    }

    cout << ans << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // Fast I/O Setup
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    // vsCode;
    return 0;
}
// By KaarLarax