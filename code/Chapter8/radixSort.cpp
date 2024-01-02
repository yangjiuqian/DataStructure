#include <iostream>
#include <vector>

// 获取数组中最大值
int getMax(std::vector<int> &arr) {
    int max = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 对数组按照指定的位数进行计数排序
void countSort(std::vector<int> &arr, int exp) {
    const size_t n = arr.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    // 统计当前位数的每个数字的出现次数
    for (size_t i = 0; i < n; ++i) {
        count[(arr[i] / exp) % 10]++;
    }

    // 计算累计次数，以便在输出中确定每个元素的位置
    for (size_t i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // 从后向前遍历原始数组，将元素放入输出数组中的正确位置
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // 将输出数组复制回原始数组
    for (size_t i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

// 基数排序函数
void radixSort(std::vector<int> &arr) {
    // 获取数组中的最大值
    int max = getMax(arr);

    // 对每个位数进行计数排序
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    size_t n = arr.size();

    std::cout << "Original array: ";
    for (size_t i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    // 调用基数排序函数
    radixSort(arr);

    std::cout << "\nSorted array: ";
    for (size_t i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
