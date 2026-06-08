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
    int n;
    cin >> n;
    vll h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vll ans(n);
    for (int i = 0; i < n; i++) {
        vll shh(n);
        for (int j = 0; j < n; j++) {
            shh[j] = h[(i + j) % n];
        }
        vll l(n, 0), r(n, 0);
        l[1] = shh[0];
        for (int j = 2; j < n; j++) {
            l[j] = max(l[j - 1], shh[j - 1]);
        }
        r[n - 1] = shh[n - 1];
        for (int j = n - 2; j >= 1; j--) {
            r[j] = max(r[j + 1], shh[j]);
        }
        ll sum = 0;
        for (int j = 1; j < n; j++) {
            sum += min(l[j], r[j]);
        }
        ans[i] = sum;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << edl;
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