#pragma once

#include "AComponent.hpp"

namespace nts {
	class Input : public AComponent {
	public:
		Input() = default;
		Input(const std::string &_name): _name(_name) {};
		~Input() = default;

		nts::Tristate compute(std:: size_t pin = 1) {
			(void)pin;
			return state;
		};

		void setLink(std::size_t, nts::IComponent &, std::size_t) {
		};

		void dump() const {
			
		};
	private:
		const std::string _name = "RandomName";
		std::vector<nts::Tristate> pins;
		nts::Tristate state;
	};
}