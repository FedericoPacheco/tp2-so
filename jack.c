#include <stdio.h>
#define rutaDoble "./doble"

int main(int argc, char* argv[], char* envp[])
{
	printf("Soy el gran Jack: %i.\n", getpid());
	execve(rutaDoble, argv, envp);                           
	printf("Toma siguiente, no pudo correrse la escena.\n");      // en caso de error

	return 0;
}
