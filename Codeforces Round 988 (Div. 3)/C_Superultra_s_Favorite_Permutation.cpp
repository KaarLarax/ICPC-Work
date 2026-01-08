// BY LARA 1424
// https://codeforces.com/profile/DarkoLaraSlowed
// https://github.com/KaarLarax
// https://www.youtube.com/@KaarLarax

#include <bits/stdc++.h>

// Namespaces
using namespace std;

// Typedefs
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vii = vector<pii>;
using vvi = vector<vi>;
using vvll = vector<vll>;

// Macros
#define debug(x) cerr << #x << " = " << x << '\n'
#define mp make_pair
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

// Macros para iteraciones
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define repr(i, a, b) for(int i = a; i >= b; --i)
#define each(x, a) for(auto &x : a)

// Utility Functions
template<class T>
bool chmax(T &A, T &&B) { return B > A ? A = B, true : false; }

template<class T>
bool chmin(T &A, T &&B) { return B < A ? A = B, true : false; }

template<typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

template<typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<typename T>
void debug_vector(vector<T> &v) {
    cerr << "[ ";
    for (T &x: v) cerr << x << " ";
    cerr << "]" << edl;
}

// Constants
constexpr int64_t LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr array<int, 4> dx{1, 0, -1, 0};
constexpr array<int, 4> dy{0, 1, 0, -1};

// Funciones de entrada/salida
template<typename T>
void read(T &x) { cin >> x; }

template<typename T>
void read(vector<T> &v) { for (T &x : v) cin >> x; }

template<typename T>
void write(const T &x) { cout << x << '\n'; }

template<typename T>
void write_vector(const vector<T> &v) {
    for (const T &x : v) cout << x << ' ';
    cout << '\n';
}

// sieve of eratosthenes
bool boleansieve[MxN];
void sieve() {
    for (int i = 2; i * i <= MxN; ++i) {
        if (!boleansieve[i]) {
            for (int j = i * i; j <= MxN; j += i) {
                boleansieve[j] = true;
            }
        }
    }
}
// Main funtion
int32_t main() {
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    sieve();
    int m;
    read(m);
    while (m--) {
        int n;
        read(n);
        int aux;
        vi si;
        for (int i = 1; i <= n; i += 2) {
            si.pb(i);
            aux = i;
        }
        bool band = false;
        vi sobrantes;
        for (int i = 2; i <= n; i += 2) {
            if (boleansieve[aux + i]) {
                band = true;
                for (int j = i; j <= n; j += 2) {
                    si.pb(j);
                }
                break;
            } else {
                sobrantes.pb(i);
            }
        }
        if (!band) {
            cout << -1 << edl;
        } else {
            for (auto c: si) {
                cout << c << ' ';
            }
            for (auto c: sobrantes) {
                cout << c << ' ';
            }
            cout << edl;
        }
    }
    return 0;
}