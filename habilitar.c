#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#define rutaUsuario 	"./usuario"
#define rutaClave 	"./clave"
#define rutaNombresTxt 	"./nombres.txt"
#define rutaUsuariosTxt "./usuarios.txt"

int main (int argc, char* argv[], char* envp[])
{
	int tuberia[2];
	int* aux;

	pipe(tuberia);

	if (!fork())    					 // en el hijo
	{
		close(0);   					 // cerrar entrada estandar
		open(rutaNombresTxt, O_RDONLY);   		 // entrada desde nombres.txt		
		
		close(tuberia[0]);    				 // cerrar lectura tuberia
		close(1);   					 // cerrar salida estandar
		dup(tuberia[1]);  				 // salida a la tuberia	

		execve(rutaUsuario, argv, envp);		 // ./usuario ...	
	}
	else							 // en el padre
	{
		wait(aux);
		
		close(0);					
		dup(tuberia[0]); 				// entrada desde tuberia

		close(tuberia[1]);				// cerrar escritura tuberia
		close(1);
		open(rutaUsuariosTxt, O_CREAT | O_WRONLY);  	// salida a usuarios.txt
		
		execve(rutaClave, argv, envp);			// ./clave ...
	}

	return 0;
}
