#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*주사위는 1~6수를 가지고 있다.
주사위를 1000번 던질 때, 주사위 수가 몇 번씩 나오는지
출력하는 프로그램을 배열을 이용하러 작성하라.*/
int main() {
	int dice_freq[6] = { 0, };
	int i;
	srand(time(NULL));
	for (i = 0; i < 1000; i++) {
		++dice_freq[rand() % 6];//P=rand()%6
								//fg[P]=fg[P]+1
	}
	printf("숫자 빈도\n");
	for (i = 0; i < 6; i++)
		printf("%4d %4d\n", i + 1, dice_freq[i]);
	return 0;
}