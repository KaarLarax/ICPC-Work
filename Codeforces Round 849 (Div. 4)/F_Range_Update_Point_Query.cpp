#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

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

struct segtree {
    int size = 0;
    vll mx;
    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        mx.assign(2 * size, 0);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            mx[x] = v;
            return;
        }

        int m = lx + (rx - lx) / 2;

        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }

        mx[x] = max(mx[2 * x + 1], mx[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    ll digitSum(ll v) {
        ll ans = 0;

        while (v > 0) {
            ans += v % 10;
            v /= 10;
        }

        return ans;
    }

    void update(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return;
        }
        if (mx[x] <= 9) {
            return;
        }
        if (rx - lx == 1) {
            mx[x] = digitSum(mx[x]);
            return;
        }

        int m = lx + (rx - lx) / 2;

        update(l, r, 2 * x + 1, lx, m);
        update(l, r, 2 * x + 2, m, rx);

        mx[x] = max(mx[2 * x + 1], mx[2 * x + 2]);
    }
    void update(int l, int r) {
        update(l, r, 0, 0, size);
    }
    ll mini(int pos, int x, int lx, int rx) {
        if (rx - lx == 1) {
            return mx[x];
        }

        int m = lx + (rx - lx) / 2;

        if (pos < m) {
            return mini(pos, 2 * x + 1, lx, m);
        } else {
            return mini(pos, 2 * x + 2, m, rx);
        }
    }

    ll mini(int pos) {
        return mini(pos, 0, 0, size);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    segtree ans;
    ans.init(n);

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;

        ans.set(i, v);
    }

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int l, r;
            cin >> l >> r;
            ans.update(l - 1, r);
        }

        else if (op == 2) {
            int pos;
            cin >> pos;
            cout << ans.mini(pos - 1) << edl;
        }
    }
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);

    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int q = 1;
    cin >> q;

    while (q--) {
        solve();
    }

    // vsCode;
    return 0;
}

// By KaarLarax