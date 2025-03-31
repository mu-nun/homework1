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
//��������(VHSertSort)
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

// �鲢����������
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
//�鲢����MergeSort��
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
//��������������
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
//��������QuickSort��
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
//��������CountSort��
void CountSort(int arr[], int n) {
	// 1. �ҳ����ֵ����Сֵ
	int max = arr[0], min = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
	}

	// 2. �����������鲢��ʼ��Ϊ0
	int range = max - min + 1;
	int* count = (int*)calloc(range, sizeof(int));

	// 3. ͳ��ÿ��Ԫ�س��ִ���
	for (int i = 0; i < n; i++)
		count[arr[i] - min]++;

	// 4. �����ۼƴ���
	for (int i = 1; i < range; i++)
		count[i] += count[i - 1];

	// 5. ����������(���������֤�ȶ���)
	int* output = (int*)malloc(n * sizeof(int));
	for (int i = n - 1; i >= 0; i--) {
		output[count[arr[i] - min] - 1] = arr[i];
		count[arr[i] - min]--;
	}

	// 6. �����������ԭ����
	for (int i = 0; i < n; i++)
		arr[i] = output[i];

	// 7. �ͷ��ڴ�
	free(count);
	free(output);
}
// ��ȡ������������ֵ�λ��
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

// ��������RadixCountSort��
void RadixCountSort(int arr[], int n) {
	int max_digits = getMaxDigits(arr, n);
	int exp = 1;  // �Ӹ�λ��ʼ

	int* output = (int*)malloc(n * sizeof(int));

	for (int d = 0; d < max_digits; d++) {
		int count[10] = { 0 };  // ʮ��������0-9

		// ͳ�Ƶ�ǰλ�����ֳ��ִ���
		for (int i = 0; i < n; i++)
			count[(arr[i] / exp) % 10]++;

		// �����ۼƴ�����ȷ��λ�ã�
		for (int i = 1; i < 10; i++)
			count[i] += count[i - 1];

		// ������䱣֤�ȶ���
		for (int i = n - 1; i >= 0; i--) {
			output[count[(arr[i] / exp) % 10] - 1] = arr[i];
			count[(arr[i] / exp) % 10]--;
		}

		// �����������ԭ����
		for (int i = 0; i < n; i++)
			arr[i] = output[i];

		exp *= 10;  // ������һλ
	}

	free(output);
}

//�����������
void generateRandomArray(int arr[], int n, int min_val, int max_val) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % (max_val - min_val + 1) + min_val;
	}
}

