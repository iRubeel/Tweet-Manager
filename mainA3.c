#include "headerA3.h"

int main()
{
    int condition,menu,tweetFound;
    condition = 1;
    tweet * tweetList;
    tweet * tweetNode;
    tweetList = NULL;
    tweetNode = NULL;
    
    while(condition)
    {
        printf("-------------------------\n");
        printf("1.Create a new tweet\n");
        printf("2.Display tweets\n");
        printf("3.Search a tweet\n");
        printf("4.Find how many count words are stop words\n");
        printf("5.Delete the nth tweet\n");
        printf("6.Save tweets to a file\n");
        printf("7.Load tweets from a file\n");
        printf("8.Exit\n");
        printf("-------------------------\n");

        printf("Choose menu option: ");
        scanf("%d",&menu);

        if(menu == 1)
        {
            tweetNode = createTweet(tweetList);
            addNodeToList(&tweetList,tweetNode);
        }
        else if(menu == 2)
        {
            displayTweets(tweetList);
        }
        else if(menu == 3)
        {
            tweetFound = searchTweetsByKeyword(tweetList);
            if(!tweetFound)
            {
                printf("No Match found\n");
            }
            
        }
        else if(menu == 4)
        {
            countStopWords(tweetList);
        }
        else if(menu == 5)
        {
            deleteTweet(&tweetList);
        }
        else if(menu == 6)
        {
            saveTweetsToFile(tweetList);
        }
        else if(menu == 7)
        {
            loadTweetsFromFile(&tweetList);
        }
        else if(menu == 8) //option 8 Exit
        {
            condition = 0;
            printf("- Exited -\n");
            free(tweetList);
            free(tweetNode);
        }
        else
        {
            printf("Please Enter a Number Between 1 to 8\n");
        }
    }
    return 0;
}
