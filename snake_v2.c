#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int height = 25 ;
int width = 78 ;
int border = 219 ;
int snake_speed = 60;
void delay(unsigned int mseconds)  // delay func
{
	clock_t goal = mseconds + clock();
	while (goal > clock())
		;
}

void gotoxy(int x, int y)   	   // where ever u want to go in command prompt ( cmd )
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}


void frame()                       // the frame
{
	int a;
	for (a = 0; a <= width; a++)
	{
		gotoxy(a, 0);
		printf("%c", border);
		gotoxy(a, height);
		printf("%c", border+1);
	}

	for (a = 0; a <= height; a++)
	{
		gotoxy(width, a);
		printf("%c", border);
		gotoxy(0, a);
		printf("%c", border);
	}

}

void print_snake(int array[] , int lenght_of_the_array ) 
{
	int i = 0 , x , y ;
	for ( i = 0; i < lenght_of_the_array; i++ )
	{
		if ( i == lenght_of_the_array - 1 ){
			x = array[i] / 100;
			y = array[i] % 100;
			gotoxy( x , y );
			printf(" ");
		}
		else
		{
			x = array[i] / 100;
			y = array[i] % 100;
			gotoxy( x , y );
			printf("#");
		}
		 
		
	}
	

}
int  four_digit(int x , int y){
	return (x*100) + y;
}

void add_tail(int array[],int length_array){


}


void apple ( int x , int y ){
	gotoxy(x,y);
	printf("a");
}

int main()
{
	int snake[100000] , x1, y1, a, b , score = 0 , i = 4 , loop = 0 , temp , temp2 , f,j,ak=0;
	char yon ;
	int location_x,location_y;
	srand(time(NULL));
	a = rand() % width-4 + 4;  // snake s loca +4, the reason ıs snake s stock longness is 4 block       ####
	b = rand() % height-1 + 4;  // 
	x1 = rand() % width-4 + 1; // apple s locatıon x axis
	y1 = rand() % height-1 + 1; // y axis
	
	for (f=0;f<4;f++ ){   // random place for snake to start 
		snake[f]=(a-f)*100+b;
	}	

	for (;;)                 
	{
		print_snake(snake, i);
		frame();       		
		apple( x1 , y1 );     // start screen thıs 3 lines going to work
		
		yon = getch();  	         
		if (yon == 'w'||yon == 's'||yon == 'a'||yon == 'd'){
		do
		{     
			if( yon == 's' || yon == 'w' ){
				delay(snake_speed*2);
			}
			else {
				delay(snake_speed);
			}           
			
			temp=snake[0];
			for (loop = 0 ; loop < i ; loop++ )
			{
				temp2 = temp;
				temp  = snake[loop + 1];
				snake[loop+1] = temp2 ;
				
				for (  j = 1; j < i; j++)
				{
					if ( loop+1 != j ){
						if ( snake[ loop+1 ] == snake[ j ]){
							ak++;
							if(ak>0){
								gotoxy(30,26);printf("\nGAME IS OVER \nSCORE IS %d",score);
								getch();
								return 0; // if snake eats itselves game wıll over
							} 
						}			
					}
				}			
			}
			switch (yon) 
			{
			case 's':            // if snake hits the borders ,thıs wıll teleport opposıte way
				if (b == 24)
				{
					b -= 23;
					break;
				}
				else
				{
					++b ;
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
					++a ;
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
					--a ;
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
			snake[0] = a * 100 + b;
			
			if (a == x1 && b == y1)
			{
				score++ ; i++ ;
				printf("\a");
				srand(time(NULL));
				x1 = rand() % 77 + 1;
				y1 = rand() % 24 + 1;
				
				if ( snake[ i - 2 ] / 100 - snake[ i-1 ] / 100 != 0 || snake[ i - 1 ] / 100 - snake[ i - 2 ] / 100 != 0 )   // we don't and can't know where the tail of snake is so ıf we make math on the last 2 columnm or line  
				{																											// we ll know where we gonna add taıl : ) 
					if (snake[ i - 1 ] / 100 - snake[ i - 2 ] / 100 > 0 )													// as u see ı added just number to array 
					{																										// because ı m keeping snake s locatıon and ıt has end	 
						snake[i] = snake[i - 1] - 100;																		// ıf ı add 1 more number with 4 digits... array[i] (to)==> array[i+1] longer array
					}
					else
					{
						snake[i] = snake[i - 1] + 100;
					}
				}
				else
				{
					if (snake[ i - 1 ] % 100 - snake[ i - 2 ] % 100 > 0)
					{
						snake[i] = snake[i - 1] - 1;
					}
					else
					{
						snake[i] = snake[i - 1] + 1;
					}	
				}
			}
			frame();
			print_snake(snake, i);
			apple( x1 , y1 );
			gotoxy(30,26);printf("Snake's length :%d " , i-1 );

		} while (!kbhit());}
	}
}
