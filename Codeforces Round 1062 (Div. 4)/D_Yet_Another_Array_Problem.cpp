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
constexpr int MxN = 1e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int sieveb[MxN];
vll sieve(const int &n) {
    vll arr;
    arr.reserve(300);
    for (int i = 2; i * i < n; i++) {
        if (!sieveb[i]) {
            for (int j = i + i; j < n; j += i) {
                sieveb[j] = true;
            }
        }
    }
    for (int i = 2; i < n && sz(arr) < 30; i++) {
        if (!sieveb[i]) {
            arr.pb(i);
        }
    }
    return arr;
}

void solve(const vll& val) {
    int n;
    cin >> n;
    bool band = false;
    vll arr(n);
    ll maxsum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxsum = gcd(arr[i], maxsum);
    }
    for (int j = 0; j < sz(val); j++) {
        if (maxsum % val[j] != 0) {
            cout << val[j] << edl;
            return;
        }
    }
    cout << -1 << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // Fast I/O Setup
    auto val = sieve(MxN);
    int q = 1;
    cin >> q;
    while (q--) {
        solve(val);
    }
    // vsCode;
    return 0;
}
// By KaarLarax