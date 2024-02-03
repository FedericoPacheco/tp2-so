#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <ctype.h>

void imprimirMensaje(char* hijo, char* padre, int valor);

int main(int argc, char* argv[])
{
	int valor;
	int* aux;

	valor = atoi(argv[1]);
	printf("\nNODO R - VALOR = %i\n", valor);
	printf("ID proceso principal: %i\n\n", getpid());
	
	if (!fork())    // pid = 0, en el hijo
	{
		valor += 100;
		imprimirMensaje("1", "R", valor);

		if (!fork())
		{
			valor *= 2;
			imprimirMensaje("1.1", "1", valor);
		}
		else
		{
			wait(aux);     // esperar a que el hijo termine
			if (!fork())
			{
				valor /= 2;
				imprimirMensaje("1.2", "1", valor);
			}
		}
	}
	else
	{
		wait(aux);
		if (!fork())
		{
			valor -= 100;
			imprimirMensaje("2", "R", valor);
		}
	}

	return 0;
}

void imprimirMensaje(char* hijo, char* padre, int valor)
{
	printf("NODO %s - VALOR = %i\n", hijo, valor);
	printf("ID NODO %s: %i - ID padre NODO %s(NODO %s): %i\n\n", hijo, getpid(), hijo, padre, getppid());
}


