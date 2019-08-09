#pragma once

#include "IComponent.hpp"

namespace nts {
	class Input : public IComponent {
	public:
		Input() {}
		Input(std::string &_name): name(_name) {

		}
		~Input() = default;

		nts::Tristate compute(std:: size_t pin = 1) {
			if (pin != 1)
				std::cout << "Pin " << pin << " does not exist\n";
			return pinValue;
		};

		void setLink(std::size_t, nts::IComponent &, std::size_t) {
		};

		void dump() const {

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