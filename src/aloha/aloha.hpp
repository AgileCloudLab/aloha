#include <string>

#include <ctime>

#include <fstream>

namespace aloha
{
class aloha
{
public:
    aloha(bool to_file=false) : m_to_file(to_file)
    {
        if (to_file)
        {
            m_file_path = "./aloha.log";
            outfile.open(m_file_path, std::ios_base::app);
        }
    }

    aloha(std::string file_path) : m_to_file(true), m_file_path(file_path)
    {
        outfile.open(file_path, std::ios_base::app);
    }


    void timestamp_on()
    {
        m_timestamp = true;
    }

    void timestamp_off()
    {
        m_timestamp = false;
    }

    void success(std::string msg)
    {
        present_msg("success", msg);
    }

    void info(std::string msg)
    {
        present_msg("info", msg);
    }

    void data(std::string msg)
    {
        present_msg("data", msg);
    }

    void warning(std::string msg)
    {
        present_msg("warning", msg);
    }

    void error(std::string msg)
    {
        present_msg("error", msg);
    }

    void fault(std::string msg)
    {
        present_msg("fault", msg);
    }

    void failur(std::string msg)
    {
        present_msg("failur", msg);
    }

    void custom_msg(std::string type, std::string msg)
    {
        present_msg(type, msg);
    }


private:

    void present_msg(std::string type, std::string msg)
    {
        write("[" + type + "] " + msg);
    }

    void write(std::string msg)
    {
        if (m_time_stamp)
        {
            msg = time_stamp + ": " + msg;
        }

        if (m_to_file)
        {
            write_to_file(msg);
        }
        else
        {
            std::cout << msg << std::endl;
        }

    }

    void write_to_file(msg)
    {
        outfile << msg << std::endl;
    }

    std::string time_stamp()
    {
        std::time_t result = std::time(nullptr);
        return std::asctime(std::localtime(&result));
    }




private:
    std::string m_file_path;

    bool m_to_file;
    bool m_timestamp;

    std::ofstream outfile;
}
}
