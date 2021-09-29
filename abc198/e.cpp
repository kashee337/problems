#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n, s) for (int i = (s); i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define rreps(i, n, s) for (int i = s; i >= n; i--)

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> c(n);
    vector<vector<ll>> G(n);
    rep(i, n) cin >> c[i];
    rep(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    //現在居る頂点と、そこに至るまでに消費した色をメモするunorder_mapをqueueで保持する
    queue<pair<ll, unordered_map<ll, ll>>> q;

    unordered_map<ll, ll> _past;
    vector<bool> used(n, false);
    q.push({0, _past});

    vector<ll> res;

    // BFS
    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        ll crr = v.first;
        unordered_map<ll, ll> past = v.second;
        used[crr] = true;

        //一度も使ってない色ならば良い頂点とする
        if (past[c[crr]] == 0) res.push_back(crr + 1);
        past[c[crr]]++;

        for (auto next : G[crr]) {
            if (used[next]) continue;
            q.push({next, past});
        }
    }

    for (auto v : res) cout << v << endl;
    return 0;
}
