#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>

void printUsage(char *);
int countWords(std::string);

int main(int argc, char * argv[])
{
    if (argc < 2 || argc > 3) //Arguments can be either <filename> or -f <filename>
    {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    if (argv[1] == "-f")
    {
        //TODO: Implement display words with frequency
    }
    else
    {
        if (argc > 2) //Arguments should be only <filename> in this case
        {
            printUsage(argv[0]);
            return EXIT_FAILURE;
        }

        std::string filename(argv[1]);
        int count = countWords(filename);
        std::cout << "The total number of words is: " << count;
    }
    
    return EXIT_SUCCESS;
}


void printUsage(char * path)
{
    std::cout << "Usage:\n";
    std::cout << "\t" << path << " <path to file>\n"
        << "\t" << "Output total number of words in file\n\n";
    std::cout << "\t" << path << " -f <path to file>\n"
        << "\t" << "Output frequency of all words in the file in ascending order, sorted lexicographically\n\n";
}

//Count total number of words in a file (word means a contigous group of non space characters)
int countWords(std::string filename)
{
    std::ifstream textFile(filename);
    if (textFile)
    {
        int count = 0;
        std::string tmp;
        while (textFile >> tmp)
            ++count;

        return count;
    }
    else
    {
        char errmsg[256];
#ifdef _WIN32
        strerror_s(errmsg, sizeof(errmsg), errno);
#else
        strerror_r(errno, errmsg, sizeof(errmsg);
#endif
        std::cerr << "The file could not be opened\n";
        std::cerr << "Error: " << errmsg << "\n";
        exit(EXIT_FAILURE);
    }
}