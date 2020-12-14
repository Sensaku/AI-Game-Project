#include<stdio.h>

const int seed_value = 12;

struct Position{
    int cells_player[12];
    int cells_computer[12];
    int computer_play;
    int seeds_player; 
    int seeds_computer;
};




struct Position initPosition(int bot_status){
    struct Position game;
    for(int i = 0;i<seed_value;i++){
        game.cells_computer[i] = 4;
        game.cells_player[i] = 4;
    }
    game.computer_play = bot_status;
    game.seeds_player = seed_value;
    game.seeds_computer = seed_value;
    return game;
}

void displayPosition(struct Position position){
    printf("cells_player   = ");
    for (int i = 0; i < seed_value; i++){
        printf("%d ",position.cells_player[i]);
    }
    printf("\ncells_computer = ");
    for (int i = 0; i < seed_value; i++){
        printf("%d ",position.cells_computer[i]);
    }
    printf("\n");
    printf("computer_play  = %d \n",position.computer_play);
    printf("seeds_player   = %d \n",position.seeds_player);
    printf("seeds_computer = %d \n",position.seeds_computer);
}

int main(void) {
    struct Position position = initPosition(1);
    displayPosition(position);
    return 0;
}