#pragma once

#include "AComponent.hpp"

namespace nts {
	class Chip4081 : public AComponent {
	public:
		Chip4081() = default;
		Chip4081(const std::string &_name): name(_name) {};
		~Chip4081() = default;

		nts::Tristate compute(std:: size_t pin = 1) {
			(void)pin;
			return state;
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
		std::vector<nts::Tristate> pins;
		nts::Tristate state;
	};
}