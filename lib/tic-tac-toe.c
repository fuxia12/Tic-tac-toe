// Author: @fuxia.12 - https://github.com/fuxia12

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct{
    char players[2][10];
    char winning_player[10];
    char moves[2];
    int draw;
    int move_status_int;
} Information;

Information info;

char board[9][1] = {
                    {" "}, {" "}, {"."},
                    {" "}, {"-"}, {" "}, 
                    {"."}, {" "}, {" "}
                    };

void clear(void){
    system("clear");
}

int generate_report(void){
    
    char file_path[30] = "reports/report-";
    char improvised[5];
    
    srand(time(NULL));
    time_t seconds;
    time(&seconds);
    struct tm *ptime = localtime(&seconds);

    snprintf(improvised, 5, "%d", rand()%10000);
    strcat(file_path, improvised);
    strcat(file_path, ".txt");

    FILE *file = fopen(file_path, "w");

    if(file == NULL){
        fprintf(stderr, "\n::> The report for this match could not be generated. Possible cause: the reports directory doesn't have write permissions. \n\n");
        return 0;
    }
  
    fprintf(file, "-=-=-=-=-=-=-=-=-=-=-=-=-=-| Tic-Tac-Toe |-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    fprintf(file, "\n\n[-] Report generated at %d:%d:%d on %d/%d/%d", ptime->tm_hour, 
    ptime->tm_min, ptime->tm_sec, ptime->tm_mday, 
    ptime->tm_mon+1, ptime->tm_year+1900);
    fprintf(file, "\n\n[-] This report was generated automatically at the end of a match");
    fprintf(file, "\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-| Report |-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-");  
    fprintf(file, "\n\n[-] %s (%c) vs (%c) %s", info.players[0], info.moves[0], 
    info.moves[1], info.players[1]);

    if(info.draw == -2)
        fprintf(file, "\n\n[-] Winner ==> The match ended in a draw\n");
    else
        fprintf(file, "\n\n[-] Winner ==> %s\n", info.winning_player);

    fprintf(file, "\n[-] Board\n\n");

    fprintf(file, "     |     |     \n");
    fprintf(file, " %c   | %c   | %c   \n", board[0][0],board[1][0],board[2][0]);
    fprintf(file, "_____|_____|______\n");
    fprintf(file, "     |     |       \n");
    fprintf(file, " %c   | %c   | %c    \n", board[3][0],board[4][0],board[5][0]);
    fprintf(file, "_____|_____|______\n");
    fprintf(file, "     |     |       \n");
    fprintf(file, " %c   | %c   | %c    \n", board[6][0],board[7][0],board[8][0]);
    fprintf(file, "_____|_____|______\n");
    fprintf(file, "     |     |       \n");

    printf("\n::> Report generated in the reports directory with the identification code <%s>. \n", improvised);

    fclose(file);
}

void menu(void){
    printf("-=-=-=-=-=-| Tic-Tac-Toe |-=-=-=-=-=-\n\n");;
    printf("[1] - Play with Friends\n");
    printf("[2] - Play with Computer\n");
    printf("[3] - How to Play\n");
    printf("[4] - Exit\n");
    printf("\nEnter your choice::> ");
}

void reset_board(void){
    for(int i = 0; i < 9; i++){
        board[i][0] = ' ';
    }

    board[2][0] = '.';
    board[4][0] = '-';
    board[6][0] = '.';
}

void print_board(void){
    printf("     |     |     \n");
    printf(" %c   | %c   | %c   \n",board[0][0],board[1][0],board[2][0]);
    printf("_____|_____|______\n");
    printf("     |     |       \n");
    printf(" %c   | %c   | %c    \n",board[3][0],board[4][0],board[5][0]);
    printf("_____|_____|______\n");
    printf("     |     |       \n");
    printf(" %c   | %c   | %c    \n",board[6][0],board[7][0],board[8][0]);
    printf("_____|_____|______\n");
    printf("     |     |       \n");
}

int verify_play(void){

    if(board[info.move_status_int][0] == 'X' || board[info.move_status_int][0] == 'O')
        return -1;

    return 0;
}

int translate(char *move){
   
    if(strlen(move) > 2 || strlen(move) < 2)
        return -1;

    else if(strcmp(move, "A1") == 0 || strcmp(move, "a1") == 0){
        info.move_status_int = 0;
        return 0;
    }

    else if(strcmp(move, "A2") == 0 || strcmp(move, "a2") == 0){
        info.move_status_int = 1;
        return 0;
    }

    else if(strcmp(move, "A3") == 0 || strcmp(move, "a3") == 0){
        info.move_status_int = 2;
        return 0;
    }
    
    else if(strcmp(move, "B1") == 0 || strcmp(move, "b1") == 0){
        info.move_status_int = 3;
        return 0;
    }

    else if(strcmp(move, "B2") == 0 || strcmp(move, "b2") == 0){
        info.move_status_int = 4;
        return 0;
    }

    else if(strcmp(move, "B3") == 0 || strcmp(move, "b3") == 0){
        info.move_status_int = 5;
        return 0;
    }

    else if(strcmp(move, "C1") == 0 || strcmp(move, "c1") == 0){
        info.move_status_int = 6;
        return 0;
    }

    else if(strcmp(move, "C2") == 0 || strcmp(move, "c2") == 0){
        info.move_status_int = 7;
        return 0;
    }

    else if(strcmp(move, "C3") == 0 || strcmp(move, "c3") == 0){
        info.move_status_int = 8;
        return 0;
    }

    return -1;
}

