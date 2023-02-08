#ifndef STRUCTWIRESCALAR_HPP
#define STRUCTWIRESCALAR_HPP


#include <cstdint>
#include <optional>
#include <ostream>
#include <string>

#include <fmt/core.h>
#include <nameof.hpp>

#include "CommonBase.hpp"
#include "Enums/Color.hpp"
#include "Enums/LineStyle.hpp"
#include "Enums/LineWidth.hpp"
#include "General.hpp"
#include "Structures/StructWire.hpp"


class StructWireScalar : public StructWire
{
public:

    StructWireScalar(ParserContext& aCtx) : StructWire{aCtx}
    { }

    // std::string to_string() const override;

    // void read(FileFormatVersion aVersion = FileFormatVersion::Unknown) override;

    virtual void accept(Visitor& aVisitor) const override
    {
        aVisitor.visit(*this);
    }

    // uint32_t dbId;

    // Color wireColor;

    // int32_t startX;
    // int32_t startY;
    // int32_t endX;
    // int32_t endY;

    // LineWidth wireLineWidth;
    // LineStyle wireLineStyle;
};


#endif // STRUCTWIRESCALAR_HPP