#ifndef NODE_HDR
#define NODE_HDR

#include <ostream>

template<typename T>
class Node {
    private:
        int id_;
        T value_;
        Node<T>* left_;
        Node<T>* right_;
    public:
        Node(int id, T value) :
            id_ {id}, value_ {value}, left_ {nullptr}, right_ {nullptr} {};
        int id() const { return id_; };
        T value() const { return value_; };
        void setvalue_(T v) { value_ = v; };
        bool has_left() const { return left_ != nullptr; };
        Node<T>* left() const { return left_; };
        void set_left(Node<T>* child) { left_ = child; };
        bool has_right() const { return right_ != nullptr; };
        Node<T>* right() const { return right_; };
        void set_right(Node<T>* child) { right_ = child; };
        void to_str(std::ostream& out) const { to_str(out, ""); };
        void to_str(std::ostream& out, const std::string& indent) const {
            out << indent << id() << ": " << value_ << std::endl;
            if (has_left())
                left()->to_str(out, indent + "  ");
            if (has_right())
                right()->to_str(out, indent + "  ");
        };
        friend std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
            out << node.id();
            if (node.has_left())
                out << std::endl << (*node.left());
            if (node.has_right())
                out << std::endl << (*node.right());
            return out;
        };
        ~Node<T>() {
            if (has_left())
                delete left_;
            if (has_right())
                delete right_;
        };
};

#endif
