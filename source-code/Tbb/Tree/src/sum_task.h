#ifndef SUM_TASK_HDR
#define SUM_TASK_HDR

#include <oneapi/tbb/task_group.h>

#include "tree.h"

template<typename T>
T sum_values(Node<T>* node) {
    T sum = (*node)();
    if (node->left())
        sum += sum_values(node->left());
    if (node->right())
        sum += sum_values(node->right());
    return sum;
}

template<typename T>
T sum_values_parallel(Node<T>* node) {
    if (node->nr_descendants() < 1000) {
        return sum_values(node);
    }

    T sum = (*node)();
    T left_sum {0.0};
    T right_sum {0.0};
    oneapi::tbb::task_group task_group;

    if (node->left()) {
        task_group.run([&left_sum, node]() {
            left_sum = sum_values_parallel(node->left());
        });
    }
    if (node->right()) {
        task_group.run([&right_sum, node]() {
            right_sum = sum_values_parallel(node->right());
        });
    }

    task_group.wait();
    return sum + left_sum + right_sum;
}

#endif
