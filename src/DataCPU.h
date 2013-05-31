#ifndef __DataCPU_h_
#define __DataCPU_h_

// DataCPU.h
// This file contains the definition of the CPU data class. 
// This class inherits the base data class from DataBase.h


#include "DataBase.h"

namespace KnnAm {
  class DataCPU : public DataBase {
  private:
    std::string   filename_;
  public:
    DataCPU();
    virtual ~DataCPU();
    
    float*        get_data(void);
    void          set_data(float* data);
    
    unsigned int* get_labels(void);
    void          set_labels(unsigned int* labels);
    
    unsigned int  get_number_of_points(void);
    void          set_number_of_points(unsigned int);
    
    unsigned int  get_dimension(void);
    void          set_dimension(unsigned int);
    
    std::string   get_filename(void);
    void          set_filename(std::string filename);
  };

};
