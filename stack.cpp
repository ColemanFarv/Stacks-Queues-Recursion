/******************************************************************************
FILENAME:   stack.cpp 
COURSE:     MREN 178
LAB:        2 

STUDENT:   [Coleman Farvolden]         STUDENT ID: [20335398]  
PARTNER:   [Hannah Vibien]    STUDENT ID: [20332596]  

OTHER CONTRIBUTORS: [AS PART OF ACADEMIC INTEGRITY POLICY, ANY CONTRIBUTIONS
OBTAINED FROM ADDITIONAL SOURCES MUST BE LISTED. THESE INCLUDE WEBSITES, OTHER
STUDENTS, ETC.]
******************************************************************************/

#include <stdio.h>
#include "Stack.h"

void CreateStackArray(Stack stack_array[], int num_stacks){
  for (int i=0; i<num_stacks; i++) {
    Stack stack; 
    stack.top = -1; 
    stack_array[i] = stack;
  }
}

int Push(pStack stack, int timestamp, char data) {
  
  /*-------------------------insert your code here--------------------------*/

  if(IsStackFull(stack) == true){ //The maxindex has been reached
    
     return EXIT_ERR; //Returns error as nothing was pushed on to stack
  }
  
  StampedItem temp1; //create new item
  temp1.timestamp = timestamp; //put timestamp in item
  temp1.data = data; //pit char data in item
  stack->top = stack->top + 1; //index the top counter of the stack
  stack->stack_of_items[stack->top] = temp1; //put temp1 item in stack

return EXIT_OK; //Item was pushed onto stack successfuly
}

int Pop(pStack stack, int &timestamp, char &data) {

  /*-------------------------insert your code here--------------------------*/

if(IsStackEmpty(stack) == true){ //Check if stack is empty

  
 return EXIT_ERR;  //Returns error as nothing can be popped from the stack
  
}


stack->top = stack->top - 1; //Pop top item from the stack'


  return EXIT_OK; //Returns that the stack is not empty
}

bool IsStackFull (pStack stack) {
  /*-------------------------insert your code here--------------------------*/

if(stack->top == MAX_STACK_LEN-1){ //The maxindex has been reached
     return true;
  }

  // this return value will need to be changed once your code is written
   return false;
}

bool IsStackEmpty (pStack stack) {
   /*-------------------------insert your code here--------------------------*/

if(stack->top == -1){ //Check if stack is empty
  
 return true; //Return that the stack is empty
}

else{
  
  return false; //Return that the stack is not empty
}

}

void PopAll(pStack stack) {
  /*-------------------------insert your code here--------------------------*/

if(IsStackEmpty(stack) == true){ //Check if stack is empty

  
 return EXIT_ERR; //Error, stack is already empty
  
}

  for (int i = stack->top; stack->top > -1; stack->top--){ //Use loop to pop all ITEMs in stack


stack->top = stack->top - 1; //Pop top item from the stack
    
  }

   return EXIT_OK; //All items were succsessfuly popped from stack

}

int GetTime(DS3231 rtc_clock) {
  /*-------------------------insert your code here--------------------------*/
bool h2flag = false;
bool pmflag;

  int sec = rtc_clock.getSecond(); //finds the amount of seconds
  int min = rtc_clock.getMinute(); //finds the amount of minutes


  long totalSec = min*60 + sec; //returns sum of seconds by converting minutes to seconds and adding to seconds


  return totalSec; //Returns amount of seconds 
}
