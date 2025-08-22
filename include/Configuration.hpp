#if !defined(CONFIGURATION_HPP)
#define CONFIGURATION_HPP

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

class Configuration
{
private:
    std::string fileName;
    std::ifstream configFile;

private:
    std::string readFile();

public:
    inline Configuration(const std::string &fileName) : fileName(fileName) {}
    std::string getOption(const std::string &keyPath);
};

#endif // CONFIGURATION_HPP
