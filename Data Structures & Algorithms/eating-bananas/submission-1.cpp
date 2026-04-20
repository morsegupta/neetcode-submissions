class Solution {
public:
    int reqd(vector<int>& piles, int mid){
        long long ans = 0;
        for(int i = 0; i<piles.size(); i++){
            ans += ceil((double)piles[i]/mid);
        }
        return (int)ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = INT_MIN;
        for(int i = 0; i<n; i++){
            maxi = max(piles[i], maxi);
        }
        long long l = 1;
        long long r = maxi;
        while(l<=r){
            long long mid = (l + r)/2;
            long long totime = reqd(piles, mid);
            if(totime > h){
                l = mid+1; 
            }
            else r = mid-1;
        }
        return (int)l;
    }
};
