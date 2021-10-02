/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

bool cmp(pair<int, int>&a, pair<int, int>&b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return (a.second < b.second);
}
class Solution {
public:
    map<int, vector<pair<int, int>>> d;
    
    void find(TreeNode* root, int num, int height){
        
        if(root == NULL) return;
        d[num].push_back({root->val, height});
        
        find(root->left, num-1, height+1);
        find(root->right, num+1, height+1);
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        find(root, 0, 0);
        vector<vector<int>> ans;
        for(auto it: d){
            sort(it.second.begin(), it.second.end(), cmp);
            vector<int> temp;
            for(auto x: it.second){
                temp.push_back(x.first);
            }
            ans.push_back(temp);
        }
        return ans;
    }
    
};
