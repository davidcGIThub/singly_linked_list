#include <iostream>
#include <fstream>
#include <string>

#include "LinkedListFileParser.hpp"


LinkedListFileParser::LinkedListFileParser()
{

}

// LinkedListFileParser::~LinkedListFileParser()
// {
//     this->clearListOfLinkedLists();
// }

void LinkedListFileParser::getListsFromInputFile(std::string inputFilePath)
{
    std::string line;
    std::ifstream fileStream("example.txt");
    if (fileStream.is_open())
    {
        while ( getline(fileStream,line) )
        {
            // lineIndex = line.find(letters,position+1);
            std::cout << line << std::endl;
            std::cout << line[0] << std::endl;
            if(fileStream.eof())
                 break;
        }
        fileStream.close();
    }   
}


// void LinkedListFileParser::createOutputFileFromLists(std::string outputFilePath);

// void LinkedListFileParser::clearListOfLinkedLists();
