#ifndef __DataBase_h_
#define __DataBase_h_

// DataBase.h
// This file contains the definition of the abstract base data class.
// The data typically will have the following format:
// 1. The raw data: Arranged in a continuous matrix 
// 2. The labels:   Typically, training data will have labels, 
//                  Test data does not have labels
// 3. Number of Rows
// 4. Dimensionality

#include <string>

namespace KnnAm {
  class DataBase {
  private:
    float*        data_;
    unsigned int* labels_;
    unsigned int  number_of_points_;
    unsigned int  dimension_;
    
  public:
    DataBase() {}
    virtual ~DataBase() {}
    
    // Functions needed by the interface
    virtual float*        get_data(void)                     = 0;
    virtual void          set_data(float* data)              = 0;
    
    virtual unsigned int* get_labels(void)                   = 0;
    virtual void          set_labels(unsigned int* labels)   = 0;
    
    virtual unsigned int  get_number_of_points(void)         = 0;
    virtual void          set_number_of_points(unsigned int) = 0;
    
    virtual unsigned int  get_dimension(void)                = 0;
    virtual void          set_dimension(unsigned int)        = 0;
  };
};

#endif
