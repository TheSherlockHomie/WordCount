#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <unordered_map>
#include <set>

void printUsage(char *);
int countWords(std::string);
void getFrequency(std::string);


int main(int argc, char * argv[])
{
    if (argc < 2 || argc > 3) //Arguments can be either <filename> or -f <filename>
    {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    if (std::string(argv[1]) == "-f")
    {
        if (argc != 3)
        {
            printUsage(argv[0]);
            return EXIT_FAILURE;
        }

        std::string filename(argv[2]);
        getFrequency(filename);
    }
    else
    {
        if (argc != 2) //Arguments should be only <filename> in this case
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

//print list of words with thier frequency (case insensitive)
void getFrequency(std::string filename)
{
    std::ifstream textFile(filename);
    if (textFile)
    {
        std::unordered_map<std::string, int> dict; //store words with their frequencies in an unordered map
        std::string word;
        while (textFile >> word)
        {
            std::transform(word.begin(), word.end(), word.begin(), ::tolower); //case insensitive: convert everything to lowercase
            if (dict.find(word) == dict.end())
                dict[word] = 1;
            else
                ++dict[word];
        }

        //save unordered map data into a set, which will sort it first by frequency and then by lexicographic order
        std::set <std::pair<int, std::string>> wordSet;
        for (auto x : dict)
            wordSet.insert(std::make_pair(x.second, x.first));

        //print
        for (auto x : wordSet)
            std::cout << x.first << " " << x.second<<"\n";
        std::cout << std::endl;
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