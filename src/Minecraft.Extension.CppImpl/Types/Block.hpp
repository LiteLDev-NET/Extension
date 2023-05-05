#pragma once
#include <mc/Block.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension::Handle
{
    ref class CompoundTagHandle;
    ref class HashedStringHandle;
}

namespace BedrockServer::Extension::Handle
{
    public ref class BlockHandle :SafeHandle, ICppClass
    {
        DEFAULT_DEF(BlockHandle, ::Block)
    public:

        inline static BlockHandle^ Create(const String^ str, unsigned short tileData);
        inline static BlockHandle^ Create(CompoundTagHandle^ nbt);

        property HashedStringHandle^ Name { HashedStringHandle^ get(); };
        property CompoundTagHandle^ Nbt { CompoundTagHandle^ get(); void set(CompoundTagHandle^ value); };

        property int Id
        {
            int get();
        }
        property unsigned short TileData
        {
            unsigned short get();
        }
    };
} // namespace BedrockServer::Extension::Handle
