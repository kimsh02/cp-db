#include "fieldtype.hpp"

FieldType::FieldType(const std::string &fn, const std::string &tq,
		     DBValueType dvt)
	: fieldName(fn)
	, tableQualifier(tq)
	, fieldType(dvt)
{
}

const std::string &FieldType::getFieldName() const
{
	return fieldName;
}

const std::string &FieldType::getTableQualifier() const
{
	return tableQualifier;
}

FieldType::DBValueType FieldType::getFieldType() const
{
	return fieldType;
}

void FieldType::setTableQualifier(const std::string &alias)
{
	tableQualifier = alias;
}
