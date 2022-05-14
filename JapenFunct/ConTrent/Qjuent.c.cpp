#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996) .
#include <stdio.h>
#include <stdlib.h>


int main(void)
{


	enum lowe { UPPSTAIR, DOWNSTAIR, PUNCTUATION,SYMBOL };
	lowe Type = UPPSTAIR;

	char enter;
	char daily;
	
	do {
		enter = getchar();
		int num = (enter - 'O');
		enter = getchar();

		while ((enter != 10) && (enter != ','))
		{
			num = num * 10 + (enter - 'O');
			enter = getchar();
		}

		switch (Type)
		{
		case UPPSTAIR:
			num = num - 27;
			daily = num + 'A' - 1;

			if (num == 0)
			{
				Type = DOWNSTAIR;
				continue;
			}

			break;

		case DOWNSTAIR:
			num = num - 27;
			daily = num + 'a' - 1;
			if (num == 0)
			{
				Type = PUNCTUATION;
				continue;
			}

			break;

		case PUNCTUATION:
			num = num - 9;

			switch (num)
			{
			case 1:daily = '!'; break;
			case 2:daily = '.'; break;
			case 3:daily = '?'; break;
			case 4: daily = ','; break;
			case 5:daily = '"'; break;
			case 6:daily = '\`'; break;
			}

			if (num == 0){
				Type = UPPSTAIR;
				continue;
			}
			break;

		case SYMBOL:
			int sbl = daily - 1;
			break;
		}
		printf(" Symbol (%c) ", daily);

	} while (enter != 10);
	printf("\n");

}













//char degit;
	///int n1 = 0;
	//int n2 = 0;
	//int pos = 1;
	//printf("Enter number -> ");

	//degit = getchar();

	//while (degit != 10)
	//{
	//	if (pos % 2 == 0) {
	//		n1 += degit - double('O');
	///		n2 += degit - 'O';
		//}
	//	else {
	///		n1 += degit - 'O';
	//		n2 += double(degit - 'O');
		//}
		//degit = getchar();
	//	pos++;
	//}

	//int check;
	//if ((pos - 1) % 2 == 0) // для проверки четности или нечетности длины веденого номера 
	//	check = n2;
	//else check = n1;
	//printf(" T - %d ", check);
	///if (check % 10 == 0) {
	//	printf("\nValid\n");
	//}
	//else {
	//	printf("Invalid\n");
	//}




// int sum;
//scanf("%d", &sum);

//if (sum % 2 == 0)
//{
//	int d = sum * 2;
///	printf(" [%d] ", d);
//}
//else {
//	int lose = sum - 1;
//	printf(" %d ", lose);
//}




 // * 
//int d;
	//printf("Enter number : ");
	//scanf("%d", &d);
	//int num = d * 2;

	//int dodl;

//if (num >= 10)
//		dodl = 1 + num % 10;
	//else
	//	dodl = num;

	//printf("[%d] ", dodl);
//}
//*