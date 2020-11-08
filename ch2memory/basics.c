#include <stdio.h>

int y = 1;
void go_south_east(int *lat, int *lon)
{
    *lat = *lat -1;
    *lon = *lon + 1;

}

void doShipMoves(){
    int latitude = 32;
    int longitude = -64;
    go_south_east(&latitude, &longitude);
    printf("Now at: [%i, %i]\n", latitude, longitude);

}

void simplePointerExample()
{
    int x = 4;
    printf("x is stored at %p\n", &x);
}

void fortune_cookie(char msg[]) // or char msg*
{   
    printf("Message reads: %s\n", msg); 
    printf("msg occupies %i bytes\n", sizeof(msg)); // size of the pointer 
}

void pointerAddressing()
{
    int contestants[] =  { 1, 2, 3,}; 
    int *choice = contestants;  // address of the contestants array

    printf("Choice equal %d \n", *choice);
    contestants[0] = 2; // oooh ok it's two because we overwrote the original pointer 
    contestants[1] = contestants[2];
    contestants[2] = *choice;
    printf("Im going to pic contestant number %i\n", contestants[2]);
    

}

void call_cookie()
{
    char quote[] = "Cookies make you fat";
    printf("the quote string is stored at:%p\n", quote);

    fortune_cookie(quote);
}

void array_pointer_differences()
{
    char s[] = "how big is it";
    char *t  = s;

    printf("Sizeof s : %d \n", sizeof(s));
    printf("Size of t : %d \n", sizeof(t));
}

void array_pointer_arithmetic()
{

    int drinks[] = { 1, 2, 3};
    printf("1st order: %i drinks\n", drinks[0]);  // 1
    printf("1st order: %i drinks\n", *drinks);    // 1

    printf("3rd order: %i drinks\n", drinks[2]);
    printf("3rd order: %i drinks\n", *(drinks + 2));

    char *msg_from_amy = "Don't call me";
    {
        puts(msg_from_amy + 6);
    }
    
}

// i need to comment more on what I'm doing here
// here we are demonstrating various format specifiers and giving
// examples on input.
void getinput()
{

    char name[40];
    printf("Enter your name");
    scanf("%39s", name); // read up to 39 plus the string terminator \0

    int age;
    printf("Enter your age: ");
    scanf("%i", &age); // use the & operator to get the value of an int 
                    // %i enter an integer 
                    // %f enter a floating point number 

    // scanf contains the same format codes as printf

    char first_name[20];
    char last_name[20];
    printf("enter first and last name: ");
    scanf("%19s %19s", first_name, last_name);
    printf("First: %s Last: %s\n", first_name, last_name);
}

// problems with scanf this will crash 
// but it doesn't basically all it really does is 
// print the value entered up to 5, but it might crash 
// on other systems. 
// scanf can cause buffer overflows
void scanfcrash()
{

    char food[5];
    printf("Enter your favorite food");
    scanf("%s", food); 
    printf("Favorite food: %s\n", food);
}

// fgets must be given a maximum length 
// output is 
void fgetsForInput()
{
    char food[5];
    printf("Enter favorite food: ");
    fgets(food, sizeof(food), stdin);  // never use gets
    printf("Your favorite food is %s\n", food);
}

void threeCardMonte()
{
    //char *cards = "JQK"; // cannot modify with the code below
    char cards[]  = "JQK";  
    char a_card = cards[2];
    cards[2] = cards[1]; // ouch you can never update a string literal its in rom i.e. constant
    cards[1] = cards[0];
    cards[0] = cards[2];
    cards[2] = cards[1];
    cards[1] = a_card;
    puts(cards);

}
int main()
{
 
    threeCardMonte();
    return 0;
}

