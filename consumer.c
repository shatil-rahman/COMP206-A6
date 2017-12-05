#include <stdio.h>
#include <stdlib.h>

void consumer(){
	
	
	char turn;
	char data;

	while(1){

		FILE *t;	
		FILE *d;
		// Checking who's turn it is
		while((t = fopen("TURN.txt", "r")) == NULL); // busy loop
		turn = fgetc(t);
		
		if(turn == 'e'){ //if DATA.txt is empty, exit the main loop
				
				d = NULL;
				fclose(t);
				t = NULL;
				
				break; 
			}

		if(turn == '1'){ // waiting until TURN is  1, ie consumer's turn
			while((d = fopen("DATA.txt", "r")) == NULL); // busy loop
			
			data = fgetc(d);
			
			
			// printing whats on DATA.txt
			printf("%c", data);
			
			fclose(t); 
			t = NULL;
			
			while(fopen("TURN.txt", "w") == NULL); // setting TURN to 0
			FILE *newTurn = fopen("TURN.txt", "w");
			
			fprintf(newTurn, "0\n");
			fclose(newTurn);
			newTurn = NULL;

			fclose(d);
			d = NULL;
			


		}

		if(t!= NULL){
			fclose(t);	
		}
		
		
	}


	
}