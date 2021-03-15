#ifndef SINGLYLINKEDLIST_HPP
#define SINGLYLINKEDLIST_HPP

#include "SinglyLinkedListLibrary.hpp"

class SinglyLinkedList
{
    private:
        SinglyLinkedListLibrary::LinkedListNode *head{nullptr};

    public:
        SinglyLinkedList();

        ~SinglyLinkedList();

        std::string convert_linked_list_to_string();

        void add_item_to_end_of_list(int item);

        void remove_item_from_list(int item);

        void clear_linked_list();
};
#endif