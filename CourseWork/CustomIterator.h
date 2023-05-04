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

	CustomIterator& operator++() {
		index++;
		return *this;
	}

	CustomIterator& operator++(int) {
		CustomIterator it = *this;
		++(*this);
		return *this;
	}

	Coworker& operator*() const {
		return array[index];
	}

	Coworker* operator -> () const {
		return &array[index];
	}

	Coworker* operator[](int index) { 
		return array + index; 
	}

	bool operator==(const CustomIterator& other) const {
		return index == other.index;
	}

	bool operator!=(const CustomIterator& other) const {
		return !(*this == other);
	}

};

