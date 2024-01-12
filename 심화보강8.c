#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct student{
	int number;
	char name[20];
	double grade;
};
int main(){
	struct student s = {1,"홍길동",4.3};//구조체 선언
	struct student* p;
	p = &s;

		printf("학번=%d 이름=%s 학점=%f\n", s.number,s.name, s.grade);
		
		printf("학번=%d 이름=%s 학점=%f\n", (*p).number, (*p).name, (*p).grade);
	
		printf("학번=%d 이름=%s 학점=%f\n", p->number, p->name, p->grade);

	
return 0;
}
/*
#include<stdio.h>
struct student{
	int number;
	char name[10];
	double grade;
};
int main(){
	struct student s;
	s.number = 202325008;
	strcpy(s.name, "원수민");
	s.grade = 4.0;

	printf("학번: %d\n", s.number);
	printf("이름: %s\n", s.name);
	printf("학점: %.2f\n", s.grade);
return 0;
}

#include<stdio.h>
#define SIZE 3;

struct student{
	int number;
	char name[20];
	double grade;
};
int main(){
	struct student list[SIZE];//구조체 선언
	int i;
	for (i = 0; i < SIZE; i++) {
		printf("학번을 입력하시오: \n");
		scanf("%d", &list[i].number);
		printf("이름을 입력하시오: \n");
		scanf("%s", &list[i].name);
		printf("학점을 입력하시오: \n");
		scanf("%lf", &list[i].grade);
	}
	for (i = 0; i < SIZE; i++)
		printf("학번: %d,이름: %s,학점: %lf\n", list[i].number, list[i].name, list[i].grade);
return 0;
}
*/


//구조체