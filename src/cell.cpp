#include <iostream>
#include "../include/cell.hpp"

Cell::Cell(int _age)
{
	age = _age;
}

Cell::Cell() {
	age = 0;
}

Cell::~Cell()
= default;

void Cell::grow() {
	age++;
}

int Cell::getAge() {
	return age;
}