#include "tringlist.h"
#include <gtest.h>
TEST(TRingList, can_create_ringlist) {
	ASSERT_NO_THROW(TRingList<int>* rl = new TRingList<int>());
}
TEST(TRingList, can_create_ringlist_w_pFirst) {
	TNode<int>* _pFirst = new TNode<int>(2, nullptr);
	ASSERT_NO_THROW(TRingList<int>* rl = new TRingList<int>(_pFirst));
}
TEST(TRingList, can_copy_ringlist) {
    TRingList<int> ringList1;
	ringList1.InsertFirst(3);
    ASSERT_NO_THROW(TRingList<int> ringList2(ringList1));
}
TEST(TRingList, can_insrt_first) {
	TRingList<int> ringList;
	ASSERT_NO_THROW(ringList.InsrtFirst(1));
}
TEST(TRingList, can_insrt_first_data) {
	TRingList<int> ringList;
	ringList.InsrtFirst(8);

	EXPECT_EQ(8, ringList.GetCurrent()->data);
}
TEST(TRingList, can_del_first) {
	TRingList<int> ringList;
	ringList.InsrtFirst(8);
	ASSERT_NO_THROW(ringList.DeleteFirst());
}
TEST(TRingList, can_del_first_data) {
	TRingList<int> ringList;
	ringList.InsrtFirst(8);
	ringList.InsrtFirst(9);
	ringList.DeleteFirst();
	ringList.Reset();
	EXPECT_EQ(8, ringList.GetCurrent()->data);
}