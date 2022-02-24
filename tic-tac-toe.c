#include <stdio.h>
#include <stdlib.h>

#include "lib/tic-tac-toe.h"

int return_menu(){

	int choice;

	printf("\n::> (1=yes|2=no) Do you want to return to the menu? ");
	scanf("%d", &choice);

	if(choice == 1){
		reset_board();
		return 1;
	}
	else if(choice == 2)
		exit(0);
	else
		printf("\n::> Invalid input, exiting...\n");
		exit(0);
}

int main(){

    int choice;

    while(1){
        
        clear();
        menu();
        scanf("%d", &choice);

        switch(choice){
            case 1: 
                with_friends();
				return_menu();

				if(return_menu())
					continue;
            case 2:
                with_computer();
				return_menu();

				if(return_menu())
					continue;
            case 3:
                how_to_play();
                exit(0);
            case 4:
                clear();
                exit(0);
            default:
                continue;  
        }
    }

    return 0;
}
