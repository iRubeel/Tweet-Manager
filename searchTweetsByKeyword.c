#include "headerA3.h"

int searchTweetsByKeyword(tweet * tweetList)
{
    int matchFound;
    tweet * temp;
    temp = tweetList;
    matchFound = 0;
    char keyword[141],tweetString[141];

    printf("Enter a keyword to search:"); //prompt user for keyword
    while(getchar() != '\n');
    scanf("%[^\n]",keyword);

    for(int i = 0; i<strlen(keyword) ; i++) //coverts the keyword to lowercase to account for case insensitive
    {
        keyword[i] = tolower(keyword[i]);
    }
    while(temp != NULL)
    {
        strcpy(tweetString,temp->text);

        for(int i = 0; i <strlen(tweetString); i++)
        {
            tweetString[i] = tolower(tweetString[i]); //coverts tweets to lower case 
        }
        if(strstr(tweetString,keyword)) //finds matching keyword in tweets
        {
            matchFound = 1;
        }
        temp = temp->next;
    }
    return matchFound;
}