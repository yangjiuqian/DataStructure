#include <iostream>
#include <vector>

// 合并两个已排序的子数组
void merge(std::vector<int> &arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // 创建临时数组存储两个子数组
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    // 将数据复制到临时数组中
    for (int i = 0; i < n1; ++i) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArr[j] = arr[middle + 1 + j];
    }

    // 合并两个子数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    // 将剩余的元素复制到数组
    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

// 归并排序函数
void mergeSort(std::vector<int> &arr, int left, int right) {
    if (left < right) {
        // 计算中间索引，防止整数溢出
        int middle = left + (right - left) / 2;

        // 递归地对左右两个子数组进行排序
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // 合并已排序的子数组
        merge(arr, left, middle, right);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    std::cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    // 调用归并排序函数
    mergeSort(arr, 0, n - 1);

    std::cout << "\nSorted array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
