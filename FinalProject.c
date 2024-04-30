/* 
Partner 1: Julian Cardiel
Partner 2: Justin Renner-Brodie
4-29-2024
Image Editor
*/

#include <stdio.h>

#define Max_Row 500
#define Max_Col 500

void LoadImage(int *ProR, int *ProC, char ImageArray[][Max_Col]);

void displayImage(int *Rows, int *Col, char ImageArray[][Max_Col]);

void ProcessImage(int *Rows, int *Col, char Arr[][Max_Col], char ProArr[][Max_Col]);

int main(){
	
	//user Choice
	int choice;
	
	//end Program Bool
	_Bool End = 0;
	
	//Store Image
	int ProR, ProC;
	char Image[ProR][ProC];
	char ProImage[ProR][ProC];
	
	
	//does this while End is false
	do{
	//Print to screen
	printf("***0^ Image Editor ^0***\n\n");
	printf("Please input one of the Following Choices (1,2,3):\n\n");
	printf("1. Load Image\n");
	printf("2. Edit Image\n");	
	printf("3. Close Program\n\n");

	//User Input
	scanf("%d", &choice);
	
		//Does user Choice
		switch(choice){
			
			//Load Image
			case 1:
				printf("\n\nLoading Image\n\n");
				
				
				//Load Image
				LoadImage(&ProR, &ProC, Image);	

				//Process Image
				ProcessImage(&ProR, &ProC, Image, ProImage);
				printf("______________________________________\n\n");

				displayImage(&ProR,&ProC,ProImage);
				
				printf("______________________________________\n");
				break;
				

	
			//Edit Image
			case 2: 
				printf("\n\nEditing Image\n\n");
				break;
				
			//Closing Program
			case 3:
				printf("\n\nClosing Program\n\n");
				End = 1;
				break;
			
			//ERROR
			default:
				printf("\n\nPlease put a new Input\n\n");
				break;
		}
	
	}while(End != 1);
	
return 0;
}

//FUNCTIONS


//LOAD IMAGE FROM FILE
void LoadImage(int *ProR, int *ProC, char ImageArray[][Max_Col]){
	
	FILE *FP;
	char FileName[1000];
	int Rows = 0, Cols = 0;
	
		//Reset array
		for(int i = 0; i < *ProR; i++){
			for(int j = 0; j< *ProC; j++){
				ImageArray[i][j] = 0;
			}
		}
	
		//ask for file name
		printf("Please put in the File Name\n");
		scanf("%s", FileName);
		
		//Opens File or Errors
		FP = fopen(FileName, "r");
			
			//NO SUCH FILE
			if(FP == NULL){

				printf("Error Opening File. \n");					
			
			//FOUND FILE
			}else{
				
			
				
					
				//Store Data in array
				for(Rows = 0; Rows < Max_Row; Rows++){
								
							fgets(ImageArray[Rows], (Max_Row+1), FP);
							
						
				}
				fclose(FP);
				
				//Get Size Of Row And Column
				for(Rows = 0; ImageArray[Rows][0] != '\0' && ImageArray[Rows][0] != '\n'; Rows++){}
					*ProR = Rows;
				
					
				for(Cols = 0; ImageArray[0][Cols] != '\0' && ImageArray[0][Cols] != '\n'; Cols++){}
					*ProC = Cols;		
			}
			
}	






//PROCESSING Array
void ProcessImage(int *Rows, int *Col, char Arr[][Max_Col], char ProArr[][Max_Col]){

char CurChar;
	
	//transfers Numbers to brightness
	for(int i = 0; i < *Rows; i++){
		for (int j = 0; j < *Col; j++){
		
			CurChar = Arr[i][j];
			
			switch(CurChar){
			
			case 48:
				ProArr[i][j] = ' ';
				break;
				
			case 49:
				ProArr[i][j] = '.';
				break;
				
			case 50:
				ProArr[i][j] = 'o';
				break;
				
			case 51: 
				ProArr[i][j] = 'O';
				break;
				
			case 52:
				ProArr[i][j] = '0';
				break;
				
			default: 
				printf("ERROR ON Row %d, Column %d\n", i,j);
				break;
			}
		}
	}
				
}


//DISPLAYING Raw Data IMAGE
void displayImage(int *Rows, int *Col, char ImageArray[][Max_Col]){
		
	for(int i = 0; i < *Rows; i++){
		for(int j = 0; j < *Col; j++){
			printf("%c",ImageArray[i][j]);
		}
		printf("\n");
	}	
}

