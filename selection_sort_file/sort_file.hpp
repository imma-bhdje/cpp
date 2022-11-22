// Do not change
#include <iostream>
#include <fstream>


#include <list>
#include <vector>
#include <deque>

#include "my_sort.hpp"

// Change here
// All occurences of XXX need to be replaced with
// something more meaningful


template<class TYPE, class CNTN>
void read_file_to_cont(std::ifstream& f, CNTN c) {
    TYPE msg;
    while (f >> msg) {
        c.push_back(msg);
    }
}

template<class type, class CNTN>
void read_and_sort(std::ifstream& fi, std::ofstream& fo) {
    CNTN fle = {};
    read_file_to_cont<type, CNTN>(fi, fle);
    my_selection_sort(fle.begin(), fle.end());
    for (type &msg : fle) {
        fo << msg << std::endl;
    }
}

template<class type>
void read_and_sort_decide_container(std::ifstream& fi, std::ofstream& fo) {
    char nextLine;
    fi >> nextLine;
    fo << nextLine << std::endl;
    switch(nextLine)
    {
        case 'l':
            read_and_sort<type, std::list<type>>(fi, fo);
            break;

        case 'd':
            read_and_sort<type, std::deque<type>>(fi, fo);
            break;

        case 'v':
            read_and_sort<type, std::vector<type>>(fi, fo);
            break;
    }
}

void read_and_sort_decide_valuetype(std::ifstream& fi, std::ofstream& fo) {
    char Line;
    fi >> Line;
    fo << Line << std::endl;
    switch(Line)
    {
        case 'i':
            read_and_sort_decide_container<int>(fi, fo);
            break;

        case 'u':
            read_and_sort_decide_container<unsigned>(fi, fo);
            break;

        case 'f':
            read_and_sort_decide_container<float>(fi, fo);
            break;

        case 'd':
            read_and_sort_decide_container<double>(fi, fo);
            break;

        case 'c':
            read_and_sort_decide_container<char>(fi, fo);
            break;

        case 's':
            read_and_sort_decide_container<std::string>(fi, fo);
            break;
    }
}



