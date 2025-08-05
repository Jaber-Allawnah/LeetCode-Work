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
    string smallest="~";

    void DFS(TreeNode* root,string path){
        if(root==NULL)
            return ;

        path+=char('a'+root->val);
        if (root->right==NULL&&root->left==NULL){
            string reversedpath=path;
            reverse(reversedpath.begin(),reversedpath.end());
            if(reversedpath<smallest){
                smallest=reversedpath;
            }
        }

        DFS(root->left,path);
        DFS(root->right,path);

    }

    string smallestFromLeaf(TreeNode* root) {
        DFS(root,"");
        return smallest;
    }   
};