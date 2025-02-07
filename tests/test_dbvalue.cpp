#include <gtest/gtest.h>

#include <stdexcept>

#include "dbvalue.hpp"

// Test DBValue methods
TEST(DBTest, DBValueMethods)
{
	DBLong dblong(0);
	EXPECT_EQ(dblong.get(), 0);

	DBString dbstring("dbstring");
	EXPECT_EQ(dbstring.get(), "dbstring");
}

// Test DBString max length
TEST(DBTest, DBValueEdgeCases)
{
	EXPECT_THROW(
		DBString dbstring(
			"dbstringdbstringdbstringdbstringdbstringdbstringdbstringdbstringdbstringdbstringdbstringdbstringdbstringdbstringdbstringdbstringdbstring");
		, std::runtime_error);
}
