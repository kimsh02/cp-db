#pragma once

#include <string>
#include <vector>

class TupleDesc {
    private:
	enum DBValueType { LONG, STRING };

	struct FieldType {
		std::string fieldName;
		std::string tableQualifier;
		DBValueType fieldType;

		FieldType(const std::string &, const std::string &,
			  DBValueType);

		bool operator==(const FieldType &) const = default;
		bool operator!=(const FieldType &) const = default;
	};

	std::vector<FieldType> tupleDesc;

    public:
	// TupleDesc(std::vector<std::string>);

	bool operator==(const TupleDesc &) const;
	bool operator!=(const TupleDesc &) const;

	// RAII
	TupleDesc(const TupleDesc &);
	~TupleDesc();
	TupleDesc &operator=(const TupleDesc &other);

	size_t bytesPerTuple() const;
	size_t findFieldInTd(const FieldType &, const TupleDesc &) const;

	void	    merge(TupleDesc &&);
	void	    setTableAlias(const std::string &);
	std::string headerString(bool) const;

	std::vector<FieldType> &get();
};
