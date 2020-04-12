/*
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //解法一，递归
        if (preorder.size() == 0 || inorder.size() == 0) {
            return NULL;
        }
        // int root = preorder.at(0);
        // TreeNode *treeNode = new TreeNode(root);
        // int mid = distance(begin(inorder), find(inorder.begin(), inorder.end(), preorder[0]));
        // vector<int> left_pre(preorder.begin() + 1, preorder.begin() + mid + 1);
        // vector<int> right_pre(preorder.begin() + mid + 1, preorder.end());
        // vector<int> left_in(inorder.begin(), inorder.begin() + mid);
        // vector<int> right_in(inorder.begin() + mid + 1, inorder.end());
        
        // treeNode->left  = buildTree(left_pre,left_in);
        // treeNode->right = buildTree(right_pre,right_in);

        // return treeNode;

        //解法二，递归用迭代器
        // return recursionBuild(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());

        //解法三，栈
        int tSize = preorder.size();
        if (tSize == 0) return nullptr;

        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);
        
        stack<TreeNode*> s;
        s.push(root);

        for (int pIndex = 1, iIndex = 0; pIndex < tSize; ++pIndex) {
            TreeNode* tmp = nullptr;
            while (! s.empty() && s.top()->val == inorder[iIndex]) {
                ++iIndex;
                tmp = s.top();
                s.pop();
            }
            TreeNode* cur = new TreeNode(preorder[pIndex]);
            if (tmp == nullptr) s.top()->left = cur;
            else tmp->right = cur;
            s.push(cur);
        }
        return root;
    }

    // 解法二，递归用迭代器
    TreeNode* recursionBuild(vector<int>::iterator preBegin, vector<int>::iterator preEnd,vector<int>::iterator inBegin, vector<int>::iterator inEnd ){
        if (inEnd == inBegin) {
            return NULL;
        }
        TreeNode *current = new TreeNode(preBegin[0]);
        auto root = find(inBegin,inEnd,preBegin[0]);
        current->left  = recursionBuild(preBegin+1,preBegin+1+(root - inBegin),inBegin,root);
        current->right = recursionBuild(preBegin+1+(root - inBegin),preEnd,root+1,inEnd);

        return current;
    }
};
