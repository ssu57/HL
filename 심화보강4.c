#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void quick_sort();
int main() {
	int arr[10] = { 10, 30, 22, 50, 20, 90, 83, 2, 6, 66 };
	quick_sort(arr, 0, 9);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
int partition(int* arr, int left, int right) {
	int pivot_index = left;
	int pivot = arr[pivot_index];
	int i = left + 1;
	int j = right;

	while (i <= j) {
		while (arr[i] < pivot&&i<=right) {
			i++;
		}
		while (arr[j] > pivot)
			j--;
		if (i < j) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	arr[left] = arr[j];
	arr[j] = pivot;
	return j;
}
void quick_sort(int* arr, int left, int right) {
	if (left < right) {
		int p = partition(arr, left, right);
		quick_sort(arr, left, p - 1);
		quick_sort(arr, p + 1, right);
	}
}
/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int A[18] = { 4, 9, 11, 24, 29, 30, 37, 38, 39, 49, 50, 54, 57, 63, 71, 76, 81, 87 };
	int target = 0;
	int low = 0, high = 17;
	printf("찾고싶은 숫자를 입력하세요: ");
	scanf("%d", &target);
	int ret_ve = binarySearch(A, low, high, target);
	printf("%d", ret_ve);

	return 0;
}
int binarySearch(int A[], int low, int high, int target) {
	while (low <= high) {
		int mid = (low + high) / 2;
		if (A[mid] == target)	return mid;
		if (A[mid] > target)	high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}
int binarySearchRecur(int A[], int low, int high, int target) {
	if (low > high)	return -1;
	int mid = (low + high) / 2;
	if (A[mid] == target)	return mid;
	if (A[mid] > target) {
		return binarySearchRecur(A, low, mid - 1, target);
	}
	return binarySearchRecur(A, mid + 1,high,target)
}
*/