// Implement the game Tic Tac Toe
// gcc -o tic_tac_toe tic_tac_toe.c

#include <stdio.h>

char b[3][3] = {
    ' ',' ',' ',
    ' ',' ',' ',
    ' ',' ',' '
};
char m[2] = {'X','O'};
int game_running = 1;

void display_board() {
    printf(
        "1: %c | %c | %c \n"
        "  -----------\n"
        "2: %c | %c | %c \n"
        "  -----------\n"
        "3: %c | %c | %c \n"
        "  -A---B---C-\n\n",
        b[0][0],b[0][1],b[0][2],
        b[1][0],b[1][1],b[1][2],
        b[2][0],b[2][1],b[2][2]
    );
}

void place_marker(char marker, char* position) {
    int x = position[1] - '1';
    int y = position[0] - 'A';
    b[x][y] = marker;
}

int validate_marker(char* position) {
    int x = position[1] - '1';
    int y = position[0] - 'A';

    if (!(position[0] >= 65 && position[0] <= 67) || !(position[1] >= 49 && position[1] <= 51) || (b[x][y] == m[0] || b[x][y] == m[1])) {
        printf("Invalid %s position!\n", position);
        return 0;
    }
    return 1;
}

void check_win_condition() {
    for (int i=0; i < 2; i++) {
        if (
         (b[0][0] == m[i] && b[0][1] == m[i] && b[0][2] == m[i]) ||
         (b[1][0] == m[i] && b[1][1] == m[i] && b[1][2] == m[i]) ||
         (b[2][0] == m[i] && b[2][1] == m[i] && b[2][2] == m[i]) ||
         (b[0][0] == m[i] && b[1][0] == m[i] && b[2][0] == m[i]) ||
         (b[0][1] == m[i] && b[1][1] == m[i] && b[2][1] == m[i]) ||
         (b[0][2] == m[i] && b[1][2] == m[i] && b[2][2] == m[i]) ||
         (b[0][0] == m[i] && b[1][1] == m[i] && b[2][2] == m[i]) ||
         (b[2][0] == m[i] && b[1][1] == m[i] && b[0][2] == m[i])) {
            printf("Game over %c won!\n", m[i]);
            game_running = 0;
            return;
        }
    }
    if (!(
     b[0][0] == ' ' || b[0][1] == ' ' || b[0][2] == ' ' ||
     b[1][0] == ' ' || b[1][1] == ' ' || b[1][2] == ' ' ||
     b[2][0] == ' ' || b[2][1] == ' ' || b[2][2] == ' ')) {
        printf("Game over draw, board is full!\n");
        game_running = 0;
    }
}

int main() {
    char user_input[2];
    display_board();
    int turn = 0;
    char marker;

    while (game_running) {
        marker = m[turn % 2];
        printf("Player %c turn: ", marker);
        scanf("%s", user_input);
        while (validate_marker(user_input) == 0) {
            printf("Player %c turn: ", marker);
            scanf("%s", user_input);
        }

        place_marker(marker, user_input);
        display_board();
        check_win_condition();
        turn++;
    }
}
