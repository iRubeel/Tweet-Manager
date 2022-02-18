#include "headerA3.h"

void loadTweetsFromFile(tweet ** tweetList)
{
    FILE * fp;
    char filename[50],fileText[1024];
    int condition; 
    condition = 0;
    char* Commas;
    tweet * tempTweet;
    
    printf("Enter a filename to load from:");
    scanf("%s",filename);
    fp =  fopen(filename,"r");

    if(fp == NULL)
    {
        printf("File could not be opened for loading\n");
        return;
    }
    while(fgets(fileText,1024,fp) != NULL) //gets the data from the file till end of file
    {
        tempTweet = (tweet*)malloc(sizeof(tweet));

        if(fileText[strlen(fileText)-1]=='\n' || fileText[strlen(fileText)-1]==',' )
        {
            fileText[strlen (fileText)-1] = '\0';
        }
        Commas = strtok(fileText,","); //reads userID
        tempTweet->id = atoi(Commas);

        Commas = strtok(NULL,","); //reads username
        strcpy(tempTweet->user,Commas);

        Commas = strtok(NULL,"\n"); //reads tweet
        strcpy(tempTweet->text,Commas);

        addNodeToList(tweetList,tempTweet); //adds the node to the linked list
        condition = 1;
    }
    fclose(fp);

    if(condition == 1)
    {
        printf("Tweets Imported!\n");
    }
    else
    {
        printf("Tweets Not Imported!\n");
    }
}