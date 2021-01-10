#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_rules();
int generate_number();
int get_user_guess(int user_try);
int play_game(int random_number, int i, int guess);
void complete_game(int won, int tries);

int main()
{

    int i = 8, random_number, guess, outcome;
    //generate random number
    random_number = generate_number();
    //show rules of the game to the user
    print_rules();
    //process the game
    outcome = play_game(random_number, i, guess);
    //complete game
    complete_game(outcome, i);

    return 0;
}

void print_rules()
{
    printf("Welcome to the Number Guessing Game.\n");
    printf("RULES:\n1. You only have 8 chances to guess the correct number.");
    printf("\n2. You can WIN the game when the number guessed is same as the randomly generated number.");
    printf("\n3. Hints will be provided during the PLAY.");
    printf("\n\n$$$ Good Luck. Start Guessing $$$");
}

int generate_number()
{
    srand(time(NULL));

    int number = rand() % (100 + 1 - 0);

    return number;
}

int get_user_guess(user_try)
{
    printf("\n\nGUESS %d : ", user_try);

    char value[10];
    //get the value
    fgets(value, 10, stdin);
    //set guess to from value inputted by the user
    int number = atoi(value);

    return number;
}

int play_game(random_number, i, guess)
{

    int flag = 0;

    for (i = 1; i <= 8; i++)
    {
        guess = get_user_guess(i);

        if (guess > random_number)
        {
            printf("Your guess is GREATER THAN the randomly generated number.");
        }
        else if (guess < random_number)
        {
            printf("Your guess is LESS THAN the randomly generated number.");
        }
        else
        {
            flag = 1;
            break;
        }
    }

    return flag;
}

void complete_game(won, tries)
{
    if (won)
    {
        printf("\n\n***You WIN. No. of tries = %d ***", tries);
    }
    else
    {
        printf("\n\n*** You LOST. ***");
    }
}
