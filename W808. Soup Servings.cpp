//dp
class Solution {
public:
    vector<vector<double>> dp;

    double serve(int a, int b) {
        double res = 0;
        if (a <= 0)
            return b <= 0 ? 0.5 : 1;
        if (b <= 0)
            return 0;
        if (dp[a][b] > 0)
            return dp[a][b];
        res = (serve(a - 4, b) + serve(a - 3, b - 1) + serve(a - 2, b - 2) + serve(a - 1, b - 3)) / 4;
        dp[a][b] = res;
        return res;
    }

    double soupServings(int N) {
        if (N >= 6000)
            return 1;
        int n = N / 25 + (N % 25 > 0 ? 1 : 0);
        dp = vector(n + 1, vector<double>(n + 1, 0));
        return serve(n, n);
    }
};