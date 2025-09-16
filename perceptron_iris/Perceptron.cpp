#include "perceptron.h"
#include "rng.h"

void Perceptron::initialize_params(size_t n) {
	srand(time(0));

	for (size_t input_size = 0; input_size < n; input_size++) { 
		double weight = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
		weights.push_back(weight);
	}

	bias = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
}


void Perceptron::dot_product(std::vector<Input> data, int input_index, bool debug) {
	z = 0.f;
	for (size_t i = 0; i < data[0].features.size(); i++) { //tak samo jak konstruktor, moge dac 4
		z += data[input_index].features[i] * weights[i];

		if(debug) std::cout << "Dot product no bias: " << z << std::endl;
	}
	z += bias;

	if(debug) std::cout << "Dot product with bias: " << z << std::endl;
}


void Perceptron::step_function() {
	if (z >= 0) output = 1;
	else output = 0;
}


void Perceptron::learn(std::vector<Input> data, std::vector<Input> data_test, int epochs, bool debug) {

	initialize_params(data[0].features.size());
	for (int it = 0; it < epochs; it++) {
		std::shuffle(data.begin(), data.end(),rng);
		if(debug) std::cout << "Epoch: " << it << std::endl;

		for (size_t i = 0; i < data.size(); i++) {

			dot_product(data, i, debug);
			step_function();

			if(debug) std::cout << "Output: " << output << std::endl;

			error = data[i].label - output;

			if(debug) std::cout << "Label: " << data[i].label << std::endl;

			if(debug) std::cout << "Error: " << error << std::endl;

			for (int j = 0; j < data[i].features.size(); j++) {
				weights[j] = weights[j] + eta * error * data[i].features[j];

				if(debug) std::cout << "Weight number: " << j << " : " << weights[j] << std::endl;
			}
			bias = bias + eta * error;

			if(debug) std::cout << "Bias: " << bias << std::endl;

		}
		z = 0.f;
		std::cout << "Epochs: " << it + 1 << " Accuracy: " << accuracy_score(data_test) << "\n";
	}
}

int Perceptron::ask(std::vector<Input> data, int input_index, bool debug) {

	dot_product(data, input_index, debug);
	step_function();
	if (debug) {
	    std::cout << "Input number: " << input_index << std::endl;

		for (size_t i = 0; i < data[input_index].features.size(); i++) {
			std::cout << data[input_index].features[i] << " ";
		}
		std::cout << data[input_index].label << std::endl;
	}
	std::string result;
	result = output == 1 ? label[0] : label[1];

	return output;
	
}


float Perceptron::accuracy_score(std::vector<Input>& data) {

	size_t data_size = data.size();
	float n = 0;
	for (size_t i = 0; i < data_size; i++) {
		int y_ = ask(data, i, false);
		if (data[i].label == y_) n++;
	}
	return n / static_cast<float>(data.size());

}