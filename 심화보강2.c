#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int max(int x, int y) {
	if (x > y)
		return x;
	else
		return y;
}
int main(void) {
	int x = 0, y = 0, larger;
	printf("더 큰 정수를 입력");
	scanf("%d %d", &x, &y);//scnaf만 고치기
	larger = max(x, y);
	printf("더 큰 수는 : %d입니다.", larger);
}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int menu() {
	int n;
	printf("1.더하기\n");
	printf("2.빼기\n");
	printf("3.곱하기\n");
	printf("4.나누기\n");
	printf("5.루트\n");
	printf("6.팩토리얼\n");
	printf("7.사인(sin)\n");
	scanf("%d", &n);
	return n;
}
int add() {
	int a, b;
	printf("숫자를 입력하시오: ");
	scanf("%d %d", &a, &b);
	printf("%d\n", a + b);
}
int mit() {
	int a, b;
	printf("숫자를 입력하시오: ");
	scanf("%d %d", &a, &b);
	printf("%d\n", a - b);
}
int pul() {
	int a, b;
	printf("숫자를 입력하시오: ");
	scanf("%d %d", &a, &b);
	printf("%d\n", a * b);
}
int div() {
	int a, b;
	printf("숫자를 입력하시오: ");
	scanf("%d %d", &a, &b);
	printf("%d\n", a / b);
}
void rute() {
	double sum;
	printf("숫자를 입력하세요: ");
	scanf("%lf", &sum);
	printf("%.2lf의 제곱근  %.2lf\n", sum, sqrt(sum));
}
void factorial() {
	long long n, result = 1, i;
	printf("정수를 입력하시오: \n");
	scanf("%lld", &n);
	for (i = 1; i <= n; i++) {
		result = result * i;
	}
	printf("결과=%lld\n\n", result);
}
void sine() {
	double a, result;
	printf("각도를 입력하시오: \n");
	scanf("%lf", &a);
	result = sin(a*3.1415926/180);
	printf("결과 = %lf\n\n", result);
}
	int main(void){
		while (1) {
			switch (menu()) {
			case 1:
				add();
				break;
			case 2:
				mit();
				break;
			case 3:
				pul();
				break;
			case 4:
				div();
				break;
			case 5:
				rute();
				break;
			case 6:
				factorial();
				break;
			case 7:
				sine();
				break;
			}
		}
		return 0;
	}


#include<stdio.h>
int main() {
	int i, j = 0;
	int test = 5;
	for (i = 0; i < test; i++) {
		for (j = test - 1; j > i; j--) {
			printf(" ");
		}
		for (j = 0; j < 2 * i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = 0; i < test; i++) {
		for (int j = 0; j < i; j++) {
			printf(" ");
		}

		for (int j = 2 * test - 1; j > 2 * i; j--) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
		return result;
}
	int main(void){
		int n;
		int result = 0;
		printf("알고 싶은 팩토리얼의 값은?\n");
		scanf("%d", &n);
		result = factorial(n);
		printf("%d!는%d입니다.\n", n, result);
		return 0;
	}//팩토리얼

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int get_integer(void) {
	int n;
	printf("정수를 입력하시오.\n");
	scanf_s("%d", &n);
	return n;
}
int is_prime(int n) {
	int i;
	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			return 0;
		}
		return 1;
	}
}
int main(void) {
	int n;
	n = get_integer();
	if (is_prime(n) == 1) {
		printf("%d은 소수입니다.\n", n);
	}
	else
		printf("%d은 소수가 아닙니다.\n", n);
	return 0;
	//소수 찾기(get_integer(void), int is_prime(int n))