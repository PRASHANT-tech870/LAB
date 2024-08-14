#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printSolution(int board[][10], int N)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n"); // Print a newline between solutions
}

bool isSafe(int board[][10], int row, int col, int N)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

void solveNQUtil(int board[][10], int col, int N)
{
    if (col >= N) {
        printSolution(board, N);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;
            solveNQUtil(board, col + 1, N);
            board[i][col] = 0; 
        }
    }
}

void solveNQ(int N)
{
    int board[10][10] = { { 0 } };
    solveNQUtil(board, 0, N);
}

int main()
{
    int N;
    printf("Enter the number of queens (N): ");
    scanf("%d", &N);
    solveNQ(N);
    return 0;
}
