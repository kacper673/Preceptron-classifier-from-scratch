#ifndef data_h
#define data_h
#include <iostream>
#include <vector> 
#include <string>
#include <sstream>
#include <fstream>
#include "variables.h"

int countSeparators(std::string, char);

std::vector<Input> loadData(const std::string& filename,std::string[2], char);

void splitData(std::vector<Input> data, std::vector<Input>& data_train, std::vector<Input>& data_test, double split_size,bool debug);


#endif 