#include "Set.h"
#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;


void test_insert_average(int count_value, int count_attempt) {
    Set<int> set;
    std::vector<int> values;

    while (values.size() <= count_value) {
        int value = rand() % 10000000;
        if (!set.contains(value)) {
            values.push_back(value);
            set.insert(value);
        }
    }

    auto start = std::chrono::high_resolution_clock::now();
    for (int attempt = 0; attempt < count_attempt; attempt++) {
        Set<int> temp_set;
        for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
            temp_set.insert(*it);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Time Running Insert to Set " << count_value << " items : " << duration.count() / count_attempt << std::endl;

    start = std::chrono::high_resolution_clock::now();
    for (int attempt = 0; attempt < count_attempt; attempt++) {
        std::vector<int> temp_vect;
        for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
            temp_vect.push_back(*it);
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Time Running Insert to Vector " << count_value << " items : " << duration.count() / count_attempt << std::endl;

}



void test_search_average(int count_value, int count_attempt) {
    Set<int> set;
    std::vector<int> vect;

    while (vect.size() <= count_value) {
        int value = rand() % 10000000;
        if (!set.contains(value)) {
            vect.push_back(value);
            set.insert(value);
        }
    }

    auto start = std::chrono::high_resolution_clock::now();
    for (int attempt = 0; attempt < count_attempt; attempt++) {
        int value = rand() % 10000000;
        set.contains(value);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Time Running Search to Set " << count_value << " items : " << duration.count() / count_attempt << std::endl;

    start = std::chrono::high_resolution_clock::now();
    for (int attempt = 0; attempt < count_attempt; attempt++) {
        int value = rand() % 10000000;
        std::find(vect.begin(), vect.end(), value);
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Time Running Search to Vector " << count_value << " items : " << duration.count() / count_attempt << std::endl;
}

//std::vector<int> task_vector(std::vector<int> v) {
//    Set<int> set;
//    Set<int> r;
//    std::vector<int> h;
//
//    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//        if (!set.contains(*it))
//            set.insert(*it);
//        else
//            r.insert(*it);
//    }
//    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//        if (!r.contains(*it))
//            h.push_back(*it);
//    }
//    return h;
//}
int main()
{
   /* std::vector<int> test = { 3, 2, 2, 4 };
    std::vector<int> res = task_vector(test);

    for (std::vector<int>::iterator it = test.begin(); it != test.end(); it++) {
        std::cout << *it << "  ";
    }
    std::cout << std::endl;

    for (std::vector<int>::iterator it = res.begin(); it != res.end(); it++) {
        std::cout << *it << "  ";
    }
    std::cout << std::endl;

    return 0;*/

    test_insert_average(1000, 100);
    test_insert_average(10000, 100);
    test_insert_average(100000, 100);

    test_search_average(1000, 1000);
    test_search_average(10000, 1000);
    test_search_average(100000, 1000);

}