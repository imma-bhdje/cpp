// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful

template<class txt>
void swap(txt& i, txt& j) {
    txt cd = i;
    i = j;
    j = cd;
}

template<class lng >

void my_selection_sort( lng begin, lng end)
{
    lng nbr;
    lng aft;
    for (lng i = begin; i != end; ++i)
    {
        nbr = i;
        aft = i;
        for (lng j = ++aft; j != end; ++j)
        {
            if (*j < *nbr)
            {
                nbr = j;
            }
        }
        swap(*nbr, *i);
    }
}