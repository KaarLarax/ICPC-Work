// BY LARA 1424
// https://codeforces.com/profile/DarkoLaraSlowed
// https://github.com/KaarLarax
// https://www.youtube.com/@KaarLarax

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<long long>;
using vull = vector<ull>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vii = vector<pii>;
using vvi = vector<vi>;
using vvll = vector<vll>;

#define mp make_pair
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

constexpr int64_t LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr array<int, 4> dx{1, 0, -1, 0};
constexpr array<int, 4> dy{0, 1, 0, -1};

// Main funtion
int main() {
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        vector<vi> arr(n, vi(m));
        int orden[n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> arr[i][j];
                if (arr[i][j] < n) {
                    orden[arr[i][j]] = i + 1;
                }
            }
        }
        vector<vi> arr2 = arr;
        for (int i = 0; i < n; ++i) {
            sort(all(arr2[i]));
        }
        std::sort(arr2.begin(), arr2.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });
        bool band = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (arr2[i][0] != arr2[i][j] - (j * n)) {
                    band = false;
                    break;
                }
            }
            if (!band) {
                break;
            }
        }
        if (band) {
            for (int i = 0; i < n; ++i) {
                cout << orden[i] << ' ';
            }
            cout << edl;
        } else {
            cout << -1 << edl;
        }
    }
    return 0;
}