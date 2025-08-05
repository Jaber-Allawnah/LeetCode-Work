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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL){
            return vector<int>(0);
        }
        vector <int> v;
        int maxval;
        queue <TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int currentSize=q.size();
            maxval=INT_MIN;
            for(int i=0;i<currentSize;i++){
               TreeNode* node=q.front();
               q.pop(); 
               maxval=max(maxval,node->val);
                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }
            v.push_back(maxval);
        }
        return v;
    }
};