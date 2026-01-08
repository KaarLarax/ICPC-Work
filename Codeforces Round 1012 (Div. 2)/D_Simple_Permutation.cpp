#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool prime[MxN + 1];

void sieve() {
    prime[0] = prime[1] = true;
    for (int i = 2; i * i <= MxN; ++i) {
        if (!prime[i]) {
            for (int j = i * i; j <= MxN; j += i) {
                prime[j] = true;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << 2 << ' ' << 1 << edl;
        return;
    }
    const int lmt = (n + 1) / 2;
    int q = -1;
    for (int i = lmt; i >= 2; i--) {
        if (!prime[i]) {
            q = i;
            break;
        }
    }
    const int l = max(1, (2 * q) - n);
    vi perm;
    perm.pb(q);
    vector<pair<int, int>> pairs;
    for (int x = l; x < q; x++) {
        int y = 2 * q - x;
        if (y >= 1 && y <= n) {
            pairs.pb(x, y);
        }
    }

    sort(pairs.begin(), pairs.end(), [](auto &a,
                                        auto &b) { return a.first > b.first; });

    for (auto &pr: pairs) {
        perm.pb(pr.first);
        perm.pb(pr.second);
    }

    vector<bool> usados(n + 1, false);
    usados[q] = true;
    for (auto &pr: pairs) {
        usados[pr.second] = true;
        usados[pr.first] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (!usados[i]) {
            perm.pb(i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (i + 1 >= n) {
            cout << perm[i] << edl;
        } else {
            cout << perm[i] << " ";
        }
    }
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    sieve();
    int q = 1;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}

// By KaarLarax