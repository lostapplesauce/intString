/***********************

  File: fileStats.xcodeproj
  Compile: gcc fileStats.c -o fileStats
  Run: ./fileStats [file1] [file2] ...

  Description: Similar to Unix utility wc
               [file1], [file2] etc are text files. fileStats counts the
               number of lines, words and characters in each file, reports
               the counts for each file, and total counts over all the files.

***********************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <sys/types.h>

#define MAXCHARS 80

struct FileInfo {
  char *name;    /* name of file */
  int numLines;  /* number of lines in file */
  int numWords;  /* number of words in file */
  int numChars;  /* number of characters in file */
} fileInfo;
int countWords(char *);

//pthread_mutex_t lock;

int numLines = 0, numWords = 0, numChars = 0;

void *threads(void *argument) //threads call this function
 {
   //  pthread_mutex_lock(&lock);
     
  FILE *fp;
     struct FileInfo *info  = (struct FileInfo*)argument;
     /* array of counts for each file */
 // int numLines = 0, numWords = 0, numChars = 0; /* total counts */
  char inString[MAXCHARS];
  char *rs;
     
     info = (struct FileInfo *)malloc(sizeof(struct FileInfo));
    
     fp = fopen(argument, "r");
        
     if (fp == NULL) {
          printf("Error: cannot open file\n");
          return 0;
        }
     info[0].name = (char *)malloc(MAXCHARS* sizeof(char));
     strncpy(info[0].name,(char*)argument,MAXCHARS);
     info[0].numLines = 0;
     info[0].numChars = 0;
     info[0].numWords = 0;
     
     /* read each line, update counts */
        rs = fgets(inString, MAXCHARS, fp);
        
        while (rs != NULL)
        {
            info[0].numLines++;       //keeps counting the lines while possible
          info[0].numChars += strlen(inString);
          info[0].numWords += countWords(inString);
          rs = fgets(inString, MAXCHARS, fp);
        }
      
          printf("%d: %s lines, %d words, %d characters\n",
           syscall(SYS_gettid), info[0].name,
       info[0].numLines, info[0].numWords, info[0].numChars);
       numLines += info->numLines; //calculate
      numWords += info->numWords;
     numChars += info -> numChars;
     free(info);
    
         // pthread_mutex_unlock(&lock);
          pthread_exit(NULL);
      
  }
     int main(int argc, char **argv)
    {
         pthread_t thread[argc];
        int iret;
         
         for(int i = 0; i<argc - 1; i++)
            {
                
                if((iret = pthread_create(&thread[i],NULL, threads, argv[i+1]))){
                    printf("Error creating thread %d\n",i);
                    exit(0);
                }
        
             }
             for(int i = 0; i<argc - 1; i++)
             {
                 pthread_join(thread[i], NULL);
             }
   
  printf("Total: %d lines, %d words, %d characters\n",
     numLines, numWords, numChars);
     }

/***********************

  int countWords(char *inS)

  inS: input null-terminated string
  
  returns number of words in string, delimited by spaces

***********************/

 int countWords(char *inS) {
  char *token;
  int numTokens = 0;
  int i=0;

  for (i=1; i<strlen(inS); i++) {
    if ((isalnum(inS[i-1]) || ispunct(inS[i-1])) && (inS[i] == ' ')) {
      numTokens++;
    }
  }
      
  if (isalnum(inS[strlen(inS)-2]) || ispunct(inS[strlen(inS)-2])) {
    numTokens++;
  }
  return numTokens;
}
    

