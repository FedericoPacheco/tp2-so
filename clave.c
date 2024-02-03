#include <stdio.h>
#include <string.h>
#define numeroFijo "2718" // itoa no funciona (no olvidar las comillas)  
#define T 128

int main ()
{
	char str[T];	
	
	while(scanf("%s", &str) == 1)    // scanf retorna el numero de variables que pudo leer correctamente		
	{
		strcat(str, numeroFijo);		
		printf("%s\n", str);
	}	

	return 0;
}
