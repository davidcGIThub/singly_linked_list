#ifndef SINGLYLINKEDLISTLIBRARY_HPP
#define SINGLYLINKEDLISTLIBRARY_HPP
#include <array>
#include <string>

namespace SinglyLinkedListLibrary
{
    struct LinkedListNode
    {
        int value;
        LinkedListNode *pointer;
    };

    void add_item_to_end_of_list(LinkedListNode *&head, int item);

    void remove_item_from_list(LinkedListNode *&head, int item);

    std::string convert_linked_list_to_string(LinkedListNode *&head);

    void clear_linked_list(LinkedListNode *&head);
}

#endif