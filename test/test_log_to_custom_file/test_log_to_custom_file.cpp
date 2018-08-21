#include "../../src/aloha/aloha.hpp"

#include <iostream>
#include <string>
int main(void)
{
    auto log = aloha::aloha(std::string("temp.log"));

    std::cout << "Testing without timestamps" << std::endl << std::endl;

    log.success("Testing success");
    log.info("Testing info");
    log.data("Testing data");

    log.warning("Testing warning");
    log.error("Testing error");
    log.fault("Testing fault");
    log.failur("Testing failur");

    log.custom("custome", "Testing custom");

    std::cout << std::endl << std::endl << "Testing withtimestamps" << std::endl << std::endl;

    log.timestamp_on();
    log.success("Testing success");
    log.info("Testing info");
    log.data("Testing data");

    log.warning("Testing warning");
    log.error("Testing error");
    log.fault("Testing fault");
    log.failur("Testing failur");

    log.custom("custom", "Testing");

    return 0;
}
