#include "stackFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int ch;
    FILE *file;
    char *filename = "project2_dataaction.txt"; // The file containing the action data
    count=0;
    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read each line from the file and store it in the array
    while (fgets(lines[count], MAX_LENGTH, file)) {
        // Remove the newline character from the line
        lines[count][strcspn(lines[count], "\n")] = '\0';
        count++;
        // Stop if the maximum number of lines is reached
        if (count >= MAX_LINES) {
            printf("Reached maximum line limit (%d).\n", MAX_LINES);
            break;
        }
    }

    // Close the file
    fclose(file);
   //performing operations on the lines according to the action specified in the file
 for (int i=0;i<count;i++)
 {
if(strcmp(lines[i],"Type")==0)
{
    type(i);                        //getting the line from the file to perform actions 

}
else if(strcmp(lines[i],"Undo")==0)
{
undo_push(line);                     //performing undo as specified in the actions
}
else if(strcmp(lines[i],"Redo")==0)
{
redo_pop(line);                     //performing redo as specified in the actions
}
 }

clearStack(&start);              //clearing the stack before performing dynamic operations
 
       while(1)
    {
        printf("\n enter any operation");
        printf("\n  undo=1 redo=2 type=3\n");   //asking user which operation to be pereformed
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :user_undo(sentence);  //to perform undo
                     break;
            case 2 :user_redo(sentence);   //to perform redo
                     break;
            case 3 :printf("\n type a sentence:"); //take the string from the user
                   scanf(" %[^\n]",sentence);
                   printf("\n%s",sentence);
                     break;
                  
            default: printf("\nInvalid choice");  //terminate the program when there is invalid output
                    printf("\n total undo operations are:%d",dynamic_undo); //number of dynamic undo operations
                    printf("\n total redo operations are:%d",dynamic_redo);  //number of dynamic redo operations
            exit(1);
        }
    
    }
    return 0;
}

