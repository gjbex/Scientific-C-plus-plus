#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
    std::ofstream out_stream;
    if (argc > 1) {
        out_stream.open(argv[1]);
        if (out_stream.fail()) {
            std::cerr << "oops, can not open file!\n";
        }
    }
    std::ostream& os(out_stream.is_open() ? out_stream : std::cout);
    os << "hello world\n";
    return 0;
}
