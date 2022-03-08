#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/filesystem.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/formatter_parser.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/support/date_time.hpp>
#include <chrono>
#include <iostream>
#include <thread>

namespace logging = boost::log;
namespace expr = boost::log::expressions;

void init_logger() {
    logging::add_file_log(
        logging::keywords::file_name = "sample.log",
        logging::keywords::format = "%TimeStamp% [%Severity%]: %Message%",
        logging::keywords::auto_flush = true
    );
    logging::add_common_attributes();

    BOOST_LOG_TRIVIAL(info) << "Log initialized";
    boost::filesystem::path full_path(boost::filesystem::current_path());
    BOOST_LOG_TRIVIAL(info) << "Working dir: " << full_path;
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
