#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


// Function to display a matrix
void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Part A: Transpose Matrix
void transposeMatrix(int matrix[10][10], int rows, int cols)
{
    int transpose[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "\nTransposed Matrix:\n";
    displayMatrix(transpose, cols, rows);
}

// Part B: Add Two Matrices
void addMatrices(int A[10][10], int B[10][10], int rows, int cols)
{
    int sum[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\nSum of Matrices:\n";
    displayMatrix(sum, rows, cols);
}

// Part C: Multiply Two Matrices
void multiplyMatrices(int A[10][10], int B[10][10], int result[10][10], int m, int n, int p)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < n; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nProduct Matrix:\n";
    displayMatrix(result, m, p);
}

int main()
{
    int A[10][10], B[10][10], result[10][10];
    int rows, cols;

    // ---------- PART A ----------
    cout << "PART A - Matrix Transpose\n";
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    displayMatrix(A, rows, cols);

    transposeMatrix(A, rows, cols);

    // ---------- PART B ----------
    cout << "\nPART B - Matrix Addition\n";

    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter columns: ";
    cin >> cols;

    cout << "Enter Matrix A:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    cout << "Enter Matrix B:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
    }

    addMatrices(A, B, rows, cols);

    // ---------- PART C ----------
    cout << "\nPART C - Matrix Multiplication\n";

    int m, n, p;

    cout << "Enter rows of Matrix A: ";
    cin >> m;

    cout << "Enter columns of Matrix A: ";
    cin >> n;

    cout << "Enter Matrix A:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    cout << "Enter columns of Matrix B: ";
    cin >> p;

    cout << "Enter Matrix B (" << n << " x " << p << "):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
    }

    multiplyMatrices(A, B, result, m, n, p);

    return 0;
}