int mark_board(char *move, int player_status){
   
    if(translate(move) == -1)
        return -1;

    else if(verify_play() == -1)
        return -1;

    board[info.move_status_int][0] = info.moves[player_status];
    
    return 0;
}

int verify_winner(){

    // Horizontal

    if(strncmp(board[0], board[1], 1) == 0 && strncmp(board[1], board[2], 1) == 0){
        if(strncmp(board[1], " ", 1) == 0)
            return -1;

        return 0;
    }
    else if(strncmp(board[3], board[4], 1) == 0 && strncmp(board[4], board[5], 1) == 0){
        if(strncmp(board[4], " ", 1) == 0)
            return -1;

        return 0;
    }
    else if(strncmp(board[6], board[7], 1) == 0 && strncmp(board[7], board[8], 1) == 0){
        if(strncmp(board[6], " ", 1) == 0)
            return -1;
        
        return 0;
    }
    
    // Vertical

    else if(strncmp(board[0], board[3], 1) == 0 && strncmp(board[3], board[6], 1) == 0){
        if(strncmp(board[6], " ", 1) == 0)
            return -1;
        
        return 0;
    }
    else if(strncmp(board[1], board[4], 1) == 0 && strncmp(board[4], board[7], 1) == 0){
        if(strncmp(board[4], " ", 1) == 0)
            return -1;
        
        return 0;
    }
    else if(strncmp(board[2], board[5], 1) == 0 && strncmp(board[5], board[8], 1) == 0){
        if(strncmp(board[5], " ", 1) == 0)
            return -1;
        
        return 0;
    }

    // Diagonal

    else if(strncmp(board[0], board[4], 1) == 0 && strncmp(board[4], board[8], 1) == 0){
        if(strncmp(board[0], " ", 1) == 0)
            return -1;
        
        return 0;
    }
    else if(strncmp(board[2], board[4], 1) == 0 && strncmp(board[4], board[6], 1) == 0){
        if(strncmp(board[2], " ", 1) == 0)
            return -1;
        
        return 0;
    }

    for(int i = 0; i < 9; i++){
        if(strncmp(board[i], " ", 1) == 0)
            return -1;
    }

    return 1;
}

void computer_move(void){
    
    int i = -1;
    

    while(i == -1){

        srand(time(NULL));

        info.move_status_int = rand()%9;

        i = verify_play();
    }

    board[info.move_status_int][0] = info.moves[1];
}

void how_to_play(void){

    char buffer[100];
    FILE *file = fopen("help/help.txt", "r");

    if(file == NULL)
        fprintf(stderr, "Error: Help file doesn't exist or doesn't have read permission.\n");
    
    clear();

    while(fgets(buffer, sizeof(buffer), file) != NULL)
        printf("%s", buffer);

    fclose(file);
}


void print_winner(void){

    clear();
    print_board();

    if(info.draw == -2)
        printf("\n::> DRAW!\n");
    else
        printf("\n::> %s won!\n", info.winning_player);
}


void with_friends(void){

    int player_status = 2, i = -1;
    char player_input[5];
    info.draw = 1;
    strcpy(info.moves, "XO");

    clear();
    printf("\n[X] Nickname - Player 1:> ");
    scanf("%s", info.players[0]);
    printf("\n[O] Nickname - Player 2:> ");
    scanf("%s", info.players[1]);

    while(i == -1){
        
        player_status %= 2;

        clear();
        print_board();
        printf("\n[%c] %s::> ", info.moves[player_status], info.players[player_status]);
        scanf("%s", player_input);

        if(mark_board(player_input, player_status) == -1)
            continue;

        i = verify_winner();

        player_status++;
    }

    if(i == 0){
        strcpy(info.winning_player, info.players[--player_status]);
        print_winner();
        generate_report();
    }
    else{
        info.draw = -2;
        print_winner();
        generate_report();
    }
}

void with_computer(void){
    
    int player_status = 2, i = -1;
    char player_input[5];
    strcpy(info.moves, "XO");
    strcpy(info.players[0], "Human");
    strcpy(info.players[1], "Computer");
    info.draw = 1;

    while(i == -1){
        
        player_status %= 2;
        
        if(player_status == 1){
            computer_move();
            i = verify_winner();
            player_status++;
            continue;
        }

        clear();
        print_board();
        printf("\n[%c] %s::> ", info.moves[0], info.players[0]);
        scanf("%s", player_input);

        if(player_status == 0){
            if(mark_board(player_input, player_status) == -1)
                 continue;
        }

        i = verify_winner();
        
        player_status++;
    }

    if(i == 0){
        strcpy(info.winning_player, info.players[--player_status]);
        print_winner();
        generate_report();
    }
    else{
        info.draw = -2;
        print_winner();
        generate_report();
    }
}   


