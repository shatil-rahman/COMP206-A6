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
		while(fopen("TURN.txt", "r") == NULL); // busy loop
		t = fopen("TURN.txt", "r");
		turn = fgetc(t);
		//printf("Producer read %c from TURN.txt", turn);

		if(turn == '0'){
			
			text = fgetc(mydata);
			//printf("Producer read %c from mydata.txt\n", text );
			fclose(t);
			t = NULL;

			while((t = fopen("TURN.txt", "w")) == NULL);
			while((d = fopen("DATA.txt", "w")) == NULL);

			if(feof(mydata)){
				fprintf(t, "e\n");
				fclose(t);
				fclose(d);
				fclose(mydata);
				t = NULL;
				d = NULL;
				mydata = NULL;
				break;
			}


			fprintf(d, "%c\n", text);
			fprintf(t, "1\n");

			fclose(d);
			d = NULL;

		}




		
		if(t!= NULL){
			fclose(t);
		}
		//printf("reached here before the error producer %d\n", counter);
	}

	//printf("finally exited the loop Producer at %d\n", counter);


	//fclose(mydata);

}