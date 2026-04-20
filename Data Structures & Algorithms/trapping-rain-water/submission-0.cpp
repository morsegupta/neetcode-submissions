class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int maxleft = 0;
        int maxright = 0;
        int tot =0;
        while(l<r){
            if(height[l] <= height[r]){
                if(height[l] >= maxleft){
                    maxleft = height[l];
                }
                else{
                    tot += maxleft-height[l];
                }
                l++;
            }
            else{
                if(height[r] >= maxright){
                    maxright = height[r];
                }
                else{
                    tot += maxright-height[r];
                }
                r--;
            }
        }
        return tot;
    }
};
