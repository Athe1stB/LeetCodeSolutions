class Solution {
public:
    void sortColors(vector<int>& v) {
        
        int n = v.size();
        int zero = 0, two = n-1, one = 0;
        
        while(one<=two)
        {
            if(v[one]==1)
                one++;
            
            else if(v[one]==0)
            {
                swap(v[one],v[zero]),
                zero++;
                one++;
            }
            
            else
            {
                swap(v[one],v[two]),
                two--;
            }
        }
    }
};
