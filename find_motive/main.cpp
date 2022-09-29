#include<string>
#include<sstream>
#include<fstream>
#include<iostream>

int main(int argc, char **argv)
{
    if (argc != 3) 
    {
        std::cout << "Please provide both filename and motive" << std::endl;
        return 0;
    }
    std::ifstream file(argv[1]);

    if (file.fail()) 
    {
        std::cout << "The file " << argv[1] << " could not be opened." << std::endl;
        return 1;
    }

    std::string motive(argv[2]);
    std::string line;

    size_t count = 0;

    while (std::getline(file, line))
    {
        if (line == "")
        {
            continue;
        }
        size_t pos = 0;
        std::string match;
        while (((pos = line.find(' ')) != std::string::npos)) 
        {
            match = line.substr(0, pos);
            if (match.find(motive) != std::string::npos) 
            {
                count++;
            }
            line.erase(0, pos + 1);
        }

        if (line != "" && (line.find(motive) != std::string::npos))
        {
            count++;
        }
    }
    std::cout << "The file " << argv[1] << " contains " << count << " words containing the motive " << motive << std::endl;
    return 0;
}
