#include <boost/filesystem.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <iostream>
#include <chrono>
#include <thread>

namespace logging = boost::log;

void init_logger() {
      boost::filesystem::path full_path(boost::filesystem::current_path());

      auto sink = logging::add_file_log("sample.log");
      BOOST_LOG_TRIVIAL(info) << "Log initialized";
      BOOST_LOG_TRIVIAL(info) << "Working dir: " << full_path;
      sink->flush();
}

int main() {
    const int sleep_time {5000};
    init_logger();
    for (int iter = 0; iter < 5; ++iter) {
        BOOST_LOG_TRIVIAL(info) << "Iteration " << iter << " started";
        std::cout << "iteration " << iter << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
        BOOST_LOG_TRIVIAL(info) << "Iteration " << iter << " ended";
    }
    BOOST_LOG_TRIVIAL(info) << "Application done";
    return 0;
}
