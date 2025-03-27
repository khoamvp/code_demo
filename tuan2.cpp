// Pham Minh Khoa
// MSSV: 24280078
#include <iostream>
using namespace std;

void input_row_and_column(int &row, int &column)
{
    cin >> row >> column;
}

void input_array_2D(int array_2D[][100], int row, int column)
{
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> array_2D[i][j];
        }
    }
}

void output_array_2D(int array_2D[][100], int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << array_2D[i][j] << " ";
        }
        cout << endl;
    }
}

void sum_2_array_2D(int array_2D_1[][100], int array_2D_2[][100], int sum_array_2D[][100], int row, int column, int row_1, int column_1)
{
    if (column != column_1 || row != row_1)
    {
        cout << "Not valid" << endl;
    }
    else
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                sum_array_2D[i][j] = array_2D_1[i][j] + array_2D_2[i][j];
            }
        }
    }
}

void swap_array_i_j(int array_2D_1[][100], int row, int column, int index1, int index2)
{
    for (int j = 0; j < column; j++)
    {
        int temp = array_2D_1[index1 - 1][j];
        array_2D_1[index1 - 1][j] = array_2D_1[index2 - 1][j];
        array_2D_1[index2 - 1][j] = temp;
    }
}

void matrix_product(int array_2D_2[][100], int array_2D_3[][100], int product_array[][100], int row_1, int column_1, int row_2, int column_2)
{
    if (row_2 != column_1)
    {
        cout << " Not valid" << endl;
        ;
    }
    else
    {
        for (int i = 0; i < row_1; i++)
        {
            for (int k = 0; k < column_2; k++)
            {
                int sum = 0;
                for (int j = 0; j < column_1; j++)
                {
                    sum += array_2D_2[i][j] * array_2D_3[j][k];
                }
                product_array[i][k] = sum;
            }
        }
    }
}
void create_diagonal_matrix(int diagonal_matrix[100][100], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j - i < size; j++)
        {
            diagonal_matrix[i][j] = 5;
        }
    }
}
int main()
{
    int row, column, row_1, column_1;
    int array_2D_1[100][100], array_2D_2[100][100], sum_array_2D[100][100];
    // NHAP VAO MA TRAN 1
    cout << " Enter rows and columns for matrix 1:" << endl;
    input_row_and_column(row, column);

    input_array_2D(array_2D_1, row, column);
    // NHAP VAO MA TRAN 2
    cout << " Enter rows and columns for matrix 2:" << endl;
    input_row_and_column(row_1, column_1);

    input_array_2D(array_2D_2, row_1, column_1);
    // TONG 2 MA TRAN
    sum_2_array_2D(array_2D_1, array_2D_2, sum_array_2D, row, column, row_1, column_1);
    if (row == row_1 && column == column_1)
    {
        cout << "Sum two matrices " << endl;
        output_array_2D(sum_array_2D, row, column);
    }
    // IN RA MA TRAN 1
    cout << "Output matrix 1:" << endl;
    output_array_2D(array_2D_1, row, column);
    // HOAN DOI DONG I J TRONG MA TRAN
    cout << "Enter two rows to swap:" << endl;
    int index1, index2;
    cin >> index1 >> index2;
    if (index1 < 1 || index2 < 1 || index1 > row || index2 > row)
    {
        cout << "Not valid" << endl;
    }
    else
    {
        swap_array_i_j(array_2D_1, row, column, index1, index2);
        cout << "Matrix after swapping: " << endl;
        output_array_2D(array_2D_1, row, column);
    }
    // TICIH 2 MA TRAN 2 VA 3
    int row_2, column_2;
    int array_2D_3[100][100], product_array[100][100];
    cout << " Enter rows and columns for matrix 3:" << endl;

    input_row_and_column(row_2, column_2);

    input_array_2D(array_2D_3, row_2, column_2);

    matrix_product(array_2D_2, array_2D_3, product_array, row_1, column_1, row_2, column_2);
    if (column_1 == row_2)
    {
        output_array_2D(product_array, row_1, column_2);
    }
    // MA TRAN DUONG CHEO CO N GIA TRI 5
    int size;
    cout << " Enter size ";
    cin >> size;
    int diagonal_matrix[100][100] = {0};
    create_diagonal_matrix(diagonal_matrix, size);

    output_array_2D(diagonal_matrix, size, 2 * size);
}
