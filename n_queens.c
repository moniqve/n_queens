#include <stdio.h>
#include <stdlib.h>

int queens;
int **board;

int **chessboard(int q_number)
{
    int i, j;

    int **c_board = (int **)malloc(q_number * sizeof(int *));

    for (i = 0; i < q_number; i++)
    {
        c_board[i] = (int *)malloc(q_number * sizeof(int));
        for (j = 0; j < q_number; j++)
        {
            c_board[i][j] = 0;
        }
    }
    return c_board;
}

void print_chessboard()
{
    int i, j;
    for (i = 0; i < queens; i++)
    {
        for (j = 0; j < queens; j++)
        {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

int under_attack(int row, int col)
{
    int i, j;
    //procura rainhas na linha e coluna
    for (i = 0; i < queens; i++)
    {
        if ((board[row][i] == 1) || (board[i][col] == 1))
            return 1;
    }
    //procura rainhas nas diagonais
    for (i = 0; i < queens; i++)
    {
        for (j = 0; j < queens; j++)
        {
            if (((i + j) == (row + col)) || ((i - j) == (row - col)))
            {
                if (board[i][j] == 1)
                    return 1;
            }
        }
    }
    return 0;
}

int n_queens(int n)
{
    int i, j;

    //para n = 0 não há tabuleiro, portanto, retorna 0
    if (n == 0)
        return 1;

    for (i = 0; i < queens; i++)
    {
        for (j = 0; j < queens; j++)
        {
            //confere se a posição está sob ataque para poder colocar a rainha
            if ((!under_attack(i, j)) && (board[i][j] != 1))
            {
                board[i][j] = 1;
                if (n_queens(n - 1) == 1)
                {
                    return 1;
                }
                board[i][j] = 0;
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    queens = atoi(argv[1]);
    board = chessboard(queens);
    n_queens(queens);
    print_chessboard();
}