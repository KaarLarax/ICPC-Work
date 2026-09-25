// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// combinatoria

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
constexpr int MOD = 122333221;
constexpr int MxN = 1e3 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ll dp[int(1e5) + 10];

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void memo() {
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= 1e5; i++) {
        dp[i] = i * dp[i - 1] % MOD;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
     if (k < 0 || k > n) {
        cout << 0 << edl;
        return;
    }

    ll ans = dp[n];

    ans = ans * binpow(dp[k], MOD - 2) % MOD;
    ans = ans * binpow(dp[n - k], MOD - 2) % MOD;

    cout << ans << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // Fast I/O Setup
    int q = 1;
    memo();
    cin >> q;
    while (q--) {
        solve();
    }
    // vsCode;
    return 0;
}
// By KaarLarax