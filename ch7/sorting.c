#include <stdio.h>
#include <stdlib.h>


// qsort(void *array,       
//      size_t length,
//      size_t item_size,
//      int (*compar)(const void *, const void *))


int compare_scores(const void* score_a, const void* score_b) // yeah I like void pointers 
{
    int a = *(int*)score_a; // first cast to int pointer then dereference 
    int b = *(int*)score_b; 
    return a - b;
}

int compare_scores_desc(const void* score_a, const void* score_b)
{
    int a = *(int*)score_a; // first cast to int pointer then dereference 
    int b = *(int*)score_b; 
    return b-a; 
}

typedef struct {
    int width;
    int height;
} rectangle;

int main() 
{
    int scores[] = { 543, 323, 32, 554, 11, 2, 112};
    qsort(scores, 7, sizeof(int), compare_scores);
    puts("These scores are in order");
    for(int i = 0; i < 7; i++)
    {
        printf("Score = %i\n", scores[i]);
    }
    
}