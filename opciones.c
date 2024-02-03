#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

void longitudCadena(char*);
void vocalesCadena(char*);
void vocalEnPosicion(char*, int);
int esVocal(char);                     // En C no existen booleans

int main (int argc, char* argv[])
{
	int i, ch;
	
	opterr = 0;   // evitar que se imprima el mensaje de error por defecto                 
	ch = getopt(argc, argv, "lvp:");
	while(ch != -1)	
	{
		switch(ch)
		{
			case 'l':	
				longitudCadena(argv[0]);
				break;
			case 'v':
				vocalesCadena(argv[0]);
				break;
			case 'p':
				vocalEnPosicion(argv[0], atoi(optarg));
				break;
			default:					
				printf("Error. %c: opcion no valida.\n", optopt);
				break;
		}
		printf("\n");

		ch = getopt(argc, argv, "lvp:");
	}
	
	printf("Cantidad de argumentos: %i\n", argc);	
	
	for(i = 0; i < argc; i++){
		printf("Argumento[%i]: %s\n", i, argv[i]);
	}
	
	return 0;
}

void longitudCadena(char* str)
{
	printf("Longitud: %i\n", strlen(str));
}

void vocalesCadena(char* str)
{
	int i;

	for(i = 0; i < strlen(str); i++)	
		if (esVocal(str[i]))
			printf("Vocal [%i] = %c\n", i, str[i]);
}

int esVocal(char ch)
{
	char ch2 = tolower(ch);
	
	if(ch2 == 'a' || ch2 == 'e' || ch2 == 'i' || ch2 == 'o' || ch2 == 'u')
		return 1;
	else
		return 0;
}

void vocalEnPosicion(char* str, int i)
{
	if (i < strlen(str))
		if(esVocal(str[i]))
			printf("Posicion vocal [%i] = %c\n", i, str[i]);
		else
			printf("No es vocal [%i] = %c\n", i, str[i]);
	else
		printf("Error. Posicion fuera de los limites  de la cadena.\n");
}


 
