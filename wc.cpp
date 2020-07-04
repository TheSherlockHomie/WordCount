#include <iostream>
#include <cstdlib>

int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage:\n";
        std::cout << "\t" << argv[0] << " <path to file>\n"
            << "\t" << "Output total number of words in file\n\n";
        std::cout << "\t" << argv[0] << " -f <path to file>\n"
            << "\t" << "Output frequency of all words in the file in ascending order, sorted lexicographically\n\n";

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}