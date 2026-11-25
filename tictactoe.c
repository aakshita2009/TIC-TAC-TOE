#include <stdio.h>

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void displayBoard(void) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int checkWin(void) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

int main(void) {
    int player = 1;
    int choice, row, col, moves = 0;
    char mark;

    while (moves < 9) {
        displayBoard();
        mark = (player == 1) ? 'X' : 'O';

        printf("\nPlayer %d (%c), enter position (1-9): ", player, mark);

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }

        if (choice < 1 || choice > 9) {
            printf("Invalid position! Try again.\n");
            continue;
        }

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Position already occupied! Try again.\n");
            continue;
        }

        board[row][col] = mark;
        moves++;

        if (checkWin()) {
            displayBoard();
            printf("\nCongratulations! Player %d wins!\n", player);
            return 0;
        }

        player = (player == 1) ? 2 : 1;
    }

    displayBoard();
    printf("\nGame Draw!\n");
    return 0;
}
