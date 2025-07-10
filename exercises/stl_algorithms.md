 # Exercises: STL Algorithms

 This exercise set covers common generic algorithms from `<algorithm>` and `<numeric>`.
 Each task builds familiarity with range-based operations, higher-order functions,
 and performance considerations.

 ## Exercise 1: Sequence Generation & Iteration
 1. Create a `std::vector<int> v(20);`.
 2. Use `std::iota(v.begin(), v.end(), 1);` to fill it with values 1..20.
 3. Print all elements using `std::for_each` and a lambda.
 4. Repeat the print using a range-based `for` loop; compare readability.

 ## Exercise 2: Element-wise Transformation
 1. Given the vector `v` from Exercise 1, create an empty vector `w` of the same size.
 2. Use `std::transform` to fill `w` with the squares of `v`.
 3. Print the first 10 elements of `w`.

 ## Exercise 3: Reduction & Accumulation
 1. Compute the sum of `v` using `std::accumulate(v.begin(), v.end(), 0);`.
 2. Compute the product of the first 10 elements of `v` (hint: initial value = `1`, use a lambda or `std::multiplies<int>()`).
 3. Compute the running prefix sums into a new vector `p` using `std::partial_sum` and print it.

 ## Exercise 4: Filtering & Counting
 1. Count how many elements in `v` are divisible by 3 using `std::count_if` and a lambda.
 2. Find the first element greater than 15 using `std::find_if`.
 3. Check whether the value 42 appears in `v` using `std::find` or `std::binary_search` (after sorting).

 ## Exercise 5: Sorting & Unique
 1. Create a vector `dup` initialized with: `{5,3,9,1,3,5,7,9,1}`.
 2. Sort `dup` with `std::sort`.
 3. Remove consecutive duplicates using `std::unique` and the erase–remove idiom:
    ```cpp
    dup.erase(std::unique(dup.begin(), dup.end()), dup.end());
    ```
 4. Print the resulting unique, sorted list.

 ## Exercise 6: Partitioning
 1. Starting from `v`, partition its elements so that even numbers come before odd, using `std::partition`.
 2. Print the partition point index and the reordered vector.
 3. Repeat with `std::stable_partition` and compare the relative order of evens/odds.

 ## Exercise 7: Remove Elements
 1. From the vector `v`, remove all prime numbers using `std::remove_if` (write a helper `is_prime(int)`).
 2. Erase the removed elements with the erase–remove idiom and print the result.

 ## Exercise 8: Selection Algorithm
 1. Generate a large vector of random doubles (e.g., 100000 elements).
 2. Use `std::nth_element` to partition around the median element.
 3. Print the median value (i.e., element at `v[v.size()/2]`).

 ## Exercise 9: Merging Sorted Ranges
 1. Create two sorted `std::vector<int>`: `a = {1,4,6}`, `b = {2,3,5,7}`.
 2. Merge them into a third vector `c` using `std::merge`.
 3. Print `c` (should be `{1,2,3,4,5,6,7}`).

 ## Exercise 10: Boolean Algorithms
 1. Check if **all** elements of `v` are positive with `std::all_of`.
 2. Check if **any** element is a multiple of 10 with `std::any_of`.
 3. Check if **none** are negative with `std::none_of`.

 ## Exercise 11: Adjacent Algorithms
 1. Given a vector `r = {1,2,2,3,3,3,4}`, find the first duplicate adjacent element using `std::adjacent_find`.
 2. Erase one of each adjacent duplicate by combining `std::unique` and erase.

 ## Quiz Questions
 - What is the complexity of `std::sort`, `std::unique`, `std::partition`, and `std::nth_element`?  
 - Why use `std::remove_if` instead of `erase` in a loop?  
 - What is the difference between `partition` and `stable_partition`?  
 - How does `std::merge` differ from `std::inplace_merge`?  
 - When would you choose `std::partial_sort` over `std::sort`?  