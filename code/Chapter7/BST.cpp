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

// 递归插入函数
TreeNode* insertBST(TreeNode* root, int value) {
    // 如果树为空，直接插入新节点
    if (root == nullptr) {
        return new TreeNode(value);
    }

    // 如果插入值小于当前节点值，在左子树中插入
    if (value < root->data) {
        root->left = insertBST(root->left, value);
    }
    // 如果插入值大于当前节点值，在右子树中插入
    else if (value > root->data) {
        root->right = insertBST(root->right, value);
    }

    // 如果插入值等于当前节点值，不进行重复插入

    return root;
}

// 从数组构建二叉排序树
TreeNode* buildBSTFromArr(const int arr[], int n) {
    TreeNode* root = nullptr;

    for (int i = 0; i < n; ++i) {
        root = insertBST(root, arr[i]);
    }

    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// 查找二叉排序树中最小值节点
TreeNode* findMin(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// 递归删除函数
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
        return root;
    }

    // 如果要删除的节点在左子树
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    // 如果要删除的节点在右子树
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    // 如果找到要删除的节点
    else {
        // 节点只有一个子树或无子树
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // 节点有两个子树，找到中序遍历的后继节点
        TreeNode* temp = findMin(root->right);

        // 将后继节点的值复制给当前节点
        root->data = temp->data;

        // 删除后继节点
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
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
