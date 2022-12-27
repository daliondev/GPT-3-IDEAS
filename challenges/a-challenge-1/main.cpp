#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, int> word_lengths(const std::string &string)
{
    // Split the string into a vector of words
    std::vector<std::string> words;
    std::istringstream iss(string);
    for (std::string word; iss >> word;)
    {
        words.push_back(word);
    }

    // Create the result unordered_map with an unordered_map comprehension
    std::unordered_map<std::string, int> result;
    for (const auto &word : words)
    {
        result[word] = word.length();
    }

    return result;
}

int main()
{
    std::string string = "Hello everyone";
    auto result = word_lengths(string);
    for (const auto &[word, length] : result)
    {
        std::cout << word << ": " << length << std::endl;
    }
    return 0;
}
