#pragma once

#include "AComponent.hpp"

namespace nts {
	class Input : public AComponent {
	public:
		Input() = default;
		Input(const std::string &_name): name(_name) {};
		~Input() = default;

		nts::Tristate compute(std:: size_t pin = 1) {
			(void)pin;
			return state;
		};

		void setLink(std::size_t, nts::AComponent &, std::size_t) {
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