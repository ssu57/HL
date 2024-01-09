/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 5

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;
int is_empty(int stack[]) {
	return (top == -1);
}
int is_full(int stack[]) {
	return(top == (MAX_STACK_SIZE - 1));
}
int push(element item) {
	if (is_full(stack)) {
		printf("스택 포화\n");
		return;
	}
	else stack[++top] = item;
}
int pop(int stack[]) {
	if (is_empty(stack)) {
		printf("스택 공백\n");
		return;
	}
	else
		return (stack[top--]);
}
int menu() {
	printf("1. push\n");
	printf("2. pop\n");
	printf("3. end\n");
	printf("------------\n");
}
int main(void) {
	int a = 0;
	int item = 1;
	while (a!=3) {
		menu();
		printf("입력: ");
		scanf("%d", &a);
		if (a == 1) {
			push(item);
			printf("출력: %d\n", stack[top]);
			item++;
		}
		if (a == 2) {
			if(is_empty(stack))
			pop(stack);
			else {
				printf("출력: %d\n", pop(stack));
				item--;
			}
		}
		if (a == 3) {
			printf("종료\n");
			break;
		}
	}
	return 0;
}
//스택(stack)
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int Low[MAX_SIZE], High[MAX_SIZE], Mid[MAX_SIZE];
int top = -1;
void push(int low, int high, int mid) {
	if (top >= MAX_SIZE - 1) {
		printf("스택이 꽉 찼습니다.\n");
		return;
	}
	Low[++top] = low;
	High[top] = high;
	Mid[top] = mid;
}
int isStackEmpty() {
	return top == -1;
}
void pop(int* low, int* high, int* mid) {
	if (isStackEmpty()) {
		printf("스택 공백");
		*low = -1;
		*high = -1;
		*mid = -1;
		return;
	}
	*low = Low[top];
	*high = High[top];
	*mid = Mid[top];
	top--;
}
int binarySearch(int arr[], int n, int a) {
	push(0, n - 1, -1);
	while (!isStackEmpty()) {
		int low, high, mid;
		pop(&low, &high, &mid);

		if (mid == -1)
			mid = low + (high - low) / 2;
		if (low <= high) {
			if (arr[mid] == a)
				return mid;
			if (arr[mid] > a)
				push(low, mid - 1, -1);
			else
				push(mid + 1, high, -1);
		}
	}
	return -1;
}
int menu(int arr[], int n) {
	int a;
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("찾고싶은 값: ");
	scanf("%d", &a);
	return a;
}
int main() {
	int arr[] = { 2, 3, 4, 10, 21, 33, 45, 61, 78, 81 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int a = menu(arr, n);
	int result = binarySearch(arr, n, a);

	if (result != -1) {
		printf("원소 %d는 arr[%d]에 있습니다.\n", a, result);
	}
	else {
		printf("원소를 찾을 수 없습니다.\n");
	}
	return 0;
}