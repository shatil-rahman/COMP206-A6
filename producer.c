#include <stdio.h>
#include <stdlib.h>

void producer(){

	char turn;
	char data;
	char text;
	FILE *mydata;

	while((mydata = fopen("mydata.txt", "r")) == NULL);

	int counter = 0;

	while(1){
		counter++;

		FILE *t;	
		FILE *d;
		
		// Checking who's turn it is
		while(fopen("TURN.txt", "r") == NULL); // 
		t = fopen("TURN.txt", "r");
		turn = fgetc(t);

		if(turn == '0'){ // if producer's turn
			
			text = fgetc(mydata);
			//printf("Producer read %c from mydata.txt\n", text );
			fclose(t);
			t = NULL;

			while((t = fopen("TURN.txt", "w")) == NULL);
			while((d = fopen("DATA.txt", "w")) == NULL);

			if(feof(mydata)){ //if reached end of mydata.txt, will signal this in TURN for consumer
				fprintf(t, "e\n");
				fclose(t);
				fclose(d);
				fclose(mydata);
				t = NULL;
				d = NULL;
				mydata = NULL;
				break;
			}


			fprintf(d, "%c\n", text); //writing to DATA.txt
			fprintf(t, "1\n"); // writing to TURN.txt

			fclose(d);
			d = NULL;

		}
		
		if(t!= NULL){
			fclose(t);
		}
	
	}



}