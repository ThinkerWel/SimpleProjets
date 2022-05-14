#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996) .
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	
	enum lowe { UPPSTAIR, DOWNSTAIR, PUNCTUATION };
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

		}
		printf(" Symbol (%c) ", daily);

	} while (enter != 10);
	printf("\n");

}
