#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};
// 根据前序遍历和中序遍历构建二叉树
TreeNode* buildTree(string preorder, string inorder, int pre_start, int pre_end, int in_start, int in_end, unordered_map<char, int>& in_map) {
    // 如果前序遍历序列为空，直接返回 NULL
    if (pre_start > pre_end) {
        return NULL;
    }
    // 构建根节点
    char root_val = preorder[pre_start];
    TreeNode* root = new TreeNode(root_val);
    // 在中序遍历序列中查找根节点的位置
    int in_root = in_map[root_val];
    // 左子树节点个数
    int left_size = in_root - in_start;
    // 构建左子树
    root->left = buildTree(preorder, inorder, pre_start + 1, pre_start + left_size, in_start, in_root - 1, in_map);
    // 构建右子树
    root->right = buildTree(preorder, inorder, pre_start + left_size + 1, pre_end, in_root + 1, in_end, in_map);
    return root;
}

// 后序遍历二叉树
void postorderTraversal(TreeNode* root, string& res) {
    if (root == NULL) {
        return;
    }
    // 遍历左子树
    postorderTraversal(root->left, res);
    // 遍历右子树
    postorderTraversal(root->right, res);
    // 将根节点的值加入结果字符串中
    res += root->val;
}

// 主函数
int main() {
    string inorder, preorder;
    cin >> inorder >> preorder;
    unordered_map<char, int> in_map;
    for (int i = 0; i < inorder.size(); i++) {
        in_map[inorder[i]] = i;
    }
    // 构建二叉树
    TreeNode* root = buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, in_map);
    // 后序遍历二叉树
    string res;
    postorderTraversal(root, res);
    cout << res << endl;
    return 0;
}

