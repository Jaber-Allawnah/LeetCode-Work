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
    vector <string> final;
    void DFS(TreeNode* root,string path){
        if(!root) return ;
        if(root->right==NULL&&root->left==NULL){
            path+=to_string(root->val);
            final.push_back(path);
        }
        else{
            path=path+to_string(root->val)+"->";
            DFS(root->left,path);
            DFS(root->right,path);
        }
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        DFS(root,"");
        return final;
    }
};