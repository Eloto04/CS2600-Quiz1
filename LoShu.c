#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isMagic(int square[3][3]) {
    // Returns 1 if square is magic, 0 otherwise
    int sums[8];

    sums[0] = square[0][0] + square[0][1] + square[0][2]; // first row
    sums[1] = square[1][0] + square[1][1] + square[1][2]; // second row
    sums[2] = square[2][0] + square[2][1] + square[2][2]; // third row
    sums[3] = square[0][0] + square[1][0] + square[2][0]; // first column
    sums[4] = square[0][1] + square[1][1] + square[2][1]; // second column
    sums[5] = square[0][2] + square[1][2] + square[2][2]; // third column
    sums[6] = square[0][0] + square[1][1] + square[2][2]; // first diagonal
    sums[7] = square[2][0] + square[1][1] + square[0][2]; // second diagonal

    for (int i = 0; i < 7; i++){
        if (sums[i] != sums[i + 1]){
            return 0;
        }
    }

    return 1;

}

int loopUntilMagic(int square[3][3]) {
    int magic_tracker = 0;
    int counter = 0;

    while (isMagic(square) == 0){
        counter++;
        int firstRow = rand() % 3;
        int secondRow = rand() % 3;
        int firstCol = rand() % 3;
        int secondCol = rand() % 3;

        while(firstRow == secondRow && firstCol == secondCol){
            secondRow = rand() % 3;
            secondCol = rand() % 3;
        }

        int temp = square[firstRow][firstCol];
        square[firstRow][firstCol] = square[secondRow][secondCol];
        square[secondRow][secondCol] = temp;

        if(isMagic(square) == 1){
            break;
        }

    }

    printf("LoShu Square generated in %d shuffles!\n", counter);

    for(int i = 0; i < 3; i++){
        printf("[%d ", square[i][0]);
        printf("%d ", square[i][1]);
        printf("%d]\n", square[i][2]);
    }

}

int main() {
    int magic_square[3][3] = {{4,9,2}, 
                            {3,5,7}, 
                            {8,1,6}};
    
    int isSquare = isMagic(magic_square);

    if (isMagic(magic_square) == 0) {
        printf("Your input is not a magic square.\n");
    }
    else {
        printf("Your input is a magic square!\n");
    }

    int rand_square[3][3] = {{6,5,2}, 
                            {3,9,8}, 
                            {7,1,4}};

   int run = loopUntilMagic(rand_square);

    return 0;
}