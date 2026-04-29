// https://leetcode.com/problems/two-sum/description/
// leetcode two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> nums_indx;     // num: index
        vector<int> ans (2);

        for (int i = 0; i < nums.size(); i++) {
            nums_indx[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums_indx.count(target - nums[i]) && i != nums_indx[target - nums[i]]) {
                ans[0] = i; ans[1] = nums_indx[target - nums[i]];
                break;
            }
        }

        return ans;
    }
};


class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_indx;     // num: index
        vector<int> ans (2);

        for (int i = 0; i < nums.size(); i++) {
            num_indx[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (num_indx.contains(target - nums[i]) && i != num_indx[target - nums[i]]) {
                ans[0] = i; ans[1] = num_indx[target - nums[i]];
                break;
            }
        }

        return ans;
    }
};