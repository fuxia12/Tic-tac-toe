#include <stdio.h>
#include <stdlib.h>

#include "lib/tic-tac-toe.h"

int return_menu(){

	int choice;

    while(1){
        
        printf("\n::> (1=yes|2=no) Do you want to return to the menu? ");
        scanf("%d", &choice);

        if(choice == 1){
            reset_board();
            return 1;
        }
        else if(choice == 2){
            printf("\n::> Well done! Good luck in your next matches! Coming out...\n");
            exit(0);
        }
        else{
            printf("\n[x] Invalid input, try again...\n");
            continue;
        }
    }
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

		if(return_menu())
		   continue;

            case 2:
                with_computer();

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
