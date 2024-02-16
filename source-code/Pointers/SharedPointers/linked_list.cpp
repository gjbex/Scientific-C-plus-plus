#include "linked_list.h"

LinkedList LinkedList::copy() const {
    LinkedList new_list;
    ElementPtr old_element = first();
    while (old_element != nullptr) {
        ElementPtr element {std::make_shared<ListElement>(old_element->value())};
        if (new_list.is_empty()) {
            new_list.first_ = element;
            new_list.last_ = element;
        } else {
            new_list.last()->next_ = element;
            new_list.last_ = element;
        }
        old_element = old_element->next_;
    }
    return new_list;
}

LinkedList LinkedList::prepend(int value) const {
    LinkedList new_list;
    ElementPtr new_first_element = std::make_shared<ListElement>(value, first());
    new_list.first_ = new_first_element;
    if (new_first_element->next() == nullptr) {
        new_list.last_ = new_first_element;
    } else {
        new_list.last_ = last();
    }
    return new_list;
}

LinkedList LinkedList::append(int value) const {
    LinkedList new_list {copy()};
    ElementPtr new_element = std::make_shared<ListElement>(value);
    new_list.last()->next_ = new_element;
    new_list.last_ = new_element;
    return new_list;
}

LinkedList LinkedList::reverse() const {
    LinkedList new_list;
    ElementPtr element = first();
    while (element != nullptr) {
        new_list = new_list.prepend(element->value());
        element = element->next();
    }
    return new_list;
}

void LinkedList::apply(std::function<void(ListElement)> function) const {
    ElementPtr element = first();
    while (element != nullptr) {
        function(*element);
        element = element->next();
    }
}       

std::vector<size_t> LinkedList::use_counts() const {
    std::vector<size_t> counts;
    ElementPtr element = first();
    while (element != nullptr) {
        // one less because element also points temporarily to it
        counts.push_back(element.use_count() - 1);
        element = element->next();
    }
    return counts;
}

std::vector<ListElement*> LinkedList::addresses() const {
    std::vector<ListElement*> element_addresses;
    ElementPtr element = first();
    while (element != nullptr) {
        element_addresses.push_back(element.get());
        element = element->next();
    }
    return element_addresses;
}
