/* 
   KnnAm:
   Akshay Chandrashekaran
   2013/06/03
   Description:
   This is the implementation of the DataCPU_transpose Class which is 
   derived from the DataBase Class. 
   It contains the definitions of the functions 
   needed to interface with the data class. 
   It takes ownership of the data from any wrapper. i.e.
   It is the responsibility of the inherited object to 
   free up the memory associated with this object
   
   V0.0: 2013/06/03 Initial Implementation
   
   
*/

#include "Global.h"
#include "DataCPU_transpose.h"
#include <iostream>
#include <cstdlib>

namespace KnnAm {

  DataCPU_transpose::DataCPU_transpose() {
    data_                = NULL;
    label_               = NULL;
    number_of_points_    = 0;
    dimension_           = 0;
    maximum_label_value_ = 0;
  }

  DataCPU_transpose::~DataCPU_transpose() {
    if (data_ != NULL)   free(data_);
    data_ = NULL;
    if (label_ != NULL)  free(label_);
    label_ = NULL;
    number_of_points_    = 0;
    dimension_           = 0;
    maximum_label_value_ = 0;
  }
  
  BaseFloat* DataCPU_transpose::get_data(void) {
    return data_;
  }
  
  void DataCPU_transpose::set_data(BaseFloat* data) {
    data_ = data;
    return;
  }
  
  uint32* DataCPU_transpose::get_label(void) {
    return label_;
  }
  
  void DataCPU_transpose::set_label(uint32 label) {
    label_ = label;
    return;
  }
  
  uint32 DataCPU_transpose::get_number_of_points(void) {
    return number_of_points_;
  }
  void DataCPU_transpose::set_number_of_points(uint32 number_of_points) {
    number_of_points_ = number_of_points;
    return;
  }
  uint32 DataCPU_transpose::get_dimension(void) {
    return dimension_;
  }
  void DataCPU_transpose::set_dimension(uint32 dimension) {
    dimension_ = dimension;
    return;
  }
  
  uint32 DataCPU_transpose::get_maximum_label_value(void) {
    return maximum_label_value_;
  }
  
  void DataCPU_transpose::set_maximum_label_value(uint32 maximum_label_value) {
    maximum_label_value_ = maximum_label_value;
    return;
  }
  
  void DataCPU_transpose::transpose_data(BaseFloat* data,
			  uint32*    label,
			  uint32     number_of_points,
			  uint32     dimension,
			  uint32     maximum_label_value) {
    // Loads the data into the dataCPU_transpose object
    // it gets the above 5 inputs from the some other object, 
    // typically the dataPFile* object. 
    // It takes ownership of data and label
    BaseFloat tempdata = (BaseFloat* ) calloc (number_of_points*dimension,sizeof(BaseFloat));
    for (uint32 pointX = 0; pointX < number_of_points; pointX++) {
      for (uint32 dimX = 0; dimX < dimension, dimX++) {
	tempdata[j*number_of_points + i] = data[i*dimension + j];
      }
    }
    set_data(tempdata);
    templabel = (uint32 *) malloc (sumber_of_points * sizeof(uint32));
    memcpy(templabel, label, number_of_points * sizeof(uint32));
    set_label(templabel);
    set_number_of_points(number_of_points);
    set_dimension(dimension);
    set_maximum_label_value(maximum_label_value);
    return;
  }
}
