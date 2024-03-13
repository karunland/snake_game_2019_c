#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int height = 25;
int width = 78;
int border = 219;
int snake_speed = 90;
void delay(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock())
		;
}

void gotoxy(int x, int y)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void frame()
{
	int a;
	for (a = 0; a <= width; a++)
	{
		gotoxy(a, 0);
		printf("%c", border);
		gotoxy(a, height);
		printf("%c", border + 1);
	}

	for (a = 0; a <= height; a++)
	{
		gotoxy(width, a);
		printf("%c", border);
		gotoxy(0, a);
		printf("%c", border);
	}
}

void print_snake(int array[], int lenght_of_the_array)
{
	int i = 0, x, y;
	for (i = 0; i < lenght_of_the_array; i++)
	{
		if (i == lenght_of_the_array - 1)
		{
			x = array[i] / 100;
			y = array[i] % 100;
			gotoxy(x, y);
			printf(" ");
		}
		else
		{
			x = array[i] / 100;
			y = array[i] % 100;
			gotoxy(x, y);
			printf("#");
		}
	}
}

int four_digit(int x, int y)
{
	return (x * 100) + y;
}

void add_tail(int array[], int length_array)
{
}

void apple(int x, int y)
{
	gotoxy(x, y);
	printf("a");
}

int main()
{
	system("cls");
	int snake[100000], x1, y1, a, b, score = 0, i = 4, loop = 0, temp, temp2, f, j, ak = 0;
	char yon;
	int location_x, location_y;
	boolean decision = FALSE;

	srand(time(NULL));
	a = (rand() % width - 5) + 2;
	b = (rand() % height - 5) + 2;
	x1 = (rand() % width - 2) + 1;
	y1 = (rand() % height - 2) + 1;

	for (f = 0; f < 5; f++)
	{
		snake[f] = (a - f) * 100 + b;
	}

	for (;;)
	{

		print_snake(snake, i);
		frame();
		apple(x1, y1);
		gotoxy(0, height + 1);
		printf("head: x:(%d) y:(%d)", snake[0] / 100, snake[0] % 100);
		gotoxy(0, height + 2);
		printf("apple:x:(%d) y:(%d)", x1, y1);
		gotoxy(30, 26);
		printf("Snake's length :%d ", i - 1);

		yon = getch();
		if (yon == 'w' || yon == 's' || yon == 'a' || yon == 'd' || yon == 'o')
		{
			do
			{

				if (yon == 's' || yon == 'w')
				{
					delay(snake_speed * 3 / 2);
				}
				else
				{
					delay(snake_speed);
				}

				temp = snake[0];
				for (loop = 0; loop < i; loop++)
				{
					temp2 = temp;
					temp = snake[loop + 1];
					snake[loop + 1] = temp2;

					for (j = 1; j < i; j++)
					{
						if (loop + 1 != j)
						{
							if (snake[loop + 1] == snake[j])
							{
								ak++;
								if (ak > 0)
								{
									gotoxy(30, 27);
									printf("\nGAME IS OVER \nSCORE IS %d", score);
								}
							}
						}
					}
				}

				switch (yon)
				{
				case 's':
					if (b == 24)
					{
						b -= 23;
						break;
					}
					else
					{
						++b;
						break;
					}

				case 'd':
					if (a == 77)
					{
						a -= 76;
						break;
					}
					else
					{
						++a;
						break;
					}

				case 'a':
					if (a == 1)
					{
						a += 76;
						break;
					}
					else
					{
						--a;
						break;
					}
				case 'w':
					if (b == 1)
					{
						b += 23;
						break;
					}
					else
					{
						--b;
						break;
					}
				}

				if ((snake[0] % 100) - 1 == y1 || (snake[0] % 100) + 1 == y1)
				{
					if (snake[0] / 100 > x1)
					{
						yon = 'a';
					}
					else
					{
						yon = 'd';
					};
				}
				if ((snake[0] / 100) - 1 == x1 || (snake[0] / 100) + 1 == x1)
				{
					if (snake[0] % 100 > y1)
					{
						yon = 'w';
					}
					else
					{
						yon = 's';
					}
				}

				snake[0] = a * 100 + b;

				if (a == x1 && b == y1)
				{
					score++;
					i++;
					printf("\a");

					srand(time(NULL));
					x1 = (rand() % 75) + 1;
					y1 = (rand() % 23) + 1;

					if (snake[i - 2] / 100 - snake[i - 1] / 100 != 0 || snake[i - 1] / 100 - snake[i - 2] / 100 != 0)
					{
						if (snake[i - 1] / 100 - snake[i - 2] / 100 > 0)
						{
							snake[i] = snake[i - 1] - 100;
						}
						else
						{
							snake[i] = snake[i - 1] + 100;
						}
					}
					else
					{
						if (snake[i - 1] % 100 - snake[i - 2] % 100 > 0)
						{
							snake[i] = snake[i - 1] - 1;
						}
						else
						{
							snake[i] = snake[i - 1] + 1;
						}
					}
				}
				gotoxy(0, height + 1);
				printf("head:x:%d,y:%d", snake[0] / 100, snake[0] % 100);
				gotoxy(0, height + 2);
				printf("apple:x:%d:x,y:%d", x1, y1);
				gotoxy(30, 26);
				printf("Snake's length :%d ", i - 1);
				frame();
				print_snake(snake, i);
				apple(x1, y1);

			} while (!kbhit());
		}
	}
}
