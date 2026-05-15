class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        if(n==1) return nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                if(nums[i]==nums[n-1]){
                    ans=nums[0];
                }
            }
            
            else{
            ans= nums[i];
            break;
            }
        }
        return ans;
    }
};