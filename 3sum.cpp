class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int l=i+1,r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                //cout<<nums[i]<<" "<<nums[l]<<" "<<nums[r]<<"\n";
                if(sum>0){
                    r--;
                }else if(sum<0){
                    l++;
                }else{
                    vector<int>sub;
                    sub.push_back(nums[i]);
                    sub.push_back(nums[l]);
                    sub.push_back(nums[r]);
                    ans.push_back(sub);
                    while(l<n-1 && nums[l]==nums[l+1])l++;
                    while(r>=1 && nums[r]==nums[r-1])r--;
                    l++;
                    r--;
                }
                //cout<<"l and r "<<l<<" "<<r<<"\n";
            }
        }
        return ans;
    }
};
