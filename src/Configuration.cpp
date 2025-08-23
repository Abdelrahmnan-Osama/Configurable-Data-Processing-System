#include "Configuration.hpp"

std::string Configuration::readFile()
{
    // open the file for reading
    configFile.open(fileName);
    if (!configFile.is_open())
    {
        throw std::runtime_error("Failed to open file: " + fileName);
    }

    // extract file content and convert it into string
    std::stringstream buffer;
    buffer << configFile.rdbuf();
    std::string content = buffer.str();
    configFile.close();

    // return json string
    return content;
}

std::string Configuration::getOption(const std::string &keyPath)
{
    // extract key from the keyPath
    std::string key = keyPath.substr(keyPath.find_last_of('.') + 1);

    // extract configuration data
    std::string configData = readFile();

    // search for the key
    std::string keyPattern = "\"" + key + "\"";
    std::size_t keyPos = configData.find(keyPattern);
    if (keyPos == std::string::npos)
    {
        throw std::runtime_error("Configuration key '" + key + "' not found");
    }

    // extact json key-value delimeters
    size_t semiColonPos = configData.find(":", keyPos);
    size_t commaPos = configData.find(",", keyPos);

    // extact value of processor type
    size_t valueStart = configData.find("\"", semiColonPos) + 1;
    size_t valueEnd = configData.find("\"", valueStart);
    if (valueStart >= commaPos || valueEnd >= commaPos || commaPos != valueEnd + 1)
    {
        throw std::runtime_error("Malformed configuration value for key '" + key + "'");
    }
    else if (valueEnd == valueStart)
    {
        throw std::runtime_error("Empty configuration value for key '" + key + "'");
    }

    // return the extracted value
    return configData.substr(valueStart, valueEnd - valueStart);
}