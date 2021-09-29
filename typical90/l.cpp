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
template <typename T> struct UnionFind {
    vector<T> _parent;
    vector<T> _size;
    UnionFind(T N) : _parent(N), _size(N, (T)1) { rep(i, N) _parent[i] = i; }
    void init(T N) {
        _parent.resize(N);
        _size.assign(N, (T)1);
        rep(i, N) _parent[i] = i;
    }

    T root(T x) {
        if (_parent[x] == x) return x;
        return _parent[x] = root(_parent[x]);
    }

    T size(T x) { return _size[root(x)]; }
    bool same(T x, T y) {
        T rx = root(x);
        T ry = root(y);
        return rx == ry;
    }
    bool unite(T x, T y) {
        T rx = root(x);
        T ry = root(y);
        if (rx == ry) return false;
        if (_size[rx] < _size[ry]) swap(rx, ry);
        if (_size[rx] == _size[ry]) { _size[rx]++; }
        _parent[ry] = rx;
        return true;
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    vector<vector<bool>> maze(h, vector<bool>(w, false));

    int q;
    cin >> q;
    UnionFind<ll> uf(h * w);
    int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, -1, 0, 1};

    rep(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int r, c;
            cin >> r >> c;
            r--, c--;
            maze[r][c] = true;
            rep(i, 4) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
                if (maze[nr][nc]) { uf.unite(r * w + c, nr * w + nc); }
            }
        } else {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ra--, ca--, rb--, cb--;
            if (maze[ra][ca] && maze[rb][cb] && uf.same(ra * w + ca, rb * w + cb)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}