#include <aloha/aloha.hpp>

#include <iostream>

int main(void)
{
    auto log = aloha::aloha();

    std::cout << "Testing without timestamps" << std::endl << std::endl;

    log.success("Testing success");
    log.info("Testing info");
    log.data("Testing data");

    log.warning("Testing warning");
    log.error("Testing error");
    log.fault("Testing fault");
    log.failure("Testing failure");

    log.custom("custome", "Testing custom");

    std::cout << std::endl << std::endl << "Testing withtimestamps" << std::endl << std::endl;

    log.timestamp_on();
    log.success("Testing success");
    log.info("Testing info");
    log.data("Testing data");

    log.warning("Testing warning");
    log.error("Testing error");
    log.fault("Testing fault");
    log.failure("Testing failure");

    log.custom("custom", "Testing");

    std::cout << "" << std::endl;
    std::cout << "Turning logging off" << std::endl;
    log.logging_off();
    log.success("Testing success");
    log.info("Testing info");
    log.data("Testing data");

    log.warning("Testing warning");
    log.error("Testing error");
    log.fault("Testing fault");
    log.failure("Testing failure");

    log.custom("custom", "Testing");
    std::cout << "Turning logging back on off" << std::endl;
    log.logging_on();
    log.success("Testing success");
    log.info("Testing info");
    log.data("Testing data");

    log.warning("Testing warning");
    log.error("Testing error");
    log.fault("Testing fault");
    log.failure("Testing failure");

    return 0;
}
