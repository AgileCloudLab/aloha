#include <aloha/aloha.hpp>

#include <iostream>

int main(void)
{
    auto log = aloha::aloha();

    std::cout << "Without std::cerr" << std::endl << std::endl;

    log.success("Testing success");
    log.info("Testing info");
    log.data("Testing data");

    log.warning("Testing warning");
    log.error("Testing error");
    log.fault("Testing fault");
    log.failur("Testing failur");

    log.custom("custom", "Testing custom");

    std::cout << "With std::cerr" << std::endl << std::endl;

    log.success("Testing success");
    log.info("Testing info");
    log.data("Testing data");
    log.warning("Testing warning", true);
    log.error("Testing error", true);
    log.fault("Testing fault", true);
    log.failur("Testing failur", true);

    log.custom("custom", "Testing", true);

    return 0;
}
