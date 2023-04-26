#ifndef LINKED_LIST_HDR
#define LINKED_LIST_HDR

#include <functional>
#include <memory>

class ListElement {
    using ElementPtr = std::shared_ptr<ListElement>;

    private:
        int element_;
        ElementPtr next_;

    public:
        friend class LinkedList;
        ListElement(int value) : element_ {value}, next_ {nullptr} {}
        ListElement(int value, ElementPtr next) : element_ {value}, next_ {next} {}
        int value() const { return element_; }
        ElementPtr next() const { return next_; }
};

class LinkedList {
    using ElementPtr = std::shared_ptr<ListElement>;

    private:
        ElementPtr first_;
        ElementPtr last_;

        ElementPtr first() const { return first_; }
        ElementPtr last() const { return last_; }

    public:
        LinkedList() : first_ {nullptr}, last_ {nullptr} {}
        LinkedList copy() const;
        bool is_empty() const { return first() == nullptr; }
        LinkedList prepend(int value) const;
        LinkedList append(int value) const;
        LinkedList reverse() const;
        void apply(std::function<void(ListElement)> function) const;
        std::vector<size_t> use_counts() const;
        std::vector<ListElement*> addresses() const;
};
      
#endif
