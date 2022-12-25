#ifndef STRUCTSTHINPAGES0_HPP
#define STRUCTSTHINPAGES0_HPP


#include <cstdint>
#include <optional>
#include <ostream>
#include <string>

#include <fmt/core.h>
#include <nameof.hpp>

#include "General.hpp"


struct StructSthInPages0
{

};


[[maybe_unused]]
static std::string to_string(const StructSthInPages0& aObj)
{
    std::string str;

    str += fmt::format("{}:\n", nameof::nameof_type<decltype(aObj)>());
    // str += fmt::format("x1     = {}\n", aObj.x1);
    // str += fmt::format("y1     = {}\n", aObj.y1);

    return str;
}


[[maybe_unused]]
static std::ostream& operator<<(std::ostream& aOs, const StructSthInPages0& aVal)
{
    aOs << to_string(aVal);

    return aOs;
}


#endif // STRUCTSTHINPAGES0_HPP