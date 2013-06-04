/* 
   KnnAm:
   Akshay Chandrashekaran
   2013/06/03
   Description:
   This is the implementation of the DataPFile_old Class which is 
   derived from the DataBase Class. 
   It contains the definitions of the functions 
   needed to interface with the data class. 
   
   Though it creates the data and label arrays, it gives its 
   ownership to the next object, typically dataCPU
   
   Additional functions compared to base: 
   - get and set filename
   - load data
   V0.0: 2013/06/03 Initial Implementation
   
   
*/

#include "Global.h"
#include "DataPFile_old.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>


namespace KnnAm {

  DataPFile_old::DataPFile_old() {
    data_                = NULL;
    label_               = NULL;
    number_of_points_    = 0;
    dimension_           = 0;
    maximum_label_value_ = 0;
  }

  DataPFile_old::~DataPFile_old() {
    data_ = NULL;
    label_ = NULL;
    number_of_points_    = 0;
    dimension_           = 0;
    maximum_label_value_ = 0;
  }
  
  BaseFloat* DataPFile_old::get_data(void) {
    return data_;
  }
  
  void DataPFile_old::set_data(BaseFloat* data) {
    data_ = data;
    return;
  }
  
  uint32* DataPFile_old::get_label(void) {
    return label_;
  }
  
  void DataPFile_old::set_label(uint32 label) {
    label_ = label;
    return;
  }
  
  uint32 DataPFile_old::get_number_of_points(void) {
    return number_of_points_;
  }
  
  void DataPFile_old::set_number_of_points(uint32 number_of_points) {
    number_of_points_ = number_of_points;
    return;
  }
  
  uint32 DataPFile_old::get_dimension(void) {
    return dimension_;
  }
  
  void DataPFile_old::set_dimension(uint32 dimension) {
    dimension_ = dimension;
    return;
  }
  
  uint32 DataPFile_old::get_maximum_label_value(void) {
    return maximum_label_value_;
  }
  
  void DataPFile_old::set_maximum_label_value(uint32 maximum_label_value) {
    maximum_label_value_ = maximum_label_value;
    return;
  }
  
  String DataPFile_old::get_filename(void) {
    return filename_;
  }
  
  void DataPFile_old::set_filename(String filename) {
    filename_ = filename;
    return;
  }
  
  // Load the file 
  void DataPFile_old::load_file(void) {
    // THis function is used to load the file in the pfile format into the 
    // Format of data input as described in dataCPU. This object creates the data and 
    // then the next function gets the ownership of the data and label arrays
    // The destruct of this function pretty much does nothing.
    if (dimension_ == 0)
      std::cerr << "Dimension not set. Abort." 
		<< std::endl;
    assert(dimension_ != 0);
    
    point_offset_ = (dimension_ +   
		     LABEL_OFFSET + 
		     FRAME_OFFSET + 
		     UTTID_OFFSET);
    FILE* file_pointer = fopen(filename_.c_str(),"rb");
    
    // Get the total size of the file and use that along with the point offset 
    // to determine the number of points in the file
    fseek(file_pointer,0,SEEK_END);
    uint32 size = ftell(file_pointer);
    // Make sure that the file is in the correct format. i.e. its size should be a 
    // multiple of the point offset. If not, the file type is wrong.
    if (size%point_offset_ != 0)
      std::cerr << "size of file seems to be wrong. "
		<< "Check file type and/or dimension"
		<< std::endl;
    assert((size%point_offset_ == 0));
    number_of_points_ = ((size/4)/point_offset_);
    fseek(file_pointer, 0, SEEK_SET);
    
    
    // Allocate the memory required for the data and the label
    data_  = (BaseFloat*) calloc(number_of_points_*dimension_, sizeof(BaseFloat));
    label_ = (uint32* )   calloc(number_of_points_, sizeof(uint32));
    
    // Start reading in the data from the file
    for (uint32 pointX = 0; pointX < number_of_points_; pointX++) {
      
      uint32 dataOffset = ((pointX*point_offset_) + 
			   (FRAME_OFFSET + UTTID_OFFSET)) * sizeof(uint32);
      uint32 labelOffset  = dataOffset + (sizeof(BaseFloat)*dimension_);
      
      for (uint32 dimX = 0; dimX < dimension_; dimX++, dataOffset+=4) {
	BaseFloat tempData;
	fseek(file_pointer, dataOffset, SEEK_SET);
	fread(&tempData, sizeof(BaseFloat),1,file_pointer);
	tempData = reverse_float(tempData);
	data[pointX*dimension_ + dimX] = tempData;
      }
      fseek(file_pointer, labelOffset, SEEK_SET);
      uint32 tempLabel;
      fread(&tempLabel, sizeof(uint32), 1, file_pointer);
      tempLabel = BYTE_4_REVERSE(tempLabel);
      if (tempLabel > maximum_label_value_)
	maximum_label_value_ = tempLabel;
      label_[pointX] = tempLabel;
    }
  }
  return;
}
