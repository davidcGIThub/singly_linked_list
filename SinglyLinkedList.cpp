
#include "SinglyLinkedList.hpp"
#include <iostream>


SinglyLinkedList::SinglyLinkedList()
{

}

SinglyLinkedList::~SinglyLinkedList()
{
    this->clear_linked_list();
}

std::string SinglyLinkedList::convert_linked_list_to_string()
{
    return SinglyLinkedListLibrary::convert_linked_list_to_string(this->head);
}

void SinglyLinkedList::add_item_to_end_of_list(int item)
{
    SinglyLinkedListLibrary::add_item_to_end_of_list(this->head, item);
}

void SinglyLinkedList::remove_item_from_list(int item)
{
    SinglyLinkedListLibrary::remove_item_from_list(this->head, item);
}

void SinglyLinkedList::clear_linked_list()
{
    SinglyLinkedListLibrary::clear_linked_list(this->head);
}