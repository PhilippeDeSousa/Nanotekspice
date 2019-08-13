#pragma once

#include "IComponent.hpp"

namespace nts {
	class AComponent: public IComponent {
		public:
			~AComponent() {};
			std::string getName() const {
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
