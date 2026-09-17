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

class NodeInfo{
public: 
    int size; bool isBalanced;
    NodeInfo(int size, bool isBalanced){
        this->size=size;
        this->isBalanced=isBalanced;
    }
};


class Solution {
public:

    NodeInfo helper(TreeNode* root, vector<int>&v) {
        if(!root)return NodeInfo(0,true);
        NodeInfo left=helper(root->left,v);
        NodeInfo right=helper(root->right,v);

        if(left.isBalanced && right.isBalanced && left.size==right.size){
            v.push_back(left.size+right.size+1);
        }
        return NodeInfo(left.size+right.size+1, (left.isBalanced && right.isBalanced && left.size==right.size));
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int>v;
        helper(root,v);
        sort(v.begin(), v.end(), greater<int>());
        for(int x: v)cout<<x<<" ";
        return k<=v.size() ? v[k-1] : -1;
    }
};