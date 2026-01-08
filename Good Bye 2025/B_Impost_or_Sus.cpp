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
        string s;
        cin >> s;
        int ans = (s[0] == 'u') + (s[sz(s) - 1] == 'u');
        s[0] = 's', s[sz(s) - 1] = 's';
        for (int i = 1; i < sz(s) - 1;) {
            if ('u' == s[i]) {
                ans += (s[i - 1] == 'u') + (s[i + 1] == 'u');
                s[i - 1] = 's';
                s[i + 1] = 's';
                i += 2;
            } else {
                i++;
            }
        }
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