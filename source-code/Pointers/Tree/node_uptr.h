#ifndef NODE_HDR
#define NODE_HDR

#include <ostream>
#include <memory>

template<typename T>
class Node {
    private:
        int id_;
        T value_;
        std::unique_ptr<Node<T>> left_;
        std::unique_ptr<Node<T>> right_;
    public:
        Node(int id, T value) :
            id_ {id}, value_ {value}, left_ {nullptr}, right_ {nullptr} {};
        Node(Node<T>&& other) : id_ {other.id_}, value_ {other.value_} {
            left_ = std::move(other.left_);
            right_ = std::move(other.right_);
        };
        int id() const { return id_; };
        T value() const { return value_; };
        void setvalue_(T v) { value_ = v; };
        bool has_left() const { return left_ != nullptr; };
        Node<T>& left() {
            return *left_.get();
        };
        void set_left(std::unique_ptr<Node<T>>& child) {
            left_ = std::move(child);
        };
        bool has_right() const { return right_ != nullptr; };
        Node<T>& right() {
            return *right_.get();
        };
        void set_right(std::unique_ptr<Node<T>>& child) {
            right_ = std::move(child);
        };
        void to_str(std::ostream& out) { to_str(out, ""); };
        void to_str(std::ostream& out, const std::string& indent) {
            out << indent << id() << ": " << value_ << std::endl;
            if (has_left())
                left().to_str(out, indent + "  ");
            if (has_right())
                right().to_str(out, indent + "  ");
        };
};

#endif
