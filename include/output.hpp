#pragma once

#include "IComponent.hpp"

namespace nts {
	class Output : public IComponent {
	public:
		Output() {}
		Output(const std::string &_name): name(_name) {

		}
		~Output() = default;

		virtual nts::Tristate compute(std:: size_t pin = 1) {
			if (pin != 1)
				std::cout << "Pin " << pin << " does not exist\n";
			return pinValue;
		};

		virtual void setLink(std::size_t, nts::IComponent &, std::size_t) {
		};

		virtual void dump() const {

		};

		std::string getName() const {
			return name;
		}
	private:
		const std::string name;
		nts::Tristate pinValue;
		//nts::IComponent link;
	};
}