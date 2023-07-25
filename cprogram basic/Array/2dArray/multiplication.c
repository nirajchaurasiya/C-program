#include <stdio.h>

void get_matrix_dimensions(int *rows, int *columns)
{
    printf("Enter the number of rows: ");
    scanf("%d", rows);
    printf("Enter the number of columns: ");
    scanf("%d", columns);
}

void get_matrix_elements(int rows, int columns, int matrix[][columns])
{
    printf("Enter the elements row-wise:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void multiply_matrices(int rows1, int columns1, int matrix1[][columns1], int rows2, int columns2, int matrix2[][columns2], int result[][columns2])
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < columns2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < columns1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void display_matrix(int rows, int columns, int matrix[][columns])
{
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows1, columns1, rows2, columns2;

    printf("Enter the details for the first matrix:\n");
    get_matrix_dimensions(&rows1, &columns1);
    int matrix1[rows1][columns1];
    get_matrix_elements(rows1, columns1, matrix1);

    printf("\nEnter the details for the second matrix:\n");
    get_matrix_dimensions(&rows2, &columns2);
    int matrix2[rows2][columns2];
    get_matrix_elements(rows2, columns2, matrix2);

    if (columns1 != rows2)
    {
        printf("Invalid input. Number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return 1;
    }

    printf("\nFirst Matrix:\n");
    display_matrix(rows1, columns1, matrix1);
    printf("\nSecond Matrix:\n");
    display_matrix(rows2, columns2, matrix2);

    int result[rows1][columns2];
    multiply_matrices(rows1, columns1, matrix1, rows2, columns2, matrix2, result);

    printf("\nResultant Matrix (Multiplication of the two matrices):\n");
    display_matrix(rows1, columns2, result);

    return 0;
}
