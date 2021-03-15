#include "gtest/gtest.h"
#include "LinkedListFileParser.hpp"

class LinkedListFileParserAcceptanceTest : public ::testing::Test 
{
    protected:
        LinkedListFileParser fileParser;
        std::string inputFile{"testInputFile.txt"};
        std::string outputFile{"testOutputFile.txt"};

};   

TEST_F(LinkedListFileParserAcceptanceTest, AcceptInputFile)
{
    fileParser.generateListFileFromInputFile(inputFile, outputFile);
}
