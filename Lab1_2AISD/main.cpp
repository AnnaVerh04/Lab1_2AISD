#include "Set.h"
#include <iostream>
#include <vector>



std::vector<int> task_vector(std::vector<int> v) {
    Set<int> set;
    Set<int> r;
    std::vector<int> h;
    // {3, 2, 2, 4}
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        if (!set.contains(*it))
            set.insert(*it);
        else
            r.insert(*it);
    }
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        if (!r.contains(*it))
            h.push_back(*it);
    }
    return h;
}
int main()
{
    std::vector<int> test = { 3, 2, 2, 4 };
    std::vector<int> res = task_vector(test);

    for (std::vector<int>::iterator it = test.begin(); it != test.end(); it++) {
        std::cout << *it << "  ";
    }
    std::cout << std::endl;

    for (std::vector<int>::iterator it = res.begin(); it != res.end(); it++) {
        std::cout << *it << "  ";
    }
    std::cout << std::endl;

    return 0;
}