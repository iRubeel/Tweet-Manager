#include "headerA3.h"

void saveTweetsToFile(tweet * tweetList)
{
    FILE * fp;
    char filename[50];
    tweet * traverse;
    traverse = tweetList;

    printf("Enter a filename where you would like to store your tweets:");
    scanf("%s",filename);
    fp =  fopen(filename,"w");

    if(fp == NULL) //if file could not be opened
    {
        printf("File could not be opened for saving\n");
        return;
    }
    while(traverse != NULL) //loop till end of linked list
    {
        fprintf(fp,"%d,%s,%s\n",traverse->id,traverse->user,traverse->text); //saves in a csv format file
        traverse = traverse->next;
    }
    printf("Output Successful\n");
    fclose(fp);
}