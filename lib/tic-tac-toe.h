#ifndef _LIB_TICTACTOE
#define _LIB_TICTACTOE

void menu(void);

void clear(void);

void print_board(void);

int verify_play();

int translate(char *move);

int mark_board(char *move, int status);

int verify_winner(void);

void how_to_play(void);

void generate_report(void);

void with_friends(void);

void with_computer(void);

void reset_board(void);

#endif
