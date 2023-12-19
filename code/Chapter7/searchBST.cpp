#include <iostream>

// 定义二叉树节点结构
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// 递归查找函数
TreeNode* searchBST(TreeNode* root, int target) {
    // 如果树为空或者找到目标值，返回当前节点
    if (root == nullptr || root->data == target) {
        return root;
    }

    // 如果目标值小于当前节点值，在左子树中继续查找
    if (target < root->data) {
        return searchBST(root->left, target);
    }
    // 如果目标值大于当前节点值，在右子树中继续查找
    else {
        return searchBST(root->right, target);
    }
}

// 测试
int main() {
    // 构建一个简单的二叉排序树
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // 在二叉排序树中查找目标值
    int target = 4;
    TreeNode* result = searchBST(root, target);

    // 输出结果
    if (result != nullptr) {
        std::cout << "找到目标值 " << target << "。" << std::endl;
    } else {
        std::cout << "未找到目标值 " << target << "。" << std::endl;
    }

    // 释放内存
    // 注意：在实际应用中，可能需要实现一个释放二叉树节点的函数
    // 这里简化，略过释放节点的部分
    return 0;
}
