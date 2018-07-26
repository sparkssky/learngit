/*************************************************************************
    > File Name: Simon.c
    > Author: GatieMe
    > Mail: gatieme@163.com
    > Created Time: Wed 21 Mar 2018 01:39:27 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    char another_game = 'Y';
    const unsigned int DELAY = 1;
    bool correct = true;

    unsigned int tries = 0;
    unsigned int digits = 0;
    time_t seed = 0;
    unsigned int number = 0;
    time_t wait_start=0;
    clock_t start_time=0;
    unsigned int score=0;
    unsigned int total_digits = 0;
    unsigned int game_time=0;

    printf("\nTo play simple simon, ");

    scanf("%c",&another_game);

    /*
     * main loop
     * */
    do
    {
        /* initialize a game*/
        correct = true;
        tries = 0;
        digits = 2;
        start_time=clock();
        //Inner loop continues as long as sequences are entered correctly
        while(correct)
        {
            ++tries;
            wait_start=clock();

            //generate a sequence of digits and display them
            srand(time(&seed));//initialize the random sequence
            for(unsigned int i =1;i<=digits;++i)
                printf("%u ",rand() % 10);//output a random digit
            for(;clock()-wait_start < DELAY*CLOCKS_PER_SEC;);//wait delay seconds

            //overwrite the digit sequence
            printf("\r");//go to the beginning of the line
            for(unsigned int i=1;i<=digits;++i)
                printf(" ");//output two spaces
            if(tries == 1)
                printf("\nnow you enter the sequence - don't forget\n");
            else
                printf("\r");//else return to the beginning of the line

            srand(seed);//reinitialize the random sequence

            for(unsigned int i =1;i<=digits;++i)
            //read the input sequence & check against the original
            {
                scanf("%u",&number);
                if(number != rand()%10)
                {
                    correct = false;
                    break;
                }
            }

            //on every third successful try,increase the sequence length
            if(correct&& (tries%3)==0)
                ++digits;
            printf("%s\n",correct? "correct!":"wrong!");


        }
        /*output the scope when a game is finished*/
        score = 10*(digits -((tries%3) == 1));
        total_digits = digits*(((tries %3)==0)?3:tries%3);
        if(digits >2)
            total_digits+=3*((digits-1)*(digits-2)/2-1);
        game_time=(clock() -start_time)/CLOCKS_PER_SEC-tries*DELAY;

        if(total_digits>game_time)
            score+=10*(game_time-total_digits);
        fflush(stdin);
        //check if a new game is required

        printf("\n do u want to play again (y/n)? ");
        scanf("%c",&another_game);
    }while(toupper(another_game)=='Y');

    return 0;
}
