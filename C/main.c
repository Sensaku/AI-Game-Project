#include<stdio.h>

static int seed_value = 12;

struct Position{
    int cells_player[12];   // each cell contains a certain number of seeds
    int cells_computer[12];
    int computer_play;      // boolean true if the computer has to play and false otherwise
    int seeds_player;       // seeds taken by the player
    int seeds_computer;     // seeds taken by the computer
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

int validMove(struct Position* pos_current,int computer_play,int index){
    return 0;
}

int evaluation(struct Position* pos_current,int computer_play,int depth){
    return 0;
}

void playMove(struct Position* pos_next,struct Position* pos_current,int computer_play,int index){

}

int finalPosition(struct Position* pos_current,int computer_play,int depth){
    return 0;
}

//fournis par le professeur
int minMaxValue(struct Position* pos_current,int computer_play,int depth,int depthMax){
    // computer_play is true if the computer has to play and false otherwise
    int tab_values[12];
    struct Position pos_next; // In C : created on the stack: = very fast
    if(finalPosition(pos_current, computer_play, depth)){
        // WRITE the code: returns VALMAX (=96) if the computer wins, -96 if it loses; 0 if draw
    }
    if(depth == depthMax){
        return evaluation(pos_current, computer_play, depth);
        // the simplest evealution fucntion is the difference of the taken seeds
    }
    for(int i=0;i<12;i++){
        // we play the move i
        // WRITE function validMove(pos_current, computer_play,i)
        // it checks whether we can select the seeds in cell i and play (if there is no seed the function returns false)
        if (validMove(pos_current, computer_play,i)){
            // WRITE function playMove(&pos_next,pos_current, computer_play,i)
            // we play th emove i from pos_current and obtain the new position pos_next
            playMove(&pos_next,pos_current, computer_play,i);
            // pos_next is the new current poisition and we change the player
            tab_values[i]=minMaxValue(&pos_next,!computer_play,depth+1,depthMax);
        }else{
            if(computer_play){
                tab_values[i]=-100;
            }else{
                tab_values[i]=+100;
            }
        }
    }

    int res;
    if (computer_play){
        // WRITE the code: res contains the MAX of tab_values
    }else{
        // WRITE the code: res contains the MIN of tab_valuess
    }
    return res;
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
            fflush(stdin);
        }
    }

    return 0;
}