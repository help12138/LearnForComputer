// STLDemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "count.h"



int randomArr(int* nums, int index) {
	// 随机获取元素值
	int randomNum = rand() % index;
	int result = nums[randomNum];
	return result;
}

void insert(int* nums, int size, int num, int index) {
	// 在index位置插入num, index之后的数据都要后移一位
	for (int i = size - 1; i > index; i--) {
		nums[i] = nums[i - 1];
	}
	nums[index] = num;

}

void remove(int* nums, int size, int index) {
	// 删除指定位置的元素, 则元素后面的数据都要前移一位
	for (int i = index; i < size; i++)
	{
		nums[i] = nums[i + 1];
	}
}

// 扩展原数组内存
int* extend(int* nums, int size, int addLen) {
	int* res = new int[size + addLen];
	for (int i = 0; i < size; i++) {
		res[i] = nums[i];
	}
	delete[] nums;
	// 扩展后返回新数组
	return res;
}
