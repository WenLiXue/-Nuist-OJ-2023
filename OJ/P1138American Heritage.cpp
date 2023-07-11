#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};
// ����ǰ������������������������
TreeNode* buildTree(string preorder, string inorder, int pre_start, int pre_end, int in_start, int in_end, unordered_map<char, int>& in_map) {
    // ���ǰ���������Ϊ�գ�ֱ�ӷ��� NULL
    if (pre_start > pre_end) {
        return NULL;
    }
    // �������ڵ�
    char root_val = preorder[pre_start];
    TreeNode* root = new TreeNode(root_val);
    // ��������������в��Ҹ��ڵ��λ��
    int in_root = in_map[root_val];
    // �������ڵ����
    int left_size = in_root - in_start;
    // ����������
    root->left = buildTree(preorder, inorder, pre_start + 1, pre_start + left_size, in_start, in_root - 1, in_map);
    // ����������
    root->right = buildTree(preorder, inorder, pre_start + left_size + 1, pre_end, in_root + 1, in_end, in_map);
    return root;
}

// �������������
void postorderTraversal(TreeNode* root, string& res) {
    if (root == NULL) {
        return;
    }
    // ����������
    postorderTraversal(root->left, res);
    // ����������
    postorderTraversal(root->right, res);
    // �����ڵ��ֵ�������ַ�����
    res += root->val;
}

// ������
int main() {
    string inorder, preorder;
    cin >> inorder >> preorder;
    unordered_map<char, int> in_map;
    for (int i = 0; i < inorder.size(); i++) {
        in_map[inorder[i]] = i;
    }
    // ����������
    TreeNode* root = buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, in_map);
    // �������������
    string res;
    postorderTraversal(root, res);
    cout << res << endl;
    return 0;
}

