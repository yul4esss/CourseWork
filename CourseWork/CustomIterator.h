#pragma once
#include "Coworker.h"
class CustomIterator
{
private:
	Coworker* array;
	size_t index;
	size_t size;

public:

	CustomIterator(Coworker* array, size_t index, size_t size) {
		this->array = array;
		this->index = index;
		this->size = size;
	}

	CustomIterator& operator++();

	CustomIterator& operator++(int);

	Coworker& operator*() const;

	Coworker* operator -> () const;

	Coworker* operator[](int index);

	bool operator==(const CustomIterator& other) const;

	bool operator!=(const CustomIterator& other) const;

};

