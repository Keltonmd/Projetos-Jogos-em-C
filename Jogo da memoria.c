#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gconio.h>

int main(){
	int mem[100], lem[100], sort = 0, acert = 0, l = 0;
	
	srand(time(NULL));
	
	for(int i = 0; i < 100; i++)
	{
		mem[i] = rand() % 101;
		sort++;
		printf("Numero da sequencia\n");
		printf("%d\n", mem[i]);
		printf("Digite a sequencia\n");
			
		for(int x = 0; x < sort; x++)
		{
			scanf(" %d", &lem[x]);
			l += 5;
			gotoxy(l, 4);
		}
		l = 0;
			
		for(int z = 0; z < sort; z++)
		{
			if(mem[z] == lem[z])
			acert++;
		}
		clrscr();
		if(acert != sort)
		{
			printf("Sequencia incorreta!\n");
			break;
		}
		else
		acert = 0;
	}
	
	return 0;
}
