#include<stdio.h>

static int seed_value = 12;

struct Position{
    int cells_player[12];
    int cells_computer[12];
    int computer_play;
    int seeds_player; 
    int seeds_computer;
};

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
/*
void illegal_move(bot,indice){

}
*/




struct Position initPosition(int bot_status){
    struct Position position;
    for(int i = 0;i<seed_value;i++){
        position.cells_computer[i] = 4;
        position.cells_player[i] = 4;
    }
    position.computer_play = bot_status;
    position.seeds_player = seed_value;
    position.seeds_computer = seed_value;
    return position;
}

int sumgame(struct Position position){
    int sum = 0;
    for (int i = 0; i < seed_value; i++){
        sum += position.cells_player[i] + position.cells_computer[i];
    }
    if(sum > 8){
        return 0;
    }else{
        return 1;
    }
}

int main(void) {
    struct Position position = initPosition(1);
    displayPosition(position);

    while(sumgame(position)==0){
        int input;
        if(position.computer_play == 0){

        }else{
            printf("Quel case pour le joueur ?");
            scanf("%d",&input);
        }
    }

    return 0;
}