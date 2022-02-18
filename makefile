CC=gcc
CFLAGS=-Wall	-std=c99
A3:	mainA3.o	createTweet.o	displayTweets.o	searchTweetsByKeyword.o	countStopWords.o	deleteTweet.o	saveTweetsToFile.o	loadTweetsFromFile.o	addNodeToList.o
	$(CC)	$(CFLAGS)	createTweet.o	displayTweets.o	searchTweetsByKeyword.o	countStopWords.o	deleteTweet.o	saveTweetsToFile.o	loadTweetsFromFile.o	addNodeToList.o	mainA3.o	-o	a3
createTweet.o:	createTweet.c	headerA3.h
	$(CC)	$(CFLAGS)	-c	createTweet.c
displayTweets.o:	displayTweets.c	headerA3.h
	$(CC)	$(CFLAGS)	-c	displayTweets.c
searchTweetsByKeyword.o:	searchTweetsByKeyword.c	headerA3.h
	$(CC)	$(CFLAGS)	-c	searchTweetsByKeyword.c
countStopWords.o:	countStopWords.c	headerA3.h
	$(CC)	$(CFLAGS)	-c	countStopWords.c
deleteTweet.o:	deleteTweet.c	headerA3.h
	$(CC)	$(CFLAGS)	-c	deleteTweet.c
saveTweetsToFile.o:	saveTweetsToFile.c	headerA3.h
	$(CC)	$(CFLAGS)	-c	saveTweetsToFile.c
loadTweetsFromFile.o:	loadTweetsFromFile.c	headerA3.h
	$(CC)	$(CFLAGS)	-c	loadTweetsFromFile.c
addNodeToList.o:	addNodeToList.c	headerA3.h
	$(CC)	$(CFLAGS)	-c	addNodeToList.c
mainA3.o:	mainA3.c	headerA3.h
clean:
	rm *.o

