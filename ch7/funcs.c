
#include <string.h>
#include <stdio.h>

int NUM_ADS = 7;
char *ADS[] = {
    "William: SBM GSOH likes sports, TV, dining",
    "Matt: SWM NS likes art, movies and theater",
    "Luis: SLM ND likes books, theater, art",
    "Mike: DWM DS likes trucks, sports and bieber",  
    "Peter: SAM likes chess, working out and art",
    "Josh: SJM likes sports, movies and theater",  
    "Jed: DBM likes theater, books and dining"
    
};


int sports_no_bieber(char * s)
{
    return strstr ( s, "sports") && !strstr( s, "bieber");
}

int sports_or_workout(char *s)
{
    return strstr(s,"sports") || strstr(s,"working out"); 
}

int arts_theater_or_dining(char *s)
{
    return strstr(s,"theater") || strstr(s,"dining") || strstr(s,"arts");
}

int ns_theater(char *s)
{
    return strstr(s,"NS") && strstr(s,"theater");
}
void find( int(*match)(char*)) // return-type (* names_fn)(param types) // function pointers 
{
    int i;
    puts("Search results:");
    puts("-------------------------------");

    for (i=0; i <  NUM_ADS; i++)
    {
        if( match(ADS[i])){
            printf("%s\n", ADS[i]);
        }
    }
    puts("-------------------------------");
}
int main ()
{
    find(sports_no_bieber); 
    find(sports_or_workout);
    find(ns_theater);
    find(arts_theater_or_dining);

    return 0;
}