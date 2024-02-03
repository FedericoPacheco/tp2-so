#include <stdio.h>
#define T 128

int main ()
{
	char str[T];	
	
	while(scanf("%s", &str) == 1)    // scanf retorna el numero de variables que pudo leer correctamente		
		printf("u%s\n", str);	

	return 0;
}

