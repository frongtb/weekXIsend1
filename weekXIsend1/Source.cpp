#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
int main()
{
	char fruit[5][20] = { "apple","banana","cherry","orange","strawberry" };
	char show[20], old_guess[100];
	int choice, i, j = 0, check = 0, guess = 0, status = 0;
	char guess_word;
	printf("HANGMAN\n");
	printf("Please select choice 1-5 : ");
	scanf("%d", &choice);
	if (choice < 1 || choice >5 )
	{
		printf("Please select choice 1-5 only");
		return 0;
	}
	else
		for (i = 0; i < strlen(fruit[choice - 1]); i++)
		{
			if (fruit[choice - 1][i] == 'a' || fruit[choice - 1][i] == 'e' || fruit[choice - 1][i] == 'i' || fruit[choice - 1][i] == 'o' || fruit[choice - 1][i] == 'u')
			{
				show[i] = fruit[choice - 1][i];
				old_guess[j++] = fruit[choice - 1][i];
				guess++;
			}
			else
				show[i] = '_';
		}
	show[i] = '\0';
	guess = strlen(fruit[choice - 1]) - guess;
	printf("Please guess word\n");
	for (i = 0; i < strlen(show); i++)
		printf("%c", show[i]);
	printf("\n\n");
	while (check != guess)
	{
		guess_word = _getch();
		printf("\n");
		for (i = 0; i < strlen(old_guess); i++)
		{
			if (old_guess[i] == guess_word)
			{
				status = 1;
				break;
			}
		}
		if (status != 1)
		{
			old_guess[j++] = guess_word;
			for (i = 0; i < strlen(fruit[choice - 1]); i++)
			{
				if (fruit[choice - 1][i] == guess_word)
				{
					check++;
					show[i] = guess_word;
				}

			}
		}
		for (i = 0; i < strlen(show); i++)
			printf("%c", show[i]);
		printf("\n\n");
		status = 0;
	}
	printf("Congratulation , you win !!!!!\n");
	_getch();
}