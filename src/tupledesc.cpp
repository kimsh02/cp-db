#include "tupledesc.hpp"

#include "constants.hpp"

TupleDesc::FieldType::FieldType(const std::string &fn, const std::string &tq,
				DBValueType dvt)
	: fieldName(fn)
	, tableQualifier(tq)
	, fieldType(dvt)
{
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

size_t TupleDesc::bytesPerTuple() const
{
	size_t size = 0;
	for (const auto &ft : tupleDesc) {
		switch (ft.fieldType) {
		case LONG:
			size += sizeof(long);
			break;
		case STRING:
			size += sizeof(char) * DBSTRING_LENGTH;
			break;
		}
	}
	return size;
}
