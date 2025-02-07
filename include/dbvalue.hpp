#pragma once

#include <string>

// DBValue is pure virtual class
class DBValue {
    public:
	virtual ~DBValue() = 0;
};

class DBLong : public DBValue {
    private:
	long long value;

    public:
	explicit DBLong(long long);
	long long get() const;
};

class DBString : public DBValue {
    private:
	std::string value;

    public:
	explicit DBString(const std::string &);

	/* This could potentially cause dangling references
	 if heap page is forced back, be careful. */
	const std::string &get() const;
};
