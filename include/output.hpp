#pragma once

#include "AComponent.hpp"

namespace nts {
	class Output : public AComponent {
	public:
		Output() = default;
		Output(const std::string &_name): name(_name) {};
		~Output() = default;

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
		std::string getType() const {
			return _type;
		}
	private:
		const std::string name;
		std::vector<nts::Tristate> pins;
		nts::Tristate state;
		std::string _type;
		//AComponent &link;
	};
}