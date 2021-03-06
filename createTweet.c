#include "headerA3.h"

tweet * createTweet( tweet * tweetList)
{
    tweet * temp;
    tweet * x;
    x = (tweet*)malloc(sizeof(tweet));
    temp = (tweet*)malloc(sizeof(tweet));

    int lenofUser,sumofAscii,lenoftweet,id;
    id = 0;
    lenofUser =0;
    sumofAscii =0;
    lenoftweet =0;
    temp->id =0;

    //Ask user for username
    printf("Enter a username:");
    scanf("%s",temp->user);
    
    while(strlen(temp->user) < 0 || strlen(temp->user)> 51 ) //Asking user to enter username again if username is longer than 50 characters
    {
        printf("Please enter a username that is less than 50 characters\n");
        printf("Enter a username:");
        scanf("%s",temp->user);
    }

    //Ask user for tweet
    printf("Enter the user's tweet:");
    while(getchar() != '\n');
    scanf("%[^\n]",temp->text);

    while(strlen(temp->text) < 0 || strlen(temp->text)> 141 ) //Asking user to enter tweet again if tweet is longer than 141 characters
    {
        printf("Please enter a tweet that is less than 141 characters\n");
        while(getchar() != '\n');
        scanf("%[^\n]",temp->text);
    }
    temp->next = NULL;
    
    //calculates the sum of ASCII characters in username for ID
    lenofUser = strlen(temp->user);
    lenoftweet = strlen(temp->text);
    for(int i = 0; i<lenofUser;i++)
    {
        sumofAscii = sumofAscii + temp->user[i];
    }

    id = sumofAscii + lenoftweet; //Calculates Computer - Generated ID

    temp->id = id;
    
    //Creates unique ID if SAME ID is generated by computer 
    if(tweetList != NULL)
    {
        x = tweetList;
        while(x != NULL)
        {
            if(x->id == temp->id)
            {
                temp->id = id + rand() % 999 + 1;
            }
            x = x -> next;
        }
    }
    printf("Your computer-generated userid is %d\n",temp->id);
    return temp;
}