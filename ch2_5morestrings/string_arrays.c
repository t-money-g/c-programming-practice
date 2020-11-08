
// demonstrating strcmp - comparing strings
// string search 
// string copy 
// and string slice 
#include <stdio.h>
#include <string.h>

// create an array of arrays 
// The first set of brackets is for the array of all strings 
// the second set of brackets is used for each individual string (len < 80)
// the compiler knows how many strings we have in this array so we don't need to specify 
// in the first bracket 


// [0][0-79] == "'I',' ','l','e','f'..." and so on to \0
char tracks[][80] = { 
    "I left my heart in harvard med",
    "Newark, newark - a wonderful town",
    "Dancing with a dork",
    "From here to maternity",
    "The girl from Iwo Jima"
};

void find_track(char search_for[])
{

    int i;

    for (i = 0; i < 5; i++) {

        if (strstr(tracks[i],search_for ))
            printf("Track %i: '%s'\n",i, tracks[i]);
    }
}
int main() {

    char search_for[80];
    printf("Search for: ");
    scanf("%79s", search_for); 
    //search_for[strlen(search_for) - 1] = '\0'; // why? this will replace the last char with \0 super paranoid 
    //https://en.cppreference.com/w/c/io/fscanf
    find_track(search_for);
    return 0;

}