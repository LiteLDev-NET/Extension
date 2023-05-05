#pragma once
#include <mc/BlockPalette.hpp>
#include "Types.hpp"
namespace BedrockServer::Extension::Handle
{
    public ref class BlockPaletteHandle : SafeHandle, ICppClass
    {
        DEFAULT_DEF(BlockPaletteHandle, ::BlockPalette)
    public:
    };
} // namespace BedrockServer::Extension::Handle