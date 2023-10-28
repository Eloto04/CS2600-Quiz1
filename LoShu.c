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

    for (int i = 0; i < 6; i++){
        if (sums[i] != sums[i + 1]){
            return 0;
        }
    }

    return 1;

}

int loopUntilMagic() {
    int startingSquare[3][3] = {{1,2,3}, 
                            {4,5,6}, 
                            {7,8,9}};

    for(int i = 0; i < 3; i++){
        printf("[%d ", startingSquare[i][0]);
        printf("%d ", startingSquare[i][1]);
        printf("%d]\n", startingSquare[i][2]);
    }

    int magic_tracker = 0;
    int counter = 0;

    int firstRow = 0;
    int secondRow = 0;
    int firstCol = 0;
    int secondCol = 0;
    int temp = 0;

    while(magic_tracker == 0){
        counter++;
        firstRow = rand() % 4;
        secondRow = rand() % 4;
        firstCol = rand() % 4;
        secondCol = rand() % 4;

        while(firstRow == secondRow && firstCol == secondCol){
            secondRow = rand() % 4;
            secondCol = rand() % 4;
        }

        temp = startingSquare[firstRow][firstCol];
        startingSquare[firstRow][firstCol] = startingSquare[secondRow][secondCol];
        startingSquare[secondRow][secondCol] = temp;

        if(isMagic(startingSquare) == 1){
            magic_tracker = 1;
        }

    }

}

int main() {
    int my_square[3][3] = {{4,9,2}, 
                            {3,5,7}, 
                            {8,1,6}};
    
    int isSquare = isMagic(my_square);

    if (isMagic(my_square) == 0) {
        printf("Not a magic squrare");
    }
    else {
        printf("This is a magic square!");
    }

   int run = loopUntilMagic();

    return 0;
}