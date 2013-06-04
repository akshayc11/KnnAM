/* 
   KnnAm:
   Akshay Chandrashekaran
   2013/06/03
   Description:
   Contains typedefs and declaration of functions 
   needed for making coding simpler and understandable.
   
   V0.0: 2013/06/03 Initial Implementation
   
*/

#ifndef __Global_h__
#define __Global_h__

#include <string>

/* Byte reversal in case of big Endian */
#define BYTE_4_REVERSE(x)       ((((x)<<24)&0xFF000000U) | (((x)<<8)&0x00FF0000U) | \
				 (((x)>>8) & 0x0000FF00U) | (((x)>>24)&0x000000FFU))
#define BYTE_2_REVERSE(x)       ((((x)<<8)&0xFF00U) | (((x)>>8) & 0x00FFU))

namespace KnnAm {
  /* Related to int */
  typedef unsigned int uint32;
  typedef int int32;
  typedef long int64;
  typedef unsigned long uint64;
  typedef short int16;
  typedef unsigned short uint16;


  typedef float BaseFloat;

  typedef unsigned char UCHAR;

  typedef std::string String;
  
  /* Byte reversal in case of big Endian */
  BaseFloat reverse_float(BaseFloat number);
}

#endif	/* __Global_h__ */
