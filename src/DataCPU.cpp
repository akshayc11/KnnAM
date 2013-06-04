/* 
   KnnAm:
   Akshay Chandrashekaran
   2013/06/03
   Description:
   This is the implementation of the DataCPU Class which is 
   derived from the DataBase Class. 
   It contains the definitions of the functions 
   needed to interface with the data class. 
   It takes ownership of the data from any wrapper. i.e.
   It is the responsibility of the inherited object to 
   free up the memory associated with this object
   
   V0.0: 2013/06/03 Initial Implementation
   
   
*/

#include "Global.h"
#include "DataCPU.h"
#include <iostream>
#include <cstdlib>

namespace KnnAm {

  DataCPU::DataCPU() {
    data_                = NULL;
    label_               = NULL;
    number_of_points_    = 0;
    dimension_           = 0;
    maximum_label_value_ = 0;
  }

  DataCPU::~DataCPU() {
    if (data_ != NULL)   free(data_);
    data_ = NULL;
    if (label_ != NULL)  free(label_);
    label_ = NULL;
    number_of_points_    = 0;
    dimension_           = 0;
    maximum_label_value_ = 0;
  }
  
  BaseFloat* DataCPU::get_data(void) {
    return data_;
  }
  
  void DataCPU::set_data(BaseFloat* data) {
    data_ = data;
    return;
  }
  
  uint32* DataCPU::get_label(void) {
    return label_;
  }
  
  void DataCPU::set_label(uint32 label) {
    label_ = label;
    return;
  }
  
  uint32 DataCPU::get_number_of_points(void) {
    return number_of_points_;
  }
  void DataCPU::set_number_of_points(uint32 number_of_points) {
    number_of_points_ = number_of_points;
    return;
  }
  uint32 DataCPU::get_dimension(void) {
    return dimension_;
  }
  void DataCPU::set_dimension(uint32 dimension) {
    dimension_ = dimension;
    return;
  }
  
  uint32 DataCPU::get_maximum_label_value(void) {
    return maximum_label_value_;
  }
  
  void DataCPU::set_maximum_label_value(uint32 maximum_label_value) {
    maximum_label_value_ = maximum_label_value;
    return;
  }
  
  void DataCPU::load_data(BaseFloat* data,
			  uint32*    label,
			  uint32     number_of_points,
			  uint32     dimension,
			  uing32     maximum_label_value) {
    // Loads the data into the dataCPU object
    // it gets the above 5 inputs from the some other object, 
    // typically the dataPFile* object. 
    // It takes ownership of data and label
    
    set_data(data);
    set_label(label);
    set_number_of_points(number_of_points);
    set_dimension(dimension);
    set_maximum_label_value(maximum_label_value);
    return;
  }
}
