/* From head first c chapter 1
*   Program to evaluate face values 
*   HFC
*/

#include <stdlib.h>
#include <stdio.h>

int main()
{
    char card_name[3];
    puts("Enter card name");
    scanf("%2s", card_name);
    int val = 0;

   /*  if (card_name[0] == 'K')
    {
        val = 10;
    } 
    else if (card_name[0] == 'Q')
    {
        val = 10;
    }
    else if (card_name[0] == 'J')
    {
        val = 10;
    }
    else if (card_name[0] == 'A')
    {
        val = 11;
    }
    else
    {
        val = atoi(card_name); /* converts text to a number */
/*   } */

    switch(card_name[0]){

        case 'K':
        case 'Q':
        case 'J':
            val = 10;
            break;
        case 'A':
            val = 11;
            break;
        default:
            val = atoi(card_name);
    }
    /* printf("The card value is: %i\n", val); */

    /* card counting check if the value is 3 to 6 */
    if(val <= 6 && val >= 3) // wrong actuall
        puts("Count has gone up");
    else if (val == 10)
    {
        puts("Count has gone down");
    }
    
    return 0;
}