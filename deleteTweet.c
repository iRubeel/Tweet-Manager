#include "headerA3.h"

void deleteTweet(tweet ** tweetList)
{
    int n,tweetCount;
    tweetCount = 0;
    tweet * traverse;
    traverse = *tweetList;
    tweet * temp1;
    temp1 = *tweetList;
    
    while(traverse != NULL) //counts number of tweets
    {
        tweetCount++;
        traverse = traverse->next;
    }
    printf("Currently there are %d tweets\n",tweetCount);
    printf("Which tweet do you wish to delete - Enter a value between 1 and %d:",tweetCount);
    scanf("%d",&n);

    if(tweetCount == 0) //checks if theres 0 tweets then nothing can be deleted 
    {
        printf("Currently there are 0 Tweets,therefore nothing can be deleted\n");
        return;
    }
    if(n == 1) //deletes the first tweet
    {
        *tweetList = temp1->next;
        free(temp1);
        printf("Tweet %d deleted.There are now %d tweets left\n",n,tweetCount--);
    }
    else //deletes the Nth tweet
    {
        printf("Tweet %d deleted.There are now %d tweets left\n",n,tweetCount--);
        for(int i=0; i<n-2 ;i++)
        {
            temp1 = temp1->next;
        }
        tweet * temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp2);
    }
}