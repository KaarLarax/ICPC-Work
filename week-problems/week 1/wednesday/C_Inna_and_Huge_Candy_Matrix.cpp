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
    int n, m, x, y, z, q;
    cin >> n >> m >> x >> y >> z >> q;
    ll v = x % 4;
    ll h = y % 2;
    ll v2 = abs(3ll * z % 4);
    while (q--) {
        int i, j, n1 = n, m1 = m;
        cin >> i >> j;
        if (v == 1) {
            swap(i, j);
            j = n1 - j + 1;
            swap(n1, m1);
        } else if (v == 2) {
            i = n1 - i + 1;
            j = m1 - j + 1;
        } else if (v == 3) {
            swap(i, j);
            i = m1 - i + 1;
            swap(n1, m1);
        }

        if (h) {
            j = m1 - j + 1;
        }

        if (v2 == 1) {
            swap(i, j);
            j = n1 - j + 1;
            swap(n1, m1);
        } else if (v2 == 2) {
            i = n1 - i + 1;
            j = m1 - j + 1;
        } else if (v2 == 3) {
            swap(i, j);
            i = m1 - i + 1;
            swap(n1, m1);
        }

        cout << i << ' ' << j << edl;
    }
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