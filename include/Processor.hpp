#if !defined(PROCESSOR_HPP)
#define PROCESSOR_HPP

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

class Processor
{
public:
        template <typename T>
        void process(const std::vector<T> &data)
        {
                std::vector<std::string> textData = convertToString(data);
                processInternal(textData);
        }

protected:
        virtual void processInternal(const std::vector<std::string> &data) = 0;

private:
        template <typename T>
        std::vector<std::string> convertToString(const std::vector<T> &data)
        {
                std::vector<std::string> textData;
                textData.reserve(data.size());
                for (auto &&element : data)
                {
                        textData.emplace_back(std::to_string(element));
                }

                return textData;
        }
};

template <>
inline std::vector<std::string> Processor::convertToString(const std::vector<std::string> &data)
{
        return data;
}

class TextProcessor : public Processor
{

private:
        void processInternal(const std::vector<std::string> &data) override;
};

class NumericProcessor : public Processor
{

private:
        void processInternal(const std::vector<std::string> &data);
};

class ImageProcessor : public Processor
{

private:
        void processInternal(const std::vector<std::string> &data);
};

class AudioProcessor : public Processor
{

private:
        void processInternal(const std::vector<std::string> &data);
};

#endif // PROCESSOR_HPP
