//dp
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
	    if (n == 0) 
            return 0;
	    unordered_map<int, int> map;
	    for (int i = 0; i < n; i++) {
		    map[A[i]] = i;
	    }
	    vector<vector<int>> dp(n, vector<int>(n, 0));
	    for (int i = 0; i < n; i++) {
		    for (int j = i + 1; j < n; j++) {
			    dp[i][j] = 2;
		    }
	    }
	    int res = 0;

	    for (int i = 0; i < n; i++) {
		    for (int j = i + 1; j < n; j++) {
			    int diff = A[j] - A[i];
			    if (map.count(diff)) {
				    int index = map[diff];
				    if (index < i) {
					    dp[i][j] = max(dp[i][j], dp[index][i] + 1);
				    }
			    }
			    res = max(res, dp[i][j]);
		    }
	    }

	    return res > 2 ? res : 0;
    }
};