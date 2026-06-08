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
 constexpr int dx[4] = {1, 1, -1, -1}, dy[4] = {1, -1, 1, -1};

 int dp[300][300][5];


 int traverse(const int x, const int y, const int& n, const int& m, const int& dir, const vector<vi>& grid) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return 0;
    }
    if (dp[x][y][dir] != -1) {
        return dp[x][y][dir];
    }

    return dp[x][y][dir] = grid[x][y] + traverse(x + dx[dir], y + dy[dir], n, m, dir, grid);
 }

 void solve() {
    int n, m;
    cin >> n >> m;

    memset(dp, -1, sizeof(dp));

    vector<vi> grid(n, vi(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int maxi = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp = 0;
            for (int k = 0;k < 4; k++) {
                tmp += traverse(i, j, n, m, k, grid);
            }
            tmp -= 3 * grid[i][j];
            maxi = max(maxi, tmp);
        }
    }
    cout << maxi << edl;
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