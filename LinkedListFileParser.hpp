#ifndef LINKEDLISTFILEPARSER_HPP
#define LINKEDLISTFILEPARSER_HPP

#include "SinglyLinkedList.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class LinkedListFileParser
{
    private:
        std::string currentInputFile;
        std::ofstream currentOutputFileStream;
        std::string currentCase;
        SinglyLinkedList currentLinkedList;
        bool firstListFlag;
        void parseInputFile();
        void updateOutputFile(std::string command, std::string input, bool endOfFileReached);

    public:
        LinkedListFileParser();

        void generateListFileFromInputFile(std::string inputFile, std::string outputFile);

};
#endif