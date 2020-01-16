class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        std::vector<int> ret_vector;
        std::map<int,int> value_index;
        for (int i = 0; i < numbers.size(); ++i)
        {
            const int gap = target - numbers[i];
            if (value_index.find(gap) != value_index.end())
            {
                ret_vector.push_back(std::min(i+1,value_index[gap]+1));
                ret_vector.push_back(std::max(i+1,value_index[gap]+1));
                break;
            }
            else
            {
                value_index[numbers[i]] = i; 
            }
        }
        return ret_vector;
    }
};