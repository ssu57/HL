#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main() {
	int num[10];
	int cnt;
	srand(time(NULL));
	printf("배열\n");
	for (int i = 0; i < 10; i++) {
		num[i] = rand() % 100 + 1;
		printf("%d  ", num[i]);
		for (int j = i; j >0&&num[j]<num[j-1]; j--) {
				cnt = num[j];
				num[j] = num[j - 1];
				num[j - 1] = cnt;
		}
	}
	printf("\n--------------------------------------\n오름차순\n");
	for (int i = 0; i < 10; i++) {
		printf("%d  ", num[i]);
	}
	return 0;
}
/*
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main() {
	int even[10] = { 0, };
	int add[10] = { 0, };
	int i, j = 0, k = 0;

	srand(time(NULL));
	for (; j <= 10 && k <= 10;) {
		int sum = rand() % 100;
		if (sum % 2 == 0) {
			even[j] = sum;
			j++;

		}
		else {
			add[k] =sum;
			k++;
		}
	}
		printf("\n짝수 개수: %d\n", j);
		printf("\n홀수 개수: %d\n", k);
}



#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define LOWS 20
#define SOLS 5
int main() {
	int a[LOWS][SOLS] = {0,};
	double total_score[LOWS] = {0,};
	int i, j;
	srand(time(NULL));

	for (i = 0; i < LOWS; i++) {
		for (j = 0; j < SOLS; j++) {
			a[i][j] =1+rand() % 100;
			
		}
		a[i][4] = rand() % 10 + 1;
	}
	for (i = 0; i < LOWS; i++) {
		total_score[i] = a[i][0] * 0.3 + a[i][1] * 0.4 + a[i][2] * 0.2 + a[i][3] * 0.3 - a[i][4];
		printf("%i번 학생의 최종성적 = %10.2f\n", i+1,total_score[i]);
		
	}
	double max=total_score[0], min=total_score[0];
	for (i =1; i < LOWS; i++) {
		if (max < total_score[i])
			max = total_score[i];

		if (min > total_score[i])
			min = total_score[i];
	}
	printf("최종성적 1등: %.2lf\n", max);
	printf("최종성적 20등: %.2lf\n", min);
	
	return 0;
}
*/