//��������
void copyArray(int src[], int dest[], int n) {
	for (int i = 0; i < n; i++) {
		dest[i] = src[i];
	}
}
//�ڴ��������µĲ���
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
			cout << "��10000���ݲ���½��в��ԣ�" << endl;
			break;
		case 1:
			cout << "��50000���ݲ���½��в��ԣ�" << endl;
			break;
		case 2:
			cout << "��200000���ݲ���½��в��ԣ�" << endl;
			break;
		default:
			break;
		}
		// ���Բ�������
		copyArray(arr, temp, n);
		clock_t start = clock();
		VHSertSort(temp, n);
		clock_t end = clock();
		double time = (double)(end - start) / CLOCKS_PER_SEC;
		printf("��������\t");
		printf("%.3f\t", time);

		// ���Թ鲢����
		copyArray(arr, temp, n);
		int* tee = (int*)malloc(n * sizeof(int));
		start = clock();
		MergeSort(temp,tee, 0, n - 1);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		printf("\n�鲢����\t");
		printf("%.3f\t", time);

		// ���Կ�������
		copyArray(arr, temp, n);
		start = clock();
		QuickSort(temp, 0, n - 1);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		printf("\n��������\t");
		printf("%.3f\t", time);

		// ���Լ�������
		copyArray(arr, temp, n);
		start = clock();
		CountSort(temp, n);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		printf("\n��������\t");
		printf("%.3f\t", time);

		// ���Ի�������
		copyArray(arr, temp, n);
		start = clock();
		RadixCountSort(temp, n);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		printf("\n��������\t");
		printf("%.3f\t", time);

		free(arr);
		free(temp);
		free(tee);
		cout << "\n";
	}
	printf("\n\n");

}
//�ڴ���С�����µĲ���
void test2()
{
	const int Frequency = 100000;
	
	int* arr = (int*)malloc(100 * sizeof(int));
	int* temp = (int*)malloc(100 * sizeof(int));

	generateRandomArray(arr, 100, 0, 100);

	//��������
	clock_t start = clock();
	for (int i = 0; i < Frequency; i++)
	{
		copyArray(arr, temp, 100);
		VHSertSort(temp, 100);
	}
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("��������%.3f ��\n", time);

	//�鲢����
	start = clock();
	int* tee = (int*)malloc(100 * sizeof(int));
	for (int i = 0; i < Frequency; i++)
	{
		copyArray(arr, temp, 100);
		MergeSort(temp,tee,0, 99);
	}
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("�鲢����%.3f ��\n", time);

	//��������
	start = clock();
	for (int i = 0; i < Frequency; i++)
	{
		copyArray(arr, temp, 100);
		QuickSort(temp, 0, 99);
	}
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("��������%.3f ��\n", time);

	//��������
	start = clock();
	for (int i = 0; i < Frequency; i++)
	{
		copyArray(arr, temp, 100);
		CountSort(temp, 100);
	}
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("��������%.3f ��\n", time);

	//��������
	start = clock();
	for (int i = 0; i < Frequency; i++)
	{
		copyArray(arr, temp, 100);
		RadixCountSort(temp, 100);
	}
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("��������%.3f ��\n", time);


	free(arr);
	free(temp);
	free(tee);
}
// ���ɲ������ݲ����浽�ļ�
void getTestDataToFile(const char* filename, int n, int min_val, int max_val) {
	FILE* file = fopen(filename, "w");//û���򴴽��ļ�
	if (file == NULL) {
		perror("���ļ�ʧ��");
		return;
	}

	fprintf(file, "%d\n", n);
	for (int i = 0; i < n; i++) {
		int num = rand() % (max_val - min_val + 1) + min_val;
		fprintf(file, "%d\n", num);
	}

	fclose(file);
	printf("�ѽ��������д�� %s\n", filename);
}
void readAndSortFromFile(const char* filename, const char* output_filename) {
	// 1. �ļ�������
	FILE* file = fopen(filename, "r");
	if (file == NULL) 
	{
		fprintf(stderr, "�޷����ļ� %s: %s\n", filename, strerror(errno));
		return;
	}

	// 2. ��ȡ���鳤��
	int n;
	if (fscanf(file, "%d", &n) != 1 || n <= 0)
	{
		fprintf(stderr, "��Ч���ļ���ʽ\n");
		fclose(file);
		return;
	}

	int* arr = (int*)malloc(n * sizeof(int));
	int* temp = (int*)malloc(n * sizeof(int));
	if (arr == NULL || temp == NULL) 
	{
		fprintf(stderr, "�ڴ����ʧ��\n");
		fclose(file);
		free(arr); free(temp);
		return;
	}

	//���ļ��е�����д��arr
	for (int i = 0; i < n; i++) {
		if (fscanf(file, "%d", &arr[i]) != 1) {
			fprintf(stderr, "���ݶ�ȡ����\n");
			fclose(file);
			free(arr); free(temp);
			return;
		}
	}
	fclose(file);

	// ����ԭʼ�������ڲ�ͬ����
	copyArray(arr, temp, n);

	// ���Բ�������
	clock_t start = clock();
	VHSertSort(temp, n);
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("��������%.3f ��\n", time);

	// ���Թ鲢����
	copyArray(arr, temp, n);
	int* tee = (int*)malloc(n * sizeof(int));
	start = clock();
	MergeSort(temp,tee,0, n - 1);
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("�鲢����%.3f ��\n", time);
	free(tee);

	// ���Կ�������
	copyArray(arr, temp, n);
	start = clock();
	QuickSort(temp, 0, n - 1);
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("��������%.3f ��\n", time);

	// ���Լ�������
	copyArray(arr, temp, n);
	start = clock();
	CountSort(temp, n);
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("��������%.3f ��\n", time);

	// ���Ի�������
	copyArray(arr, temp, n);
	start = clock();
	RadixCountSort(temp, n);
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("��������%.3f ��\n", time);

	// �������Ľ�����浽�ļ� (ʹ�����һ������Ľ��)
	FILE* outfile = fopen(output_filename, "w");
	if (outfile == NULL) {
		perror("���ļ�ʧ��");
		free(arr);
		free(temp);
		return;
	}

	for (int i = 0; i < n; i++) {
		fprintf(outfile, "%d\n", temp[i]);
	}
	fclose(outfile);
	printf("��������������� %s\n", output_filename);

	free(arr);
	free(temp);
}


int main()
{
	//cout << "������ʾ" << endl;
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
	cout << "���������������" << endl;
	test1();
	cout << "��β���С����"<<endl;
	test2();
	cout << "�ļ�����" << endl;
	getTestDataToFile("test_data.txt", 10000, 0, 100000);
	readAndSortFromFile("test_data.txt", "sorted_data.txt");
	return 0;
}