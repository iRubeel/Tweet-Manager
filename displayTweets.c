#include "headerA3.h"

void displayTweets(tweet * tweetList)
{
    tweet * traverse;
    traverse = tweetList;
    
    while(traverse != NULL) //Loop to traverse till the end of linked list
    {
        printf("%d:Created by %s:%s\n",traverse->id,traverse->user,traverse->text); //prints the data in the  linked list
        traverse = traverse->next;
    }
}