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
    vll arr(n);
    for (auto &i : arr) {
        cin >> i;
    }

    int l = 0, r = n - 1;
    ll curr = 0;
    int ans = 0;
    string s;
    while (l <= r) {
        bool ri = curr < arr[r];
        bool li = curr < arr[l];

        if (!ri && !li) {
            break;
        }

        if ((arr[l] < arr[r] && li) || !ri) {
            s += 'L';
            curr = arr[l];
            l++;
            ans++;
        } else if ((arr[l] > arr[r] && ri) || !li) {
            s += 'R';
            curr = arr[r];
            r--;
            ans++;
        } else {
            ll ant = arr[l];

            int l1 = l + 1;

            while (l1 <= r && arr[l1] > ant) {
                ant = arr[l1];
                l1++;
            }

            ant = arr[r];

            int r1 = r - 1;

            while (l <= r1 && arr[r1] > ant) {
                ant = arr[r1];
                r1--;
            }

            if (abs(l - l1) > abs(r - r1)) {
                for (int i = 0; i < abs(l - l1); i++) {
                    s += 'L';
                }
                ans += abs(l - l1);
            } else {
                for (int i = 0; i < abs(r - r1); i++) {
                    s += 'R';
                }
                ans += abs(r - r1);
            }

            break;
        }
    }
    cout << ans << edl;
    cout << s << edl;
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