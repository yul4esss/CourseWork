#include "CustomIterator.h"

CustomIterator& CustomIterator::operator++()
{
	index++;
	return *this;
}

CustomIterator& CustomIterator::operator++(int)
{
	CustomIterator it = *this;
	++(*this);
	return *this;
}

Coworker& CustomIterator::operator*() const
{
	return array[index];
}

Coworker* CustomIterator::operator->() const
{
	return &array[index];
}

Coworker* CustomIterator::operator[](int index)
{
	return array + index;
}

bool CustomIterator::operator==(const CustomIterator& other) const
{
	return index == other.index;
}

bool CustomIterator::operator!=(const CustomIterator& other) const
{
	return !(*this == other);
}
