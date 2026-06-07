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
    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    string s;
    cin >> s;
    ll sum = 0;
    vll ans(n, 1);
    ans[0] = 1;
    vll tmp(n, 1);
    int aux = 1;
    for (int i = sz(s) - 1; i >= 0; i--) {
        if (s[i] == '>') {
            aux++;
            tmp[i] = aux;
        } else if (s[i] == '=') {
            tmp[i] = aux;
        } else {
            aux = 1;
        }
    }
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == '=') {
            tmp[i] = tmp[i + 1];
        }
    }
    ans[0] = tmp[0];
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == '<') {
            ans[i + 1] = max(ans[i] + 1, tmp[i + 1]);
        } else if (s[i] == '>') {
            ans[i + 1] = tmp[i + 1];
        } else {
            ans[i + 1] = ans[i];
        }
    }
    for (int i = 0; i < n; i++) {
        sum += arr[i] * ans[i];
    }
    cout << sum << edl;
    for (auto &i : ans) {
        cout << i << ' ';
    }
    cout << edl;
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