#include "nanotekspice.hpp"
#include <fstream>
#include <vector>

void nano::Nanotekspice::run() {
	std::cout << "Running" << std::endl;
}

bool nano::Nanotekspice::checkContent(const std::vector<std::string> &fileContent) const {
	bool chip = false;
	bool links = false;
	for (auto &&i: fileContent) {
		if (i.compare(".chipsets:") == 0)
			chip = true;
		else if (i.compare(".links:") == 0)
			links = true;
	}
	return links && chip;
}

void disp(const std::vector<std::string> &arr) {
	std::cout << "Array: \n";
	for (auto &&i: arr)
		std::cout << i << std::endl;
}

bool nano::Nanotekspice::setLinks(const std::vector<std::string> &fileContent, const std::vector<std::string> &inputs, const std::vector<std::string> &outputs) {
	disp(inputs);
	disp(outputs);
	return true;
}

bool nano::Nanotekspice::setIO(std::vector<std::string> &fileContent) {
	std::vector<std::string> inputs;
	std::vector<std::string> outputs;
	for (auto &&i: fileContent)
		if (i.find("input", 0) != std::string::npos) {
			inputs.push_back(i.substr(6));
		}
		else if (i.find("output", 0) != std::string::npos) {
			outputs.push_back(i.substr(7));
		}
	return setLinks(fileContent, inputs, outputs);
}

int nano::Nanotekspice::parseFile(const std::string &filename) {
	std::cout << "Filename: " << filename << std::endl;
	std::ifstream file;
	std::vector<std::string> fileContent;

	file.open(filename, std::ifstream::in);
	if (!file) {
		std::cout << "TODO: Add excepections and throw" << std::endl;
		return 1;
	}
	else {
		std::string line;
		while (getline(file, line)) {
			if (line[0] != '#' && line.length() > 0)
				fileContent.push_back(line);
		}
		file.close();
		if (checkContent(fileContent))
			return (setIO(fileContent));
		return 1;
	}

	return 0;
}