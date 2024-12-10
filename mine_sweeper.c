// implement mine sweeper
// gcc -o mine_sweeper mine_sweeper.c

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <wchar.h>

wchar_t b[10][10] = {
    '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
    '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
    '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
    '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
    '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
    '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
    '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
    '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
    '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
    '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
};
int game_running = 1;
#define NO_BOMBS 8
int bombs[NO_BOMBS];
char valid_columns[10] = {'Q','W','E','R','T','Y','U','I','O','P'};
const wchar_t BOMB_ICON = 'B';
const wchar_t FLAG_ICON = 'F';
const wchar_t EMPTY_ICON = 'X';

void display_board(int moveUp) {
    if (moveUp == 0) printf("\033[16A\r");
    printf(
        "\n    Q   W   E   R   T   Y   U   I   O   P\n"
        "  -----------------------------------------\n"
        "0 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n"
        "1 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n"
        "2 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n"
        "3 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n"
        "4 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n"
        "5 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n"
        "6 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n"
        "7 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n"
        "8 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n"
        "9 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n"
        "  -----------------------------------------\n"
        "                                           \n",
        b[0][0],b[0][1],b[0][2],b[0][3],b[0][4],b[0][5],b[0][6],b[0][7],b[0][8],b[0][9],
        b[1][0],b[1][1],b[1][2],b[1][3],b[1][4],b[1][5],b[1][6],b[1][7],b[1][8],b[1][9],
        b[2][0],b[2][1],b[2][2],b[2][3],b[2][4],b[2][5],b[2][6],b[2][7],b[2][8],b[2][9],
        b[3][0],b[3][1],b[3][2],b[3][3],b[3][4],b[3][5],b[3][6],b[3][7],b[3][8],b[3][9],
        b[4][0],b[4][1],b[4][2],b[4][3],b[4][4],b[4][5],b[4][6],b[4][7],b[4][8],b[4][9],
        b[5][0],b[5][1],b[5][2],b[5][3],b[5][4],b[5][5],b[5][6],b[5][7],b[5][8],b[5][9],
        b[6][0],b[6][1],b[6][2],b[6][3],b[6][4],b[6][5],b[6][6],b[6][7],b[6][8],b[6][9],
        b[7][0],b[7][1],b[7][2],b[7][3],b[7][4],b[7][5],b[7][6],b[7][7],b[7][8],b[7][9],
        b[8][0],b[8][1],b[8][2],b[8][3],b[8][4],b[8][5],b[8][6],b[8][7],b[8][8],b[8][9],
        b[9][0],b[9][1],b[9][2],b[9][3],b[9][4],b[9][5],b[9][6],b[9][7],b[9][8],b[9][9]
    );
}

void generate_bombs() {
    srand(time(0));
    int bomb;
    for (int i=0; i < NO_BOMBS; i++) {
        bombs[i] = rand() % 100;
    }
}

void show_all_bombs() {
    int x, y;
    for (int i=0; i < NO_BOMBS; i++) {
        x = (int)(bombs[i] / 10);
        y = (int)(bombs[i] % 10);
        b[x][y] = BOMB_ICON;
    }
}

int calc_score() {
    int score = 0;
    for (int x=0; x < 10; x++) {
        for (int y=0; y < 10; y++) {
            if ((b[x][y] >= 49 && b[x][y] <= 57) || (b[x][y] == EMPTY_ICON)) {
                score++;
            }
        }
    }
    return score;
}

int column_char2int(int col) {
    switch (col) {
        case 'Q': return 0;
        case 'W': return 1;
        case 'E': return 2;
        case 'R': return 3;
        case 'T': return 4;
        case 'Y': return 5;
        case 'U': return 6;
        case 'I': return 7;
        case 'O': return 8;
        case 'P': return 9;
        default: return -1;
    }
}

int xy2bombPos(int x, int y) {
    if (x > 10) return -1;
    if (y > 10) return -1;
    return (x * 10) + y;
}

void update_numbering_pos(int x, int y) {
    int c = 0;
    int is_bomb = 0;

    for (int i=0; i < NO_BOMBS; i++) {
        if (xy2bombPos(x + 1, y) == bombs[i]) c++;
        if (xy2bombPos(x - 1, y) == bombs[i]) c++;
        if (xy2bombPos(x, y + 1) == bombs[i]) c++;
        if (xy2bombPos(x, y - 1) == bombs[i]) c++;
        if (xy2bombPos(x - 1, y - 1) == bombs[i]) c++;
        if (xy2bombPos(x - 1, y + 1) == bombs[i]) c++;
        if (xy2bombPos(x + 1, y - 1) == bombs[i]) c++;
        if (xy2bombPos(x + 1, y + 1) == bombs[i]) c++;
        if (xy2bombPos(x,y) == bombs[i]) is_bomb = 1;
    }
    if (c > 0 && is_bomb == 0) {
        b[x][y] = c + '0';
    }
}

void update_numbering(char* position) {
    int x = position[1] - '0';
    int y = column_char2int(position[0]);

    update_numbering_pos(x, y);
    update_numbering_pos(x + 1, y);
    update_numbering_pos(x - 1, y);
    update_numbering_pos(x, y + 1);
    update_numbering_pos(x, y - 1);
    update_numbering_pos(x - 1, y - 1);
    update_numbering_pos(x - 1, y + 1);
    update_numbering_pos(x + 1, y - 1);
    update_numbering_pos(x + 1, y + 1);
}

void place_marker(char* position) {
    int x = position[1] - '0';
    int y = column_char2int(position[0]);
    b[x][y] = EMPTY_ICON;
}

void add_flag(char* position) {
    if (position[0] == FLAG_ICON) {
        int x = position[2] - '0';
        int y = column_char2int(position[1]);
        if (b[x][y] == '.') {
            b[x][y] = FLAG_ICON;
        } else if (b[x][y] == 'F') {
            b[x][y] = '.';
        }
    }
}

void check_win_condition(char* position) {
    int x = position[1] - '0';
    int y = column_char2int(position[0]);
    int pos = (x * 10) + y;

    // Check if player hit bomb
    for (int i=0; i < NO_BOMBS; i++) {
        if (bombs[i] == pos) {
            show_all_bombs();
            display_board(0);
            printf("Game Over, you hit a bomb, score %d!\n", calc_score());
            game_running = 0;
        }
    }

}

int validate_position(char* pos) {
    int x = pos[1] - '0';
    int y = column_char2int(pos[0]);
    
    int valid_col = 0;
    for (int i=0; i < 10; i++) {
        if (pos[0] == valid_columns[i]) valid_col = 1;
    }

    if (valid_col == 0) return 1;                       // Check if column is valid
    if (!(pos[1] >= '0' && pos[1] <= '9')) return 1;    // check if row is valid
    if (b[x][y] == EMPTY_ICON) return 1;                // Check if position already played
    check_win_condition(pos);                           // Check if their is a bomb in this position

    return 0;
}

int main() {
    char user_input[3];
    generate_bombs();
    display_board(1);

    while (game_running) {
        display_board(0);
        printf("Enter position: ");
        scanf("%3s", user_input);
        add_flag(user_input);
        
        while (validate_position(user_input) == 1) {
            display_board(0);
            printf("Invalid position: ");
            scanf("%3s", user_input);
            add_flag(user_input);
        }
        place_marker(user_input);
        update_numbering(user_input);
        check_win_condition(user_input);
    }
}
