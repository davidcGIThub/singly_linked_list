#ifndef LINKEDLISTFILEPARSER_HPP
#define LINKEDLISTFILEPARSER_HPP

#include "SinglyLinkedList.hpp"
#include <string>

class LinkedListFileParser
{
    private:
        SinglyLinkedList listOfLinkedLists;

    public:
        LinkedListFileParser();

        ~LinkedListFileParser();

        void getListsFromInputFile(std::string inputFilePath);

        void createOutputFileFromLists(std::string outputFilePath);

        void clearListOfLinkedLists();

};
#endif