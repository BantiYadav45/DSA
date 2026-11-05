
class Solution {
public:

    void getallsubsets(vector<int>& nums, vector<int>& ans,int i, vector<vector<int>>& allsubsets) {
                       

        if (i == nums.size()) {
            allsubsets.push_back(ans);
            return;
        }

        // Include current element
        ans.push_back(nums[i]);

        getallsubsets(nums, ans, i + 1, allsubsets);

        // Backtracking
        ans.pop_back();

        // Skip duplicate elements
        int idx = i + 1;

        while (idx < nums.size() && nums[idx] == nums[i]) {
            idx++;
        }

        // Exclude current element
        getallsubsets(nums, ans, idx, allsubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> allsubsets;
        vector<int> ans;

        getallsubsets(nums, ans, 0, allsubsets);

        return allsubsets;
    }
};
