﻿
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>


struct liRent {
	char name[40];
	int age;
	int salary;
	int id;
};

char name[30];
struct liRent list;
int size = sizeof(list);

FILE* fp, * ft;

void FunctRecord(void)
{
	system("cls");
	int ExOrCon = 1;

	while (ExOrCon == 1)
	{
		printf("Name : ");
		scanf("%s", list.name);
		printf("Age : ");
		scanf("%d", &list.age);
		printf("Salary : ");
		scanf("%d", &list.salary);
		printf("Id : ");
		scanf("%d", &list.id);

		fprintf(fp, "Name - %s\n", list.name);
		fprintf(fp, "Age - %d\n", list.age);
		fprintf(fp, "Salary - %d\n", list.salary);
		fprintf(fp, "Id - %d\n", list.id);


		printf("Is you want continue work program (1/0) ?");
		scanf("%d", &ExOrCon);

	}
}

void RemoveRecord(void)
{
	fclose(fp);
	remove("data.txt");
	fp = fopen("data.txt", "wb");
}

void DisplayRecord(void)
{
	system("cls");
	fp = fopen("data.txt", "rb+");

	rewind(fp);
	printf("================================\n\n");

	while (fread(&list, sizeof(list), 4, fp) == 1)
		printf("%s %d %d %d", list.name, list.age, list.salary, list.id);
	fread(&list, sizeof(list), 4, fp);
	printf("%s", list.name);

	printf("\n=================================\n");
	
	system("pause");
}

void ModificationRecord(void)
{
	
	int ExOrCon = 1;
	system("cls");

	while (ExOrCon == 1) {
		fp = fopen("data.txt", "r");
		ft = fopen("temp.txt", "w");
		fflush(stdin);
		printf("Name :");
		scanf("%s", name);

		while (fread(&list, sizeof(list), 1, fp) == 1)
		{
			if (strcmp(name, list.name) != 0) {
				fwrite(&list, sizeof(list), 1, ft);
			}
		}

		fflush(stdin);
		printf("Editing name %s\n\n", name);

		printf("New Name :");
		scanf("%s", list.name);

		fwrite(list.name, sizeof(list.name), 1, ft);
	
		remove("data.txt");
		rename("temp.txt", "data.txt");

		printf("Enter  (1/0) if want continue :  ");
		scanf("%d", &ExOrCon);

	}
}
	
int main(void) 
{
	system("color 3F");

	fp = fopen("data.txt", "rb+");
	if (fp == NULL) {
		fp = fopen("data.txt", "wb+");
		if (fp == NULL) {
			printf("No connect !");
			exit(1);
		}
	}

	printf("\n\n======================");
	printf("\n\n1)FUNCT_RECORD\n");
	printf("2)REMOVE_RECORD\n");
	printf("3)DISPLAY_RECORD\n");
	printf("4)MODIFICATIOM_RECORD\n");
	printf("\n=======================");
	printf("\nCHOICE : ");


	int choice;
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:FunctRecord();
		break;

	case 2:RemoveRecord();
		break;

	case 3:DisplayRecord();
		break;

	case 4:ModificationRecord();
		break;

	
	
	}
}