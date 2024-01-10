/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_QUEUE_SIZE 8
int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;
int n;
int main() {
	int item=0;
	
	while (1) {
		switch (menu()) {
		case 1:
			printf("입력: \n");
			scanf("%d", &n);
			enq(n);
			break;
		case 2:
			while (!is_empty_q()) {
				printf("%d ", deq());
				break;
			}
		default:
			printf("종료\n");
			return 0;
		}
	}
	return 0;
}//원형 큐
int menu() {
	printf("1. 추가\n");
	printf("2. 출력\n");
	printf("3. 종료\n");
	scanf("%d", &n);
	return n;
}
int is_empty_q() {//rear=front공백
	return front == rear;
}
int is_full_q() {//rear=(n-1)포화
	if (front == (rear + 1) % MAX_QUEUE_SIZE) {
		return 1;
	}
	else {
		return 0;
	}
}
int deq() {//f+=1(front 값)아이템 삭제
	if (is_empty_q()) {
		printf("큐 공백\n");
		return -1;
	}
	else
		printf("%d ", queue[front++]);
}
int enq(int item) {//r+=1(rear 값)//아이템 추가
	if (is_full_q()) {
		printf("큐 포화\n");
		return;
	}
	else {
		queue[rear++] = item;
		printf("아이템 추가: %d\n", item);
	}
    //내가 틀린 코드
}*/
//////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_QUEUE_SIZE 8

int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

int menu();
int is_empty_q();
int is_full_q();
int deq();
void enq(int item);

int main() {
    int n;

    while (1) {
        switch (menu()) {
        case 1:
            printf("입력: \n");
            scanf("%d", &n);
            enq(n);
            break;
        case 2:
            while (!is_empty_q()) {
                printf("%d ", deq());
            }
            printf("\n");
            break;
        default:
            printf("종료\n");
            return 0;
        }
    }
    return 0;
}

int menu() {
    int n;
    printf("1. 추가\n");
    printf("2. 출력\n");
    printf("3. 종료\n");
    scanf("%d", &n);
    return n;
}

int is_empty_q() {
    return front == -1 && rear == -1;
}

int is_full_q() {
    return (rear + 1) % MAX_QUEUE_SIZE == front;
}

int deq() {
    if (is_empty_q()) {
        printf("큐 공백\n");
        return -1;
    }
    else {
        int item = queue[front];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX_QUEUE_SIZE;
        }
        return item;
    }
}

void enq(int item) {
    if (is_full_q()) {
        printf("큐 포화\n");
    }
    else {
        if (is_empty_q()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
        }
        queue[rear] = item;
        printf("아이템 추가: %d\n", item);
    }
}