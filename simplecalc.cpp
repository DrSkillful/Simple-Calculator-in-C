#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int op; //User option
float num1;
float num2;
float SUM, DIV, SUB, MULT;
int prev; //User option if they wish to use previous numbers
char previ[100]; //Buffer string

int main(void){
	
	/*Invoke file, setup for reading/writing */
	
	FILE *fptr;

	printf("Input your operation [SUM 1, DIV 2, SUB 3, MULT 4]: \n");
	scanf("%d", &op);
	
	
	/* Invalid option handling */
	if (op > 4 || op < 1) {
		printf("Error.");
		return 0;
	}
	
	printf("Do you wish to use the results of a previous calculation? [1 YES, 2 NO] \n");
	scanf("%d", &prev);
	
	if (prev == 2) {
		printf("Input your first number: \n");
		scanf("%f", &num1);
		printf("Input your second number: \n");
		scanf("%f", &num2);
		fptr = fopen("previous.txt", "w"); //opens or creates "previous.txt" and prepares to write data. Refer to line 55.
	} else {
		printf("Input your second number: \n");
		scanf("%f", &num2);
		fptr = fopen("previous.txt", "r"); //opens "previous.txt" and prepares to read data
		fgets(previ, 8, fptr); //sets the previ char index variable to the value inside "previous.txt"
		num1 = strtod(previ, NULL); //sets the first number used as the float conversion of the string previ ^
		fclose(fptr);
		fptr = fopen("previous.txt", "w");
	}
	
	/* Variables to do/store functions */
	
	SUM = num1+num2;
	DIV = num1/num2;
	SUB = num1-num2;
	MULT = num1*num2;
	
	if (op == 1 && prev == 2 || op == 1 && prev == 1) {
		printf("The sum of %.3f and %.3f is: %.3f", num1, num2, SUM);
		fprintf(fptr, "%f", SUM); //Writes result of SUM into "previous.txt", overwritting previous data
		fclose(fptr);
	} else if (op == 2 && prev == 2 || op == 2 && prev == 1) {
		printf("The division of %.3f and %.3f is: %.3f", num1, num2, DIV);
		fprintf(fptr, "%f", DIV);
		fclose(fptr);
	} else if (op == 3 && prev == 2 || op == 3 && prev == 1) {
		printf("The subtraction of %.3f and %.3f is: %.3f", num1, num2, SUB);
		fprintf(fptr, "%f", SUB);
		fclose(fptr);
	} else if (op == 4 && prev == 2 || op == 4 && prev == 1) {
		printf("The multiplication of %.3f and %.3f is: %.3f", num1, num2, MULT);
		fprintf(fptr, "%f", MULT);
		fclose(fptr);
	}
	printf("\nThis small program was made by Ioannis Stav. :)");
	_getch();
	return 0;
}
