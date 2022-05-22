
#define FILE_NAME "QUIZ.txt"

void ShowRecord();
void help();

void menu(void)
{
	printf("\n\t\t_____________________________________\n");
	printf("\n\t\tFor Start Game  enter - ('S') ");
	printf("\n\t\tFor help enter - ('H') ");
	printf("\n\t\tFor exit enter - ('Q') ");
	printf("\n\t\t_____________________________________\n");
	printf("\n\t\tEnter choise : > ");
}

int main(void)
{
	menu();
	FILE* fp;
	fp = fopen(FILE_NAME, "a+");
	if (fp == NULL) {
		printf("\nNot connect by file ");
		exit(1);
	}

	int count = 0;
	char playerName[12] = { 0 };
	char choise;

	choise = toupper(getch());

	 if (choise == 'H') {
		help();
	}

	 else if (choise == 'Q') {
		 exit(1);
	 }

	else if (choise == 'S') {

		printf("\n\t\tEnter name player :  ");
		scanf("%s", playerName);
		

		printf("\n\t\t\t ----------- Welcome %s Program quzi Game  ------------- \n", playerName);
		printf("\n\t\t\t________________________________________________________\n");
		printf("\n\t\t\t ~~~~~~~~~ Rules and  Instructions of the game  ~~~~~~~~~\n");
		printf("\n\t #1 This game have two qustions warm up,next come three qustions about more complicated ");
		printf("\n\t #2 After the passage of 2(3) warm-up, and 5 regular,ones there are difficult qustions and the final ones");
		printf("\n\t #3 After passing the final questions, you become the winner, 1 million rubles");
		printf("\n\t #4 After every 2 correct answers to the question, you are transferred to a new level ");
		printf("\n\tFor start Game enter 'Y' :  ");

		if (toupper(getch()) == 'Y')
		{
			printf("\n\tWhat is the national animal in Shotland ?");
			printf("\t(A) - Horse (B) - Wolf (C)- Cow (D) - Unicorn\n");

			if (toupper(getch()) == 'D') {
				printf("\n\tCorrect !!! ");
				count++;

			}
			else {
				printf("\n\tWrong !!! ");
			}
			printf("\n");

			printf("\n\tWhich country produces more coffee ? ");
			printf("\t(A) - Colombia (B) - Indonesia (C) - Brazil (D) - Vietnam\n ");

			if (toupper(getch()) == 'C') {
				printf("\n\tCorrect !!!\n ");
				count++;

			}
			else {
				printf("\n\tWrong !!!\n");
			}
			printf("\n");

			printf("\n\tWhich soft drink was the first to be taken into space ? ");
			printf("\t(A) - Coca Cola (B) - Peps (C) - Fanta (D) - Snapl\n ");

			if (toupper(getch()) == 'A') {
				printf("\n\tCorrect !!!\n ");
				count++;

			}
			else {
				printf("\n\tWrong !!! \n");
			}
			printf("\n");

			printf("\n\tHow long does a moment last? ");
			printf("\t(A) - 60 Sec (B) - 90 Sec (C) - 120 Sec (D) - 180 Sec\n ");

			if (toupper(getch()) == 'B') {
				printf("\n\tCorrect !!! \n");
				count++;

			}
			else {
				printf("\n\tWrong !!! \n");
			}
			printf("\n");
		}
		else {
			printf("Error choice  #1\n");
		}
		fprintf(fp, "\nName - %s  N2 = %d\n ", playerName, count);

		printf("\n\t Вurchlaufen der Testphase,Player %s sammelte %d punkten \n", playerName, count);

		if (count == 3 || count == 4) {
			printf("\n\tYour prize amount is $15000 Congratulate ");
		}
	}


		if (count >= 2) {
			printf("\n\tCongratulations %s have passed the training stage ", playerName);
			printf("\n\tThe rules and instructions are the same here, but the questions are more complicated ");
			printf("\n\t++++ - Questions of medium complexity - ++++ ");
			printf("\n\tFor continue  game,enter 'Q' ");

			if (toupper(getch()) == 'Q') {

				printf("\n\tWhat is the smallest planet in our Solar system? ");
				printf("(A) - Land (B) - Venus (G) - Mars (D) - Mercury\n ");
				if (toupper(getch()) == 'D') {
					printf("\n\tCorrect !!! ");
					count++;
				}
				else {
					printf("\n\tWrong !!! ");
				}
				printf("\n");

				printf("\n\tWhat is Canada's national sport?");
				printf("(A) - Bowling (B) - Basketball (G) - Lacrosse (D) - Futball\n");
				if (toupper(getch())== 'G') {
					printf("\n\tCorrect !!! ");
					count++;

				}	else {
					printf("\n\tWrong ");
				}
				printf("\n");

				printf("\n\tHow many players are on the baseball team ?");
				printf("(A) - 8 (B) - 9 (G) - 10 (D) - 11\n");
				if (toupper(getch()) == 'B') {
					printf("\n\tCorrect !!!");
					count++;

				}else {
					printf("\n\tWrong !!! ");
				}
				printf("\n");

				printf("\n\tWhich country is the smallest in the world ? ");
				printf("(A) - Malta (B) - Maldives (G) - Vatican City (D) - Monaco \n");

				if (toupper(getch()) == 'G') {
					printf("\n\tCorrect !!! ");
					count++;

				}	else {
					printf("\n\tWrong !!! ");
				}
			}
			else {
				printf("\n\tError choice !!!");
			}

			fprintf(fp, "\nName - %s  N2 = %d\n ", playerName,count);
			printf("\n\t Вurchlaufen der Testphase,Player %s sammelte %d punkten \n", playerName, count);
			
			if (count == 7 || count == 6) {
				printf("\n\tYour prize amount is $150000 Congratulate ");
			}
		}

		if (count >= 6)
		{
			
			printf("\n\t\t=============  The final game =============\n");
			printf("\n\t Congratulations %s are in the final",playerName);
		
			printf("\n\tAnd so let's start......");
			getch();

			printf("\n\t Where was Alisha Keys born? ");
			printf("\n (A) - New york (B) - California (G) - Texas (D) - New Mexico \n");
				if (toupper(getch()) == 'A') {
					printf("\n\tCorrect !!! ");
					count++;

				}	else {
					printf("\n\tWrong !!! ");

				}

				printf("\n\tHow many bones do sharks have?");
				printf("\n (A) - 4 (B) - 5 (G) - 10 (D) - 0 ");
				if (toupper(getch()) == 'D') {
					printf("\n\tCorrect !!!");
					count++;

				}else {
					printf("\n\tWrong !!!");
				}

				printf("\n\tWhat is the IATA airport code for Madurai Airport?");
				printf("\n(A) - RDR (B) - IXM (G) - AIA (D) - IRA ");
				if (toupper(getch()) == 'B') {
					printf("\n\tCorrect !!! ");
					count++;

				}	else {
					printf("\n\tWrong !!!");
				}

				printf("\n\t The last one left qustion ..... ");

				printf("\n\tHow many days does a year last on the planet Pluto in days ? ");
				printf("\n (A) - 59800.0 (B) - 10747.0 (G) - 90560.0 (D) - 88.0");
				if (toupper(getch()) == 'G') {
					printf("\n\tCorrect !!!");
					count++;
				}	else {
					printf("\n\tWrong !!! ");

				}
				
				if (count == 10 || count == 11) {
					printf("\n\tYou are the winner of the final");
					printf("\n\tYour prize amount is $1000000 Congratulate ");
				}
				fprintf(fp, "\nName - %s  N3 = %d\n ", playerName, count);
		}

}

void help(void)
{
	printf("\n-------------------------------------------------------\n");
	printf("Each correct answer to the question gives 1000 dollars");
	printf("\nYou have one attempt to choose the right option");
	printf("\nIn the final game, your prize is 1 million rubles");
	printf("\nDo not write off and be careful, Good luck");
	printf("\n\tTo get to the final, 6 points are required, that is, 6 correct answers");
	printf("\n------------------------------------------------------\n");
}
