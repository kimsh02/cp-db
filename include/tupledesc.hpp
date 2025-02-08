#pragma once

#include <string>
#include <vector>

#include "fieldtype.hpp"

class TupleDesc {
    private:
	std::vector<FieldType> tupleDesc;

    public:
	TupleDesc() = default;

	// RAII
	TupleDesc(const TupleDesc &)		= default;
	~TupleDesc()				= default;
	TupleDesc &operator=(const TupleDesc &) = default;
	;

	size_t			      bytesPerTuple() const;
	std::string		      headerString(bool) const;
	bool			      operator==(const TupleDesc &) const;
	bool			      operator!=(const TupleDesc &) const;
	const std::vector<FieldType> &get() const;

	std::unique_ptr<TupleDesc> merge(const TupleDesc &);
	void			   setTableAlias(const std::string &);
};
