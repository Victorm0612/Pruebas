#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char** argv)
{
	if(argc != 2)//comprobar que solo hayan dos argumentos
	{
		printf("Requiere un solo nombre de programa\n");
		exit(0);
	}
	//fragmento para extraer el nombre del programa
	char program_arg[60];
	strcpy(program_arg, "/");//anteponerle un / para luego ser concatenado
	strcat(program_arg, argv[1]);
	
	//declarar variables e igualar path a la cadena global PATH que contiene las rutas
	char *split_path;
	char program_path[100];
	char *path = getenv("PATH");
	
	split_path = strtok (path,":");//partir cadena
	int i = 0;//bandera usada para comprobar si almenos encontro en alguna coincidencia
	while (split_path!= NULL)
	{
		strcpy(program_path, "");//asignar vacio a program_path
		strcat(program_path, split_path);//concatenar a program_path la ruta que se esta analizando
		strcat(program_path, program_arg);//concatenar a program_path el nombre del programa a analizar
		if(access(program_path, F_OK) != -1 )//verificar si existe el archivo 
		{
			printf("El programa se encuentra en %s\n",program_path);
			i++;
		}
		split_path = strtok (NULL, ":");//indicarle al puntero que se mueva hacia la siguiente cadena
	}
	if(i==0)
		printf("No se encontro el comando en ninguna directorio de PATH\n");

	return 0;
}
