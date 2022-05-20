#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996) .
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct date {
	int day;
	int month;
	int year;
};

struct airline {

	char name[12];
	char passport[12];
	char email[12];
	char distation[12];
	int sit_number;

	struct date peek;
}
*simple,add;

void AddInfo(); 
void Reserve(int x);
void close();
void Depetments_menu(void);
void Display(void);

int main(void);

void AddInfo()
{
	system("cls");

	FILE* fp;
	int count = 0;
	int i = 0;

	fp = fopen("outside.txt", "a+");
	if (fp == NULL) {
		printf("\n\tError #1");
		exit(1);
	}

	printf("\n\tEnter D/M/Y : ");
	scanf("%d %d %d", &add.peek.day, &add.peek.month, &add.peek.year);

	printf("\n\tName : ");
	scanf("%s", simple->name);

	printf("\n\tPassport : ");
	scanf("%s", simple->passport);

	printf("\n\tEmail : ");
	scanf("%s", simple->email);

	printf("\n\tDistation : ");
	scanf("%s", simple->distation);		


	fprintf(fp, "\nD/%d M/%d Y/%d \n%s \n %s\n %s\n %s\n ", add.peek.day,add.peek.month,add.peek.year,
		simple->name,simple->passport, simple->email, simple->distation); 
		count++;

	if (count == 1)
	{
	
		printf("\n+================================================================+\n");
		printf("\n\tD|%d - M|%d - Y|%d\n\n", add.peek.day, add.peek.month, add.peek.year);
		
		printf("\n\tName:%s\n\t Passport:%s \n\tEmail: %s \n\tDistation:%s\n", simple->name,simple->passport,
			simple->email,simple->distation);

		printf("+===============================================================+\n");
	}
	else {
		printf("\n\tNot found record in file !!! ");
	}


	int ExOrCon = 0;
	printf("\n\tIf you want continue,enter (1/0): ");
	scanf("%d", &ExOrCon);

	if (ExOrCon == 1)
	{
		main();
	}
	else {
		close();
	}

}

void Reserve(int x)
{

	if (simple == NULL)
	{
		simple = (struct airline*)malloc(sizeof(struct airline));
		Depetments_menu();
		AddInfo();

		printf("\n\tSeat booking succeful");
		printf("\n\tYour seat number A - %d\n", x);
		simple->sit_number = x;

		return;

	}
	else if (x > 5) {
		printf("\n\tAll seat full !");
	}
	else {
		while (simple)
		{
			simple = (struct airline*)malloc(sizeof(struct airline));
			AddInfo();
			Depetments_menu();
			printf("\n\tSeat Booking succeful ");
			printf("\n\tYour seat number is Seat A - %d", x);
			simple->sit_number = x;
			return;
		}
	}
	free(simple);
}

void Depetments_menu(void)
{
	system("cls");

	FILE* fp;
	fp = fopen("outside.txt", "a");
	if (fp == NULL) {
		printf("\n\tNot connect by file ");
		exit(1);
	}

	printf("\n\t~~~ Business Class ~~~ \n");
	printf("\n\t A --> Time 12:15");
	printf("\n\t B --> Time 6:00");
	printf("\n\t G --> Time 17:40");
	printf("\n\t D --> Time 23:30");
	printf("\n\t Z --> Time 14:55");

	char choise[12];
	printf("\n\n\tEnter your choise : ");
	scanf("%s", choise);

	switch (*choise)
	{
	case 'A': fprintf(fp, "\nA --> Time 12:15\n");
		break;

	case 'B':fprintf(fp, "\n B --> Time 6:00\n");
		break;

	case 'G':fprintf(fp, "\nG --> Time 17:40");
		break;

	case 'D': fprintf(fp, "\nD --> Time 23:30");
		break;

	case 'Z':fprintf(fp, "\nZ --> Time 14:55");
		break;
	default:
		printf("\n\tNot variant !");
		Depetments_menu();
		break;
	}
}

void SmokingAreas(int x)
{
	system("cls");

	printf("\n\tWhat seat you need ? \n#1/With Smoke\n#2/NotSmoke ? :");
	char answer[12];
	int booking[12];

	scanf("%s", answer);

	if (strstr(answer, "Smoke"))
	{
		
		printf("\n\tYour seat [%d],with smoke ready ! ", x);
	}
	else {

		printf("\n\tSeat with smoke have here  !");
	}
}

void Display(void) {

	system("cls");

	FILE* fp;
	fp = fopen("outside.txt", "r+");
	if (fp == NULL) {
		printf("\n\tEror #1");
	}
	
	simple = (struct airline*)malloc(sizeof(struct airline));
		while (fscanf(fp, "%s %s %s %s", simple->name,
			simple->passport,simple->email,simple->distation)==4) {	
			
			printf("\n+++++++++++++++++++++\n");
			printf("\n%s %s %s %s\n", simple->name,simple->passport,
			simple->email, simple->distation);
			printf("\n+++++++++++++++++++++\n");
		}

		free(simple);
}

void close()
{
	printf("\n\t ~~~~~~ Good Luck ~~~~~~\n ");
}

int main(void)
{
	system("cls");
	int ch;
	int count = 1;

	do {
		printf("\n\t*************************************\n");
		printf("\n\t            - Airline -               \n");
		printf("\n\t*************************************\n");
		printf("\n\t1.Reserved");
		printf("\n\t2.SmokingAreas");
		printf("\n\t3.Display");
		printf("\n\t5.Exit");

		printf("\n\n\tEnter choise : ");
		scanf("%d", &ch);
		printf("\n\n");

		switch (ch)
		{
		case 1: Reserve(count);
			count++;
			break;

		case 2:SmokingAreas(count);
			break;

		case 3:Display();
			break;

		case 4:
			return 0;

		}

	} while (ch != 4);
}

