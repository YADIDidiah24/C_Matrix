#include <stdio.h>
#include <stdbool.h>
#include <string.h>
void printMat(int array[3][4]);
void printRow(int array[3][4]);
void printCol(int array[3][4]);
void reverseRow(int array[3][4]);
void printMenu();
void findRowPrimes(int arr[3][4]);
bool is_prime(int number);




int main() {

    char value[10];  
    int option;
    
    do {
       int array[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

       printMenu();
       printf("Enter which option to choose as int (1-6): ");
       scanf("%d",&option);
       printf("\n");

       switch (option){
            case 1:
                printMat(array);
                break;

            case 2:
                printRow(array);
                break;

            case 3:
                printCol(array);
                break;
            case 4:
                reverseRow(array);
                break;
            case 5:
                findRowPrimes(array);
                break;
            case 6:
                break;
            default:
                printf("WRONG INPUT!!!");
                break;
       }
        printf("Do you want to continue? (Y or N): ");
        scanf("%s",value);
        printf("\n");
        
        } while (strcmp(value, "N") != 0); 
        
    return 0;
}


void printMat(int array[3][4]){
     for(int i=0;i<3;i++){
       printf("\n");
      for(int j=0;j<4;j++){
        
        printf("%d \t",array[i][j]);
        }
          printf("\n");
    }
        printf("\n");
}

void printMenu(){
    printf("This program provides the following matrix manipulation services:\n");
    printf("\n");
    printf("1. Print the matrix in tabular form. \n");
    printf("2. Print a specific row or a number of rows in sequence (using a function printRow()). \n");
    printf("3. Print a specific column or a number of columns in sequence (using a function printCol()). \n");
    printf("4. Get the elements of a specific row reversed (using a function reverseRow()), then print the matrix to check.\n");
    printf("5. Find the number of prime numbers in a specific row (using a function findRowPrimes()). \n");
    printf("6. Quit. \n");
}

void printRow(int array[3][4]){
    int row;
    int no;
    printf("Enter the number of rows to print: ");
    scanf("%d",&no);


    int n=0;

    while (n<no){
    printf("Enter row to print (Maximum = 2): ");
    scanf("%d",&row);
    printf("\n");
    
    int i;
    for (i=0;i<4;i++){
    printf("%d\t ",array[row][i]);

    }
    printf("\n\n");
    n++;
    }
}

void printCol(int array[3][4]){
    int col;
    int no;
    printf("Enter the number of coloums to print: ");
    scanf("%d",&no);
    int n=0;

    while (n<no){
    printf("Enter the coloum to print (Maximum = 3): ");
    scanf("%d",&col);
    printf("\n");
    
    int i;
    for (i=0;i<3;i++){
    printf("%d\t ",array[i][col]);

    }
    printf("\n\n");
    n++;
    }
}

void reverseRow(int array[3][4]){
    int row;
    
    printf("Enter row to reverse: ");
    scanf("%d",&row);
    printf("\n");
    
    int i;
    for (i=0;i<(4/2);i++){
    int temp = array[row][i];
    array[row][i]=array[row][4-i-1];
    array[row][4-i-1]=temp;
    
    }

    for (int k=0;k<3;k++){
        for (int l=0;l<4;l++){
            printf("%d\t",array[k][l]);
        }
        printf("\n");
    }
    
    printf("\n\n");
}

void findRowPrimes(int arr[3][4]){
    int row;
    printf("Enter the row to count prime numbers: ");
    scanf("%d",&row);
    
    int count=0;

    for (int i=0;i<4;i++){
        if (is_prime(arr[row][i])==1){
            count+=1;
        }
    }

    printf("There are %d prime numbers in the row %d.\n",count,row);
}

bool is_prime(int number){
    if (number <=1 ) return false;

    for (int i=2; i<number; i++) {
        if (number % i ==0) return false;
    }
    return true;
}
