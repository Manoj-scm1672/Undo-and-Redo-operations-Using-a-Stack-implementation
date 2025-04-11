#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "stackFunctions.h"
//int dynamic_undo,dynamic_redo,count=0;
STACK *start=NULL;
        //undo action from the file
void undo_push(char line[])
{
    STACK *th=(STACK*)malloc(sizeof(STACK));   //create a stack
   int len = strlen(line);
    int i = 0;
    //getting the last character of the line into stack
         while (line[i] != '\0' && line[i] != '\n') {
            th->data = line[i];
            i++;
        }
        //removing the last character from the line
         if (len > 0 && line[len - 1] != '\n') {
            line[len - 1] = '\0';
        }
        else if (len > 1 && line[len - 1] == '\n') {
            line[len - 2] = '\0';
        }
        printf("\n Undo"); 
    printf("\n %s",line);      //dispalying the line after performing undo operation
   printf("\n removed character:%c",th->data);     // removed character
   //storing the characters into stack
    if(start==NULL)
    {
        th->next=NULL;
        start=th;
    }
    else{
        th->next=start;
        start=th;
    }
}
//redo action from the file
void redo_pop(char line[])
{
    STACK* th=start;
    int size=strlen(line);
    int i;
    //adding back the character to the line
    for (i = 0; i <=size; i++) 
    {

             if (line[i] == '\0') 
                {
                  line[i]=th->data;
                  i++;
                  line[i]='\0';
                }
    }
    printf("\nRedo");
    printf("\n %s",line);   // displaying the line after performing redo operation
    printf("\n added item:%c",th->data);
    //removing the character from the stack
    start=start->next;
    th->next=NULL;
    free(th);

}
//taking text from the file
void type(int lineNumber)
 {
    FILE *file = fopen("project2_data.txt", "r");      //reading the text or lines from the text file
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    int currentLine = 1;
lineNumber=lineNumber+1;
//getting the line which is corresponding to the type action
    // Iterate through the file line by line
    while (fgets(line, sizeof(line), file) != NULL) {
        if (currentLine == lineNumber) {
           printf("\nType");
           printf("\n%s",line);
            fclose(file);
            return;
        }
        currentLine++;
    }

    printf("Error: Line %d not found in the file\n", lineNumber);
    fclose(file);
}
 //dynamic undo operation from the user
void user_undo(char sentence[])
{
    dynamic_undo++;          //counting number of dynamic undo operations
    STACK *th=(STACK*)malloc(sizeof(STACK));
   int len = strlen(sentence);
    int i = 0;
    printf("\n%s",sentence);     //before undo operation
    //removing the last character of the sentence and storing it in stack
         while (sentence[i] != '\0' && sentence[i] != '\n') {
            th->data = sentence[i];
            i++;
        }
         if (len > 0 && sentence[len - 1] != '\n') {
            sentence[len - 1] = '\0';
        }
        else if (len > 1 && sentence[len - 1] == '\n') {
            sentence[len - 2] = '\0';
        }
   printf("\n removed item:%c",th->data);
    printf("\n %s",sentence);        //after undo operation
    //adding a character into stack
    if(start==NULL)
    {
        th->next=NULL;
        start=th;
    }
    else{
        th->next=start;
        start=th;
    }
    return;
}
//dynamic redo operartion from the user
void user_redo(char sentence[])
{
    dynamic_redo++;       //counting number of dynamic redo operations
    if(start==NULL){
    printf("\n stack underflow");     //if stack is empty
    return;
    }
    
    STACK* th=start;
    int size=strlen(sentence);
    int i;
    printf("\n%s",sentence); //before redo operation
    //adding the character to the end of the line
    for (i = 0; i <=size; i++) 
    {

             if (sentence[i] == '\0') 
                {
                  sentence[i]=th->data;
                  i++;
                  sentence[i]='\0';
                }
    }
   printf("\n added item:%c",th->data);
    printf("\n %s",sentence);      //after redo operation
    //deleting the character from stack
    start=start->next;
    th->next=NULL;
    free(th);
    return;

}
//clearing the stack before using it for dynamic operations
void clearStack(STACK** start) {
    STACK* temp;
    while (*start != NULL) {
        temp = *start;
        *start= (*start)->next;
        free(temp); // Free each node
    }
}
