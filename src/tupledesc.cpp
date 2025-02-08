#include "tupledesc.hpp"

#include <algorithm>
#include <memory>

#include "constants.hpp"
#include "fieldtype.hpp"

size_t TupleDesc::bytesPerTuple() const
{
	size_t size = 0;
	for (const auto &f : tupleDesc) {
		switch (f.getFieldType()) {
		case FieldType::DBValueType::LONG:
			size += sizeof(long);
			break;
		case FieldType::DBValueType::STRING:
			size += sizeof(char) * DBSTRING_LENGTH;
			break;
		}
	}
	return size;
}

void TupleDesc::setTableAlias(const std::string &alias)
{
	std::ranges::for_each(tupleDesc, [alias](FieldType &f) {
		f.setTableQualifier(alias);
	});
}

std::unique_ptr<TupleDesc> TupleDesc::merge(const TupleDesc &other)
{
	std::unique_ptr<TupleDesc> td = std::make_unique<TupleDesc>();
	td->tupleDesc.insert(
		td->tupleDesc.end(), tupleDesc.begin(), tupleDesc.end());
	td->tupleDesc.insert(td->tupleDesc.end(),
			     other.tupleDesc.begin(),
			     other.tupleDesc.end());
	return td;
}

std::string TupleDesc::headerString(bool) const
{
	std::string header;
	for (size_t i = 0; i < tupleDesc.size(); i++) {
		std::string tableName;
	}
	return header;
}

bool TupleDesc::operator==(const TupleDesc &other) const
{
	if (tupleDesc.size() != other.tupleDesc.size()) {
		return false;
	}
	for (size_t i = 0; i < tupleDesc.size(); i++) {
		if (tupleDesc.at(i) == other.tupleDesc.at(i)) {
			return false;
		}
	}
	return true;
}

bool TupleDesc::operator!=(const TupleDesc &other) const
{
	return !(*this == other);
}
