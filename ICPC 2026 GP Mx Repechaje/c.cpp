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
using vvii = vector<map<int, int>>;

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

struct vertex {
    ll sum = 0;
    ll parent = 0;
    ll sons = 0;
};

vvii adj;
vector<vertex> ver;
ll bfs(int x, int papa) {
    ll sum = 0;
    ll sons = 0;
    for (auto &i: adj[x]) {
        if (i.first == papa) {
            continue;
        }
        sons++;
        ll sumson = (bfs(i.first, x) + (i.second * ver[i.first].sons));
        sum += i.second + sumson;
        ver[x].sons += ver[i.first].sons;
    }
    ver[x].parent = papa;
    ver[x].sons += sons;
    return ver[x].sum = sum;
}

int n;

void complete(int x, int papa) {
    for (auto &i : adj[x]) {
        if (i.first == papa) {
            continue;
        }
        ll completo = ver[x].sum;
        ll quitar = ver[i.first].sum;
        ll caminono = (ver[i.first].sons + 1) * adj[x][i.first];
        ll extranodos = n - (ver[i.first].sons + 1);
        ll caminosi = extranodos * adj[i.first][x];
        ll faltante = completo - (quitar  + caminono) + caminosi;
        ver[i.first].sum += faltante;
        complete(i.first, x);
    }
}

void solve() {
    cin >> n;
    adj.resize(n + 1);
    ver.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        ll v, u, a, b;
        cin >> v >> u >> a >> b;
        adj[v][u] = a;
        adj[u][v] = b;
    }
    bfs(1, 0);
    complete(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << ver[i].sum << ' ';
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