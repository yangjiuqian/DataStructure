#include <iostream>
#include <vector>

// 交换两个元素的函数
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// 选择排序函数
void selectionSort(std::vector<int> &arr) {
    int n = arr.size();

    // 遍历整个数组
    for (int i = 0; i < n - 1; ++i) {
        // 找到未排序部分的最小元素的索引
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // 将找到的最小元素与当前位置的元素交换
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    std::vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();

    std::cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    // 调用选择排序函数
    selectionSort(arr);

    std::cout << "\nSorted array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
