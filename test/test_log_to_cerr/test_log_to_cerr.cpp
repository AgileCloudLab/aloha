#include <aloha/aloha.hpp>

#include <iostream>

int main(void)
{
    aloha::aloha log;
    log = aloha::aloha();

    std::cout << "Without std::cerr" << std::endl << std::endl;

    log.success("Testing success");
    log.info("Testing info");
    log.data("Testing data");

    log.warning("Testing warning");
    log.error("Testing error");
    log.fault("Testing fault");
    log.failure("Testing failur");

    log.custom("custom", "Testing custom");

    std::cout << "With std::cerr" << std::endl << std::endl;

    log.success("Testing success");
    log.info("Testing info");
    log.data("Testing data");
    log.warning("Testing warning", true);
    log.error("Testing error", true);
    log.fault("Testing fault", true);
    log.failure("Testing failur", true);

    log.custom("custom", "Testing", true);

    return 0;
}
