class Solution {
public:
    
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    vector<bool> vis;
    unordered_map<int, vector<int>> graph;
    int minEl = 1;
    
    void dfs(int ind, vector<int>&nums){
        
        vis[ind] = true;
        pq.push(nums[ind]);
        for(int node: graph[ind]){
            if(!vis[node]){
                dfs(node, nums);
            }
        }
        
    }
    
    int getEl(){
    
        while(!pq.empty() && pq.top() == minEl){
            pq.pop();
            minEl++;
        }
        return minEl;
    }
    
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        
        ans = vector<int>(nums.size(), 1);
        vis = vector<bool>(nums.size());
        
        for(int i=1;i<nums.size();i++){
            graph[parents[i]].push_back(i);
        }
        
        int t = 0;
        
        for(;t<nums.size();t++){ 
            if(nums[t] == 1) break;
        }
        if(nums[t] != 1) return ans;
        
        dfs(t, nums);
        ans[t] = getEl();
        t = parents[t];
        
        while(t != -1){
            dfs(t, nums);
            ans[t] = getEl();
            t = parents[t];
        }
            
        return ans;
        
    }
};
