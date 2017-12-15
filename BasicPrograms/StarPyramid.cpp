#include<stdio.h>

int main()
{
    int noOfRows;
    printf("Number of rows to be printed: ");
    scanf("%d", &noOfRows);

    int row,colSpaces,colStar;
    
    for(row = 1; row <= noOfRows; row++)
    {
        for(colSpaces = noOfRows-row; colSpaces >= 1; colSpaces--)
        {
            printf(" ");
        }
        for(colStar = 1; colStar <= row; colStar++ )
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}