/* 
   KnnAm:
   Akshay Chandrashekaran
   2013/06/03
   Description:
   This is the base implementation of the Data Class 
   It contains the definitions of the virtual functions 
   needed to interface with the actual data classes
   It takes ownership of the data from any wrapper. i.e.
   It is the responsibility of the inherited object to 
   free up the memory associated with this object
   
   V0.0: 2013/06/03 Initial Implementation
   
   
*/


#ifndef __DataBase_h__
#define __DataBase_h__

#include <string>
#include "Global.h"

namespace KnnAm {
  class DataBase {
  private:

  public:
    DataBase() {};
    virtual ~DataBase() {};
    
    virtual BaseFloat*  get_data(void)                                      = 0;
    virtual void        set_data(BaseFloat* data)                           = 0;
    virtual uint32*     get_label(void)                                     = 0;
    virtual void        set_label(uint32* label)                            = 0;
    virtual uint32      get_number_of_points(void)                          = 0;
    virtual void        set_number_of_points(uint32 number_of_points)       = 0;
    virtual uint32      get_dimension(void)                                 = 0;
    virtual void        set_dimension(uint32 dimension)                     = 0;
    virtual uint32      get_maximum_label_value(void)                       = 0;
    virtual void        set_maximum_label_value(uint32 maximum_label_value) = 0;
  };
};

#endif	/* __DataBase_h__ */
