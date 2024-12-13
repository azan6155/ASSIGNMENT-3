#include <stdio.h>
#include <stdbool.h>

struct Player {
    char name[20];
    int ballScore[12];
    int totalScore;
};

void PlayGame(struct Player *player);
bool ValidScore(int score);
void findWinner(struct Player *player1, struct Player *player2);
void displayMatchScoreboard(struct Player player1, struct Player player2);

int main(){
    struct Player player1 = {"Alice", {0}, 0};
    struct Player player2 = {"Bob", {0}, 0};

    /*struct Player player1 = {
        "Alice",
        {3, 5, 2, 6, 4, 1, 0, 2, 4, 5, 6, 3}, // Scores for 12 balls
        0 // Total score
    };

    struct Player player2 = {
        "Bob",
        {6, 1, 3, 5, 0, 2, 4, 3, 6, 5, 1, 0}, // Scores for 12 balls
        0 // Total score
    };*/
    PlayGame(&player1);
    PlayGame(&player2);
    findWinner(&player1, &player2);
    displayMatchScoreboard(player1, player2);
    return 0;
}

void PlayGame(struct Player *player){
    printf("Enter player name: ");
    scanf("%s", player->name);
    int i;
    for(i=0;i<12;i++){
        printf("Enter score for ball %d: ", i + 1);
        scanf("%d", &(player->ballScore[i]));
        if(!ValidScore(player->ballScore[i]))
            player->ballScore[i] = -1;
    }
    player->totalScore = 0;
}


bool ValidScore(int score){
    if(score >= 0 && score <= 6)
        return true;

    return false;
}

void findWinner(struct Player *player1, struct Player *player2){
    int i = 0;
    for(;i<12;i++){
        if(player1->ballScore[i] != -1)
            player1->totalScore += player1->ballScore[i];
        if(player2->ballScore[i] != -1)
            player2->totalScore += player2->ballScore[i];
    }

    if(player1->totalScore > player2->totalScore)
        printf("Player 1 is the winner\n\n");
    else if(player1->totalScore == player2->totalScore)
        printf("It is a draw\n\n");
    else 
        printf("Player 2 is the winner\n\n");
}


void displayMatchScoreboard(struct Player player1, struct Player player2) {
    int avg_score = 0;
    int i = 0;
    printf("For Player 1\n");
    for(;i<12;i++)
        printf("Score on ball %d is %d\n", i + 1, player1.ballScore[i]);
    avg_score = player1.totalScore / 12;
    printf("Average score is %d\n", avg_score);
    printf("Total Score is %d\n\n", player1.totalScore);
    
    printf("For Player 2\n");
    for(i=0;i<12;i++)
        printf("Score on ball %d is %d\n", i + 1, player2.ballScore[i]);
    avg_score = player2.totalScore / 12;
    printf("Average score is %d\n", avg_score);
    printf("Total Score is %d", player2.totalScore);

}
