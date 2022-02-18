#include "headerA3.h"

void addNodeToList(tweet**tweetList,tweet * node)
{
    tweet * newNode;
    tweet * x = *tweetList;
    
    if(*tweetList == NULL) //adds the newnode to the head of the linked list
    {
        newNode = node;
        *tweetList = newNode;
    }
    else //adds the newnode to the end of the linked list
    {
        newNode = node;
        newNode->next = NULL;
        while(x->next != NULL)
        {
            x = x -> next;
        }
        x->next = newNode;
    }
}