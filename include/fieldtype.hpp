#pragma once

#include <string>

class FieldType {
    private:
	enum class DBValueType { LONG, STRING };
	std::string fieldName;
	std::string tableQualifier;
	DBValueType fieldType;

    public:
	FieldType(const std::string &, const std::string &, DBValueType);

	FieldType(const FieldType &)		= default;
	~FieldType()				= default;
	FieldType &operator=(const FieldType &) = default;

	bool operator==(const FieldType &) const = default;
	bool operator!=(const FieldType &) const = default;

	const std::string &getFieldName() const;
	const std::string &getTableQualifier() const;
	DBValueType	   getFieldType() const;

	void setTableQualifier(const std::string &);

	friend class TupleDesc;
};
