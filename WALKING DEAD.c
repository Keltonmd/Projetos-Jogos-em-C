#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gconio.h>

int interface(int opt){
	int x;
	if(opt == 1){
		gotoxy(0,0);
		printf("---===============>> WALKING DEAD <<===============---\n");
		printf("\n");
		printf("Alô Rick Grimes! Você precisa atravessar a cidade repleta de zumbis\n");
		printf("assassinos com apenas um rifle com 50 munições.\n");
		printf("Cada quarteirão da cidade possui a quantidade de zumbis indicado pelo\n");
		printf("número impresso, e você só pode percorrer cada quarteirão uma única vez!\n");
		printf("\n");
		printf("Você será capaz de sair vivo desse desafio?\n");
		printf("\n");
		printf("Teclas de navegação:");
		printf("\n\n");
		printf("\tw");
		printf("\n\n");
		printf("a\t\td\n");
		printf("\n\n");
		printf("\ts\n");
		printf("\n");
		printf("Pressione 'x' para encerrar o jogo.\n");
		printf("\n");
		printf("Pressione ENTER para começar...");
		setbuf(stdin, NULL);
		getchar();
		return 1;
	}else{
		clrscr();
		printf("1 - Jogar novamente\n2 - Encerrar o game\n");
		scanf(" %d", &x);
		setbuf(stdin, NULL);
		return x;
	}
}

void caminho(int v[][10], char t[][10]){
	for(int x = 0 ; x < 10; x++)
		for(int y = 0; y < 10; y++)
			v[x][y] = rand() % 10;
			
	for(int x = 0 ; x < 10; x++)
		for(int y = 0; y < 10; y++)
			t[x][y] = v[x][y] + '0';
	
}

void jogo(){
	int v[10][10], mov, x = -1, y = 0, aux, soma = 0;
	char t[10][10];
	
	clrscr();
	
	caminho(v, t);
	
	do{
		gotoxy(0, 0);
		printf("*");
		
		gotoxy(0, 2);
		
		for(int x = 0 ; x < 10; x++)
		{
			for(int y = 0; y < 10; y++)
				printf("%c ", t[x][y]);
				
			printf("\n");
		}
		
		gotoxy(18, 12);
		printf("[@]");
		
		gotoxy(0, 14);
		
		printf("MUNICAO GASTA: %d/50", soma);
		
		mov = getch();
		
		if(mov == 'a' || mov == 'd' || mov == 's' || mov == 'w' || mov == 'x')
		{
			gotoxy(0, 15);
			printf("                     ");
			if(mov == 'x')
			{
				gotoxy(0, 16);
				printf("Voce se exterminou!\n");
				printf("Game Encerrado!\n");
				printf("Digite ENTER ");
				setbuf(stdin, NULL);
				getchar();
				break;
			}
			
			if(x < 0)
			{
				if(mov == 's')
				{
					x++;
					soma += v[x][y];
					t[x][y] = '*';
					gotoxy(0, 15);
					printf("                     ");
				}
				else
				{
					gotoxy(0, 15);
					printf("Movimento Irregular");
					
				}
			}
			else
			{
				switch (mov){
					case 'd' : aux = y;
							y++;
							if((y >= 0 && y < 10) && (t[x][y] != '*'))
							{
								soma += v[x][y];
								t[x][y] = '*';
								gotoxy(0, 15);
								printf("                     ");
							}
							else
							{
								y = aux;
								gotoxy(0, 15);
								printf("Movimento Irregular");
							}
							
							break;
							
					case 's' : aux = x;
							x++;
							if(x == 10 && y == 9)
							{
								gotoxy(0, 16);
								printf("Parabens voce encontou a saida!\n");
								printf("Digite ENTER ");
								setbuf(stdin, NULL);
								getchar();
								break;
							}
							else
								if((x >= 0 && x < 10) && (t[x][y] != '*'))
								{
									soma += v[x][y];
									t[x][y] = '*';
									gotoxy(0, 15);
									printf("                     ");
								}
								else
								{
									x = aux;
									gotoxy(0, 15);
									printf("Movimento Irregular");
								}
							
							break;
							
					case 'a' : aux = y;
							y--;
							if((y >= 0 && y < 10) && (t[x][y] != '*'))
							{
								soma += v[x][y];
								t[x][y] = '*';
								gotoxy(0, 15);
								printf("                     ");
							}
							else
							{
								y = aux;
								gotoxy(0, 15);
								printf("Movimento Irregular");
							}
							
							break;
							
					case 'w' : aux = x;
							x--;
							if((x >= 0 && x < 10) && (t[x][y] != '*'))
							{
								soma += v[x][y];
								t[x][y] = '*';
								gotoxy(0, 15);
								printf("                     ");
							}
							else
							{
								x = aux;
								gotoxy(0, 15);
								printf("Movimento Irregular");
							}
							
							break;
					}
				}
			}
			else
			{
				gotoxy(0, 15);
				printf("Movimento Irregular");
			}
			
		if(x == 10 && y == 9)
		break;
		
		gotoxy(0, 14);
		
		printf("MUNICAO GASTA: %d/50", soma);
		
		if(soma > 50)
		{
			gotoxy(0, 16);
			printf("Voce se exterminou!\n");
			printf("Game Encerrado!\n");
			printf("Digite ENTER ");
			setbuf(stdin, NULL);
			getchar();
			break;
		}			
	}while(1);
}

int main()
{
	int x = 1;
	srand(time(NULL));

	do{
		switch(interface(x)){
			case 1: jogo();
					x = 2;
					break;
			default: return 0;
		}
		
	}while(1);
	
    return 0;
}


