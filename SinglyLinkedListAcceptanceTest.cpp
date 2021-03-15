#include "gtest/gtest.h"
#include "SinglyLinkedList.hpp"

class SinglyLinkedListAcceptanceTest : public ::testing::Test 
{
    protected:
        SinglyLinkedList linkedList;
        int item1{23};
        int item2{-1};
};   

TEST_F(SinglyLinkedListAcceptanceTest, AddItemToList)
{
    linkedList.add_item_to_end_of_list(item1);
    linkedList.add_item_to_end_of_list(item2);
    EXPECT_EQ("[23,-1]",linkedList.convert_linked_list_to_string());
}

TEST_F(SinglyLinkedListAcceptanceTest, RemoveItemFromList)
{
    linkedList.add_item_to_end_of_list(item1);
    linkedList.add_item_to_end_of_list(item2);
    linkedList.add_item_to_end_of_list(item1);
    int item{34};
    linkedList.remove_item_from_list(item);
    EXPECT_EQ("[23,-1,23]",linkedList.convert_linked_list_to_string());
    linkedList.remove_item_from_list(item1);
    EXPECT_EQ("[-1]",linkedList.convert_linked_list_to_string());
    linkedList.remove_item_from_list(item2);
    EXPECT_EQ("[]",linkedList.convert_linked_list_to_string());
    linkedList.remove_item_from_list(item1);
    EXPECT_EQ("[]",linkedList.convert_linked_list_to_string());
}