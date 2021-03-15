#include "SinglyLinkedListLibrary.hpp"
#include <iostream>


namespace SinglyLinkedListLibrary
{

    std::string convert_linked_list_to_string(LinkedListNode *&head)
    {
        std::string listAsString{};

        if(head == nullptr)
        {
            listAsString = "[]";
        }
        else
        {
            listAsString = "[" + std::to_string(head->value);
            LinkedListNode *currentNodePointer = head->pointer;
            while(currentNodePointer != nullptr)
            {
                listAsString = listAsString + "," + std::to_string(currentNodePointer->value);
                currentNodePointer = currentNodePointer->pointer;
            }
            listAsString = listAsString + "]";
        }
        return listAsString;
    }

    void add_item_to_end_of_list(LinkedListNode *&head, int item)
    {
        if(head == nullptr)
        {
            head = new LinkedListNode{item,nullptr};
        }
        else
        {
            LinkedListNode *currentNodePointer{head};
            while(currentNodePointer->pointer != nullptr)
            {
                currentNodePointer = currentNodePointer->pointer;
            }
            currentNodePointer->pointer = new LinkedListNode{item,nullptr};
        }
    }

    void remove_item_from_list(LinkedListNode *&head, int item)
    {
        if(head != nullptr)
        {
            LinkedListNode *currentNodePointer{head};
            LinkedListNode *nextNodePointer{head->pointer};
            do
            {
                if(nextNodePointer->value == item)
                {
                    nextNodePointer = nextNodePointer->pointer;
                    delete currentNodePointer->pointer;
                    currentNodePointer->pointer = nextNodePointer;
                }
                else
                {
                    nextNodePointer = nextNodePointer->pointer;
                    currentNodePointer = currentNodePointer->pointer;
                }
            }
            while(nextNodePointer != nullptr);

            if(head->value == item)
            {
                currentNodePointer = head;
                nextNodePointer = head->pointer;
                head = nextNodePointer;
                delete currentNodePointer;
            }
        }
    }
}
