#include "gtest/gtest.h"
#include "SinglyLinkedListLibrary.hpp"
#include <exception>

class SinglyLinkedListLibraryAcceptanceTest : public ::testing::Test 
{
    protected:

        //linked list 1 (empty)
        SinglyLinkedListLibrary::LinkedListNode *list1Head{nullptr};
        
        //linked list 2 (size one)
        int list2FirstNodeValue{2};
        SinglyLinkedListLibrary::LinkedListNode *list2Head = new SinglyLinkedListLibrary::LinkedListNode{list2FirstNodeValue,nullptr};

        //linked list 3 (size two)
        int list3FirstNodeValue{-3};
        int list3SecondNodeValue{45};
        SinglyLinkedListLibrary::LinkedListNode *list3FirstNodePointer = new SinglyLinkedListLibrary::LinkedListNode{list3SecondNodeValue,nullptr};
        SinglyLinkedListLibrary::LinkedListNode *list3Head = new SinglyLinkedListLibrary::LinkedListNode{list3FirstNodeValue,list3FirstNodePointer};

};   

TEST_F(SinglyLinkedListLibraryAcceptanceTest, CreateEmptyLinkedList)
{
    EXPECT_EQ(list1Head, nullptr);
}

TEST_F(SinglyLinkedListLibraryAcceptanceTest, CreateNonEmptyLinkedList)
{
    EXPECT_EQ(list2Head->value, 2);
    EXPECT_EQ(list2Head->pointer, nullptr);

    EXPECT_EQ(list3Head->value, -3);
    EXPECT_EQ(list3Head->pointer->value, 45);
    EXPECT_EQ(list3Head->pointer->pointer, nullptr);
}

TEST_F(SinglyLinkedListLibraryAcceptanceTest, ConvertNonEmptyListToString)
{
    EXPECT_EQ( "[]" , SinglyLinkedListLibrary::convert_linked_list_to_string(list1Head) );
}

TEST_F(SinglyLinkedListLibraryAcceptanceTest, ConvertEmptyListToString)
{
    EXPECT_EQ( "[2]" , SinglyLinkedListLibrary::convert_linked_list_to_string(list2Head) );
    EXPECT_EQ( "[-3,45]" , SinglyLinkedListLibrary::convert_linked_list_to_string(list3Head) );
}

TEST_F(SinglyLinkedListLibraryAcceptanceTest, AddItemToEmptyList)
{
    int item1{4};
    SinglyLinkedListLibrary::add_item_to_end_of_list(list1Head,item1);
    EXPECT_EQ(list1Head->value , item1);
}

TEST_F(SinglyLinkedListLibraryAcceptanceTest, AddItemToNonEmptyList)
{
    int item2{-9};
    SinglyLinkedListLibrary::add_item_to_end_of_list(list2Head,item2);
    EXPECT_EQ(list2Head->pointer->value , item2);
}

TEST_F(SinglyLinkedListLibraryAcceptanceTest, RemoveItemFromEmptyList)
{
    try
    {
        int item{3};
        SinglyLinkedListLibrary::remove_item_from_list(list1Head,item);
    }
    catch (std::exception& e)
    {
        EXPECT_EQ("No Errors", "Error in removing item from empty list");
    }

}

TEST_F(SinglyLinkedListLibraryAcceptanceTest, RemoveItemFromListOfSizeOne)
{
    int item{2};
    SinglyLinkedListLibrary::remove_item_from_list(list2Head,item);
    EXPECT_EQ(list2Head, nullptr);
}

TEST_F(SinglyLinkedListLibraryAcceptanceTest, RemoveItemFromListWhereItemIsAtBeginning)
{
    int item1{-3};
    int item2{45};
    SinglyLinkedListLibrary::remove_item_from_list(list3Head,item1);
    EXPECT_EQ(list3Head->value, item2);
}

TEST_F(SinglyLinkedListLibraryAcceptanceTest, RemoveItemFromListWhereItemIsAtEnd)
{
    int item2{45};
    SinglyLinkedListLibrary::remove_item_from_list(list3Head,item2);
    EXPECT_EQ(list3Head->pointer, nullptr);
}

TEST_F(SinglyLinkedListLibraryAcceptanceTest, RemoveItemFromListWhereItemIsNotFound)
{
    try
    {
        int item{22};
        SinglyLinkedListLibrary::remove_item_from_list(list3Head,item);
        EXPECT_EQ(list3Head->pointer->pointer, nullptr);
    }
    catch (std::exception& e)
    {
        EXPECT_EQ("No Errors", "Error in removing item from list when item not found");
    }
}

TEST_F(SinglyLinkedListLibraryAcceptanceTest, RemoveItemWithDuplicates)
{
    int list3ThirdNodeValue{-3};
    list3Head->pointer->pointer = new SinglyLinkedListLibrary::LinkedListNode{list3ThirdNodeValue,nullptr};

    int item{-3};
    SinglyLinkedListLibrary::remove_item_from_list(list3Head,item);
    EXPECT_EQ(list3Head->value, 45);
    EXPECT_EQ(list3Head->pointer, nullptr);
}

TEST_F(SinglyLinkedListLibraryAcceptanceTest, ClearFullLinkedList)
{
    SinglyLinkedListLibrary::clear_linked_list(list3Head);
    EXPECT_EQ(list3Head,nullptr);
}

TEST_F(SinglyLinkedListLibraryAcceptanceTest, ClearEmptyLinkedList)
{
    SinglyLinkedListLibrary::clear_linked_list(list1Head);
    EXPECT_EQ(list1Head,nullptr);
}