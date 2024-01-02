#include <iostream>
#include <vector>

// 交换两个元素的函数
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// 根据选定的基准值将数组分成两部分，并返回基准值的索引
int partition(std::vector<int> &arr, int low, int high) {
    int pivot = arr[high];  // 选择数组最后一个元素作为基准值
    int i = low - 1;        // 初始化一个指针，指向小于等于基准值的区域的最后一个元素

    for (int j = low; j < high; ++j) {
        // 如果当前元素小于等于基准值，交换它与指针i所指向的元素
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // 最后将基准值交换到指针i之后的位置
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// 实现快速排序的递归函数
void quickSort(std::vector<int> &arr, int low, int high) {
    if (low < high) {
        // 划分数组，并获取基准值的索引
        int pivotIndex = partition(arr, low, high);

        // 递归地对基准值左右两侧的子数组进行排序
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    std::vector<int> arr = {12, 7, 3, 1, 8, 11, 2, 6};
    int n = arr.size();

    std::cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    // 调用快速排序函数
    quickSort(arr, 0, n - 1);

    std::cout << "\nSorted array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
