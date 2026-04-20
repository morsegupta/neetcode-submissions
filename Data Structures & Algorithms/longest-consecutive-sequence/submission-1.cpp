class Solution {
public:
    void removedupli(vector<int>& nums){
         if(nums.size() == 0) return;
         int idx = 0;
         for(int i = 1; i<nums.size(); i++){
            if(nums[i] != nums[idx]){
                idx++;
                nums[idx] = nums[i];
            }
         }
         nums.resize(idx+1);
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(), nums.end());
        removedupli(nums);
        int lcs = 1;
        int curr_lcs = 1;
        for(int i = 1; i<n; i++){
            if(nums[i] == nums[i-1]+1){
                curr_lcs++;
            }
            else{
                lcs = max(lcs, curr_lcs);
                curr_lcs = 1;
            }
        }
        return max(curr_lcs, lcs);
    }
};
