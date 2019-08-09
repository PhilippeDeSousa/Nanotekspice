#pragma once

#include "IComponent.hpp"

namespace nts {
	class Chip4001 : public IComponent {
	public:
		Chip4001(std::string &);
		~Chip4001();
		virtual nts::Tristate compute(std:: size_t  pin = 1);
		virtual void setLink(std::size_t, nts::IComponent &, std::size_t);
		virtual void dump() const;
	private:
		const std::string name;
		std::vector<nts::Tristate> pins;
	};
}