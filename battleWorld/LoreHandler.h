#pragma once

#include <string>
#include <vector>
#include <map>

using std::string;


namespace bwld
{
    using LoreKey = std::string;
    using LoreValue = std::string;
    struct LoreHandler
    {
        std::map<LoreKey, LoreValue> collectionOfLoreStrings;

        void ParseLoreString(std::string input)
        {

        }
    };
}
