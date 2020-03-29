//logN + k 二分+双指针
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int count=0;
        int right=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int left=right-1;
        vector<int> res;
        while(count<k){
            if(right==arr.size()){
                res.push_back(arr[left--]);
            }
            else if(left==-1){
                res.push_back(arr[right++]);
            }
            else{
                int right_num=abs(arr[right]-x);
                int left_num=abs(arr[left]-x);
                if(left_num<=right_num){
                    res.push_back(arr[left--]);
                }
                else{
                    res.push_back(arr[right++]);
                }
            }
            count++;
        }
        sort(res.begin(),res.end());
        return res;
    }
};

//logN 窗口 二分
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int left = 0, right = arr.size() - k;
    while (left < right) {
        int mid = left + (right - left)/2;
        if (x - arr[mid] > arr[mid + k] - x ) 
            left = mid + 1;
        else 
            right = mid;
    }
    return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};