#include <boost/process.hpp>
#include <boost/process/environment.hpp>
#include <iostream>

namespace bp = boost::process;

int main() {
    bp::opstream ops;
    bp::ipstream ips;
    bp::ipstream eps;
    auto env {boost::this_process::environment()};
    env["my_var"] = "my_value";
    bp::child child_process(bp::search_path("bash"), "-l", env,
            bp::std_out > ips, bp::std_err > eps, bp::std_in < ops);
    ops << "env; exit" << std::endl;
    child_process.wait();
    std::string line;
    while (std::getline(ips, line) && !line.empty())
        std::cout << line << std::endl;
    child_process.terminate();
    return 0;
}
