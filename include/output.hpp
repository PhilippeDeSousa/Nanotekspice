#pragma once

#include "IComponent.hpp"

namespace nts {
	class Output : public IComponent {
	public:
		Output() = default;
		Output(const std::string &_name): name(_name) {};
		~Output() = default;

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