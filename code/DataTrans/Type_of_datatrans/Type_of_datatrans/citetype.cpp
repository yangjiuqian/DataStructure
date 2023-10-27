#include<iostream>
void main() {
	int i = 5;
	int& j = i;
	i = 7;
	std::cout << "i=" << i << "j=" << j;
} 
/*引用类型做参数
引用变量表示所对应的参数的地址，相当于两个参数
*/