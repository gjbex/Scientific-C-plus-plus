 # Exercises: Modern STL Ranges & Views

 These exercises illustrate C++20’s `<ranges>` library: lazy, composable views
 and range-based algorithms. Include `<ranges>` and use:
 ```cpp
 namespace rv = std::ranges;
 namespace vw = std::views;
 ```

 ## Exercise 1: Filter & Transform a Vector
 1. Create a `std::vector<int> v{1,2,3,4,5,6,7,8,9,10};`
 2. Write a view pipeline that selects even numbers and squares them:
    ```cpp
    auto evens_sq = v
      | vw::filter([](int x){ return x % 2 == 0; })
      | vw::transform([](int x){ return x * x; });
    ```
 3. Copy the results into a `std::vector<int> out;` using `std::ranges::copy`.
 4. Print `out`.

 ## Exercise 2: Generate a Sequence with `views::iota`
 1. Generate integers 1..100:
    ```cpp
    auto seq = vw::iota(1, 101);
    ```
 2. Write a helper `bool is_prime(int);` (trial division).
 3. Filter `seq` to primes:
    ```cpp
    auto primes = seq | vw::filter(is_prime);
    ```
 4. Print the first 20 primes using `std::ranges::copy_n` and an `ostream_iterator`.

 ## Exercise 3: Composite Pipeline & Accumulation
 1. Using the `seq` from Ex.2, create a pipeline that:
    - filters multiples of 3 or 5,  
    - transforms each to `double(x) / 7.0`
    ```cpp
    auto pipeline = seq
      | vw::filter([](int x){ return x%3==0 || x%5==0; })
      | vw::transform([](int x){ return x / 7.0; });
    ```
 2. Compute the sum of `pipeline` with `std::accumulate(pipeline.begin(), pipeline.end(), 0.0);`.
 3. Print the result.

 ## Exercise 4: Pagination with `drop` & `take`
 1. Given a large vector `data` of 50 integers, implement a function:
    ```cpp
    void print_page(const std::vector<int>& data, unsigned page, unsigned page_size);
    ```
    that prints elements on page `page` (0-based), using:
    ```cpp
    data
      | vw::drop(page * page_size)
      | vw::take(page_size)
    ```
 2. Demonstrate printing pages 0 to 4 with `page_size = 10`.

 ## Exercise 5: `take_while` & `drop_while`
 1. From a sorted vector `v` of integers (may contain negatives), use:
    - `vw::drop_while([](int x){ return x < 0; })` to skip negatives,
    - `vw::take_while([](int x){ return x <= 100; })` to take until >100.
 2. Print the resulting subrange.

 ## Exercise 6: Combining Views and Algorithms
 1. Generate a `std::vector<std::string> words` from a line of text (split on spaces).
 2. Use a view to:
    - filter out short words (`size() < 3`),
    - transform to uppercase,
    - remove punctuation (e.g., drop trailing `.,!?`).
 3. Copy the result to a `std::vector<std::string>` and print.

 ## Quiz Questions
 - What is the difference between a view (`std::views`) and a container?  
 - Why are views considered **lazy**?  
 - How do range-based algorithms (e.g., `std::ranges::copy`) differ from classic ones?  
 - Explain how `drop` and `take` can be used to implement pagination.  
 - When would you prefer a view pipeline over creating intermediate containers?  