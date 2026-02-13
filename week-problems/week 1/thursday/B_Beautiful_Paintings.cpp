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
    int n, maxi = -1;
    cin >> n;
    map<int, int> arr;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        arr[aux]++;
        maxi = max(maxi, arr[aux]);
    }
    vi ans[maxi];
    for (int i = 0; i < maxi; i++) {
        for (auto& j : arr) {
            if (!j.se) {
                continue;
            }
            ans[i].pb(j.fi);
            j.se--;
        }
    }
    int ans2 = 0;
    for (int i = 0; i < maxi; i++) {
        ans2 += sz(ans[i]) - 1;
    }
    cout << ans2 << edl;
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