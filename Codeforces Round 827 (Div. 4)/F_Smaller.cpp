// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<char, int>;
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

struct dt {
    map<int, ll> ocurr;
    ll si;

    void init() {
        ocurr[0]++;
        si = 1;
    }

    bool operator<(const dt &x) const {
        bool bo = false;
        for (const auto &i : x.ocurr) {
            if (i.fi > 0 && i.se > 0)
                bo = true;
        }
        if (bo)
            return true;

        bool ao = false;
        for (const auto &i : this->ocurr) {
            if (i.fi > 0 && i.se > 0)
                ao = true;
        }
        if (ao)
            return false;

        return this->si < x.si;
    }

    void sum(const map<int, ll> &a, const ll &k) {
        for (const auto &i : a) {
            this->ocurr[i.fi] += i.se * k;
            this->si += i.se * k;
        }
    }
};

void solve() {
    int n;
    cin >> n;
    dt a, b;
    a.init();
    b.init();
    while (n--) {
        int x;
        ll y;
        string s;
        cin >> x >> y >> s;
        map<int, ll> cub;
        for (auto &i : s) {
            cub[i - 'a']++;
        }
        if (x == 1) {
            a.sum(cub, y);
        } else {
            b.sum(cub, y);
        }
        cout << (a < b ? "YES" : "NO") << edl;
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