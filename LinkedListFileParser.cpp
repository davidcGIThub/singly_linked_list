#include "LinkedListFileParser.hpp"


LinkedListFileParser::LinkedListFileParser()
{

}

void LinkedListFileParser::generateListFileFromInputFile(std::string inputFile, std::string outputFile)
{
    this->currentInputFile = inputFile;
    this->currentOutputFileStream.open(outputFile);
    firstListFlag = true;
    this->parseInputFile();
    this->currentOutputFileStream.close();
}

void LinkedListFileParser::parseInputFile()
{
    std::ifstream inputFileStream(this->currentInputFile);
    std::string lineInFile;
    std::string firstWordInLine;
    std::string secondWordInLine;
    if (inputFileStream.is_open())
    {
        bool endOfFileReached = false;
        while ( getline(inputFileStream,lineInFile) || !endOfFileReached )
        {
            if(inputFileStream.eof())
            {
                endOfFileReached = true;
            }
            std::istringstream lineStream(lineInFile);
            lineStream >> firstWordInLine;
            lineStream >> secondWordInLine;
            this->updateOutputFile(firstWordInLine, secondWordInLine, endOfFileReached);
        }
        inputFileStream.close();
    }   
}

void LinkedListFileParser::updateOutputFile(std::string command, std::string input, bool endOfFileReached)
{
    if(command == "Case" || endOfFileReached)
    {
        if (firstListFlag)
        {
            firstListFlag = false;
        }
        else
        {
            this->currentOutputFileStream << "Case " << this->currentCase << "\n" << this->currentLinkedList.convert_linked_list_to_string() << "\n\n";
            this->currentLinkedList.clear_linked_list();
        }
        this->currentCase = input;
    }
    else if(command == "Add")
    {
        int item = std::stoi(input);
        this->currentLinkedList.add_item_to_end_of_list(item);
    }
    else if(command == "Remove")
    {
        int item = std::stoi(input);
        this->currentLinkedList.remove_item_from_list(item);
    }
    else
    {

    }
}

