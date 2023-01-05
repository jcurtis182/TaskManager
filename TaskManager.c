#include <stdio.h>
#include <stdlib.h>

char *strreplace(char *s, const char *s1, const char *s2);

int main() {
    procList();
}

//Main Process List
void procList(){
    char command[50];
    strcpy(command, "ps -ef");                          //getting list of processes
    
    printf("[*] Currently Running Tasks:\n");
    system(command);                                    //printing list of processes
    commandPrompt();                                    //ask for command
}

void commandPrompt(){
    printf("\n[...] Enter a command (Type help for command list): ");
    char option[10], command[100], PID[10];
	scanf("%s", option);

    //Command List
    if(strcmp(option, "help") == 0){            
        printf("\n[*] Commands\n");               
        printf("    help  - Prints a list of commands.\n");
        printf("    kill  - Force-quits a process based on given PID.\n");
        printf("    info  - Lists information about a process based on given PID.\n");
        printf("    refresh  - Re-prints process list.\n");
        printf("    quit  - Quits the program.\n");
        printf("[!] Note: All commands are case-sensitive.\n");
        commandPrompt();    //loop back
    }
    
    //Kill Process
    else if(strcmp(option, "kill") == 0){       
        printf("Enter Process ID: ");                             //User gives process id
        scanf("%s", PID);                                
        strcpy(command, "kill <PID>");                  
        strreplace(command, "<PID>", PID);                        //Placeholder PID is replaced
        system(command);                                          //Process corresponding to given PID is killed
        printf("Process %s terminated.", PID);
        commandPrompt();    //loop back
    }

    //List Process Info
    else if(strcmp(option, "info") == 0){       
        printf("Enter Process ID: ");                             //User gives process ID
        scanf("%s", PID);
        strcpy(command, "ps -p <PID> -o pid,vsz=MEMORY -o user,group=GROUP -o comm,args=ARGS"); 
        strreplace(command, "<PID>", PID);                        //Placeholder PID is replaced
        system(command);                                          //Info about given process is printed based on PID
        commandPrompt();    //loop back
    }

    //Refresh Process List
    else if(strcmp(option, "refresh") == 0){
        procList();     //loop back to top of list
    }

    //Exit
    else if(strcmp(option, "quit") == 0){
        printf("\n");
        close();        //exit program
    }
    
    //Error case
    else {
        printf("[!] Unknown command. Type 'help' for a list of commands.\n");         
        commandPrompt();    //loop back
    }
}

char *strreplace(char *string, const char *pHold, const char *new) {                 //Function to replace the placeholder PIDs
    char *p = strstr(string, pHold);
    if (p != NULL) {
        size_t len1 = strlen(pHold);
        size_t len2 = strlen(new);
        if (len1 != len2)
            memmove(p + len2, p + len1, strlen(p + len1) + 1);
        memcpy(p, new, len2);
    }
    return string;
}