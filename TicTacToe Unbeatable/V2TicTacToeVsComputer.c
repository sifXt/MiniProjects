#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char sq[10] = { 'o', 'r', 'm', 'r', 'm', 'c', 'm', 'r', 'm', 'c' };
int mov[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
char name[100];

int checkwin();

void board(int x, int c)
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Computer (X)  -  %s (O)\n\n\n",name);


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
    
    if(x==2)
    {
    	printf("You chose %d\n\n",c);
	}
	else
	{
		printf("Computer chose %d\n\n",c);
	}
}



void b()
{
	system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Computer (X)  -  %s (O)\n\n\n",name);


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}

int main()
{
	bool a1,a2,a3,a4,a11,a12,a13,a14,a21,a31,a32,a33,a331,a332,a333,a334,a41,a42;
    int player = 1, i, choice,c=0;
    
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Enter your name: ");
    scanf("%s",name);
    
    char mark;
    do
    {
    	c++;
        b();
        player = (player % 2) ? 1 : 2;
		
		mark = (player == 1) ? 'X' : 'O';
		
		if(player==1)
		{
			if(c==1)
			{
				choice = 1;
				square[1] = mark;
			}
			if(c==3)
			{
				if(sq[choice] == 'm')
				{
					choice = 5;
					square[5] = mark;
					a1=true;
				}
				else if(choice == 9)
				{
					choice = 3;
					square[3] = mark;
					a2=true;
				}
				else if(choice == 5)
				{
					choice = 9;
					square[9] = mark;
					a3=true;
				}
				else
				{
					choice = 9;
					square[9] = mark;
					a4=true;
				}
			}
			
			if(c==5)
			
			{
				if(a1)
				{
					if(square[9] == '9')
					{
						square[9] = mark;
						choice = 9;
					}
					else
					{
						if(mov[2] == 6)
						{
							choice = 3;
							square[3] = mark;
							a11 = true;
						}
						else if(mov[2] == 8)
						{
							choice = 7;
							square[7] = mark;
							a12 = true;
						}
						else if(mov[2] == 2)
						{
							choice = 7;
							square[7] = mark;
							a13 = true;
						}
						else
						{
							choice = 3;
							square[3] = mark;
							a14 = true;
						}
					}
				}
				if(a2)
				{
					if(choice != 2)
					{
						square[2] = mark;
						choice = 2;
					}
					else
					{
						square[7] = mark;
						choice = 7;
						a21 = true;
					}
				}
				if(a3)
				{
					if(choice == 7)
					{
						square[3] = mark;
						choice = 3;
						a31 = true;
					}
					else if(choice == 3)
					{
						square[7] = mark;
						choice = 7;
						a32 = true;
					}
					else
					{
						a33 = true;
						if(choice == 2)
						{
							square[8] = mark;
							choice = 8;
							a331 = true;
						}
						if(choice == 8)
						{
							square[2] = mark;
							choice = 2;
							a332 = true;
						}
						if(choice == 4)
						{
							square[6] = mark;
							choice = 6;
							a333 = true;
						}
						if(choice == 6)
						{
							square[4] = mark;
							choice = 4;
							a334 = true;
						}
					}
				}
				if(a4)
				{
					if(choice != 5)
					{
						square[5] = mark;
						choice = 5;
					}
					else
					{
						if(mov[2] == 3)
						{
							square[7] = mark;
							choice = 7;
							a41 = true;
						}
						if(mov[2] == 7)
						{
							square[3] = mark;
							choice = 3;
							a42 = true;
						}		
					}
					
				}
			}
			
			if(c==7)
			{
				if(a1)
				{
					if(a11)
					{
						if(choice != 2)
						{
							choice = 2;
							square[2] = mark;
						}
						else
						{
							choice = 7;
							square[7] = mark;
						}
					}
					if(a12)
					{
						if(choice != 3)
						{
							choice = 3;
							square[3] = mark;
						}
						else
						{
							choice = 4;
							square[4] = mark;
						}
					}
					if(a13)
					{
						if(choice != 3)
						{
							choice = 3;
							square[3] = mark;
						}
						else
						{
							choice = 4;
							square[4] = mark;
						}
					}
					if(a14)
					{
						if(choice != 2)
						{
							choice = 2;
							square[2] = mark;
						}
						else
						{
							choice = 7;
							square[7] = mark;
						}
					}
				}
				
				if(a2)
				{
					if(a21)
					{
						if(choice != 5)
						{
							square[5] = mark;
							choice = 5;
						}
						else
						{
							square[4] = mark;
							choice = 4;
						}
					}
				}
				
				if(a3)
				{
					if(a31)
					{
						if(choice != 2)
						{
							square[2] = mark;
							choice = 2;
						}
						if(choice != 4)
						{
							square[4] = mark;
							choice = 4;
						}
					}
					if(a32)
					{
						if(choice != 4)
						{
							square[4] = mark;
							choice = 4;
						}
						if(choice != 8)
						{
							square[8] = mark;
							choice = 8;
						}
					}
					if(a33)
					{
						if(a331)
						{
							if(choice != 7)
							{
								square[7] = mark;
								choice = 7;
							}
							else
							{
								square[3] = mark;
								choice = 3;
							}
						}
						if(a332)
						{
							if(choice != 3)
							{
								square[3] = mark;
								choice = 3;
							}
							else
							{
								square[7] = mark;
								choice = 7;
							}
						}
						if(a333)
						{
							if(choice != 7)
							{
								square[7] = mark;
								choice = 7;
							}
							else
							{
								square[3] = mark;
								choice = 3;
							}
						}
						if(a334)
						{
							if(choice != 3)
							{
								square[3] = mark;
								choice = 3;
							}
							else
							{
								square[7] = mark;
								choice = 7;
							}
						}
					}
				}
				
				if(a4)
				{
					if(a41)
					{
						if(choice != 4)
						{
							square[4] = mark;
							choice = 4;
						}
						if(choice != 8)
						{
							square[8] = mark;
							choice = 8;
						}
					}
					if(a42)
					{
						if(choice != 2)
						{
							square[2] = mark;
							choice = 2;
						}
						if(choice != 6)
						{
							square[6] = mark;
							choice = 6;
						}
					}
				}
				
			}
			
			if(c==9)
			{
				if(a331)
				{
					if(choice != 6)
					{
						square[6] = mark;
						choice = 6;
					}
					else
					{
						square[4] = mark;
						choice = 4;
					}
				}
				if(a332)
				{
					if(choice != 8)
					{
						square[8] = mark;
						choice = 8;
					}
					else
					{
						square[2] = mark;
						choice = 2;
					}
				}
				if(a333)
				{
					if(choice != 2)
					{
						square[2] = mark;
						choice = 2;
					}
					else
					{
						square[8] = mark;
						choice = 8;
					}
				}
				if(a334)
				{
					if(choice != 4)
					{
						square[4] = mark;
						choice = 4;
					}
					else
					{
						square[6] = mark;
						choice = 6;
					}
				}
			}
			
			i = checkwin();

        	player++;
			
		}
		
		
		else
		{
			printf("%s, enter a number:  ", name);
        	scanf("%d", &choice);
			mov[c] = choice;
        

        	if (choice == 1 && square[1] == '1')
            	square[1] = mark;
            
        	else if (choice == 2 && square[2] == '2')
            	square[2] = mark;
            
        	else if (choice == 3 && square[3] == '3')
            	square[3] = mark;
            
        	else if (choice == 4 && square[4] == '4')
            	square[4] = mark;
            
        	else if (choice == 5 && square[5] == '5')
            	square[5] = mark;
            
        	else if (choice == 6 && square[6] == '6')
            	square[6] = mark;
            
        	else if (choice == 7 && square[7] == '7')
            	square[7] = mark;
            
        	else if (choice == 8 && square[8] == '8')
            	square[8] = mark;
            
        	else if (choice == 9 && square[9] == '9')
            	square[9] = mark;
            
        	else
        	{
            	printf("Invalid move ");

            	player--;
            	getch();
        	}
        	i = checkwin();

        	player++;
		}
        
        
    }while (i ==  - 1);
    
    board(player,choice);
    
    if (i == 1)
    {
    	if(player == 2)
    	{
    		printf("==>\aComputer wins ");
		}
		else
		{
			printf("==>\a%s win ", name);
		}
	}
        //printf("==>\aPlayer %d win ", --player);
        
    else
        printf("==>\aGame draw");

    getch();

    return 0;
}

/*********************************************

FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT
 **********************************************/

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
        
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
        
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
        
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
        
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
        
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
        
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
        
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
        
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] 
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}


