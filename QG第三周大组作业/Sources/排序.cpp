#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include < stdbool.h >
#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <thread>
#include <vector>
#include <cstddef> 
using namespace std;
//插入排序(VHSertSort)
void VHSertSort(int arr[], int n)
{
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > temp; --j)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}

// 归并排序辅助函数
void merge(int arr[],int temp[] ,int left, int mid, int right) 
{
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];
	for (i = left; i <= right; i++)
		arr[i] = temp[i];
}
//归并排序（MergeSort）
void MergeSort(int arr[],int temp[],int left,int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort(arr, temp, left, mid);
		MergeSort(arr, temp, mid+1,right);
		merge(arr, temp, left, mid, right);
	}
}
//快速排序辅助函数
int Partition(int arr[], int left, int right)
{
	int temp = arr[left];
	while (left < right)
	{
		while (left < right && arr[right] >= temp)
			--right;
		arr[left] = arr[right];
		while (left < right && arr[left] <= temp)
			++left;
		arr[right] = arr[left];
	}
	arr[left] = temp;
	return left;
}
//快速排序（QuickSort）
void QuickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int pivotpos = Partition(arr, left, right);
		QuickSort(arr, left, pivotpos - 1);
		QuickSort(arr, pivotpos + 1, right);
	}
}
void show_arr(int arr[],int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
//计数排序（CountSort）
void CountSort(int arr[], int n) {
	// 1. 找出最大值和最小值
	int max = arr[0], min = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
	}

	// 2. 创建计数数组并初始化为0
	int range = max - min + 1;
	int* count = (int*)calloc(range, sizeof(int));

	// 3. 统计每个元素出现次数
	for (int i = 0; i < n; i++)
		count[arr[i] - min]++;

	// 4. 计算累计次数
	for (int i = 1; i < range; i++)
		count[i] += count[i - 1];

	// 5. 构建排序结果(反向遍历保证稳定性)
	int* output = (int*)malloc(n * sizeof(int));
	for (int i = n - 1; i >= 0; i--) {
		output[count[arr[i] - min] - 1] = arr[i];
		count[arr[i] - min]--;
	}

	// 6. 将结果拷贝回原数组
	for (int i = 0; i < n; i++)
		arr[i] = output[i];

	// 7. 释放内存
	free(count);
	free(output);
}
// 获取数组中最大数字的位数
int getMaxDigits(int arr[], int n) {
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) max = arr[i];
	}

	int digits = 0;
	while (max != 0) {
		digits++;
		max /= 10;
	}
	return digits;
}

// 基数排序（RadixCountSort）
void RadixCountSort(int arr[], int n) {
	int max_digits = getMaxDigits(arr, n);
	int exp = 1;  // 从个位开始

	int* output = (int*)malloc(n * sizeof(int));

	for (int d = 0; d < max_digits; d++) {
		int count[10] = { 0 };  // 十进制数字0-9

		// 统计当前位的数字出现次数
		for (int i = 0; i < n; i++)
			count[(arr[i] / exp) % 10]++;

		// 计算累计次数（确定位置）
		for (int i = 1; i < 10; i++)
			count[i] += count[i - 1];

		// 反向填充保证稳定性
		for (int i = n - 1; i >= 0; i--) {
			output[count[(arr[i] / exp) % 10] - 1] = arr[i];
			count[(arr[i] / exp) % 10]--;
		}

		// 将结果拷贝回原数组
		for (int i = 0; i < n; i++)
			arr[i] = output[i];

		exp *= 10;  // 处理下一位
	}

	free(output);
}

//生成随机数组
void generateRandomArray(int arr[], int n, int min_val, int max_val) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % (max_val - min_val + 1) + min_val;
	}
}

