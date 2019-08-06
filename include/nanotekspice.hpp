#ifndef NANOTEKSPICE_HPP
# define NANOTEKSPICE_HPP

#include <iostream>
#include <vector>

namespace nano {

	class Nanotekspice {
		private:
			bool setIO(std::vector<std::string>);
			bool setLinks(const std::vector<std::string>, const std::vector<std::string>, const std::vector<std::string>);
			bool checkContent(const std::vector<std::string>) const;
		public:
			Nanotekspice();
			~Nanotekspice() = default;
			int parseFile(const std::string &filename);
			void run();
	};

};

#endif /* !NANOTEKSPICE_HPP */
