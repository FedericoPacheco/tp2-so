#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <dirent.h>
#include <string.h>
#define T 128

int mostrarError = 0;

void listarContenidoDirectorio(char* ruta, int esDirectorioActual, int mostrarTipo, int mostrarINodo); // en C no hay tipo de dato boolean
void decidirQueListar(char* argvEnOptind, int mostrarTipo, int mostrarINodo);
void decirTipo(unsigned char ch);
void mostrarTitulo(char* ruta, int esDirectorioActual, int mostrarTipo, int mostrarINodo);
int esPuntoOEsPuntoPunto(char* nombreDirectorio);

int main (int argc, char* argv[])
{
	int i, ch, opciones[3], cantidadOpciones;	
	
	cantidadOpciones = 0;
	ch = getopt(argc, argv, "lti");
	while(ch != -1)	
	{
		opciones[cantidadOpciones] = ch;		
		cantidadOpciones++;
				
		ch = getopt(argc, argv, "lti");
	}

	i = 0; 
	while((i < cantidadOpciones) && !mostrarError)
	{
		switch(opciones[i])
		{
			case 'l':
				decidirQueListar(argv[optind], 0, 0);
				break;
			case 't':
				decidirQueListar(argv[optind], 1, 0);
				break;
			case 'i':	
				decidirQueListar(argv[optind], 0, 1);
				break;
		}

		i++;
	}

	if (mostrarError)
		printf("Error. Directorio no valido.\n");	
	
	return 0;
}

void listarContenidoDirectorio(char* ruta, int esDirectorioActual, int mostrarTipo, int mostrarINodo)
{
	DIR* directorio;
	struct dirent* entradaDirectorio;

	directorio = opendir(ruta);
	if(directorio == NULL)
		mostrarError = 1;
	else
	{
		mostrarTitulo(ruta, esDirectorioActual, mostrarTipo, mostrarINodo);		
			
		entradaDirectorio = readdir(directorio);
		while (entradaDirectorio != NULL)
		{
			if (!esPuntoOEsPuntoPunto(entradaDirectorio -> d_name))	
			{
				printf("%s", entradaDirectorio -> d_name);
				if(mostrarINodo)
					printf(" - %i", entradaDirectorio -> d_ino);
				if(mostrarTipo)
				{
					printf(" - ");
					decirTipo(entradaDirectorio -> d_type);
				}
				printf("\n");
			}	
		
			entradaDirectorio = readdir(directorio);
		} 

		printf("\n");
	}

}

void decidirQueListar(char* argvEnOptind, int mostrarTipo, int mostrarINodo)
{
	char directorioActual[T];
	
	getcwd(directorioActual, T);
	if (argvEnOptind == NULL)					
		listarContenidoDirectorio(directorioActual, 1, mostrarTipo, mostrarINodo);
	else
		listarContenidoDirectorio(argvEnOptind, 0, mostrarTipo, mostrarINodo);
}

void decirTipo (unsigned char ch)
{
	char str[40];	

	switch(ch)
	{
		case DT_REG:
			strcpy(str, "Regular");	
			break;
		case DT_DIR:
			strcpy(str, "Directorio");
			break;
		case DT_FIFO:
			strcpy(str, "FIFO");                      // nombre dudoso
			break;
		case DT_SOCK:
			strcpy(str, "Socket de dominio local");   // nombre dudoso
			break;
		case DT_CHR:
			strcpy(str, "Especial de dispositivo de caracteres");
			break;
		case DT_BLK:
			strcpy(str, "Especial de dispositivo de bloques");
			break;
		case DT_LNK:
			strcpy(str, "Enlace simbolico");
			break;
	}

	printf("%s", str);
}

void mostrarTitulo(char* ruta, int esDirectorioActual, int mostrarTipo, int mostrarINodo)
{
	if (esDirectorioActual)	
	{	
		if (!mostrarTipo && !mostrarINodo)
			printf("Listado del directorio actual:\n");
		else if (!mostrarTipo && mostrarINodo)
			printf("Numero de inodo de archivos del directorio actual:\n");
		else
			printf("Tipos de archivos del directorio actual:\n");
	}
	else
	{
		if (!mostrarTipo && !mostrarINodo)
			printf("Listado del directorio %s:\n", ruta);
		else if (!mostrarTipo && mostrarINodo)
			printf("Numero de inodo de archivos del directorio %s:\n", ruta);
		else
			printf("Tipos de archivos del directorio %s:\n", ruta);
	}
}

int esPuntoOEsPuntoPunto(char* nombreDirectorio)
{
	return (!strcmp(".", nombreDirectorio) || !strcmp("..", nombreDirectorio));
}

