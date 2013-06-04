/* 
   KnnAm:
   Akshay Chandrashekaran
   2013/06/03
   Description:
   This is the implementation of the DataCPU_transpose Class which is 
   derived fro the DataBase Class. 
   It contains the declarations of the functions 
   needed to interface with the data class. 
   It takes ownership of the data from any wrapper. i.e.
   It is the responsibility of the inherited object to 
   free up the memory associated with this object
   
   Own Functions: 
   - load_data: loads up the relevant information 
                from the wrapper object into itself
   
   V0.0: 2013/06/03 Initial Implementation
   
   
*/

#ifndef __DataCPU_transpose_h__
#define __DataCPU_transpose_h__

#include <string>
#include "Global.h"
#include "DataBase.h"

namespace KnnAm {
  class DataCPU_transpose : public DataBase {
  private:
    BaseFloat* data_;
    uint32*    label_;
    uint32     number_of_points_;
    uint32     dimension_;
    uint32     maximum_label_value_;
  public:
    DataCPU_transpose();
    virtual ~DataCPU_transpose();
    
    BaseFloat*  get_data(void);
    void        set_data(BaseFloat* data);
    uint32*     get_label(void);
    void        set_label(uint32* label);
    uint32      get_number_of_points(void);
    void        set_number_of_points(uint32 number_of_points);
    uint32      get_dimension(void);
    void        set_dimension(uint32 dimension);
    uint32      get_maximum_label_value(void);
    void        set_maximum_label_value(uint32 maximum_label_value);
    
    void transpose_data(BaseFloat* data,
			uint32*    label,
			uint32     number_of_points,
			uint32     dimension,
			uint32     maximum_label_value);
  }
};


#endif	/* __DataCPU_transpose_h__ */
