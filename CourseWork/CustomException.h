#pragma once
#include <iostream>
#include <exception>
#include <string>
#include <cctype>

class CustomException : public std::exception
{
private:
	std::string error;

public:
	CustomException(const std::string& message) : error(message) { }

	const char* what() const noexcept override;
};

