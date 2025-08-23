#include "ProcessorFactory.hpp"

Processor *ProcessorFactory::createProcessor(const std::string &type)
{
    if (type == "Text")
        return new TextProcessor;
    else if (type == "Numeric")
        return new NumericProcessor;
    else if (type == "Image")
        return new ImageProcessor;
    else if (type == "Audio")
        return new AudioProcessor;

    throw std::runtime_error("Invalid Processor Type");
}