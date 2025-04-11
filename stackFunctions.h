#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 5000             //define the maximum size
#define MAX_LINES 100   // Maximum number of lines
#define MAX_LENGTH 256  // Maximum length of each line
char lines[MAX_LINES][MAX_LENGTH];
int dynamic_undo,dynamic_redo,count;
char line[SIZE],sentence[SIZE];
//creating stack defination using stucture
typedef struct stack
{
    char data;
    struct stack *next;
}STACK;
extern STACK *start;
void undo_push(char line[]);        //undo action from the file
void redo_pop(char line[]);         //redo action from the file
void type(int lineNumber);          //taking text from the file
void user_undo(char sentence[]);      //dynamic undo operation from the user
void user_redo(char sentence[]);       //dynamic redo operartion from the user
void clearStack(STACK** start);       //clearing the stack before using it for dynamic operations