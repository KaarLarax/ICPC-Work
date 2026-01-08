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
constexpr int MxN = 3e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

using namespace std;

vi ps(const vi &arr, const ll& n) {
    vi temp = arr;
    vi prefix(n + 2, 0);
    for (ll x = n; x >= 1; x--) {
        prefix[x] = prefix[x + 1] + temp[x];
    }
    return prefix;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vi cubeta(n + 1, 0);
    for (ll i = 0; i < m; i++) {
        ll aux;
        cin >> aux;
        cubeta[aux]++;
    }
    vi prefix = ps(cubeta, n);
    ll ans = 0;
    for (ll i = 1; i < n; i++) {
        ans += prefix[i] * prefix[n - i] - prefix[max(i, n - i)];
    }
    cout << ans << edl;
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