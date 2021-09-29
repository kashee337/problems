#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <cmath>

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;
bool check(vector<pair<ll,ll>> ab){

}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    int sz = N * 2;
    vector<int> tp(sz), com(sz, -1);
 
    bool ng = false;
 
    rep(i, N) {
        cin >> A[i] >> B[i];
        if (A[i] != -1) {
            --A[i];
            if (tp[A[i]]) ng = true;
            tp[A[i]] = i + 1;
        }
        if (B[i] != -1) {
            --B[i];
            if (tp[B[i]]) ng = true;
            tp[B[i]] = -(i + 1);
        }
 
        if (A[i] != -1 && B[i] != -1) {
            com[A[i]] = B[i];
            com[B[i]] = A[i];
        }
    }
    if (ng) {
        puts("No");
        return 0;
    }
 
    vector<bool> dp(sz + 1);
    dp[0] = true;
 
    rep(i, sz) {
        if (!dp[i]) continue;
        for (int j = i + 1; j < sz; ++j) {
            int w = j - i + 1;
            if (w & 1) continue;
            w /= 2;
            bool ok = true;
            vector<bool> exist(N);
 
            rep(k, w) {
                int p = i + k, q = i + k + w;
                if (com[p] != -1 && !(i <= com[p] && com[p] <= j)) {
                    ok = false;
                }
                if (com[q] != -1 && !(i <= com[q] && com[q] <= j)) {
                    ok = false;
                }
 
                bool same = true;
                if (tp[p] != 0 && tp[q] != 0) {
                    if (tp[p] < 0 || tp[p] + tp[q] != 0) {
                        ok = false;
                    } else
                        same = true;
                }
                if (tp[p] < 0 || tp[q] > 0) {
                    ok = false;
                } else {
                    if (tp[p] != 0) {
                        int v = tp[p] - 1;
                        if (exist[v]) {
                            ok = false;
                        }
                        exist[v] = true;
                    }
                    if (!same && tp[q] != 0) {
                        int v = -tp[q] - 1;
                        if (exist[v]) {
                            ok = false;
                        }
                        exist[v] = true;
                    }
                }
            }
            if (ok) {
                dp[j + 1] = true;
            }
        }
    }
    puts(dp[sz] ? "Yes" : "No");
 
    return 0;
}