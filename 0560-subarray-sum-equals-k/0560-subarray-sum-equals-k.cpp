class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int count = 0;
        int current_sum = 0;
        hash[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            current_sum += nums[i];
            if (hash.find(current_sum - k) != hash.end()) {
                count += hash[current_sum - k];
            }
            hash[current_sum]++;
        }
        return count;
    }
};