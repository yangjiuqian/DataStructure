#include <iostream>
#include <vector>

// 二分查找函数
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // 检查中间元素是否是目标值
        if (arr[mid] == target) {
            return mid;  // 目标值找到，返回索引
        } else if (arr[mid] < target) {
            left = mid + 1;  // 目标值可能在右半部分
        } else {
            right = mid - 1;  // 目标值可能在左半部分
        }
    }

    return -1;  // 目标值不在数组中
}

int main() {
    // 测试二分查找
    std::vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;

    int result = binarySearch(sortedArray, target);

    if (result != -1) {
        std::cout << "target" << target << " in the arrey, index is " << result << std::endl;
    } else {
        std::cout << "target" << target << " is not in the arrey" << std::endl;
    }

    return 0;
}
