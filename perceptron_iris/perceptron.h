#ifndef perceptron_h
#define perceptron_h
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "variables.h"
#include "data.h"

class Perceptron {
private:
	std::vector<double> weights;

	double bias;
	double eta;
	double z = 0.f;
	std::string label[2];
public:
	int output;
	int error;

	Perceptron(double Eta,std::string label_[2]) : eta(Eta) {
		label[0] = label_[0];
		label[1] = label_[1];
	};

	~Perceptron() {
		weights.clear();
		bias = 0;
		eta = 0;
		z = 0;
		output = 0;
		error = 0;
	}
	
	void dot_product(std::vector<Input>, int input_index, bool debug);
	void step_function();
	void initialize_params(size_t n);
	void learn(std::vector<Input> data, std::vector<Input> data_test, int epochs, bool debug); 

	int ask(std::vector<Input> data, int input_index, bool debug);

	float accuracy_score(std::vector<Input>& data);

};








#endif