class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1 && target==nums[0]) return true;
        if(target==nums[0] || target==nums[n-1]) return true;
        int left = 1;
        int right = n-2;
        while(left<=right){
            int mid = left +(right-left)/2;
            if(nums[mid]==target) return true;
             if(nums[mid]==nums[right] && nums[mid]==nums[left]){
                left++;
                right--;
             }else if(nums[mid]>=nums[left]){
                if(target< nums[mid] && target>=nums[left]) right=mid-1;
                else left=mid+1;
            }else{
                if(target>nums[mid] && target<=nums[right]) {
                    left = mid+1;
                } else right = mid-1;
            }
        }
        return false;
    }
};