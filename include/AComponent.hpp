#pragma once

#include "IComponent.hpp"

namespace nts {
	class AComponent: public IComponent {
		public:
			~AComponent() {};
			nts::Tristate compute(std::size_t pin = 1);
			void setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin);
			void dump() const;
			std::string getName() {
				return _name;
			}
			std::string getType() {
				return _type;
			}
		private:
			const std::string _name;
			const std::string _type = "AComponent";
	};
}
