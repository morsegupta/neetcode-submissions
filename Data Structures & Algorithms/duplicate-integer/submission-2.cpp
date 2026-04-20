class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> st;
        for(int num: nums){
            if(st.find(num) != st.end()){
                continue;
            }
            st.insert(num);
        }
        if(st.size() == nums.size()) return false;
        return true;
    }
};