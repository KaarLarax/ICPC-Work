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
    int n, k;
    cin >> n >> k;

    string s, z;
    cin >> s >> z;

    ll unoss = 0, unosz = 0, unosx = 0;

    for (int i = 0; i < n; i++) {
        unoss += (s[i] == '1');
        unosz += (z[i] == '1');
        unosx += (s[i] != z[i]);
    }

    ll ceross = n - unoss;
    ll cerosz = n - unosz;
    ll cerosx = n - unosx;

    ll tot = (1LL << k) + 1;
    ll base = tot / 3;

    ll cnts, cntz, cntx;

    if (k & 1) {
        cnts = base;
        cntx = base;
        cntz = base;
    } else {
        cnts = base + 1;
        cntz = base + 1;
        cntx = base;
    }

    ll ans = 0;
    ans += cnts * unoss * ceross;
    ans += cntz * unosz * cerosz;
    ans += cntx * unosx * cerosx;

    cout << ans << edl;
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