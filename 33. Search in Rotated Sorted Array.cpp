class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n=nums.size();
        int st=0;
        int end=n-1;
        
        while (st<=end){
            
            int mid=st+(end-st)/2;
            
            if(nums[mid]==target) return mid;
            
            if(nums[st]<=nums[mid]){ //left half sorted
                if(target>=nums[st] && target < nums[mid]){
                    end=mid-1;
                }
                else{
                    st=mid +1;
                }
            }
            
            else{
                if(target>nums[mid] && target <= nums[end]){
                     st=mid +1;
                }
                else{
                    end=mid-1;
                }
            }
            
        }
        
        return -1;
    }
};

//why >= Because target itself can be at st.
//why<= Because target itself can be at end 
//why not = for mid : we return when it is..
