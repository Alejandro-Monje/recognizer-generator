#include<iostream>
#include<string>
#include<cstdlib>
#include "queue.h"
using namespace std;

//Name: Alejandro Monje

bool recognizer(string s)
{
  bool T_F = true;
  //will go through each character in the string
  for(int i = 0; i < s.length(); i++)
    {// check to see if the character is either 1 or 0 if not T_F is false
      if(s[i] != '0' && s[i] != '1')
        {
          T_F = false;
        }
    }
  //based on the string it will return true or false
  return T_F;
}


int main()
{

  queue Nq;
  el_t Ls;//string 
  //put 0,1,2 in the queue
  Nq.add("0");
  Nq.add("1");
  Nq.add("2");
 
  //go untill the queue oveflows or the user cancs using ctrl c
  while(true)
    {
      try
	{
          //get the first string from the queue
          Nq.remove(Ls);
          
          //feed the string to the recognizer to test if its in L
          if(recognizer(Ls) == true)
	    {
	      //If its in L display it
	      cout << Ls << endl;
	    }
	  //will generate the next string sequentially
          Nq.add(Ls + "0");
          Nq.add(Ls + "1");
          Nq.add(Ls + "2");
          
	}
      catch(queue::Overflow)//will catch an overflow 
	{
	  cout << "Queue has Overflowed" << endl;
          exit(1);
	}
      catch(queue::Underflow) //will catch an underflow  
	{
	  cout << "Queue has Underflowed" << endl;
	  exit(1);
        }
    }
  return 0;
}
