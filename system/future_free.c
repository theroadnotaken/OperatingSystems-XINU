/* future_free.c - future_free */

#include <xinu.h>
#include <future.h>
/***************************************************************
 * future_free.c - Frees of the memory allocated for future
 *
 * Authors: Srikanth Kanuri (srkanuri)
 *          Mangirish Wagle (mawagle)
 * Date Created: 10/06/2016
 * Last Modified by: Srikanth Kanuri
 * Date Last Modified: 10/06/2016
 * Assignment: 4
 ***************************************************************/

syscall future_free(future* f)
{
  if(freemem((char*)f->get_queue, sizeof(fqueue)) == OK) {
  	if(freemem((char*)f->set_queue, sizeof(fqueue)) == OK) {
  		return freemem(f, sizeof(f));
  	}
  }
  return SYSERR;
}

