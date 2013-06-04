/* 
   KnnAm:
   Akshay Chandrashekaran
   2013/06/03
   Description:
   This is the implementation of the DataPFile_old Class which is 
   derived fro the DataBase Class. 
   It contains the declarations of the functions 
   needed to interface with the data class. 
   It takes ownership of the data from any wrapper. i.e.
   It is the responsibility of the inherited object to 
   free up the memory associated with this object
   
   V0.0: 2013/06/03 Initial Implementation
   
   
*/

#ifndef __DataPFile_old_h__
#define __DataPFile_old_h__

#include <string>
#include "Global.h"
#include "DataBase.h"


#define LABEL_OFFSET 1		/* number of words associated with label */
#define FRAME_OFFSET 2		/* number of words associated with frameID */
#define UTTID_OFFSET 2		/* number of words associated with uttID */

namespace KnnAm {
  class DataPFile_old : public DataBase {
  private:
    BaseFloat*  data_;
    uint32*     label_;
    uint32      number_of_points_;
    uint32      dimension_;
    uint32      maximum_label_value_;
    String      filename_; 
    
  private:
    uint32      point_offset_;
    
  public:
    DataPFile_old();
    virtual ~DataPFile_old();
    
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

    String      get_filename(void);
    void        set_filename(String filename);

    void        load_file(void);
  }
};


#endif	/* __DataPFile_old_h__ */
