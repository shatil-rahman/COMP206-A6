#include <stdio.h>
#include <stdlib.h>

void consumer(){
	FILE *t;
	FILE *d;
	char turn;
	char data;

	while(1){
		// Checking who's turn it is
		while((t = fopen("TURN.txt", "r")) == NULL); // busy loop
		turn = getc(t);
		fclose(t);

		if(turn == '1'){ // waiting until TURN is  1, ie consumer's turn
			while((d = fopen("DATA.txt", "r")) == NULL); // busy loop
			
			data = getc(d);
			fclose(d);
			if(feof(d)) break; //if DATA.txt is empty, exit the main loop
			printf("%c", data);
			

			while((t = fopen("TURN.txt", "w")) == NULL);
			fprintf(t, "0");
			fclose(t);


		}
		

		// Reading when its consumer's turn
		



	}

	
}