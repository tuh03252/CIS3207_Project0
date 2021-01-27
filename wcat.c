/*
*Frank Gatto
*CIS3207 Assignment 0 Part A
*Reads a file specified by the user and prints its contents
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char buffer[1000];
    //if no files were specificed, return
    if(argc < 1)
    {
        return 0;
    }
    for(int i = 1; i < argc; i++)
    {
        FILE *fp = fopen(argv[i], "r");
        //if file cannot be opened, exit
        if(fp == NULL)
        {
            printf("WCat: Cannot open file.\n");
            exit(1);
        }
        //if file has been opened, output contents until reaching end-of-file indicator
        while(!feof(fp))
        {
            fgets(buffer, 1000, fp);
            printf("%s",buffer);
        }
        fclose(fp);
    }

    return 0;
}