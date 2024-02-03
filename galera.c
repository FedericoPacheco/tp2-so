#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#define golpesVarita 3
#define demoraEntregaObsequio 2

void sacarObsequio(int pid, int ObsequioNumero);

int main (int argc, char* argv[])
{
	int obsequioNumero, pidMago;

	srand(time(NULL));
	for(pidMago = atoi(argv[1]), obsequioNumero = 1; obsequioNumero <= 10; obsequioNumero++)
	{	
		sleep(golpesVarita);     
		sacarObsequio(pidMago, obsequioNumero);
		sleep(demoraEntregaObsequio);
	}

	return 0;
}

void sacarObsequio(int pid, int obsequioNumero)    
{
	if (rand() % 2)     // se usan dos seniales para diferenciar flores de golosinas
	{	
		printf("Es una FLOR: %i\n", obsequioNumero);	
		kill(pid, SIGUSR1);    
	}
	else
	{
		printf("Es una GOLOSINA: %i\n", obsequioNumero);		
		kill(pid, SIGUSR2);   
	}
}


