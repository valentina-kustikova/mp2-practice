#include "tringlist.h"
#include <gtest.h>
TEST(TRingList, can_create_ringlist) {
	ASSERT_NO_THROW(TRingList<int>* rl = new TRingList<int>());
}
TEST(TRingList, can_create_ringlist_w_pFirst) {
	TNode<int>* _pFirst = new TNode<int>(2, nullptr);
	ASSERT_NO_THROW(TRingList<int> rl(_pFirst));
}
TEST(TRingList, can_copy_ringlist) {
    TRingList<int> ringList1;
	ringList1.InsertFirst(3);
    ASSERT_NO_THROW(TRingList<int> ringList2(ringList1));
}
TEST(TRingList, right_copy_ringlist) {
	TRingList<int> ringList1;
	ringList1.InsertFirst(3);
	ringList1.InsertFirst(4);
	ringList1.InsertFirst(6);
	ringList1.InsertLast(-1000);
	TRingList<int> ringlist2(ringList1);
	while (!ringList1.is_End())
	{
		EXPECT_EQ(ringList1.getCurrData(), ringlist2.getCurrData());
		ringList1.Next();
		ringlist2.Next();
	}
}

TEST(TRingList, can_insrt_first) {
	TRingList<int> ringList;
	ASSERT_NO_THROW(ringList.InsertFirst(1));
}
TEST(TRingList, can_insrt_first_data) {
	TRingList<int> ringList;
	ringList.InsertFirst(8);

	EXPECT_EQ(8, ringList.GetCurrent()->data);
}
TEST(TRingList, can_del_first) {
	TRingList<int> ringList;
	ringList.InsertFirst(8);
	ASSERT_NO_THROW(ringList.DeleteFirst());
}
TEST(TRingList, can_del_first_data) {
	TRingList<int> ringList;
	ringList.InsertFirst(8);
	ringList.InsertFirst(9);
	ringList.DeleteFirst();
	ringList.Reset();
	EXPECT_EQ(8, ringList.GetCurrent()->data);
}