#ifndef PERSISTENT_BINARY_TREE_HDR
#define PERSISTENT_BINARY_TREE_HDR

#include <iostream>
#include  <memory>

template<typename T>
struct PersistentBinaryTree {

    private:
        T value_;
        std::shared_ptr<PersistentBinaryTree<T>>  left_;
        std::shared_ptr<PersistentBinaryTree<T>>  right_;
        bool is_empty_ {false};

    public:
        PersistentBinaryTree() : is_empty_ {true} {}
        PersistentBinaryTree(const T& value) : value_ {value}, left_ {nullptr}, right_ {nullptr}, is_empty_ {false} {}
        PersistentBinaryTree(const T& value,
                const PersistentBinaryTree<T>& left,
                const PersistentBinaryTree<T>& right) :
            value_ {value},
            left_ {std::make_shared<PersistentBinaryTree<T>>(left)},
            right_ {std::make_shared<PersistentBinaryTree<T>>(right)} {}
        PersistentBinaryTree(const PersistentBinaryTree&& tree) :
            value_ {tree.value()},
                   left_ {tree.left()},
                   right_ {tree.right()} {}

        T value() const { return value_; }

        bool is_empty() const { return is_empty_; }

        bool has_left() const { return left_ != nullptr; }
        std::shared_ptr<PersistentBinaryTree<T>> left() const { return left_; }

        bool has_right() const { return right_ != nullptr; }
        std::shared_ptr<PersistentBinaryTree<T>> right() const { return right_; }

        PersistentBinaryTree<T> insert(const T& value) const;

        bool search(const T& value) const;
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const PersistentBinaryTree<T>& tree);

template<typename T>
bool PersistentBinaryTree<T>::search(const T& search_value) const {
    if (this->is_empty()) {
        return false;
    } else if (!left()->is_empty() && search_value < value()) {
        return left()->search(search_value);
    } else if (!right()->is_empty() && value() < search_value) {
        return right()->search(search_value);
    } else if (search_value == value()) {
        return true;
    } else {
        return false;
    }
}

template<typename T>
PersistentBinaryTree<T> PersistentBinaryTree<T>::insert(const T& new_value) const {
    if (is_empty()) {
        PersistentBinaryTree<T> tree(new_value);
        return tree;
    } else if (new_value < value()) {
        return PersistentBinaryTree<T>(
                value(),
                left()->insert(new_value),
                right()
                );
    } else if (value() < new_value) {
        return PersistentBinaryTree<T>(
                value(),
                left(),
                right()->insert(new_value)
                );
    } else {
        return *this;
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const PersistentBinaryTree<T>& tree) {
    if (!tree.left().is_empty()) {
        out << tree.left() << "\n";
    }
    out << tree.value() << "\n";
    if (!tree.right().is_empty()) {
        out << tree.right() << "\n";
    }
    return out;
}
#endif
