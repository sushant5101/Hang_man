//===================================================including required libaries==========================
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
// #include <windows.h>

//==================================================defining functions=======================================

void EASY_LEVEL();

//==================================================adding some global variables=============================

int iLength_of_random_selected_word = 0,
    iTemp_count = 0;
char cUsed_letter[10];

//=================================================creating structure to hold details for repetative task====

struct DUPLICATE_LETTER
{
    char cCharacter;
    int iCount;
};
struct DUPLICATE_LETTER data[10];

//================================================begining of the main function==============================

int main()
{

    int iLevel_index = 0;

    printf("Welcome to Hangman!\n");
    printf("Choose a proper index according to the following list:\n");
    printf("1. Easy\n2.Medium\n3.Hard\n");
    scanf("%d", &iLevel_index);

    //============================================calling the apropriate function according to the user input====

    switch (iLevel_index)
    {
    case 1:
        EASY_LEVEL();
        break;

    case 2:
        // MEDIUM_LEVEL();
        break;

    case 3:
        // HARD_LEVEL();
        break;

    default:
        return 1;
        break;
    }

    //=====================================================for now just ending the main function=================

    return 0;
}

//======================================declaring function to handel easy level==============================

void EASY_LEVEL()
{
    srand(time(0));
    int iRand_index = rand() % 10; // (rand() % max - min + 1) + min, for random array index each time

    int iRemaining_guesses = 8;

    bool bIf_matched = false;

    char cUser_guessed_letter; //--to store the user current entred letter---

    const char *cEasy_word[] = {//---words to choose from in easy level
                                "apple",
                                "chair",
                                "happy",
                                "house",
                                "water",
                                "light",
                                "music",
                                "pizza",
                                "river",
                                "tiger"};

    printf("%s\n", cEasy_word[iRand_index]); // just checking

    iLength_of_random_selected_word = strlen(cEasy_word[iRand_index]);

//================================================Handelling player correct guesses and incorect ================

    while (iRemaining_guesses > 0)
    {
        printf("You have %d reminning guesses\n", iRemaining_guesses);
        printf("The word has total of %d letters\n", iLength_of_random_selected_word);
        scanf(" %c", &cUser_guessed_letter);

        for (int i = 0; i < iLength_of_random_selected_word; i++)
        {
            if (cUser_guessed_letter == cUsed_letter[i])
            {
                printf("You have allready guessed the letter %c guess another letter\n", cUser_guessed_letter);
                bIf_matched = true;
                break;
            }
            else if (cEasy_word[iRand_index][i] == cUser_guessed_letter)
            {
                cUsed_letter[i] = cUser_guessed_letter;
                printf("You have found one of the correct letter of the mysterious word\n");
                break;
            }
            else if (cEasy_word[iRand_index][i] != cUser_guessed_letter)
            {
                iTemp_count++;
            }
        }

        if (iTemp_count == iLength_of_random_selected_word)
        {
            printf("You lost your one guess\n");
            cUsed_letter[iTemp_count] = cUser_guessed_letter;
            iRemaining_guesses--;
        }
    }
//========================================================================================================
}