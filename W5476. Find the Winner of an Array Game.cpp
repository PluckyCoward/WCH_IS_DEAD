class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int res;
        int count = 0;
        int max = arr[0];
        if (k >= n) 
            return *max_element(arr.begin(), arr.end());
        int i = 1;
        while (count < k) {
            if (max < arr[i]) {
                arr.push_back(max);
                max = arr[i];
                count = 1;
            }
            else {
                arr.push_back(arr[i]);
                count++;n
            }
            i++;
        }
        return max;
        
    }
};