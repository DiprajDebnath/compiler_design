#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void isAccepted(char []);

void main()
{
    //printf("Enter your text ");

    char str[100];
    //scanf("%[^\n]",str);

    //file handling part
    FILE *fp;

    fp = fopen("input.txt", "r");

    if(fp == NULL)
    {
        printf("File not found\n");
        exit -1;
    }
  
    printf("The valid numbers in the file are\n");

    while (fgets(str, 99, fp) != NULL)
    {
        isAccepted(str);
    }

    fclose(fp);
}

void isAccepted(char str[])
{
    int state = 0; //initial state
    int s = 0; //starting index
    int i; //ending index
    int len = strlen(str);

    
    for(i = 0; i <= len; i++)
    {
        switch(state)
        {
            case 0: //at state 0
                    if(str[i] >= '0' && str[i] <= '9')
                    {
                        s = i;
                        state = 1;
                    }
                    break;
                    
            case 1: //at state 1
                    if(str[i] >= '0' && str[i] <= '9')
                    {
                        state = 1;
                    }
                    else if(str[i] == '.')
                    {
                        state = 2;
                    }
                    else if (str[i] == 'E' || str[i] == 'e')
                    {
                        state = 4;
                    }
                    else
                    {
                        int j;
                        //print the number
                        for(j = s; j < i; j++)
                        {
                            printf("%c",str[j]);
                        }
                        printf("\n");
                        state = 0; //again start from state 0
                    }
                    break;
                  
            case 2: //at state 2
                    if(str[i] >= '0' && str[i] <= '9')
                    {
                        state = 3;
                    }
                    else
                    {
                        int j;
                        for(j = s; j < i-1; j++)
                        {
                            printf("%c",str[j]);
                        }
                        printf("\n"); //put one 0 at the end
                        state = 0; //again start from state 
                    }
                    break;

            case 3: //at state 4
                    if(str[i] >= '0' && str[i] <= '9')
                    {
                        state = 3;
                    }
                    else if (str[i] == 'E' || str[i] == 'e')
                    {
                        state = 4;
                    }
                    else
                    {
                        int j;
                        //print the number
                        for(j = s; j < i; j++)
                        {
                            printf("%c",str[j]);
                        }
                        printf("\n");
                        state = 0; //again start from state 0
                    }
                    break;
            case 4: //at state 4
                    if(str[i] >= '0' && str[i] <= '9')
                    {
                        state = 6;
                    }
                    else if(str[i] == '+' || str[i] == '-')
                    {
                        state = 5;
                    }
                    else
                    {
                        int j;
                        for(j = s; j < i-1; j++)
                        {
                            printf("%c",str[j]);
                        }
                        printf("\n"); //put one 0 at the end
                        state = 0; //again start from state 
                    }
                    break;
            
            case 5: //at state 5
                    if(str[i] >= '0' && str[i] <= '9')
                    {
                        state = 6;
                    }
                    else
                    {
                        int j;
                        for(j = s; j < i; j++)
                        {
                            printf("%c",str[j]);
                        }printf("Enter your text ");

                        printf("0\n"); //put one 0 at the end
                        state = 0; //again start from state 
                    }
                    break;

            case 6: //at state 6
                    if(str[i] >= '0' && str[i] <= '9')
                    {
                        state = 6;
                    }
                    else
                    {
                        int j;
                        //print the number
                        for(j = s; j < i; j++)
                        {
                            printf("%c",str[j]);
                        }
                        printf("\n");
                        state = 0; //again start from state 0
                    }
                    break;

            default : break;
                        
        }
    }
}