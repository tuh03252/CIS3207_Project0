/*
*Frank Gatto
*CIS3207 Assignment 0 Part A
*Looks through a file trying to find a user-specified term
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char buffer[1000];
    char term[] = argv[1];
    //if passed no arguments, return
    if(argc == 0)
    {
        printf("wgrep: searchterm [file ...]");
        exit(1);
    }
    //if passed a term but no file, read from stdin
    if(argc == 1)
    {
        while(!feof(stdin))
        {
            fgets(buffer, 1000, stdin);
            if(strstr(buffer,term) != NULL)
            {
                printf("%s", buffer);
            } 
        }
    }
    //if passed a term and one or more file
    for(int i = 2; i < argc; i++)
    {
        FILE *fp = fopen(argv[i], "r");
        //if file cannot be opened, exit
        if(fp == NULL)
        {
            printf("wgrep: cannot open file.\n");
            exit(1);
        }
        //if file has been opened, output contents until reaching end-of-file indicator
        while(!feof(fp))
        {
            fgets(buffer, 1000, fp);
            //if the read line contains the term, print the line
            if(strstr(buffer, term) != NULL)
            {
                printf("%s",buffer);
            }
        }
        fclose(fp);
    }
    
    return 0;
}