//复制数组
void copyArray(int src[], int dest[], int n) {
	for (int i = 0; i < n; i++) {
		dest[i] = src[i];
	}
}
//在大数据量下的测试
void test1()
{
	int sizes[] = { 10000, 50000, 200000 };
	int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
	for (int i = 0; i < num_sizes; i++)
	{
		int n = sizes[i];
		int* arr = (int*)malloc(n * sizeof(int));
		int* temp = (int*)malloc(n * sizeof(int));

		generateRandomArray(arr, n, 0, 100000);
		switch (i)
		{
		case 0:
			cout << "在10000数据层次下进行测试：" << endl;
			break;
		case 1:
			cout << "在50000数据层次下进行测试：" << endl;
			break;
		case 2:
			cout << "在200000数据层次下进行测试：" << endl;
			break;
		default:
			break;
		}
		// 测试插入排序
		copyArray(arr, temp, n);
		clock_t start = clock();
		VHSertSort(temp, n);
		clock_t end = clock();
		double time = (double)(end - start) / CLOCKS_PER_SEC;
		printf("插入排序\t");
		printf("%.3f\t", time);

		// 测试归并排序
		copyArray(arr, temp, n);
		int* tee = (int*)malloc(n * sizeof(int));
		start = clock();
		MergeSort(temp,tee, 0, n - 1);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		printf("\n归并排序\t");
		printf("%.3f\t", time);

		// 测试快速排序
		copyArray(arr, temp, n);
		start = clock();
		QuickSort(temp, 0, n - 1);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		printf("\n快速排序\t");
		printf("%.3f\t", time);

		// 测试计数排序
		copyArray(arr, temp, n);
		start = clock();
		CountSort(temp, n);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		printf("\n计数排序\t");
		printf("%.3f\t", time);

		// 测试基数排序
		copyArray(arr, temp, n);
		start = clock();
		RadixCountSort(temp, n);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		printf("\n基数排序\t");
		printf("%.3f\t", time);

		free(arr);
		free(temp);
		free(tee);
		cout << "\n";
	}
	printf("\n\n");

}
//在大量小数据下的测试
void test2()
{
	const int Frequency = 100000;
	
	int* arr = (int*)malloc(100 * sizeof(int));
	int* temp = (int*)malloc(100 * sizeof(int));

	generateRandomArray(arr, 100, 0, 100);

	//插入排序
	clock_t start = clock();
	for (int i = 0; i < Frequency; i++)
	{
		copyArray(arr, temp, 100);
		VHSertSort(temp, 100);
	}
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("插入排序：%.3f 秒\n", time);

	//归并排序
	start = clock();
	int* tee = (int*)malloc(100 * sizeof(int));
	for (int i = 0; i < Frequency; i++)
	{
		copyArray(arr, temp, 100);
		MergeSort(temp,tee,0, 99);
	}
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("归并排序：%.3f 秒\n", time);

	//快速排序
	start = clock();
	for (int i = 0; i < Frequency; i++)
	{
		copyArray(arr, temp, 100);
		QuickSort(temp, 0, 99);
	}
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("快速排序：%.3f 秒\n", time);

	//计数排序
	start = clock();
	for (int i = 0; i < Frequency; i++)
	{
		copyArray(arr, temp, 100);
		CountSort(temp, 100);
	}
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("计数排序：%.3f 秒\n", time);

	//基数排序
	start = clock();
	for (int i = 0; i < Frequency; i++)
	{
		copyArray(arr, temp, 100);
		RadixCountSort(temp, 100);
	}
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("基数排序：%.3f 秒\n", time);


	free(arr);
	free(temp);
	free(tee);
}
// 生成测试数据并保存到文件
void getTestDataToFile(const char* filename, int n, int min_val, int max_val) {
	FILE* file = fopen(filename, "w");//没有则创建文件
	if (file == NULL) {
		perror("打开文件失败");
		return;
	}

	fprintf(file, "%d\n", n);
	for (int i = 0; i < n; i++) {
		int num = rand() % (max_val - min_val + 1) + min_val;
		fprintf(file, "%d\n", num);
	}

	fclose(file);
	printf("已将随机数组写入 %s\n", filename);
}
void readAndSortFromFile(const char* filename, const char* output_filename) {
	// 1. 文件打开与检查
	FILE* file = fopen(filename, "r");
	if (file == NULL) 
	{
		fprintf(stderr, "无法打开文件 %s: %s\n", filename, strerror(errno));
		return;
	}

	// 2. 读取数组长度
	int n;
	if (fscanf(file, "%d", &n) != 1 || n <= 0)
	{
		fprintf(stderr, "无效的文件格式\n");
		fclose(file);
		return;
	}

	int* arr = (int*)malloc(n * sizeof(int));
	int* temp = (int*)malloc(n * sizeof(int));
	if (arr == NULL || temp == NULL) 
	{
		fprintf(stderr, "内存分配失败\n");
		fclose(file);
		free(arr); free(temp);
		return;
	}

	//将文件中的数组写入arr
	for (int i = 0; i < n; i++) {
		if (fscanf(file, "%d", &arr[i]) != 1) {
			fprintf(stderr, "数据读取错误\n");
			fclose(file);
			free(arr); free(temp);
			return;
		}
	}
	fclose(file);

	// 复制原始数组用于不同排序
	copyArray(arr, temp, n);

	// 测试插入排序
	clock_t start = clock();
	VHSertSort(temp, n);
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("插入排序：%.3f 秒\n", time);

	// 测试归并排序
	copyArray(arr, temp, n);
	int* tee = (int*)malloc(n * sizeof(int));
	start = clock();
	MergeSort(temp,tee,0, n - 1);
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("归并排序：%.3f 秒\n", time);
	free(tee);

	// 测试快速排序
	copyArray(arr, temp, n);
	start = clock();
	QuickSort(temp, 0, n - 1);
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("快速排序：%.3f 秒\n", time);

	// 测试计数排序
	copyArray(arr, temp, n);
	start = clock();
	CountSort(temp, n);
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("计数排序：%.3f 秒\n", time);

	// 测试基数排序
	copyArray(arr, temp, n);
	start = clock();
	RadixCountSort(temp, n);
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("基数排序：%.3f 秒\n", time);

	// 将排序后的结果保存到文件 (使用最后一次排序的结果)
	FILE* outfile = fopen(output_filename, "w");
	if (outfile == NULL) {
		perror("打开文件失败");
		free(arr);
		free(temp);
		return;
	}

	for (int i = 0; i < n; i++) {
		fprintf(outfile, "%d\n", temp[i]);
	}
	fclose(outfile);
	printf("将排序后的数组存入 %s\n", output_filename);

	free(arr);
	free(temp);
}


int main()
{
	//cout << "排序显示" << endl;
	//int arr1[] = {2,5,1,4,3};
	//int arr2[] = { 2,5,1,4,3 };
	//int arr3[] = { 2,5,1,4,3 };
	//int n = sizeof(arr1) / sizeof(arr1[0]);
	//int* temp = (int*)malloc(sizeof(int) * n);
	//show_arr(arr1,n);
	//VHSertSort(arr1, n);
	//MergeSort(arr2, temp, 0, n-1);
	//QuickSort(arr3, 0, n - 1);
	//show_arr(arr1, n);
	//show_arr(arr2, n);
	//show_arr(arr3, n);
	cout << "大量数据排序测试" << endl;
	test1();
	cout << "多次测试小数据"<<endl;
	test2();
	cout << "文件操作" << endl;
	getTestDataToFile("test_data.txt", 10000, 0, 100000);
	readAndSortFromFile("test_data.txt", "sorted_data.txt");
	return 0;
}