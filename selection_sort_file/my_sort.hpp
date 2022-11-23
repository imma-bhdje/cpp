auto my_elt(auto pr, auto drn)
{
    if (pr == drn)
        return drn;
    auto min = pr;
    ++pr;

    for (; pr != drn; ++pr)
        if (*pr < *min)
            min = pr;
    return min;
}

void my_swap(auto &e, auto &f){
    auto nbr = e;
    e = f;
    f = nbr;
}

template<typename itrt>
void my_selection_sort(itrt begin, itrt end){
    for(auto it = begin; it != end; ++it) {
        my_swap(*it, *my_elt(it, end));
    }
}