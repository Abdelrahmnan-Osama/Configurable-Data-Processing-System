#include "Processor.hpp"

void TextProcessor::processInternal(const std::vector<std::string> &data)
{
    std::cout << "TextProcessor processing: ";
    size_t lastIndex = data.size() - 1;
    for (size_t i = 0; i < lastIndex; i++)
    {
        std::cout << data[i] << ", ";
    }
    std::cout << data[lastIndex] << " (interpreted as text data)" << std::endl;
}

void NumericProcessor::processInternal(const std::vector<std::string> &data)
{
    std::cout << "NumericProcessor processing: ";
    size_t lastIndex = data.size() - 1;
    for (size_t i = 0; i < lastIndex; i++)
    {
        std::cout << data[i] << ", ";
    }
    std::cout << data[lastIndex] << " (interpreted as numeric data)" << std::endl;
}

void ImageProcessor::processInternal(const std::vector<std::string> &data)
{
    std::cout << "ImageProcessor processing: ";
    size_t lastIndex = data.size() - 1;
    for (size_t i = 0; i < lastIndex; i++)
    {
        std::cout << data[i] << ", ";
    }
    std::cout << data[lastIndex] << " (interpreted as image data)" << std::endl;
}

void AudioProcessor::processInternal(const std::vector<std::string> &data)
{
    std::cout << "AudioProcessor processing: ";
    size_t lastIndex = data.size() - 1;
    for (size_t i = 0; i < lastIndex; i++)
    {
        std::cout << data[i] << ", ";
    }
    std::cout << data[lastIndex] << " (interpreted as audio data)" << std::endl;
}