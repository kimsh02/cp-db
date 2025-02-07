#include "dbvalue.hpp"

#include <stdexcept>

#include "constants.hpp"

DBValue::~DBValue()
{
}

DBLong::DBLong(long long v)
	: value(v)
{
}

long long DBLong::get() const
{
	return value;
}

DBString::DBString(const std::string &v)
	: value(v)
{
	if (value.size() > DBSTRING_LENGTH) {
		throw std::runtime_error("String must be 64 bytes!\n");
	}
}

const std::string &DBString::get() const
{
	return value;
}
