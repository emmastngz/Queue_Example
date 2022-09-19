#include <stdio.h>

#define QUEUE_SIZE 4

typedef struct
{
  unsigned char Data[QUEUE_SIZE];
  unsigned int Head;   // Points to oldest data element
  unsigned int Tail;   // Points to next free space
  unsigned int Size;   // Quantity of elements in queue
} t_Queue_Data;

t_Queue_Data Q_Read;
t_Queue_Data Q_Write;


void QUEUE_Init(t_Queue_Data* reiceve_Queue)
{
  unsigned int index;
  
  if(reiceve_Queue != NULL)
  {
    for(index = 0; index < QUEUE_SIZE; index++)
    {
      reiceve_Queue -> Data[i] = 0; // Only for debugging porpuse 
    }
    reiceve_Queue -> Head = 0;
    reiceve_Queue -> Tail = 0;
    reiceve_Queue -> Size = 0;
  }
}


int QUEUE_Empty(t_Queue_Data* reiceve_Queue)
{
  unsigned char result;
  
  if((reiceve_Queue -> Size) == 0)
  {
    result = 0;
  }
  return result;
}

int QUEUE_Full(t_Queue_Data* reiceve_Queue)
{
  unsigned char result;
  
  if((reiceve_Queue -> Size) == QUEUE_SIZE)
  {
    result = 1;
  }
  return result
}

// QUEUE_enqueueData - Put a data on the queue 
int QUEUE_enqueueData(t_Queue_Data* reiceve_Queue, unsigned char Data)
{
    int result;
    if(!QUEUE_Full(reiceve_Queue) && (reiceve_Queue != NULL)) // Check if queue is full
    {
      reiceve_Queue -> Data[reiceve_Queue -> Tail++] = d;
      reiceve_Queue -> Tail %= QUEUE_SIZE;
      reiceve_Queue -> Size++;
      result = 1; // Success
    }

    else
    {
      result = 0; // Failure
    }
}

// QUEUE_dequeueData - Take a data on from queue
int QUEUE_dequeueData(t_Queue_Data* reiceve_Queue, unsigned char Data)
{
    unsigned char t = 0;
    if(!QUEUE_Empty(reiceve_Queue)) // Check to see if queue is empty
    {
      t = reiceve_Queue -> Data[reiceve_Queue -> Head];
      reiceve_Queue -> Data[reiceve_Queue -> Head++] = 0; // To simplify debugging, clear
      reiceve_Queue -> Head %= QUEUE_SIZE;
      reiceve_Queue -> Size--;
    }
    return t;
}
