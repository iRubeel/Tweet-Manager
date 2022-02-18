#include "headerA3.h"

void countStopWords(tweet * tweetList)
{
    tweet * temp = tweetList;
    int countStopWords,countTweets;
    countStopWords = 0;
    countTweets =0;
    char stopWords[25][5] = {"a","an","and","are","as","at","be","by","for","from","has","he","in","is","it","its","of","on","that","the","to","was","were","will","with"};
    char *word;
    char userTweet[141];

    while(temp != NULL)
    {
        strcpy(userTweet,temp->text);
        if(userTweet[strlen(userTweet)-1] == '\n') //changes the newline character to a null character
        {
            userTweet[strlen(userTweet)-1] = '\0';
        }
        char *temp1 = (char*)malloc(sizeof(char)*strlen(userTweet)+1);

        for(int i =0; i <strlen(userTweet) ; i++)
        {
            temp1[i] = userTweet[i];
        }
        word = strtok(temp1," .:;?!"); //breaks each words 
        while(word != NULL)
        {
            for(int i = 0; i<25 ; i++)
            {
                if(strcmp(word,stopWords[i]) == 0) //checks each words for stop words
                {
                    countStopWords++;
                }
            }
            word = strtok(NULL," ,;:?!\n\t");
        }
        countTweets++;
        temp = temp->next;
    }
    printf("Across %d tweets, %d stop words were found.\n",countTweets,countStopWords);
}