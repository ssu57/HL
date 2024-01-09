#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define DUF 20
#define GOD 7
void scoreStu();
void total();
void sortgg();
void pt();

void scoreStu(double a[][GOD]) {
	srand(time(NULL));
	for (int i = 0; i < DUF; i++) {//점수
		a[i][0] = i + 1;;
		for (int j = 1; j < GOD - 1; j++) {
			a[i][j] = 1 + rand() % 100;
		}
	}
}
void total(double a[][GOD]) {
	for (int i = 0; i < DUF; i++) {
		a[i][5] = a[i][1] * 0.3 + a[i][2] * 0.4 + a[i][3] * 0.2 + a[i][4] * 0.1;
	}
}

void sortgg(double score[], double a[][GOD]) {
	for (int i = 0; i < DUF; i++) {
		score[i] = (int)a[i][6];
	}
	for (int i = 0; i < DUF - 1; i++) {
		for (int j = 0; j < DUF - i - 1; j++) {
			if (score[j] < score[j + 1])
			{
				int temp = score[j];
				score[j] = score[j + 1];
				score[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < DUF; i++) {
		for (int j = 0; j < DUF; j++) {
			if (a[i][5] == score[j]) {
				a[i][6]=j+1;
				break;
			}
		}
	}
}
void pt(double a[][GOD]) {
	printf("번호\t  중간\t  기말\t  과제\t 출석\t  점수\t  등수\n");
	for (int i = 0; i < DUF; i++) {
		printf("%2.0lf번\t%6.0lf\t%6.0lf\t%6.0lf\t%6.0lf\t%6.0lf\t%6.0lf등\n", a[i][0], a[i][1], a[i][2], a[i][3], a[i][4], a[i][5], (int)a[i][6]);
	}
}

int main() {
	double a[DUF][GOD] = { 0 };
	double score[DUF] = { 0 };


	scoreStu(a);
	total(a);
	sortgg(score, a);
	pt(a,score);

	return 0;
}

/*
int main() {
	int list[SIZE] = { 39, 51, 24, 12, 90, 72, 69, 30, 14, 17 };
	int i, j, temp, least;
	for (i = 0; i < SIZE - 1; i++) {
		least = i;
		for (j = i + 1; j < SIZE; j++) {
			if (list[j] < list[least])
				least = j;
		}
		temp = list[i];
		list[i] = list[least];//list[i]와list[least]교환
		list[least] = temp;
	}//선택정렬
	printf("%d", list[i]);

	return 0;
}

//////////////////////////////////////////////////////////////////////

#include<stdio.h>
#define SIZE 10
int main() {
	int list[SIZE] = { 39, 51, 24, 12, 90, 72, 69, 30, 14, 17 };
	int i, j, temp, least;
	for (i = 0; i < SIZE - 1; i++) {
		least = i;
		for (j = i + 1; j < SIZE; j++) {
			if (list[j] < list[least])
				least = j;
		}
		temp = list[i];
		list[i] = list[least];//list[i]와list[least]교환
		list[least] = temp;
	}//선택정렬
	printf("%d", list[i]);

	return 0;
}

//////////////////////////////////////////////////////////////////////

#include<stdio.h>
int main() {
	int score[10] = { 39, 51, 24, 12, 90, 72, 69, 30, 14, 17};
	int temp;
	for (int i = 0; i <= 8; i++) {
		for (int j = i + 1; j <= 9; j++) {
			if (score[i] > score[j]) {
				temp = score[i];
				score[i] = score[j];
				score[j] = temp;
			}
		}
		printf("%d  ", score[i]);
	}
	return 0;
}//오름차순

/////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
int main() {
	int score[10] = { 39, 51, 24, 12, 90, 72, 69, 30, 14, 17 };
	int temp;
	for (int i = 0; i <= 8; i++) {
		for (int j = i + 1; j <= 9; j++) {
			if (score[i] < score[j]) {
				temp = score[i];
				score[i] = score[j];
				score[j] = temp;
			}
		}
		printf("%d  ", score[i]);
	}
	return 0;
}//내림차순

/////////////////////////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 16

int main() {
	int key;
	int grade[SIZE] = { 2, 6, 11, 13, 18, 20, 22, 27, 29, 30, 34, 38, 41, 42, 45, 47 };
	printf("탐색할 값을 입력하시오: ");
	scanf("%d", &key);
	printf("탐색 결과=%d\n", binary_search(grade, SIZE, key));

	return 0;
}

int binary_search(int list[], int n, int key) {
	int low, high, middle;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		printf("[%d %d]\n", low, high);
		middle = (low + high) / 2;//중간 위치 계산
		if (key == list[middle])
			return middle;
		else if (key > list[middle])//중간 원소바다 크다면
			low = middle + 1;//새로운 값으로 low설정
		else
			high = middle-1;//새로운 값으로 high 설정
	}
	return -1;
}//중간값을 이용하여 원하는 값 찾기
*/