#include <xinu.h>
#include <prodcons.h>
/***************************************************************
 * produce.c - Program which produces the resource n until count
 *
 * Authors: Srikanth Kanuri (srkanuri)
 *          Mangirish Wagle (mawagle)
 * Date Created: 09/20/2016
 * Last Modified by: Srikanth Kanuri
 * Date Last Modified: 09/20/2016
 * Assignment: 2
 ***************************************************************/

extern int n;
extern sid32 produced, consumed;

//Code to produce values less than equal to count, 
//produced value should get assigned to global variable 'n'.
//print produced value e.g. produced : 8
void producer(int count) {

  // Limiting the number of produced items to count for demo.
  int32 x = 0;
  while(x<count) {
    // At any given time, produced items should not exceed count. 
    if(n < count) {
      wait(consumed);
      printf("produced:\t%d\n", ++n);
      signal(produced);
      x++;
    }
    else {
      sleep(1);
      continue;
    }
  }
}    

