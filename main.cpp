#include "LinkedListFileParser.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    LinkedListFileParser fileParser;
    fileParser.generateListFileFromInputFile(argv[1], argv[2]);
    return 0;
}