class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        
        vector<int> ans(a.size()+ b.size());
        
        merge(a.begin(),a.end(), b.begin(), b.end(), ans.begin());
        
        int n = ans.size();
        
        if(n%2)
            return ans[n/2];
        else
            return (ans[n/2]+ans[(n/2)-1])/2.0;
        
        return 0;
        
    }
};
