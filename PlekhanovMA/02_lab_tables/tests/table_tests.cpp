#include <gtest.h>
#include "tablesort.h"
#include "tablehash.h"

TEST(TTableScan, can_create_scantable)
{
	TTableScan<TPolinom, std::string> Tscan(200);
	ASSERT_NO_THROW();
}

TEST(TTableSort, can_create_sorttable)
{
	TTableSort<TPolinom, std::string> Tsort(200);
	ASSERT_NO_THROW();
}

TEST(TTableHash, can_create_hashtable)
{
	TTableHash<TPolinom, std::string> Thash(200, 1);
	ASSERT_NO_THROW();
}

TEST(TTableScan, can_copy_scantable)
{
	TTableScan<TPolinom, std::string> Tscan(200);
	TTableScan<TPolinom, std::string> Tscan2(Tscan);
	ASSERT_NO_THROW();
}

TEST(TTableSort, can_copy_sorttable)
{
	TTableSort<TPolinom, std::string> Tsort(200);
	TTableSort<TPolinom, std::string> Tsort2(Tsort);
	ASSERT_NO_THROW();
}

TEST(TTableScan, can_insert_scantable)
{
	TTableScan<TPolinom, std::string> Tscan(200);
	TPolinom Q("15");
	Tscan.InsertRecord("1", Q);
	Tscan.Reset();
	ASSERT_TRUE(Q == *Tscan.GetData());
}

TEST(TTableScan, can_find_scantable)
{
	TTableScan<TPolinom, std::string> Tscan(200);
	TPolinom Q("x-1");
	Tscan.InsertRecord("1", Q);
	ASSERT_TRUE(*Tscan.FindRecord("1")->GetData() == Q);
}

TEST(TTableScan, can_remove_scantable)
{
	TTableScan<TPolinom, std::string> Tscan(200);
	TPolinom Q("x-1");
	TPolinom P("y-1");
	Tscan.InsertRecord("1", Q);
	Tscan.InsertRecord("2", P);
	Tscan.RemoveRecord("2");
	ASSERT_TRUE(*Tscan.FindRecord("1")->GetData() == Q && Tscan.FindRecord("2") == NULL);
}

TEST(TTableSort, can_insert_sorttable)
{
	TTableSort<TPolinom, std::string> Tsort(200);
	TPolinom Q("15");
	Tsort.InsertRecord("1", Q);
	Tsort.Reset();
	ASSERT_TRUE(Q == *Tsort.GetData());
}

TEST(TTableSort, can_find_sorttable)
{
	TTableSort<TPolinom, std::string> Tsort(200);
	TPolinom Q("x-1");
	Tsort.InsertRecord("1", Q);
	ASSERT_TRUE(*Tsort.FindRecord("1")->GetData() == Q);
}

TEST(TTableSort, can_remove_sorttable)
{
	TTableSort<TPolinom, std::string> Tsort(200);
	TPolinom Q("x-1");
	TPolinom P("y-1");
	Tsort.InsertRecord("1", Q);
	Tsort.InsertRecord("2", P);
	Tsort.RemoveRecord("2");
	ASSERT_TRUE(*Tsort.FindRecord("1")->GetData() == Q && Tsort.FindRecord("2") == NULL);
}
TEST(TTableHash, can_insert_hashtable)
{
	TTableHash<TPolinom, std::string> Thash(200, 1);
	TPolinom Q("15");
	Thash.InsertRecord("1", Q);
	Thash.Reset();
	ASSERT_TRUE(Q == *Thash.FindRecord("1")->GetData());
}

TEST(TTableHash, can_find_hashtable)
{
	TTableHash<TPolinom, std::string> Thash(200, 1);
	TPolinom Q("x-1");
	Thash.InsertRecord("1", Q);
	ASSERT_TRUE(*Thash.FindRecord("1")->GetData() == Q);
}

TEST(TTableHash, can_remove_hashtable)
{
	TTableHash<TPolinom, std::string> Thash(200, 1);
	TPolinom Q("x-1");
	TPolinom P("y-1");
	Thash.InsertRecord("1", Q);
	Thash.InsertRecord("2", P);
	Thash.RemoveRecord("2");
	ASSERT_TRUE(*Thash.FindRecord("1")->GetData() == Q && Thash.FindRecord("2") == NULL);
}

TEST(TTableScan, can_clear_scan)
{
	TTableScan<TPolinom, std::string> Tscan(200);
	ASSERT_TRUE(Tscan.IsEmpty());
}

TEST(TTableSort, can_clear_sort)
{
	TTableSort<TPolinom, std::string> Tsort(200);
	ASSERT_TRUE(Tsort.IsEmpty());
}

TEST(TTableHash, can_clear_hash)
{
	TTableHash<TPolinom, std::string> Thash(200, 1);
	ASSERT_TRUE(Thash.IsEmpty());
}

TEST(TTableScan, can_check_full_scan)
{
	TTableScan<TPolinom, std::string> Tscan(2);
	TPolinom P("x+1");
	TPolinom Q("x-1");
	Tscan.InsertRecord("1", Q);
	Tscan.InsertRecord("2", P);
	ASSERT_TRUE(Tscan.IsFull());
}

TEST(TTableSort, can_check_full_sort)
{
	TTableSort<TPolinom, std::string> Tsort(2);
	TPolinom P("x+1");
	TPolinom Q("x-1");
	Tsort.InsertRecord("1", Q);
	Tsort.InsertRecord("2", P);
	ASSERT_TRUE(Tsort.IsFull());
}

TEST(TTableHash, can_check_full_hash)
{
	TTableHash<TPolinom, std::string> Thash(2,1);
	TPolinom P("x+1");
	TPolinom Q("x-1");
	Thash.InsertRecord("1", Q);
	Thash.InsertRecord("2", P);
	ASSERT_TRUE(Thash.IsFull());
}