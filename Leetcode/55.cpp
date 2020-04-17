class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int n=nums.size();
        if (n==1 || n==0) return true;
        for (int i=n-1;i>=0;i--){
            if (nums[i]) continue;
            int flag=0;
            for (int j=i-1;j>=0;j--){
                if (nums[j]>i-j || nums[j]>=i-j && i==n-1){
                    flag=1;
                    break;
                }
            }
            if (!flag) return false;
        }
        return true;
    }
};