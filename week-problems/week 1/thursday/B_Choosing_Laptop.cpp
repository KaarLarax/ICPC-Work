// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vii = vector<ii>;

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
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    int a, b, c, d;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        arr[i].pb(a);
        arr[i].pb(b);
        arr[i].pb(c);
        arr[i].pb(d);
    }
    int ans = INF, ans2 = -1;
    for (int i = 0; i < n; i++) {
        for (int i = 0; i < n; i++) {
            bool band = true;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1] && arr[i][2] < arr[j][2]) {
                    band = false;
                    break;
                }
            }
            if (band && ans > arr[i][3]) {
                ans = arr[i][3];
                ans2 = i;

            }
        }
    }
    cout << ans2 + 1 << edl;
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