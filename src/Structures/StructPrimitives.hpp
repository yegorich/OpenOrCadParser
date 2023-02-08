#ifndef STRUCTPRIMITIVES_HPP
#define STRUCTPRIMITIVES_HPP


#include <cstdint>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

#include <fmt/core.h>
#include <nameof.hpp>

#include "CommonBase.hpp"
#include "Primitives/PrimBase.hpp"
#include "Structures/StructGeneralProperties.hpp"
#include "Structures/StructSymbolDisplayProp.hpp"
#include "Structures/StructSymbolPin.hpp"


class StructPrimitives : public CommonBase
{
public:

    StructPrimitives(ParserContext& aCtx) : CommonBase{aCtx}, name{}, symbolPins{},
        symbolDisplayProps{}, generalProperties{aCtx}
    { }

    std::string to_string() const override;

    void read(FileFormatVersion aVersion = FileFormatVersion::Unknown) override;

    virtual void accept(Visitor& aVisitor) const override
    {
        aVisitor.visit(*this);
    }

    std::string name;

    std::vector<std::unique_ptr<PrimBase>>                primitives;
    std::vector<std::unique_ptr<StructSymbolPin>>         symbolPins;
    std::vector<std::unique_ptr<StructSymbolDisplayProp>> symbolDisplayProps;

    StructGeneralProperties generalProperties;
};


[[maybe_unused]]
static std::string to_string(const StructPrimitives& aObj)
{
    std::string str;

    str += fmt::format("{}:\n", nameof::nameof_type<decltype(aObj)>());
    str += fmt::format("{}name = {}\n", indent(1), aObj.name);

    str += fmt::format("{}primitives:\n", indent(1));
    for(size_t i = 0u; i < aObj.primitives.size(); ++i)
    {
        if(aObj.primitives[i])
        {
            str += indent(fmt::format("[{}]: {}", i, aObj.primitives[i]->to_string()), 2);
        }
    }

    str += fmt::format("{}symbolPins:\n", indent(1));
    for(size_t i = 0u; i < aObj.symbolPins.size(); ++i)
    {
        if(aObj.symbolPins[i])
        {
            str += indent(fmt::format("[{}]: {}", i, aObj.symbolPins[i]->to_string()), 2);
        }
    }

    str += fmt::format("{}symbolDisplayProps:\n", indent(1));
    for(size_t i = 0u; i < aObj.symbolDisplayProps.size(); ++i)
    {
        if(aObj.symbolDisplayProps[i])
        {
            str += indent(fmt::format("[{}]: {}", i, aObj.symbolDisplayProps[i]->to_string()), 2);
        }
    }

    str += fmt::format("{}generalProperties:\n", indent(1));
    str += aObj.generalProperties.to_string();

    return str;
}


inline std::string StructPrimitives::to_string() const
{
    return ::to_string(*this);
}


[[maybe_unused]]
static std::ostream& operator<<(std::ostream& aOs, const StructPrimitives& aVal)
{
    aOs << to_string(aVal);

    return aOs;
}


#endif // STRUCTPRIMITIVES_HPP