#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//INCOMPLETE DO NOT USE! THIS DOES NOT FREE MEMORY ALLOCATED
// C Programming Language chapter 6 self ref structures 
// Counting occurrences of all the words in some input 
// list of words isn't known in advance 

// binary tree, the most important data structure ever 
// The tree contains one, "node", per distinct word , each node contains 
// a pointer to the text of the word 
// a count of the number of occurances
// a pointer to the left child node
// a pointer to the rright child of the node 


typedef struct tnode {      // the tree node 
    char *word;             //points to the text
    int count;              // number of occurances
    struct tnode *left;     // left child
    struct tnode *right;   
} tnode;

#define MAXWORD 100
tnode *addtree(tnode *, char *);
void treeprint(tnode *);

tnode *talloc(void); // make a tnode
char *mystrdup(char *); // duplicate string 

//getword: get next word or characters from input 
int getword(char *word, int lim);

#define NUMBER '0' // a signal that a number was found used in getch; 
#define BUFFSIZE 100

char buf[BUFFSIZE];      // buffer for ungetch
int bufp = 0;           // next free position in buf

int getch(void);
void ungetch(int);


int main()
{
    tnode *root;
    char word[MAXWORD];

    root = NULL;
    while(getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    
    treeprint(root);
    return 0;
}

int getch(void) 
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push character back on input 
{
    if(bufp >= BUFFSIZE)
        printf("ungetch: too many characters \n");
    else
        buf[bufp++] = c;
}

// teh reason why you get a word by looking at chars bec a word is defined 
// as a contigous sequence of characters broken up by spaces, excluding numerical values 
int getword(char *word, int lim)
{
    int c;
    char *w = word;
    
    while(isspace(c == getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)){
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if(!isalnum(*w == getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];

}

tnode *talloc(void)
{
    return (tnode*)malloc(sizeof(tnode));
}

char *mystrdup(char *s)
{
    char *p;

    p = (char *) malloc(strlen(s) + 1); // +1 for '\0' 
    if (p != NULL)
        strcpy(p,s);
    return p;
}
/* addtree: add a node with w, at or below p */ 
tnode *addtree( tnode *p, char *w)
{
    int cond;

    if (p == NULL) { // a new word has arrived 
        p = talloc(); // make anew node 
        p->word = mystrdup(w); // heap copy 
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp (w, p->word)) == 0)
        p->count++;  // repeated word 
    else if (cond < 0) // less than into left subtree
        p->left = addtree(p->left, w);
    else           // greater than into right subtree 
        p->right = addtree(p->right, w);
    
    return p;
}

// treeprint in-order print of tree p 
void treeprint(struct tnode *p)
{
    if(p != NULL)
        treeprint (p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
}