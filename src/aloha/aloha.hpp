// Copyright 2018  AgileCloudLab - Aarhus University

// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:

// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.

// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.

// 3. Neither the name of the copyright holder nor the names of its contributors
//    may be used to endorse or promote products derived from this software without
//    specific prior written permission.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.

#pragma once

#include <string>

#include <algorithm>

#include <ctime>

#include <fstream>

#include <iostream>

namespace aloha
{
class aloha
{
public:
    aloha(bool to_file=false) : m_to_file(to_file), m_timestamp(false), m_log(true)
    {
        if (to_file)
        {
            m_file_path = "./aloha.log";
            m_outfile.open(m_file_path, std::ios_base::app);
        }
    }

    aloha(std::string file_path) : m_file_path(file_path), m_to_file(true), m_timestamp(false), m_log(true)
    {
        m_outfile.open(file_path, std::ios_base::app);
    }

    ~aloha()
    {
	if(m_to_file && m_outfile.is_open())
	{
	    m_outfile.flush();
	    m_outfile.close();
	}
    }

    aloha(const aloha& theOther)
    {
	m_file_path = theOther.m_file_path;
	m_to_file = theOther.m_to_file;
	m_timestamp =  theOther.m_timestamp;
	m_log = theOther.m_log;
	if(m_to_file)
	{
	    m_outfile.open(m_file_path, std::ios_base::app);
	}
    }
    
    aloha& operator=(const aloha& theOther)
    {
	if(this != &theOther)
	{
	    m_file_path = theOther.m_file_path;
	    m_to_file = theOther.m_to_file;
	    m_timestamp =  theOther.m_timestamp;
	    m_log = theOther.m_log;
	    if(m_to_file)
	    {
		if(m_outfile.is_open())
		{
		    m_outfile.flush();
		    m_outfile.close();
		}
		m_outfile.open(m_file_path, std::ios_base::app);
	    }
	}

	return *this;	
    }
    
    void disable()
    {
        m_log = false;
    }

    void enable()
    {
        m_log = true;
    }

    bool enabled()
    {
    	return m_log;
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
        m_log ? present_msg("success", msg) : void();
    }

    void info(std::string msg)
    {
        m_log ? present_msg("info", msg) : void();
    }

    void data(std::string msg)
    {
        m_log ? present_msg("data", msg) : void();
    }

    void warning(std::string msg, bool error=false)
    {
        m_log ? present_msg("warning", msg, error) : void();
    }

    void error(std::string msg, bool error=true)
    {
        m_log ? present_msg("error", msg, error) : void();
    }

    void fault(std::string msg, bool error=false)
    {
        m_log ? present_msg("fault", msg, error) : void();
    }

    void failure(std::string msg, bool error=false)
    {
        m_log ? present_msg("failure", msg, error) : void();
    }

    void custom(std::string type, std::string msg, bool error=false)
    {
        m_log ? present_msg(type, msg, error) : void();
    }

private:

    void present_msg(std::string type, std::string msg, bool error=false)
    {
        write("[" + type + "] " + msg, error);
    }

    void write(std::string msg, bool error=false)
    {
        if (m_timestamp)
        {
            msg = time_stamp() + ": " + msg;
        }

        if (m_to_file)
        {
            write_to_file(msg);
        }
        else
        {
            if (error)
            {
                std::cerr << msg << std::endl;
            }
            else
            {
                std::cout << msg << std::endl;
            }

        }

    }

    void write_to_file(std::string msg)
    {
        m_outfile << msg << std::endl;
    }

    std::string time_stamp()
    {
        std::time_t result = std::time(nullptr);

        std::string str = std::asctime(std::localtime(&result));
        str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
        return str;
    }




private:
    std::string m_file_path;

    bool m_to_file;
    bool m_timestamp;

    bool m_log;

    std::ofstream m_outfile;
};
}
