#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 3e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int val = 0;
    int ansl = 0, ansr = 0;

    for(int i = 0; i < n; i++){
        int aux = 0;
        for (int j = i + 1; j < n; j++){
            if(a[j] < a[i]) {
                aux++;
            } else if(a[j] > a[i]) {
                aux--;
            }

            if(aux > val){
                val = aux;
                ansl = i;
                ansr = j;
            }
        }
    }

    cout << ansl + 1 << " " << ansr + 1 << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int q = 1;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}

// By KaarLarax