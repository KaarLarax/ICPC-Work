// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vi = vector<int>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 1e6 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

char bs(const ll& x) {
    auto good = [&](const ll& t){
        string value = to_string(t);
        int digitos = sz(value);
        ll ans = 0, ans2 = 0;
        for (ll i = 1; i <= digitos; ++i) {
            ans += 9LL * ll(pow(10LL, (i-1LL))) * i;
        }
        string temp;
        for (int i = 0; i < digitos; ++i) {
            temp += '9';
        }
        ll aux = (stoll(temp) - t) * digitos;
        ans -= aux;
        ans -= digitos;
        for (int i = 0; i < digitos; ++i) {
            ans++;
            if (ans == x) {
                return make_pair(false, value[i]);
            }
        }
        return make_pair(ans < x, 'l');
    };
    ll l = 1, r = x, m;
    while (l <= r) {
        m = l + (r - l) / 2;
        auto ans = good(m);
        if (ans.se != 'l') {
            return ans.se;
        } else if (ans.fi) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return 'l';
}

void solve() {
    ll x;
    cin >> x;
    cout << bs(x) << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // Fast I/O Setup
    int q = 1;
    cin >> q;
    while (q--) solve();
    return 0;
}
// By KaarLarax