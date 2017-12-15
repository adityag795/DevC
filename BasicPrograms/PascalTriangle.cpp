#include<stdio.h>

int main()
{
    int noOfRows,row,colSpaces,colChar;

    printf("Enter number of rows: ");
    scanf("%d", &noOfRows);

    for(row = 0; row < noOfRows; row++)
    {
        for(colSpaces = noOfRows-row; colSpaces >= 1; colSpaces--)
        {
            printf(" ");
        }
        
        int printChar = 1;
        int num = row;
        int den = 1;
        for(colChar = 0; colChar <= row; colChar++)
        {
            printf("%d ",printChar);
            printChar = printChar * num;
            printChar = printChar / den;
            num--;
            den++;
        }
        printf("\n");
    }
    
    return 0;
}