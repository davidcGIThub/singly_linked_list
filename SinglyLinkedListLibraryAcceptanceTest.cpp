#include "gtest/gtest.h"
#include "SinglyLinkedListLibrary.hpp"
#include <exception>

class SinglyLinkedListAccpetanceTest : public ::testing:Test 
{
    protected:

    SinglyLinkedListAcceptanceTest()
    {
        //linked list 1 (empty)
        SinglyLinkedListLibrary::LinkedListNode *list1Head{nullptr};
        
        //linked list 2 (size one)
        int list2FirstNodeValue{2};
        SinglyLinkedListLibrary::LinkedListNode *list2FirstNodePointer{nullptr};
        SinglyLinkedListLibrary::LinkedListNode list2FirstNode{list2FirstNodeValue, list2FirstNodePointer};

        SinglyLinkedListLibrary::LinkedListNode *list2Head{&list2FirstNode};

        //linked list 3 (size two)
        int list3SecondNodeValue{-3};
        SinglyLinkedListLibrary::LinkedListNode *list3SecondNodePointer{nullptr};
        SinglyLinkedListLibrary::LinkedListNode list3SecondNode{list3SecondNodeValue, list3SecondNodePointer};
        
        int list3FirstNodeValue{45};
        SinglyLinkedListLibrary::LinkedListNode *list3FirstNodePointer{&list3SecondNode};
        SinglyLinkedListLibrary::LinkedListNode list3FirstNode{list3FirstNodeValue, list3FirstNodePointer};

        SinglyLinkedListLibrary::LinkedListNode *list3Head{&list3FirstNode};
    }

    ~FooTest() override 
    {
        delete list1Head;

        delete list2Head->pointer;
        delete list2Head;

        delete list3Head->pointer->pointer;
        delete list3Head->pointer;
        delete list3Head;
    }

}   

TEST_F(SinglyLinkedListAcceptanceTest, CreateEmptyLinkedList)
{
    EXPECT_EQ(list1Head, nullptr);
}

TEST_F(SinglyLinkedListAcceptanceTest, CreateNonEmptyLinkedList)
{
    EXPECT_EQ(list2Head->value, 2);
    EXPECT_EQ(list2Head->pointer, nullptr);

    EXPECT_EQ(list3Head->value, -3);
    EXPECT_EQ(list3Head->pointer, &list3SecondNode);
    EXPECT_EQ(list3Head->pointer->value, 45);
    EXPECT_EQ(list3Head->pointer->pointer, nullptr);
}

TEST_F(SinglyLinkedListAcceptanceTest, ConvertNonEmptyListToString)
{
    EXPECT_EQ( "[]" , SinglyLinkedListLibrary::convert_linked_list_to_string(list1Head) );
}

TEST_F(SinglyLinkedListAcceptanceTest, ConvertEmptyListToString)
{
    EXPECT_EQ( "[2]" , SinglyLinkedListLibrary::convert_linked_list_to_string(list2Head) );
    EXPECT_EQ( "[-3,45]" , SinglyLinkedListLibrary::convert_linked_list_to_string(list3Head) );
}

TEST_F(SinglyLinkedListAcceptanceTest, AddItemToEmptyList)
{
    int item1{4};
    SinglyLinkedListLibrary::add_item_to_end_of_list(list1Head,item1);
    EXPECT_EQ(list1Head->value , item1);
}

TEST_F(SinglyLinkedListAcceptanceTest, AddItemToNonEmptyList)
{
    int item2{-9};
    SinglyLinkedListLibrary::add_item_to_end_of_list(list2Head,item2);
    EXPECT_EQ(list2Head->pointer->value , item2);
}

TEST_F(SinglyLinkedListAcceptanceTest, RemoveItemFromEmptyList)
{
    try
    {
        int item{3};
        SinglyLinkedListLibrary::remove_item_from_list(list1Head,item);
    }
    catch (exception& e)
    {
        EXPECT_EQ("No Errors", "Error in removing item from empty list");
    }

}

TEST_F(SinglyLinkedListAcceptanceTest, RemoveItemFromListOfSizeOne)
{
    int item{2};
    SinglyLinkedListLibrary::remove_item_from_list(list2Head,item);
    EXPECT_EQ(list2Head, nullptr);
}

TEST_F(SinglyLinkedListAcceptanceTest, RemoveItemFromListWhereItemIsAtBeginning)
{
    int item1{-3};
    int item2{45};
    SinglyLinkedListLibrary::remove_item_from_list(list3Head,item1);
    EXPECT_EQ(list3Head->value, item2);
}

TEST_F(SinglyLinkedListAcceptanceTest, RemoveItemFromListWhereItemIsAtEnd)
{
    int item2{45};
    SinglyLinkedListLibrary::remove_item_from_list(list3Head,item2);
    EXPECT_EQ(list3Head->pointer, nullptr);
}

TEST_F(SinglyLinkedListAcceptanceTest, RemoveItemFromListWhereItemIsNotFound)
{
    try
    {
        int item{22};
        SinglyLinkedListLibrary::remove_item_from_list(list3Head,item);
        EXPECT_EQ(list3Head->pointer->pointer, nullptr);
    }
    catch (exception& e)
    {
        EXPECT_EQ("No Errors", "Error in removing item from list when item not found");
    }
}

TEST_F(SinglyLinkedListAcceptanceTest, RemoveItemWithDuplicates)
{
    int list3ThirdNodeValue{-3};
    SinglyLinkedListLibrary::LinkedListNode *list3ThirdNodePointer{nullptr};
    SinglyLinkedListLibrary::LinkedListNode list3ThirdNode{list3ThirdNodeValue,list3ThirdNodePointer};
    list3SecondNode->pointer = &list3ThirdNode;

    int item{-3};
    SinglyLinkedListLibrary::remove_item_from_list(list3Head,item);
    EXPECT_EQ(list3Head->value, 45);
    EXPECT_EQ(list3Head->pointer, nullptr);
}