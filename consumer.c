#include <stdio.h>
#include <stdlib.h>

void consumer(){
	
	
	char turn;
	char data;

	int counter = 0;

	while(1){
		counter++;
		FILE *t;	
		FILE *d;
		// Checking who's turn it is
		while((t = fopen("TURN.txt", "r")) == NULL); // busy loop
		turn = fgetc(t);
		//printf("consumer has read %c from TURN.txt\n", turn);
		if(turn == 'e'){
				//fclose(d);
				d = NULL;
				fclose(t);
				t = NULL;
				//printf("reached the end before the error consumer %d\n", counter);
				break; //if DATA.txt is empty, exit the main loop
			}

		if(turn == '1'){ // waiting until TURN is  1, ie consumer's turn
			while((d = fopen("DATA.txt", "r")) == NULL); // busy loop
			
			data = fgetc(d);
			//printf("consumer has read %c from DATA.txt\n", data);
			
			 
			printf("%c", data);
			
			fclose(t);
			t = NULL;
			
			while(fopen("TURN.txt", "w") == NULL);
			FILE *newTurn = fopen("TURN.txt", "w");
			
			fprintf(newTurn, "0\n");
			fclose(newTurn);
			newTurn = NULL;

			fclose(d);
			d = NULL;
			//printf("reached here before the error consumer %d\n", counter);


		}

		if(t!= NULL){
			fclose(t);	
		}
		
		

		
		



	}

	//printf("finally exited the loop Consumer at %d\n", counter);

	
}