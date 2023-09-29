// "Simple Betting game"
// "Jack Queen King" - computer shuffles these cards
// player has to guess the position of queen
// if he wins, he takes 3*bet
// if he looses, he looses the bet amount
// player has $100 initially

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int cash = 100;

void Play(int bet){
    // char c[3] = {'J', 'Q', 'K'}; // allocated in stack

    // to check memory leak, let's created it in heap
    int size = 100; // change the value to check memory usage
    char* c = (char*)malloc(size*sizeof(char)); // C++, char* c = new char[3];
    c[0] = 'J'; c[1] = 'Q'; c[2] = 'K';

    // Why memory usage keeps increasing when we play this game for a while?
    // char* c is a local variable.

    // char c[3]; allocated in stack
    // when function returns, it is also deallocated
    // But, char* is allocated on heap, but we never deallocate it here, 
    // so total memory used by the program increases over time.

    // anything not unused or unreferenced is garbage in heap
    // In C and C++ we have to clear those garbage,
    // In Java and C# garbage is automatically cleared.

    printf("Shuffling.....\n");
    srand(time(NULL));
    int i;
    for(i = 0; i < 5; i++){
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = c[x];
        c[x] = c[y];
        c[y] = temp; // swaps character at position x and y
    }

    int playerGuess;
    printf("What's the position of queen - 1, 2 or 3 ");
    scanf("%d", &playerGuess);
    if (playerGuess < 0 || playerGuess > 3){
        printf("Invalid position guessed!\n");
        return;
    }

    if(c[playerGuess - 1] == 'Q'){
        cash += 3 * bet;
        printf("You win! Result = \"%c\" \"%c %c\" Total cash = %d\n", c[0], c[1], c[2], cash);
    }
    else{
        cash -= bet;
        printf("You lose! Result = \"%c\" \"%c\" \"%c\" Total cash = %d\n", c[0], c[1], c[2], cash);
        
    }
    
    free(c); // check the effect without free
}

int main(){

    int bet;
    printf("Total cash = $%d\n", cash);
    while(cash > 0){
        printf("What's your bet?\n $");
        scanf("%d", &bet);
        // scanf("%d", &bet) != 1 ||
        if( bet == 0 || bet > cash ) break;
        Play(bet);
        printf("************************************\n");
    }
    return 0;
}

// Note : 
// If you want to break out of the loop when a character or non-integer 
// input is given, you can modify your code to check the return value of 
// scanf. When scanf fails to read an integer (i.e., when a character is 
// given as input), it returns a value less than the number of items 
// requested to be scanned. In your case, you are requesting one integer 
// to be scanned, so if scanf doesn't successfully read an integer, it 
// will return a value less than 1. You can use this information to break 
// out of the loop. 