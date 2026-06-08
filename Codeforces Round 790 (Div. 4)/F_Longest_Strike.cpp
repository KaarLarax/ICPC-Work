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
    map<int, int> ans;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        ans[aux]++;
    }
    int tam = -1;
    int l = -1, r = -1, x = -1, y = -1;
    int prev = -INF;

    for (auto i : ans) {
        if (i.se < k) {
            l = r = -1;
            prev = -INF;
            continue;
        }

        if (l == -1 || i.fi != prev + 1) {
            l = r = i.fi;
        } else {
            r = i.fi;
        }

        if (r - l > tam) {
            tam = r - l;
            x = l;
            y = r;
        }

        prev = i.fi;
    }

    if (x != -1 && y != -1) {
        cout << x << ' ' << y << edl;
    } else {
        cout << -1 << edl;
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