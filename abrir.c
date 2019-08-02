#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char** argv) {
	FILE* archivo = fopen("archivoPrueba", "r+");
	int pid = fork();

	if (pid == 0) {
		fprintf(archivo, "Proceso hijo escribiendo \n");
	}
	else {
		wait(NULL);
		fprintf(archivo, "Proceso padre escribiendo \n");
	}

	int caracter; 
	while ((caracter = fgetc(archivo)) != EOF) {
		printf("%c\n", caracter);
	}
	fclose(archivo);

	return 0;
}
