#include <iostream>
#include "data.h"
#include "perceptron.h"

int main()
{
    //std::string filePath = argv[1];
    //std::string label[2] = { argv[2], argv[3] };
    //double eta = std::stod(argv[4]);
    //int epochs = std::stoi(argv[5]);
    //bool debug = std::stoi(argv[6]);


    std::string filePath = "YOUR_FILE_PATH_HERE";
    std::string label[2] = { "Iris-setosa","Iris-versicolor" };  //labels

    std::vector<Input> data = loadData(filePath,label,',');
    

    Perceptron perceptron(0.01, data);  //args - (learning rate, data file)
   
    perceptron.learn(data, 100, false);  //args - (data file, epochs, show debug)

    for (int j = 0; j < 100; j++) {
        perceptron.ask(data, j, false, label);
    }
 
   return 0;
}


  
  
  
