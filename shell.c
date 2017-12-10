/*
    LAB ASSIGNMENT #3
    Submitted by - Avijit Verma (14CS01043)

    This is the code for the shell which meets all the requirements mentioned in the Lab Assignment.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

void execute(char *line_read)
{
    int i;
    
    //Implemetation of change directory
	if(strstr(line_read,"cd") != NULL)
    {
        //printf("The above is a change directory command..\n");
        //we need to extract the directory name.... 
        char buffer[256];
        for(i=3;i<strlen(line_read);i++)
		{
			//The directory name has been extracted...
			buffer[i-3] = line_read[i];
		}
		printf("Destination directory: %s\n",buffer);
		chdir(buffer);
        getcwd(buffer,sizeof(buffer));
        printf("Path :%s\n",buffer);
        
        return;
    }
    //Implementation of exit
    else if(strstr(line_read,"exit") != NULL)
    {
        printf("Need to exit from the shell..\n");
        exit(1);
    }
    //Implementation of history
    else if(strstr(line_read,"history"))
    {
        //HIST_ENTRY **entries; 
        printf("History Length = %d\n",history_length);
        //FILE *f1=fopen("file1.txt","w");
        int a=write_history ("file1.txt");
        system("cat file1.txt");

    }
    //IMplementation of the non-builtins
    else
    {
        //executing the command using system command..
        system(line_read);
        
        return;
    }
    


}



void main()
{
    
    char buffer[256],shell_prompt[256];

    while(1)
    {
        
        //For printing the user name and the current working directory as prompt
        snprintf(shell_prompt, sizeof(shell_prompt),"%s" "\x1b[34m"":%s $ " , getenv("USER"), getcwd(NULL, 1024));
        
        printf("\n");
        char *line_read = readline(shell_prompt);

        
        if(strlen(line_read) > 1)
        {
            if(strstr(line_read,"!") == NULL) //if the command does not contain ! then..
            {
                add_history(line_read); //adds to the history...
                stifle_history (10);    //Makes the limit to the 10...

                //After reading the line we need to execute the commands we intake the through the prompt...
                execute(line_read);

                
            }
            else if(strstr(line_read,"!-") == NULL) //if the string doesnot contain ! -n then....
            {
                int i,num,l_n = strlen(line_read)-1;
                //printf("The number of digits of the number..: %d\n",l_n);
                char n[l_n];
                for(i=1;i<strlen(line_read);i++)
                {
                    n[i-1] = line_read[i];
                }
                
                
                
                //change it into integer...
                sscanf(n,"%d",&num);
                
                HIST_ENTRY *h;
                if(num <= history_length)
                {
                    h = history_get(num);
                    printf("The command : %s\n",h->line);

                    execute(h->line);//executing the 2nd command in the history...!!

                }
                else
                {
                    printf("There are not that many commands in the hsitory.\n");
                }
                
            }

            else if(strstr(line_read,"!-") != NULL)
            {
                int i,num,l_n = strlen(line_read)-2;
                
                char n[l_n -1]; //to take the number...
                for(i=2;i<strlen(line_read);i++)
                {
                    n[i-2] = line_read[i];
                }
                
                
                sscanf(n,"%d",&num);
                
                HIST_ENTRY *h;
                num = abs(history_length - num +1);
                
                if(num <= history_length)
                {
                     h = history_get(num);
                     printf("The command : %s\n",h->line);

                    execute(h->line);//executing the 2nd command in the history...!!
                }
                else
                {
                    printf("There is no history before that..!!\n");
                }
               
            }
            
        }

      
    
        free(line_read);
    }
    

}