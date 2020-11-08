
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// table lookup internals often found inside symbol table management routines of a macro processor or a compiler

typedef struct nlist { // table entry 
    struct nlist* next; // next in chain
    char *name;         // defined name
    char *defn;         // replacement text  
} nlist;


#define HASHSIZE 101

static nlist *hashtab[HASHSIZE];  // pointer in table

// form hash value for string 
unsigned hash(char *s);
// lookup : look for s in hastab
nlist * lookup(char *s);

nlist *install(char *name, char*defn);

unsigned hash(char *s)
{
    unsigned hashval;
    for(hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval; // I wonder could we have xored this as well.

    return hashval % HASHSIZE;
}

nlist *lookup(char *s)
{
    nlist *np;

    // standard linked list lookup 
    // for (ptr = head; ptr != NULL; ptr= ptr->next)
    for (np = hashtab[hash(s)]; np != NULL; np =np->next)
    {
        if (strcmp(s, np->name) == 0)
            return np;          // found
    }
    return NULL;            // not found 
}

nlist *install(char *name, char*defn)
{
    nlist *np;
    unsigned hashval;

    if((np = lookup(name)) == NULL) { // not found 
        np = (nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else // all ready there
        free((void*) np->defn); // free previous defn
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}