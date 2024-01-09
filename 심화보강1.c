#include<stdio.h>
int main()
{
	//대각선 배열
	int i, j;
	int test[10][10] = { 0, };
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; i++) {
			test[i][j] = 0;
			test[i][0] = i;
			test[0][j] = j;
			
		}
		if (i == j) {
			test[i][j] = i;//i이든 j이든 상관없다
		}
		printf("%d", test[i][j]);
	}

	return 0;
}
/*
#include<stdio.h>
int main()
{
	int narr[10] = { 1, 2, -1, -2, 1, 2, -1, -2, 1, 2 };
	int temp = 0;
	for (int i = 0; i < sizeof(narr) / sizeof(int); i++) {//40(narr의 사이즈)/4(int의 사이즈)
		temp += narr[i];
		printf("결과=%d\n", temp);
	}
	return 0;
}

#include<stdio.h>
int main()
{
	int dec = 17;
	int biny[20] = {0,};
	int p = 0;
	for (;;) {//무한루프
		biny[p] = dec % 2;
		dec = dec / 2;
		p++;
		if (dec == 0)
			break;
	}
	for (int i = p - 1; i >= 0; i--)
		printf("%d", biny[i]);//10진수를 2진수로

	return 0;
}

#include<stdio.h>
int main()
{
	//피보나치 수열
	int a = 0;
	int b = 1;
	for (int i = 2; i <= 10; i++) {
		int c = a + b;
		printf("%d %d %d\n", a, b, c);
		a = b;
		b = c;
	}
	return 0;
}
*/