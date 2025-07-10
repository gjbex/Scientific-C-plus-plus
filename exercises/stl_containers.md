 # Exercises: STL Containers

 These exercises provide practice with three fundamental STL containers:
 `std::vector`, `std::set`, and `std::map`.

 ## Exercise 1: std::vector Basics

 1. Write a program that:
    - Reads an integer N from standard input.
    - Reads N integers and stores them in a `std::vector<int>` using `push_back`.
    - Prints the elements in insertion order.
 2. Sort the vector in ascending order using `std::sort` and print the sorted elements.
 3. Remove all even numbers from the vector using the erase–remove idiom:
    ```cpp
    v.erase(std::remove_if(v.begin(), v.end(),
                           [](int x){ return x % 2 == 0; }),
            v.end());
    ```
    Print the resulting vector.

 ## Exercise 2: std::set for Unique, Sorted Elements

 1. Starting from a `std::vector<std::string> words`, insert each word into a `std::set<std::string> unique_words`.
 2. Print all unique words (the set is already sorted lexicographically).
 3. Prompt the user for a word to remove:
    ```cpp
    auto it = unique_words.find(query);
    if (it != unique_words.end()) unique_words.erase(it);
    ```
    Print the set after removal.

 ## Exercise 3: std::map for Frequency Counting

 1. Read N strings from standard input and count the occurrences of each string in a `std::map<std::string, int> freq`.
    Use `freq[word]++` to increment counts.
 2. Print each `(word, count)` pair in ascending key order.
 3. Find and print the word with the highest count.

 ## Exercise 4: Custom Ordering with std::set

 1. Create a `std::set<int, std::greater<int>> desc_set` that orders integers in descending order.
 2. Insert a series of integers and print them to verify the ordering.

 ## Exercise 5: Combined Word Analysis

 1. Read a line of text from the user (use `std::getline`).
 2. Split the line into words (using `std::istringstream`).
 3. Use a `std::map<std::string,int>` to count frequencies and a `std::set<std::string>` to collect unique words.
 4. Print:
    - Number of unique words.
    - A list of unique words in sorted order.
    - Each word alongside its frequency.

 ## Quiz Questions

 - What are the time complexities of insert, find, and erase for `std::vector`, `std::set`, and `std::map`?  
 - Why does `std::vector` use the erase–remove idiom for element removal?  
 - How does a `std::map` differ from a `std::unordered_map`?  
 - In what order does `std::set` iterate over its elements?  
 - When would you choose `std::vector` over `std::set`, and vice versa?  