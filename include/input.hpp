#pragma once

#include "IComponent.hpp"

namespace nts {
	class Input : public IComponent {
	public:
		Input(std::string &);
		~Input();
		virtual nts::Tristate compute(std:: size_t  pin = 1);
		virtual void setLink(std::size_t, nts::IComponent &, std::size_t);
		virtual void dump() const;
	private:
		const std::string name;
		std::vector<nts::Tristate> pins;
	};
}