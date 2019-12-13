//
//  main.c
//  fileStats
//
//  Created by Troy Turner on 9/24/19.
//  Copyright © 2019 Troy Turner. All rights reserved.
//

/***********************

  File: fileStats.c
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
#include <ctype.h>
#include <unistd.h>

#define MAXCHARS 80

struct FileInfo {
    char *name;    /* name of file */
    int numLines;  /* number of lines in file */
    int numWords;  /* number of words in file */
    int numChars;  /* number of characters in file */
} fileInfo;

int countWords(char *);

int main(int argc, char **argv) {
    FILE *fp;
    struct FileInfo *info; /* array of counts for each file */
    int numLines = 0, numWords = 0, numChars = 0; /* total counts */
    char inString[MAXCHARS];
    char *rs;
    pid_t pid;
    
    //establish pipe to distrubute to child
    int pipes[2];
   int rc = pipe(pipes);
    if(rc == -1){
        exit(1);
    }
    
   pid = fork();
    
    //look at examples in slides
    if(pid==0){
        
    /* allocate array of structs containing counts for each file */
    info = (struct FileInfo *) malloc((argc-1) * sizeof(struct FileInfo));
        
    for (int i=0; i<argc-1; i++) {
        //child for loop
        
        rc = write(pipes[1], &info, sizeof(info));
        /* open an input file, initialize struct of counts */
        //do fork before if statement
        
        //==0 means childif(pid==0){}
    
        
        fp = fopen(argv[i+1], "r");
        if (fp == NULL) {
            printf("Error: cannot open file\n");
            return 0;
        }
    

        info[i].name = (char *) malloc(MAXCHARS * sizeof(char));
        strncpy(info[i].name, argv[i+1], MAXCHARS);
        info[i].numLines = 0;
        info[i].numWords = 0;
        info[i].numChars = 0;
    
        /* read each line, update counts */
        rs = fgets(inString, MAXCHARS, fp);

        while (rs != NULL) {
            info[i].numLines++;
            info[i].numChars += strlen(inString);
            info[i].numWords += countWords(inString);
            rs = fgets(inString, MAXCHARS, fp);
        }
        printf("%s: %d lines, %d words, %d characters\n", info[i].name,
               info[i].numLines, info[i].numWords, info[i].numChars);
    }
    }
        else {
           
            int numLines=0;
            int numWords=0;
            int numChars=0;
    for (int i=0; i<argc-1; i++) {
        
        rc = read(pipes[0],&i, sizeof(i));
        numLines += info[i].numLines;
        numWords += info[i].numWords;
        numChars += info[i].numChars;
    }

    printf("Total: %d lines, %d words, %d characters\n",
           numLines, numWords, numChars);

        }
        int countWords(char *inS);
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


