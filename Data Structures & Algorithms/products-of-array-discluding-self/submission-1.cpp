class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int zeroes_cnt = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == 0) zeroes_cnt++;
        }
        vector<int> arr(n, 0);
        if(zeroes_cnt >=2) return arr;
        else if(zeroes_cnt == 1){
            int prod = 1;
            int zero_i = -1;
            for(int i = 0; i<n; i++){
                if(nums[i] == 0){
                    zero_i = i;
                }
                else{
                    prod *= nums[i];
                }
            }
            arr[zero_i] = prod;
            return arr;
        }
        arr[0] = 1;
        for(int i = 1; i<n; i++){
            arr[i] = arr[i-1]*nums[i-1];
        }
        int suffix = 1;
        for(int i = n-1; i>=0; i--){
            arr[i] *= suffix;
            suffix *= nums[i];
        }

        return arr;
    }
};
