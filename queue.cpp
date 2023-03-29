/******************************************************************************
FILENAME:   queue.cpp 
COURSE:     MREN 178
LAB:        2 

STUDENT:   [Coleman Farvolden]   STUDENT ID: [20335398]  
PARTNER:   [Hannah Vibien]    STUDENT ID: [20332596]  

OTHER CONTRIBUTORS: [AS PART OF ACADEMIC INTEGRITY POLICY, ANY CONTRIBUTIONS
OBTAINED FROM ADDITIONAL SOURCES MUST BE LISTED. THESE INCLUDE WEBSITES, OTHER
STUDENTS, ETC.]
******************************************************************************/

#include "queue.h"

pQueue CreateQueue (void) {
  pQueue pnew = (pQueue)malloc(sizeof (struct queue));
  if (pnew != NULL) {
    pnew->front = NULL;
    pnew->back =  NULL;
    pnew->count = 0;
  }
  return pnew;
}

int CreateQueueArray(pQueue queue_array[], int num_queues){
  for (int i=0; i<num_queues; i++) {
    queue_array[i] = CreateQueue();
    if (queue_array[i] == NULL) {
      //fprintf (stderr, "ERROR: Failed to create queue %d\n", i);
      Serial.print("ERROR: Failed to create queue ");
      Serial.print(i);
      Serial.println(".");
      return EXIT_ERR;
    }
  }
  return EXIT_OK;
}

// Code to create new item and initialize value field
pStampedItem CreateItem (int timestamp) {
  pStampedItem pnew = (pStampedItem) malloc(sizeof(StampedItem));
  if (pnew != NULL) {
    pnew->timestamp = timestamp;
    pnew->next = NULL;
  } else {
    //fprintf (stderr, "ERROR: Failed to create queue %d\n", i);
    Serial.print("ERROR: Failed to create new item ");
    Serial.print(timestamp);
    Serial.println(".");
  }
  return pnew;
}

bool IsQEmpty (pQueue queue) {
  /*-------------------------insert your code here--------------------------*/
if (queue->front == NULL){ //Checks if queue is empty

return true; //The queue is empty
  
}

  return false; //The queue is not empty
}

int Enqueue (pQueue queue, pStampedItem item) {
  /*-------------------------insert your code here--------------------------*/

  //Case 1 queue is empty
  if(queue->front == NULL){ //Checks if queue is empty

queue->front = item; //makes the item the front of the queue
queue->back = item; //makes the item the rear of the queue

  return EXIT_OK; //The enqueue function was completed succesfully 

}

//Case 2 inserting at rear

queue->back->next = item; //Makes the rear of the queue point to the new item 
queue->back = item;  //Makes the new item the back of the qeueue

return EXIT_OK; //The enqueue function was completed succesfully 
  
}


int Dequeue (pQueue queue, int &timestamp) {
  /*-------------------------insert your code here--------------------------*/

  //Case 1 queue is empty
  
  if(queue->front == NULL){ //Checks if queue is empty

  return EXIT_OK; //dequeue is unessesary

 }
  
//Case 2 if last item in queue

if(queue->back == queue->front){ //Check if its the last item remaining in the queue

  //free the last remaining item in the queue

//Set to NULL to prevent memory leakage
queue->front = NULL;
queue->back = NULL;

   free(queue->front); //Free the head pointer
    free(queue->back); //Free the tail pointer
  
    return EXIT_OK; //Item was succsessfully dequed 
    }

//Case 3 more then one item in the queue

StampedItem* tempItem = queue->front->next; //Creats a temp pointer pointer to item after front

   //Frees the memory of the first item of the queue

free(queue->front); //Free old head
  queue->front = tempItem; //Makes the second item the front of the queue
  free(tempItem); //Free temp item pointer
    return EXIT_OK; //Item was succsessfully dequed 
}



int DequeueAll (pQueue queue) {
  /*-------------------------insert your code here--------------------------*/

//Case 1 queue is empty
  if(queue->front == NULL){ //Checks if queue is empty
    
  return EXIT_OK; //The queue is already empty

  }

  //Case 2 the queue is not empty
  
StampedItem* tempItem = queue->front; //Creats a temporary pointer to search the queue

while (tempItem->next != NULL) { //searches until queue is finished

  queue->front = tempItem->next; //Make the next node the head
  free(tempItem);//free the current node
  tempItem = queue->front; //itterates the temporary pointer 
}

    free(tempItem); //Free the temp pointer
    queue->front = NULL; //Free the head pointer
    queue->back = NULL; //Free the tail pointer
    free(queue->front); //Free the head pointer
    free(queue->back); //Free the tail pointer


  return EXIT_OK;  //All items successfully dequeued

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