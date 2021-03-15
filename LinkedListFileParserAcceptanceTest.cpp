#include "gtest/gtest.h"
#include "LinkedListFileParser.hpp"

class LinkedListFileParserAcceptanceTest : public ::testing::Test 
{
    protected:
        LinkedListFileParser fileParser;
        std::string inputFile "testInputFile.txt";
        std::string outputFile "testOutputFile.txt";

};   

TEST_F(LinkedListFileParserAcceptanceTest, AcceptInputFile)
{
    fileParser.getListsFromInputFile(inputFile);
    // fileParser.getCurrentListAsString()
    // std::string expectedString = "Case 1:\n[1,3]\n\n" + "Case 2:\n[4,-2,1]";
    // EXPECT_EQ(expectedString, fileParser.getCurrentListAsString());
}

// TEST_F(LinkedListFileParserAcceptanceTest, CreateOutputFile)
// {
//     try
//     {
//         fileParser.createOutputFileFromLists(outputFile);
//     }
//     catch (std::exception& e)
//     {
//         EXPECT_EQ("No Errors", "Error creating output file");
//     }
// }