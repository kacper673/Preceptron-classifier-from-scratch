#include "data.h"
#include "rng.h"

int countSeparators(std::string line, char separator) {

	static bool counted = false;
	static int n = 0;

	if (!counted) {
		

		for (size_t i = 0; i < line.size(); i++) {
			if (line[i] == separator) n++;
		}

		counted = true;
	}
	return n;
}


std::vector<Input> loadData(const std::string& filename,std::string label_actual[2], char separator) {
	std::vector<Input> data;
	std::ifstream file(filename); //do zapisywania pojedynczych skladowych input oraz jego label
	std::string line;
	if (!file.is_open()) {
		std::cerr << "Failed to load data file: " << filename << "\n";
	}
	else {
		std::cout << "Data file loaded successfully" << "\n\n";
	}
	std::getline(file, line);
	int n = countSeparators(line, separator);

	 do {

		if (line.empty()) continue;

		std::stringstream ss(line);
		std::string item;
		Input example;

		for (int i = 0; i < n; i++) {
			std::getline(ss, item, separator); 
			example.features.push_back(std::stod(item));
		}

		std::getline(ss, item, separator);
		example.label = item == label_actual[0] ? 1 : 0;

		data.push_back(example);
	 } while (std::getline(file, line));

	return data;
}


void splitData(std::vector<Input> data, std::vector<Input>& data_train, std::vector<Input>& data_test, double split_size,bool debug) {

	if (split_size < 0.05 || split_size > 0.7) {
		std::cerr << "Data_split size to small or to big \n";
		return;
	}

	if (data.empty()) {
		data_train.clear();
		data_test.clear();
		return;
	}

	std::shuffle(data.begin(), data.end(), rng);

	size_t data_size = data.size();

	size_t split = static_cast<size_t>(std::llround(data_size * split_size));

	data_test.assign(data.begin(), data.begin() + split);
	data_train.assign(data.begin() + split, data.end());

	if (debug == true) {
		std::cout << "Data size: " << data.size() << "\n";
		std::cout << "Split size: " << split_size << "\n";
		std::cout << "Train size: " << data_train.size() << "\n";
		std::cout << "Test size: " << data_test.size() << "\n";
	}
}
