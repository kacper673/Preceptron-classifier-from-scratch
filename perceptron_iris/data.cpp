#include "data.h"


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
		std::cerr << "Nie udalo sie otworzyc pliku: " << filename << std::endl;
	}
	else {
		std::cout << "Plik z danymi otworzony" << std::endl;
	}
	std::getline(file, line);
	int n = countSeparators(line, separator);

	std::cout << n << std::endl;

	 do {

		
	
		if (line.empty()) continue;

		std::stringstream ss(line);
		std::string item;
		Input example;

		for (int i = 0; i < n; i++) {
			std::getline(ss, item, separator); //separator = ,
			//item.erase(std::remove_if(item.begin(), item.end(), ::isspace), item.end());
			example.features.push_back(std::stod(item));
		}

		std::getline(ss, item, separator);
		//item.erase(std::remove_if(item.begin(), item.end(), ::isspace), item.end());
		example.label = item == label_actual[0] ? 1 : 0;

		data.push_back(example);
	 } while (std::getline(file, line));

	return data;
}
