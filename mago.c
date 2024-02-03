#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#define demoraEntregaObsequio 2

int obsequioNumero = 1;

void entregarFlor();
void entregarGolosina();

int main (int argc, char* argv[])
{
	signal(SIGUSR1, &entregarFlor);
	signal(SIGUSR2, &entregarGolosina);

	while (obsequioNumero <= 10)
		/*pause()*/;   // no conveniente: se bloquea el proceso y no puede verse su pid usando el comando top

	return 0;
}

void entregarFlor()
{
	printf("Ha salido un obsequio para ustedes.\n");	
	sleep(demoraEntregaObsequio);
	printf("Dama, esta flor es para usted.(%i)\n", obsequioNumero);
	obsequioNumero++;
}

void entregarGolosina()
{
	printf("Ha salido un obsequio para ustedes.\n");
	sleep(demoraEntregaObsequio);	
	printf("Esta golosina es para vos, niño.(%i)\n", obsequioNumero);
	obsequioNumero++;
}

