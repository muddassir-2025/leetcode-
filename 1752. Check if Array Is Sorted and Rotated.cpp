class Solution {
public:
    bool check(vector<int>& nums) {
        // ascending sort nums[i]>nums[i-1]
        int n=nums.size();
        int st=0;
        int end=n-1;
        
        int stop=-1;
        
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){ //pattern changed
                stop=i;
                break;
            }
        }
        
        if(stop==-1) return true;
        
        for(int i=1;i<stop;i++){
            if(nums[i]>=nums[i-1]){ //>= because there can be duplicates eg : 5 5 5 - ok skip
                continue;
            }
            else{
                return false;
            }
        }
        
        for(int i=stop+1;i<n;i++){
            if(nums[i]>=nums[i-1]){
                continue;
            }
            else{
                return false;
            }
        }
        
        return nums[n-1]<=nums[0]; // <= because duplicates can be there 1 1 1 1 1 - sorted
    }
};