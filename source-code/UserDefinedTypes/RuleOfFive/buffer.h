#ifndef BUFFER_HDR
#define BUFFER_HDR

#include <algorithm>
#include <iostream>

template<typename T>
struct CircularBuffer {
    private:
        size_t max_size_;
        size_t size_;
        size_t start_;
        size_t end_;
        T* data_;
        void nullify() {
            data_ = nullptr;
            max_size_ = 0;
            clear();
        }
        void copy_atts(const CircularBuffer<T>& other) {
            max_size_ = other.max_size();
            size_ = other.size();
            start_ = other.start_;
            end_ = other.end_;
        }
    public:
        CircularBuffer(size_t max_size) : max_size_ {max_size},
            size_ {0}, start_ {0}, end_ {0}, data_ {new T[max_size]} {
                std::fill(data_, data_ + max_size_, T());
            }
        CircularBuffer(const CircularBuffer<T>& other) : max_size_ {other.max_size()},
            size_ {other.size()}, start_ {other.start_}, end_ {other.end_},
            data_ {new T[other.max_size()]} {
                std::copy(other.data_, other.data_ + other.max_size(), data_);
                std::cout << "copy constructor called\n";
            }
        CircularBuffer(CircularBuffer<T>&& other) : max_size_ {other.max_size()},
            size_ {other.size()}, start_ {other.start_}, end_ {other.end_},
            data_ {other.data_} {
                other.nullify();
                std::cout << "move constructor called\n";
            }
        CircularBuffer<T>& operator=(const CircularBuffer<T>& other) {
            delete[] data_;
            data_ = new T[other.max_size()];
            std::copy(other.data_, other.data_ + other.max_size(), data_);
            copy_atts(other);
            std::cout << "copy assignment called\n";
            return *this;
        }
        CircularBuffer<T>& operator=(CircularBuffer<T>&& other) {
            delete[] data_;
            data_ = other.data_;
            copy_atts(other);
            other.nullify();
            std::cout << "move assignment called\n";
            return *this;
        }
        size_t max_size() const { return max_size_; }
        size_t size() const { return size_; }
        T pop_front() {
            T value = data_[start_++];
            start_ %= max_size_;
            size_--;
            return value;
        }
        void push_back(T value) {
            data_[end_++] = value;
            end_ %= max_size_;
            if (size_ < max_size_)
                size_++;
        }
        bool empty() const { return size_ == 0; }
        void clear() {
            size_ = 0;
            start_ = 0;
            end_ = 0;
        }
        ~CircularBuffer() {
            delete[] data_;
            nullify();
        }
        friend std::ostream& operator<<(std::ostream& out, const CircularBuffer& buffer) {
            out << "max_size = " << buffer.max_size_ << "\n";
            out << "size = " << buffer.size_ << "\n";
            out << "start = " << buffer.start_ << "\n";
            out << "end = " << buffer.end_ << "\n";
            out << "buffer:";
            for (size_t i {0}; i < buffer.max_size_; ++i) {
                out << " " << buffer.data_[i];
            }
            std::cout << "\n";
            return out;
        }
};

#endif
