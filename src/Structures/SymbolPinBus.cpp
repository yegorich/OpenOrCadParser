#include <cstdint>
#include <ostream>
#include <string>

#include <nameof.hpp>
#include <spdlog/spdlog.h>

#include "../Enums/PortType.hpp"
#include "../General.hpp"
#include "../Parser.hpp"
#include "../PinShape.hpp"
#include "SymbolPinBus.hpp"


SymbolPinBus Parser::readSymbolPinBus()
{
    spdlog::debug(getOpeningMsg(__func__, mDs.getCurrentOffset()));

    const std::optional<FutureData> thisFuture = getFutureData();

    SymbolPinBus obj;

    obj.name = mDs.readStringLenZeroTerm();

    obj.startX = mDs.readInt32();
    obj.startY = mDs.readInt32();
    obj.hotptX = mDs.readInt32();
    obj.hotptY = mDs.readInt32();

    obj.pinShape = ToPinShape(mDs.readUint16());

    mDs.printUnknownData(2, std::string(__func__) + " - 0");

    obj.portType = ToPortType(mDs.readUint32());

    mDs.printUnknownData(6, std::string(__func__) + " - 1");

    // sanitizeThisFutureSize(thisFuture);

    checkTrailingFuture();

    spdlog::debug(getClosingMsg(__func__, mDs.getCurrentOffset()));
    spdlog::info(to_string(obj));

    return obj;
}