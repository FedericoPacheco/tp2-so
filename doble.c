#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[], char* envp[])
{
	printf("Escena de riesgo: %s = %i.\n", argv[1], strlen(argv[1]));
	printf("Yo %i lo he logrado.\n", getpid());

	return 0;
}
