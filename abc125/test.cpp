#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int main() {
    int A, B, C;
    cin >> A >> B >> C;
        // double dp[110][110][110];
    vector<vector<vector<double>>> dp(110,vector<vector<double>>(110,vector<double>(110,0)));
    // memset(dp, 0, sizeof(dp));
    for (int a = 99; a >= A; --a) {
        for (int b = 99; b >= B; --b) {
            for (int c = 99; c >= C; --c) {
                dp[a][b][c] += (double)(a)/(a+b+c) * (dp[a+1][b][c] + 1);
                dp[a][b][c] += (double)(b)/(a+b+c) * (dp[a][b+1][c] + 1);
                dp[a][b][c] += (double)(c)/(a+b+c) * (dp[a][b][c+1] + 1);
            }
        }
    }
    cout << fixed << setprecision(10) << dp[A][B][C] << endl;
}