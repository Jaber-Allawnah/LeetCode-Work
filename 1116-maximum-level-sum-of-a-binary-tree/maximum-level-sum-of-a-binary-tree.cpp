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
    vector <int> sums;
    queue <TreeNode*>q;
    int sum;
    void BFS(TreeNode* root ){
        if(!root)
            return;
        
        q.push(root);
        while(!q.empty()){
            sum=0;
            int levelSize=q.size();
            
            for(int i=0;i<levelSize;i++){
                TreeNode * node=q.front();
                q.pop();
                sum+=node->val;
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);

            }
            sums.push_back(sum);
        }

    }
    int maxLevelSum(TreeNode* root) {
        BFS(root);
        int min=*max_element(sums.begin(), sums.end());
        for(int i=0;i<sums.size();i++){
            if(sums[i]==min)
            return i+1;
        }
        return 0;
    }

};