#include <iostream>
#include <string>
#include <toml++/toml.hpp>

int main() {
    try {
        auto config = toml::parse_file("config.toml");

        const auto host = config["server"]["host"].value_or(std::string{"127.0.0.1"});
        const auto port = config["server"]["port"].value_or(8080);
        const auto verbose = config["logging"]["verbose"].value_or(false);

        std::cout << "Host    : " << host << '\n';
        std::cout << "Port    : " << port << '\n';
        std::cout << "Verbose : " << std::boolalpha << verbose << '\n';

        if (const auto timeout = config["server"]["timeout_seconds"].value<int>()) {
            std::cout << "Timeout : " << *timeout << " s\n";
        } else {
            std::cout << "Timeout : not set\n";
        }
    }
    catch (const toml::parse_error& err) {
        std::cerr << "TOML parse error:\n" << err << '\n';
        return 1;
    }
    return 0;
}
