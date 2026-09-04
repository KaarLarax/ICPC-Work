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
    string s;
    cin >> s;
    int l = 0;
    int r = n - 1;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (s[i] == 'R' ? n - 1 - i : i);
    }
    ll k = 0;
    while (l <= r) {
        int lx = n - 1 - l, ly = l;
        int rx = n - 1 - r, ry = r;
        if (max(rx, ry) > max(lx, ly)) {
            if (rx > ry) {
                if (s[r] != 'R') {
                    sum += rx - ry;
                    k++;
                    cout << sum << ' ';
                }
            } else {
                if (s[r] != 'L') {
                    sum += ry - rx;
                    k++;
                    cout << sum << ' ';
                }
            }
            r--;
        } else {
            if (lx > ly) {
                if (s[l] != 'R') {
                    sum += lx - ly;
                    k++;
                    cout << sum << ' ';
                }
            } else {
                if (s[l] != 'L') {
                    sum += ly - lx;
                    k++;
                    cout << sum << ' ';
                }
            }
            l++;
        }
    }
    for (int i = k; i < n; i++) {
        cout << sum << ' ';
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