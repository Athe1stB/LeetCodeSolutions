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
class Solution {
public:
    
    void sumnum(TreeNode *root,vector<int> &arr,int i,int val){
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            val=(val*10)+root->val;
            cout << val <<endl;
            arr.push_back(val);
            return;
        }
        val=(val*10)+root->val;
        cout << val <<endl;
        sumnum(root->left,arr,i+1,val);
        sumnum(root->right,arr,i+1,val);
    }
    
    int sumNumbers(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        vector<int> arr;
        sumnum(root,arr,0,0);
        return accumulate(arr.begin(),arr.end(),0);
    }
};
