#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int dp[10001][2][2]; 
int main() {
        string s;
            cin >> s;
                int D;
                    cin >> D;

                            dp[0][0][0] = 1;
                                for (int i = 0; i < s.size(); i++) {
                                            for (int j = 0; j < 2; j++) {
                                                            for (int k = 0; k < D; k++) {
                                                                                for (int d = 0; d <= (j ? 9 : s[i] - '0'); d++) {
                                                                                                        dp[i + 1][j | (d < s[i] - '0')][(k + d) % D] += dp[i][j][k];
                                                                                                                            dp[i + 1][j | (d < s[i] - '0')][(k + d) % D] %= MOD;
                                                                                                                                            }
                                                                                            }
                                                                    }
                                                }
                                    cout << (dp[s.size()][0][0] + dp[s.size()][1][0] - 1 + MOD) % MOD << endl;
}
