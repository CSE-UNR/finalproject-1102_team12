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

void BrightImage(int *Rows, int *Col, char ProArr[][Max_Col]);

void DimImage(int *Rows, int *Col, char ProArr[][Max_Col]);

void CropImage(int *Rows, int *Col, char ProArr[][Max_Col]);

void SaveImage(int *Rows, int *Col, char ProArr[][Max_Col]);

int main(){
	
	//user Choice
	int choice;
	int choiceTwo;
	int save;
	//end Program Bool
	_Bool End = 0;
	
	//Store Image
	int ProR, ProC;
	char Image[ProR][ProC];
	char ProImage[ProR][ProC];
	
	
	//does this while End is false
	do{
	//Print to screen
	printf("\n\n***0^ Image Editor ^0***\n\n");
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
					
					if(ProImage[0][0] != 0){
						displayImage(&ProR,&ProC,ProImage);
					}
				break;
				

	
			//Edit Image
			case 2: 
			
				if(ProImage[0][0] == 0){
					printf("\nNo Image Loaded");			
				}else{
					printf("\n\nEditing Image\n\n");
				
					printf("Please Choose an Editing Option(1,2,3)\n");
					printf("1. Brighten Image\n");
					printf("2. Dim Image\n");
					printf("3. Crop Image\n");
					
					//User Input
					scanf("%d", &choiceTwo);
					
						//Brighten Image
						if(choiceTwo == 1){
						
							BrightImage(&ProR,&ProC,ProImage);
							displayImage(&ProR,&ProC,ProImage);
						
						//Dim Image
						}else if(choiceTwo == 2){
						
							DimImage(&ProR,&ProC,ProImage);
							displayImage(&ProR,&ProC,ProImage);
						
						//Crop Image
						}else if(choiceTwo == 3){
						
							CropImage(&ProR,&ProC,ProImage);
							displayImage(&ProR,&ProC,ProImage);
						
						//Error
						}else{
						
							printf("\n\nInvalid Option\n\n");
						}
						
						printf("Would you like to Save The Image?(1 - Yes, 2 - No)\n");
						scanf("%d",&save);
						
							if(save == 1){
								SaveImage(&ProR,&ProC,ProImage);
							}	
					}
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

int CurChar;
int ValidImage = 0;
	
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
			
				ValidImage = 1;
				break;
			}
		}
	}
	
	if(ValidImage == 1){
	
		printf("\n\nImage is Invalid please input a Valid Image or Fix Your Image\n");
	
		//Reset array
		for(int i = 0; i < *Rows; i++){
			for(int j = 0; j< *Col; j++){
				Arr[i][j] = 0;
				ProArr[i][j] = 0;
			}
		}
	}				
}


//DISPLAYING Raw Data IMAGE
void displayImage(int *Rows, int *Col, char ImageArray[][Max_Col]){
		
	printf("______________________________________\n\n");		
		
	for(int i = 0; i < *Rows; i++){
		for(int j = 0; j < *Col; j++){
			printf("%c",ImageArray[i][j]);
		}
		printf("\n");
	}
	
	printf("______________________________________\n\n");	
}

//Brightening Image
void BrightImage(int *Rows, int *Col, char ProArr[][Max_Col]){

int CurValue;
	
	//Brightens Image
	for(int i = 0; i < *Rows; i++){
		for(int j = 0; j < *Col; j++){
			
		CurValue = ProArr[i][j];
			
			switch(CurValue){
			
			case 32:
				ProArr[i][j] = '.';
				break;
				
			case 46:
				ProArr[i][j] = 'o';
				break;
				
			case 111:
				ProArr[i][j] = 'O';
				break;
				
			case 79: 
				ProArr[i][j] = '0';
				break;
				
			case 48:
				ProArr[i][j] = '0';
				break;
				
			default: 
				printf("ERROR ON Row %d, Column %d\n", i,j);
				break;
			}
		}
	}

}


//Dim Image
void DimImage(int *Rows, int *Col, char ProArr[][Max_Col]){

int CurValue;
	
	//Brightens Image
	for(int i = 0; i < *Rows; i++){
		for(int j = 0; j < *Col; j++){
			
		CurValue = ProArr[i][j];
			
			switch(CurValue){
			
			case 32:
				ProArr[i][j] = ' ';
				break;
				
			case 46:
				ProArr[i][j] = ' ';
				break;
				
			case 111:
				ProArr[i][j] = '.';
				break;
				
			case 79: 
				ProArr[i][j] = 'o';
				break;
				
			case 48:
				ProArr[i][j] = 'O';
				break;
				
			default: 
				printf("ERROR ON Row %d, Column %d\n", i,j);
				break;
			}
		}
	}

}


void CropImage(int *Rows, int *Col, char ProArr[][Max_Col]){

	int CropR = 0;
	int CropC = 0;
	int ValidR = 0;
	int ValidC = 0;
	int Valid = 0;
	int nRows = 0, nCols = 0;


		//keeps asking till valid number
		do{
			do{
				printf("What Row would you like to Crop at?\nThe First Row Starts at 0\n\n");
				scanf("%d", &CropR);
	
					//Checks if valid row to crop
					if(CropR > *Rows){
						printf("Your Image is smaller than than where you want to crop on Rows\n\n");
						ValidR = 0;
					}else{
						ValidR =1;
					}
			}while(ValidR == 0);
			
			
			do{
				printf("What Column would you like to Crop at?\nThe First Column Starts at 0\n\n");
				scanf("%d", &CropC);
				
					
					//Checks if Valid Columns
					if(CropC > *Col){
						printf("Your Image is smaller than than where you want to crop on Columns\n\n");
						ValidC = 0;
					}else{
						ValidC =1;
					}
			}while(ValidC == 0);	
			
				printf("You want to Crop at Row: %d\n You want to Crop at Column: %d\n Is this Correct? (1-Yes 2-No)\n\n", CropR, CropC);
				scanf("%d",&Valid);

		}while(Valid != 1);

	//goes through array and checks if its greater than crop location
	for (int i = 0; i < *Rows; i++){
		for(int j = 0; j < *Col; j++){
			if(i >= CropR || j >= CropC){
			
				ProArr[i][j] = 0;
			}
		}
	}
				//Makes New Max Row And Collumn
	for(nRows = 0; ProArr[nRows][0] != '\0' && ProArr[nRows][0] != '\n'; nRows++){}
		*Rows = nRows;
				
	for(nCols = 0; ProArr[0][nCols] != '\0' && ProArr[0][nCols] != '\n'; nCols++){}
		*Col = nCols;	
}
		
void SaveImage(int *Rows, int *Col, char ProArr[][Max_Col]){

	FILE *FP;
	char FileName[1000];

		//ask for file name
		printf("Please put in the File Name you wish to save to\n");
		scanf("%s", FileName);

		FP = fopen(FileName, "w");
		
		//NO SUCH FILE
			if(FP == NULL){

				printf("Error Opening File. \n");
			}
		
		for(int i = 0; i < *Rows; i++){
			for(int j = 0; j < *Col; j++){
				fprintf(FP,"%c",ProArr[i][j]);
			}
			fprintf(FP, "\n");
		}
		
		fclose(FP);
}		

