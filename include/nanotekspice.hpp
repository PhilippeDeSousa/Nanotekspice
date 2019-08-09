#pragma once

#include <iostream>
#include <vector>
#include <array>

#include "output.hpp"
#include "input.hpp"
#include "4081.hpp"

namespace nts {
	using link = std::pair<std::string, std::string>;

	class Nanotekspice {
		public:
			Nanotekspice() = default;
			~Nanotekspice() = default;
			int parseFile(const std::string &filename);
			void run();
		private:
			void disp(std::vector<nts::IComponent *> &arr);
			bool setIO(std::vector<std::string> &);
			bool setLinks(const std::vector<std::string> &);
			bool findChips(const std::vector<std::string> &);
			bool checkContent(const std::vector<std::string> &) const;
			bool setChip(const std::string &);
			std::vector<nts::link> links;
			std::vector<nts::IComponent *> outputs;
			std::vector<nts::IComponent *> inputs;
			// Need to create real chips
			std::vector<nts::IComponent *> chips;
	};

};