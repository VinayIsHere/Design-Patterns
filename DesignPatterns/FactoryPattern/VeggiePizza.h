#pragma once

#include "Pizza.h"
#include <iostream>

class VeggiePizza : public Pizza
{
public:

	VeggiePizza() = default;

	void prepare() override {
		std::cout << "Preparing Veggie pizza"<<std::endl;
	}

	void bake() override {
		std::cout << "Baking Veggie pizza"<<std::endl;
	}
	
	void cut() override {
		std::cout << "cutting Veggie pizza in sqaure pieces"<<std::endl;
	}
	
	void box() override {
		std::cout << "Boxing Veggie pizza"<<std::endl;
	}
};