#include "nanotekspice.hpp"
#include <fstream>
#include <vector>


void nts::Nanotekspice::disp(std::vector<nts::IComponent *> &arr) {
	std::cout << "Outputs array: \n";
	for (auto &&i: arr)
		std::cout << i->getName() << std::endl;
}

void nts::Nanotekspice::run() {
	std::cout << "Running" << std::endl;
}

bool nts::Nanotekspice::checkContent(const std::vector<std::string> &fileContent) const {
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
	
bool nts::Nanotekspice::setLinks(const std::vector<std::string> &fileContent) {
	size_t i = 0;
	for (auto &&l: fileContent) {
		if (l.compare(".links:") == 0)
			break;
		i++;
	}
	for (i += 1 ; i < fileContent.size(); i++) {
		size_t pos = fileContent[i].find_last_of(' ');
		links.emplace_back(fileContent[i].substr(0, pos + 1), fileContent[i].substr(pos + 1));
	}
	disp(inputs);
	disp(outputs);
	return true;
}

static const std::array<std::string, 2> CHIPS = {
    "4081",
	"4008"
};

bool nts::Nanotekspice::setChip(const std::string &str) {
	for (auto &&i: CHIPS) {
		if (str.find(i, 0) != std::string::npos) {
			chips.push_back(new Chip4081(str));
		}
	}
	return true;
}

bool nts::Nanotekspice::setIO(std::vector<std::string> &fileContent) {
	for (auto &&i: fileContent) {
		if (i.compare(".chipsets:") == 0)
			continue;
		if (i.find("input", 0) != std::string::npos) {
			std::string toto = i.substr(6);
			inputs.push_back(new Input(toto));
		}
		else if (i.find("output", 0) != std::string::npos) {
			const std::string toto = i.substr(7);
			outputs.push_back(new Output(toto));
		}
		else if (i.compare(".links:") == 0)
			break;
		else {
			setChip(i);
		}
	}
	disp(chips);
	return setLinks(fileContent);
}

int nts::Nanotekspice::parseFile(const std::string &filename) {
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