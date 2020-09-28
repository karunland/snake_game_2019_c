#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int height = 25;
int width = 78;

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
		printf("%c", 220);
		gotoxy(a, height);
		printf("%c", 220);
	}

	for (a = 0; a <= height; a++)
	{
		gotoxy(width, a);
		printf("%c", 219);
		gotoxy(0, a);
		printf("%c", 219);
	}

	gotoxy(32, 26);
	printf("%c", 219);
	gotoxy(50, 26);
	printf("%c", 219);
	gotoxy(57, 26);
	printf("%c", 219);

	for (a = 0; a <= 18 + 7; a++)
	{
		gotoxy(32 + a, 27);
		printf("%c", 219);
	}
}
int main()
{
	int x1, y1, a, b, x = 1, y = 1, puan = 0;
	char yon;
	srand(time(NULL));
	a = rand() % 77 + 1;
	b = rand() % 24 + 1;
	x1 = rand() % 77 + 1;
	y1 = rand() % 24 + 1;

	for (;;)
	{
		gotoxy(x1, y1);
		printf("1");
		frame();
		gotoxy(a, b);
		printf("#");
		gotoxy(33, 26);
		printf("KONUM:x(%d),y(%d)", a, b);
		gotoxy(51, 26);
		printf("PUAN:%d", puan);

		yon = getch();

		do
		{

			gotoxy(x1, y1);
			printf("1");

			frame();
			gotoxy(a, b);
			printf("#");
			gotoxy(33, 26);
			printf("KONUM:x(%d),y(%d)", a, b);
			gotoxy(51, 26);
			printf("PUAN:%d", puan);

			delay(40);
			switch (yon)
			{
			case 's':
				if (b == 24)
				{
					gotoxy(a, b);
					printf(" "); //
					b -= 23;
					gotoxy(a, b);
					printf("#");
					break;
				}
				else
				{
					gotoxy(a, b + y - 1);
					printf(" "); //
					gotoxy(a, b + y);
					printf("#");
					b = b + y;
					break;
				}

			case 'd':
				if (a == 77)
				{
					gotoxy(a, b);
					printf(" "); //
					a -= 76;
					gotoxy(a, b);
					printf("#");
					break;
				}
				else
				{
					gotoxy(a + x - 1, b);
					printf(" "); //
					gotoxy(a + x, b);
					printf("#");
					a = a + x;
					break;
				}

			case 'a':
				if (a == 1)
				{
					gotoxy(a, b);
					printf(" "); //
					a += 76;
					gotoxy(a, b);
					printf("#");
					break;
				}
				else
				{
					gotoxy(a - x + 1, b);
					printf(" "); //
					gotoxy(a - x, b);
					printf("#");
					a = a - x;
					break;
				}
			case 'w':
				if (b == 1)
				{
					gotoxy(a, b);
					printf(" "); //
					b += 23;
					gotoxy(a, b);
					printf("#");
					break;
				}
				else
				{
					gotoxy(a, b - y + 1);
					printf(" "); //
					gotoxy(a, b - y);
					printf("#");
					b = b - y;
					break;
				}
			}

			if (a == x1 && b == y1)
			{
				++puan;
				srand(time(NULL));
				x1 = rand() % 77 + 1;
				y1 = rand() % 24 + 1;
			}

		} while (!kbhit());
	}
}
