#pragma once

#include <iostream>
#include <vector>

namespace nano {

	class Nanotekspice {
		public:
			Nanotekspice() = default;
			~Nanotekspice() = default;
			int parseFile(const std::string &filename);
			void run();
		private:
			bool setIO(std::vector<std::string> &);
			bool setLinks(const std::vector<std::string> &, const std::vector<std::string> &, const std::vector<std::string> &);
			bool checkContent(const std::vector<std::string> &) const;
	};

};