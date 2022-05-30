#include <gtest.h>
#include "tablesort.h"
#include "tablehash.h"

TEST(TTableScan, can_insert_scantable)
{
	TTableScan<TPolinom, std::string> Tscan(200);
	TPolinom Q("x-1");
	TPolinom P("1-x");
	TPolinom C("x2");
	Tscan.InsertRecord("1", Q);
	Tscan.InsertRecord("2", P);
	Tscan.InsertRecord("3", C);
	Tscan.Reset();
	ASSERT_TRUE(Q == *Tscan.GetData());
}

TEST(TTableScan, can_find_scantable)
{
	TTableScan<TPolinom, std::string> Tscan(200);
	TPolinom Q("x-1");
	TPolinom P("1-x");
	TPolinom C("x2");
	Tscan.InsertRecord("1", Q);
	Tscan.InsertRecord("2", P);
	Tscan.InsertRecord("3", C);
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

TEST(TTableScan, can_remove2_scantable)
{
	TTableScan<TPolinom, std::string> Tscan(200);
	TPolinom Q("x-1");
	TPolinom P("y-1");
	Tscan.InsertRecord("1", Q);
	Tscan.InsertRecord("2", P);
	ASSERT_ANY_THROW(Tscan.RemoveRecord("3"));
}

TEST(TTableSort, can_insert_sorttable)
{
	TTableSort<TPolinom, std::string> Tsort(200);
	TPolinom Q("x-1");
	TPolinom P("1-x");
	TPolinom C("x2");
	Tsort.InsertRecord("1", Q);
	Tsort.InsertRecord("2", P);
	Tsort.InsertRecord("3", C);
	Tsort.Reset();
	ASSERT_TRUE(Q == *Tsort.GetData());
}

TEST(TTableSort, can_find_sorttable)
{
	TTableSort<TPolinom, std::string> Tsort(200);
	TPolinom Q("x-1");
	TPolinom P("1-x");
	TPolinom C("x2");
	Tsort.InsertRecord("1", Q);
	Tsort.InsertRecord("2", P);
	Tsort.InsertRecord("3", C);
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

TEST(TTableSort, can_remove2_sorttable)
{
	TTableSort<TPolinom, std::string> Tsort(200);
	TPolinom Q("x-1");
	TPolinom P("y-1");
	Tsort.InsertRecord("1", Q);
	Tsort.InsertRecord("2", P);
	Tsort.RemoveRecord("2");
	ASSERT_ANY_THROW(Tsort.RemoveRecord("3"));
}

TEST(TTableHash, can_insert_hashtable)
{
	TTableHash<TPolinom, std::string> Thash(200, 1);
	TPolinom Q("x-1");
	TPolinom P("1-x");
	TPolinom C("x2");
	Thash.InsertRecord("1", Q);
	Thash.InsertRecord("2", P);
	Thash.InsertRecord("3", C);
	Thash.Reset();
	ASSERT_TRUE(Q == *Thash.FindRecord("1")->GetData());
}

TEST(TTableHash, can_find_hashtable)
{
	TTableHash<TPolinom, std::string> Thash(200, 1);
	TPolinom Q("x-1");
	TPolinom P("1-x");
	TPolinom C("x2");
	Thash.InsertRecord("1", Q);
	Thash.InsertRecord("2", P);
	Thash.InsertRecord("3", C);
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

TEST(TTableHash, can_remove2_hashtable)
{
	TTableHash<TPolinom, std::string> Thash(200, 1);
	TPolinom Q("x-1");
	TPolinom P("y-1");
	Thash.InsertRecord("1", Q);
	Thash.InsertRecord("2", P);
	Thash.RemoveRecord("2");
	ASSERT_ANY_THROW(Thash.RemoveRecord("3"));
}

TEST(TTableScan, can_clear_scan)
{
	TTableScan<TPolinom, std::string> Tscan(200);
	TPolinom Q("x-1");
	TPolinom P("1-x");
	TPolinom C("x2");
	Tscan.InsertRecord("1", Q);
	Tscan.InsertRecord("2", P);
	Tscan.InsertRecord("3", C);
	ASSERT_NO_THROW(Tscan.Clear());
}

TEST(TTableScan, can_clear2_scan)
{
	TTableScan<TPolinom, std::string> Tscan(200);
	ASSERT_ANY_THROW(Tscan.Clear());
}

TEST(TTableSort, can_clear_sort)
{
	TTableSort<TPolinom, std::string> Tsort(200);
	TPolinom Q("x-1");
	TPolinom P("1-x");
	TPolinom C("x2");
	Tsort.InsertRecord("1", Q);
	Tsort.InsertRecord("2", P);
	Tsort.InsertRecord("3", C);
	ASSERT_NO_THROW(Tsort.Clear());
}

TEST(TTableScan, can_clear2_sort)
{
	TTableSort<TPolinom, std::string> Tsort(200);
	ASSERT_ANY_THROW(Tsort.Clear());
}

TEST(TTableHash, can_clear_hash)
{
	TTableHash<TPolinom, std::string> Thash(200, 1);
	TPolinom Q("x-1");
	TPolinom P("1-x");
	TPolinom C("x2");
	Thash.InsertRecord("1", Q);
	Thash.InsertRecord("2", P);
	Thash.InsertRecord("3", C);
	ASSERT_NO_THROW(Thash.Clear());
}

TEST(TTableHash, can_clear2_hash)
{
	TTableHash<TPolinom, std::string> Thash(200, 1);
	ASSERT_ANY_THROW(Thash.Clear());
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