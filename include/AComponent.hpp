#pragma once

#include "IComponent.hpp"

namespace nts {
	class AComponent: public IComponent {
		public:
			~AComponent() {};
			virtual std::string getName() const {
				return _name;
			}
			virtual std::string getType() const {
				return _type;
			}
			const std::string _name;
			const std::string _type;
		private:
	};
}
