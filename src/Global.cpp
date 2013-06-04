/* 
   KnnAm:
   Akshay Chandrashekaran
   2013/06/03
   Description:
   Contains definitions of general functions 
   for making coding simpler and understandable.
   
   
   V0.0: 2013/06/03 Initial Implementation
   reverse_float: reverses the endianness 
   of a float number
*/

#include "Global.h"

BaseFloat reverse_float(BaseFloat number) {
  // Used to reverse a floating point number for 
  // endianness.
  UCHAR *cptr = reinterpret_cast<UCHAR *>(&number);
  UCHAR tmp   = cptr[0];
  cptr[0]     = cptr[3];
  cptr[3]     = tmp;
  tmp         = cptr[1];
  cptr[1]     = cptr[2];
  cptr[2]     = tmp;      
  return number;

}
