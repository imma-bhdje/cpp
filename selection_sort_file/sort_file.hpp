// Do not change
#include <iostream>
#include <fstream>

#include <string>

#include <list>
#include <vector>
#include <deque>

#include "my_sort.hpp"


template <class type, class contn>
void read_file_to_cont(std::ifstream &fi , contn& c) {
    type elt;
    while (fi >> elt) {
        c.push_back(elt);
    }
}

template <class type, class contn>
void read_and_sort(std::ifstream& fi, std::ofstream& fo) {
    contn cnt = {};
    read_file_to_cont<type, contn>(fi, cnt);
    my_selection_sort(cnt.begin(), cnt.end());
    for (type &elt : cnt)
        fo << elt << std::endl;
}

template <class type>
void read_and_sort_decide_container(std::ifstream& fi, std::ofstream& fo) {
    char Line;
    fi >> Line;
    fo << Line << std::endl;
    switch(Line)
    {
        case 'l':
            read_and_sort<type, std::list<type>>(fi, fo);
            break;
        case 'v':
            read_and_sort<type, std::vector<type>>(fi, fo);
            break;
        case 'd':
            read_and_sort<type, std::deque<type>>(fi, fo);
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



