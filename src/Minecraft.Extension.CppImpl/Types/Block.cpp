#include "Block.hpp"

#include "CompoundTag.hpp"
#include "Block.hpp"
#include "HashedString.hpp"

namespace BedrockServer::Extension::Handle
{
    inline BlockHandle^ BlockHandle::Create(const String^ str, unsigned short tileData)
    {
        return gcnew BlockHandle(::Block::create(marshalString((String^)str), tileData));
    }

    inline BlockHandle^ BlockHandle::Create(CompoundTagHandle^ nbt)
    {
        return gcnew BlockHandle(::Block::create(nbt->NativePtr));
    }

    inline HashedStringHandle^ BlockHandle::Name::get()
    {
        return gcnew HashedStringHandle(const_cast<::HashedString*>(&NativePtr->getName()));
    }

    inline int BlockHandle::Id::get()
    {
        return NativePtr->getId();
    }

    inline unsigned short BlockHandle::TileData::get()
    {
        return NativePtr->getTileData();
    }

    inline CompoundTagHandle^ BlockHandle::Nbt::get()
    {
        return gcnew CompoundTagHandle(NativePtr->getNbt().release(), true);
    }

    inline void BlockHandle::Nbt::set(CompoundTagHandle^ nbt)
    {
        NativePtr->setNbt(nbt->NativePtr);
    }
} // namespace BedrockServer::Extension::Handle
