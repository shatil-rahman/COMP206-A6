#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//Name 1: Shatil Rahman
//ID: 260606042

//Name 2: Adeeb Ibne Amjad
//ID: 260625272

int main(){

	int status;
	int pid = fork();
	if( pid == -1) exit(1);

	FILE *turn = fopen("TURN.txt", "w");

	fprintf(turn, "0");

	fclose(turn);

	if(pid == 0){
		consumer();
		//wait();
	}

	if(pid != 0){
		producer();
		wait(&status);
	}




	return 0;
}