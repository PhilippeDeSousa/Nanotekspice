#pragma once

#include "IComponent.hpp"

namespace nts {
	class Output : public IComponent {
	public:
		Output(std::string &_name): name(_name) {

		}
		~Output();
		virtual nts::Tristate compute(std:: size_t pin = 1) {
			if (pin != 1)
				std::cout << "Pin " << pin << " does not exist\n";

		};
		virtual void setLink(std::size_t, nts::IComponent &, std::size_t);
		virtual void dump() const;

		std::string getName() const {
			return name;
		}
	private:
		const std::string name;
		std::vector<nts::Tristate> pins;
		//nts::IComponent link;
	};
}