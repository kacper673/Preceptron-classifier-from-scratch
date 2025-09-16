#include <iostream>
#include "data.h"
#include "perceptron.h"


int main()
{
    bool debug = false;

    std::string filePath = "C:\\Users\\alber\\Desktop\\Projekty\\perceptron_iris\\assets\\iris.data";
    std::string label[2] = { "Iris-setosa","Iris-versicolor" };

    std::vector<Input> data = loadData(filePath,label,',');
    std::vector<Input> data_train;
    std::vector<Input> data_test;

    splitData(data,data_train,data_test,0.5,debug);
    
    Perceptron perceptron(0.001,label);
   
    perceptron.learn(data_train, data_test, 20, debug);
   
    std::cout<<"\nAccuracy: " << (perceptron.accuracy_score(data_test))<<"\n";


    ///-----aveilable funcions------
    /*
    class Perceptron

    -void learn(std::vector<Input> data, std::vector<Input> data_test, int epochs, bool debug); 

	-int ask(std::vector<Input> data, int input_index, bool debug);

	-float accuracy_score(std::vector<Input>& data);
    
    Data

    -std::vector<Input> loadData(const std::string& filename,std::string[2], char);

    -void splitData(std::vector<Input> data, std::vector<Input>& data_train, std::vector<Input>& data_test, double split_size,bool debug);
    */
 
   return 0;
}


  
  
  