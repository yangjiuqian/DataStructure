#include <iostream>
#include <vector>

// 交换两个元素的函数
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// 调整堆，使其满足堆的性质
void heapify(std::vector<int> &arr, int n, int i) {
    int largest = i;  // 初始化根节点为最大值
    int left = 2 * i + 1;  // 左子节点的索引
    int right = 2 * i + 2; // 右子节点的索引

    // 如果左子节点存在且大于根节点，则更新最大值索引
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // 如果右子节点存在且大于根节点，则更新最大值索引
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // 如果最大值索引不等于根节点索引，则交换根节点和最大值，并递归调整子树
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// 堆排序函数
void heapSort(std::vector<int> &arr) {
    int n = arr.size();

    // 构建最大堆
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    // 从堆中提取元素，每次提取最大值，并调整堆
    for (int i = n - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    std::cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    // 调用堆排序函数
    heapSort(arr);

    std::cout << "\nSorted array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
