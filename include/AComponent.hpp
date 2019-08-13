#pragma once

#include "IComponent.hpp"

namespace nts {
	class AComponent: public IComponent {
		public:
			~AComponent() {};
			AComponent(const std::string &name): _name(name) {};
			virtual std::string getName() const {
				return _name;
			}
			virtual std::string getType() const {
				return _type;
			}
		protected:
			const std::string _name;
			const std::string _type;
	};
}
