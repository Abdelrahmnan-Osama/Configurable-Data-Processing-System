#include "ProcessorFactory.hpp"
#include "Configuration.hpp"
#include <iostream>
#include <vector>

int main()
{
    try
    {
        Configuration config("config/settings.json");
        auto processorType = config.getOption("Processor.Options.Type");
        auto processor = ProcessorFactory::createProcessor(processorType);

        std::vector<std::string> data = {"Sample1", "Sample2", "Sample3"};
        processor->process(data);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}