#ifndef perceptron_h
#define perceptron_h
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "variables.h"
class Perceptron {
private:
	/*struct Input {
		std::vector<double> features;
		int label;
	};*/

	std::vector<double> weights;

	double bias;
	double eta;
	double z = 0.f;
public:
	int output;
	int error;

	Perceptron(double Eta,std::vector<Input>);
	void dot_product(std::vector<Input>, int input_index, bool debug);
	void step_function();
	void learn(std::vector<Input> data,int epochs, bool debug); //uwaga data zawiera obie klasy!!! to nie pojedynczy input

	void ask(std::vector<Input> data, int input_index, bool debug,std::string label[2]);

};








#endif