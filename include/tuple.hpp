#pragma once

#include <memory>
#include <vector>

#include "dbvalue.hpp"
#include "tupledesc.hpp"

class Tuple {
    private:
	TupleDesc			       tupleDesc;
	std::vector<std::unique_ptr<DBValue> > fields;
	int				       recordID;

    public:
	Tuple();

	void writeTo(std::unique_ptr<std::vector<std::byte> >);
};
