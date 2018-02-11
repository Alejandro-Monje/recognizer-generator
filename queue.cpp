//=========================================================                                                                                                                                                                                   
//Your name: Alejandro Monje                                                                                                        
//Complier:  g++ compiler                                                                                                           
//File type: queue implemenation file                                                                                               
//===========================================================                                                                       

 using namespace std;
#include <iostream>
#include <cstdlib>
#include <string>
#include "queue.h"

// constructor                                                                                                                      
queue::queue()
{
  front = 0; //set to 0                                                                                                             
  rear = -1; // set to -1                                                                                                           
  count = 0; // set 0                                                                                                               
}

//destructor                                                                                                                        
queue::~queue()
{
}

// PURPOSE: returns true if queue is empty, otherwise false                                                                         
bool queue::isEmpty()
{
  if(count == 0) // if count is 0 then there isn't anything in the queue so return true                                             
    return true;
  else
    return false; // else returns false                                                                                             
}

// PURPOSE: returns true if queue is full, otherwise false                                                                          
bool queue::isFull()
{
  if(count ==  MAX_SIZE) // if count is equal to the max size then queue is full                                                    
    {
      throw Overflow(); // throw overflow if full                                                                                   
      return true;    // return true is full                                                                                        
    }
  else
    return false;   // else return false                                                                                            
}
// PURPOSE: if full, throws an exception Overflow                                                                                   
// if not full, enters an element at the rear                                                                                       
// PAREMETER: provide the element (newElem) to be added                                                                             
void queue::add(el_t newElem)
{
  if(isFull())  // check if full if it is throw overflow                                                                            
    {
      throw Overflow();
    }
  else
    {
      rear = (rear + 1) % MAX_SIZE;
      el[rear] = newElem;
      count++;
    }
}

// PURPOSE: if empty, throw Underflow                                                                                               
// if not empty, removes the front element to give it back                                                                          
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)                                                  
void queue::remove(el_t& removedElem)
{
  if(isEmpty()) // check if empty if it is throw underflow                                                                          
    {
      throw Underflow();
    }
  else
    {
      removedElem = el[front];
      front = (front + 1) %  MAX_SIZE;
      count--;
    }

}
// PURPOSE: if empty, throws an exception Underflow                                                                                 
// if not empty, give back the front element (but does not remove it)                                                               
//PARAMETER: provide a holder (theElem) for the element (pass by ref)                                                               
void queue::frontElem(el_t& theElem)
{
  if(isEmpty())
    throw Underflow();
  else
    theElem = el[front]; //theElem is a holder                                                                                      

}

// PURPOSE: returns the current size to make it                                                                                     
// accessible to the client caller                                                                                                  
int queue::getSize()
{
  return count;
}

// PURPOSE: display everything in the queue horizontally from front to rear                                                         
// enclosed in []                                                                                                                   
// if empty, displays [ empty ]                                                                                                     
void queue::displayAll()
{
  if(isEmpty())
    throw Underflow();
  else
    {
      int a = front; // int a is equal to front so that a i don't change front                                                      
      cout << "[ ";
      for(int i = 1; i <= count; i++)// when i equals count then it has gone through the                                            
        {                            // queue                                                                                       
          cout << el[a] << " ";
          a = (a + 1)% MAX_SIZE;
        }
      cout << " ]";
    }
}
// PURPOSE: if empty, throws an exception Underflow                                                                                 
//if queue has just 1 element, does nothing                                                                                         
//if queue has more than 1 element, moves the front one to the rear by                                                              
//doing remove followed by add.                                                                                                     
void queue::goToBack()
{
  if(isEmpty())
    throw Underflow();
  else
    {
      el_t b = el[front]; // el_t b = to the front element of the array so that I                                                   
      remove(el[front]);   // am able to still have what was removed                                                                
      add(b);
    }
}

