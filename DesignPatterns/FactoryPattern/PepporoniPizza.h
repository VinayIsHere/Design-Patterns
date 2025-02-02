#pragma once

#include "Pizza.h"

class PepporoniPizza : public Pizza
{
public:

	PepporoniPizza() = default;

	void prepare() override {
		std::cout << "Preparing pepporoni pizza" << std::endl;
	}

	void bake() override {
		std::cout << "Baking pepporoni pizza" << std::endl;
	}

	void cut() override {
		std::cout << "Cutting pepporoni pizza in sqaure shapes" << std::endl;
	}

	void box() override {
		std::cout << "Boxing pepporoni pizza" << std::endl;
	}
};