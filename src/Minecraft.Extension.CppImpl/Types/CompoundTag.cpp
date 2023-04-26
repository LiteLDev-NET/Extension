#include "CompoundTag.hpp"

#include "ItemStack.hpp"
#include "Actor.hpp"
#include "Block.hpp"
#include "BlockActor.hpp"
#include "Player.hpp"
#include "CompoundTagVariant.hpp"
#include "ByteArrayTag.hpp"
#include "ByteTag.hpp"
#include "CompoundTag.hpp"
#include "DoubleTag.hpp"
#include "ShortTag.hpp"
#include "EndTag.hpp"
#include "FloatTag.hpp"
#include "Int64Tag.hpp"
#include "IntArrayTag.hpp"
#include "IntTag.hpp"
#include "ListTag.hpp"
#include "ShortTag.hpp"
#include "StringTag.hpp"
#include "Tag.hpp"

namespace BedrockServer::Extension
{

    inline CompoundTag^ CompoundTag::Create()
    {
        return gcnew CompoundTag(::CompoundTag::create().release(), true);
    }

    inline Dictionary<String^, CompoundTagVariant^>^ CompoundTag::Value()
    {
        Dictionary<String^, CompoundTagVariant^>^ ret;
        auto& stdmap = NativePtr->value();
        ret = gcnew Dictionary<String^, CompoundTagVariant^>(int(stdmap.size()));
        for (auto iter = stdmap.begin(); iter != stdmap.end(); ++iter)
            ret->Add(
                marshalString((*iter).first),
                gcnew CompoundTagVariant(&iter->second));
        return ret;
    }

    // put value
    inline void CompoundTag::PutEnd(String^ key)
    {
        NativePtr->putEnd(marshalString(key));
    }

    inline double^ CompoundTag::PutDouble(String^ key, double val)
    {
        return NativePtr->putDouble(marshalString(key), val);
    }

    inline void CompoundTag::PutByteArray(String^ key, array<char>^ data /*, size_t size*/)
    {
        pin_ptr<char> p_ptr = &data[0];
        NativePtr->putByteArray(marshalString(key), (char*)p_ptr, data->Length);
    }

    inline void CompoundTag::PutIntArray(String^ key, array<int>^ data /*, size_t size*/)
    {
        pin_ptr<int> p_ptr = &data[0];
        NativePtr->putIntArray(marshalString(key), (int*)p_ptr, data->Length);
    }

    inline TagMemoryChunk^ CompoundTag::PutIntArray(String^ key, TagMemoryChunk^ val)
    {
        return gcnew TagMemoryChunk(
            &NativePtr->putIntArray(marshalString(key), *val->NativePtr));
    }

    // get value
    inline double CompoundTag::GetDouble(String^ key)
    {
        return NativePtr->getDouble(marshalString(key));
    }

    inline TagMemoryChunk const^ CompoundTag::GetIntArray(String^ key)
    {
        return gcnew TagMemoryChunk(const_cast<::TagMemoryChunk*>(&NativePtr->getIntArray(marshalString(key))));
    }

    // get tag
    inline IntTag const^ CompoundTag::GetIntTag(String^ key)
    {
        return gcnew IntTag((::IntTag*)NativePtr->getIntTag(marshalString(key)));
    }
    inline Int64Tag const^ CompoundTag::GetInt64Tag(String^ key)
    {
        return gcnew Int64Tag((::Int64Tag*)NativePtr->getInt64Tag(marshalString(key)));
    }
    inline ByteTag const^ CompoundTag::GetByteTag(String^ key)
    {
        return gcnew ByteTag((::ByteTag*)NativePtr->getByteTag(marshalString(key)));
    }
    inline ShortTag const^ CompoundTag::GetShortTag(String^ key)
    {
        return gcnew ShortTag((::ShortTag*)NativePtr->getShortTag(marshalString(key)));
    }
    inline FloatTag const^ CompoundTag::GetFloatTag(String^ key)
    {
        return gcnew FloatTag((::FloatTag*)NativePtr->getFloatTag(marshalString(key)));
    }
    inline DoubleTag const^ CompoundTag::GetDoubleTag(String^ key)
    {
        return gcnew DoubleTag((::DoubleTag*)NativePtr->getDoubleTag(marshalString(key)));
    }
    inline ByteArrayTag const^ CompoundTag::GetByteArrayTag(String^ key)
    {
        return gcnew ByteArrayTag((::ByteArrayTag*)NativePtr->getByteArrayTag(marshalString(key)));
    }
    inline StringTag const^ CompoundTag::GetStringTag(String^ key)
    {
        return gcnew StringTag((::StringTag*)NativePtr->getStringTag(marshalString(key)));
    }
    inline IntArrayTag const^ CompoundTag::GetIntArrayTag(String^ key)
    {
        return gcnew IntArrayTag((::IntArrayTag*)NativePtr->getIntArrayTag(marshalString(key)));
    }
    inline ListTag const^ CompoundTag::GetListTag(String^ key)
    {
        return gcnew ListTag((::ListTag*)NativePtr->getListTag(marshalString(key)));
    }
    inline CompoundTag^ CompoundTag::GetCompoundTag(String^ key)
    {
        return gcnew CompoundTag((::CompoundTag*)NativePtr->getCompoundTag(marshalString(key)));
    }

    // io
    inline void CompoundTag::SetItemStack(ItemStack^ item)
    {
        NativePtr->setItemStack(item->NativePtr);
    }

    inline void CompoundTag::SetBlock(Block^ block)
    {
        NativePtr->setBlock(block);
    }

    inline bool CompoundTag::SetActor(Actor^ actor)
    {
        return NativePtr->setActor(actor);
    }

    inline bool CompoundTag::SetBlockActor(BlockActor^ ble)
    {
        return NativePtr->setBlockActor(ble);
    }

    inline bool CompoundTag::SetPlayer(Player^ player)
    {
        return NativePtr->setPlayer(player->NativePtr);
    }

    inline CompoundTag^ CompoundTag::FromItemStack(ItemStack^ item)
    {
        return gcnew CompoundTag(::CompoundTag::fromItemStack(item->NativePtr).release(), true);
    }

    inline CompoundTag^ CompoundTag::FromBlock(Block^ block)
    {
        return gcnew CompoundTag(::CompoundTag::fromBlock(block).release(), true);
    }

    inline CompoundTag^ CompoundTag::FromActor(Actor^ actor)
    {
        return gcnew CompoundTag(::CompoundTag::fromActor(actor).release(), true);
    }

    inline CompoundTag^ CompoundTag::FromBlockActor(BlockActor^ blockActor)
    {
        return gcnew CompoundTag(::CompoundTag::fromBlockActor(blockActor).release(), true);
    }

    inline CompoundTag^ CompoundTag::FromPlayer(Player^ player)
    {
        return gcnew CompoundTag(::CompoundTag::fromPlayer(player->NativePtr).release(), true);
    }

    inline String^ CompoundTag::ToSNBT()
    {
        return marshalString(NativePtr->toSNBT());
    }
    inline String^ CompoundTag::ToBinaryNBT(bool isLittleEndian)
    {
        return marshalString(NativePtr->toBinaryNBT(isLittleEndian));
    }
    inline String^ CompoundTag::ToBinaryNBT()
    {
        return marshalString(NativePtr->toBinaryNBT());
    }
    inline CompoundTag^ CompoundTag::FromSNBT(String^ snbt)
    {
        return gcnew CompoundTag(::CompoundTag::fromSNBT(marshalString(snbt)).release(), true);
    }
    inline CompoundTag^ CompoundTag::FromBinaryNBT(void* data, size_t len, bool isLittleEndian)
    {
        return gcnew CompoundTag(::CompoundTag::fromBinaryNBT(data, len, isLittleEndian).release(), true);
    }
    inline CompoundTag^ CompoundTag::FromBinaryNBT(void* data, size_t len)
    {
        return gcnew CompoundTag(::CompoundTag::fromBinaryNBT(data, len).release(), true);
    }
    inline CompoundTag^ CompoundTag::FromBinaryNBT(void* data, size_t len, size_t& endOffset, bool isLittleEndian)
    {
        return gcnew CompoundTag(::CompoundTag::fromBinaryNBT(data, len, endOffset, isLittleEndian).release(), true);
    }
    inline CompoundTag^ CompoundTag::FromBinaryNBT(void* data, size_t len, size_t& endOffset)
    {
        return gcnew CompoundTag(::CompoundTag::fromBinaryNBT(data, len, endOffset).release(), true);
    }

} // namespace BedrockServer::Extension


#ifdef INCLUDE_MCAPI

#include <memory>

void BedrockServer::Extension::CompoundTag::DeleteChildren()
{
    ((class ::CompoundTag*)NativePtr)->deleteChildren();
}

::String^ BedrockServer::Extension::CompoundTag::ToString()
{
    auto __ret = ((class ::CompoundTag*)NativePtr)->toString();
    return clix::marshalString<clix::E_UTF8>(__ret);
}

BedrockServer::Extension::Tag::Type BedrockServer::Extension::CompoundTag::GetId()
{
    auto __ret = ((class ::CompoundTag*)NativePtr)->getId();
    return (BedrockServer::Extension::Tag::Type)__ret;
}

bool BedrockServer::Extension::CompoundTag::Equals(BedrockServer::Extension::Tag^ _0)
{
    if (ReferenceEquals(_0, nullptr))
        throw gcnew ::System::ArgumentNullException("_0", "Cannot be null because it is a C++ reference (&).");
    auto& __arg0 = *(class ::Tag*)_0->NativePtr;
    auto __ret = ((class ::CompoundTag*)NativePtr)->equals(__arg0);
    return __ret;
}

unsigned long long BedrockServer::Extension::CompoundTag::hash()
{
    auto __ret = ((class ::CompoundTag*)NativePtr)->hash();
    return __ret;
}

void BedrockServer::Extension::CompoundTag::Append(BedrockServer::Extension::CompoundTag^ _0)
{
    if (ReferenceEquals(_0, nullptr))
        throw gcnew ::System::ArgumentNullException("_0", "Cannot be null because it is a C++ reference (&).");
    auto& __arg0 = *(class ::CompoundTag*)_0->NativePtr;
    ((class ::CompoundTag*)NativePtr)->append(__arg0);
}

void BedrockServer::Extension::CompoundTag::Clear()
{
    ((class ::CompoundTag*)NativePtr)->clear();
}

bool BedrockServer::Extension::CompoundTag::Contains(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __ret = ((class ::CompoundTag*)NativePtr)->contains(__arg0);
    return __ret;
}

bool BedrockServer::Extension::CompoundTag::Contains(::String^ _0, BedrockServer::Extension::Tag::Type _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __arg1 = (enum ::Tag::Type)_1;
    auto __ret = ((class ::CompoundTag*)NativePtr)->contains(__arg0, __arg1);
    return __ret;
}

void BedrockServer::Extension::CompoundTag::DeepCopy(BedrockServer::Extension::CompoundTag^ _0)
{
    if (ReferenceEquals(_0, nullptr))
        throw gcnew ::System::ArgumentNullException("_0", "Cannot be null because it is a C++ reference (&).");
    auto& __arg0 = *(class ::CompoundTag*)_0->NativePtr;
    ((class ::CompoundTag*)NativePtr)->deepCopy(__arg0);
}

BedrockServer::Extension::Tag^ BedrockServer::Extension::CompoundTag::Get(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __ret = ((class ::CompoundTag*)NativePtr)->get(__arg0);
    if (__ret == nullptr) return nullptr;
    return (__ret == nullptr) ? nullptr : gcnew ::BedrockServer::Extension::Tag((class ::Tag*)__ret);
}

bool BedrockServer::Extension::CompoundTag::GetBoolean(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __ret = ((class ::CompoundTag*)NativePtr)->getBoolean(__arg0);
    return __ret;
}

unsigned char BedrockServer::Extension::CompoundTag::GetByte(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __ret = ((class ::CompoundTag*)NativePtr)->getByte(__arg0);
    return __ret;
}

BedrockServer::Extension::CompoundTag^ BedrockServer::Extension::CompoundTag::GetCompound(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __ret = ((class ::CompoundTag*)NativePtr)->getCompound(__arg0);
    if (__ret == nullptr) return nullptr;
    return (__ret == nullptr) ? nullptr : gcnew ::BedrockServer::Extension::CompoundTag((class ::CompoundTag*)__ret);
}

float BedrockServer::Extension::CompoundTag::GetFloat(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __ret = ((class ::CompoundTag*)NativePtr)->getFloat(__arg0);
    return __ret;
}

int BedrockServer::Extension::CompoundTag::GetInt(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __ret = ((class ::CompoundTag*)NativePtr)->getInt(__arg0);
    return __ret;
}

long long BedrockServer::Extension::CompoundTag::GetInt64(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __ret = ((class ::CompoundTag*)NativePtr)->getInt64(__arg0);
    return __ret;
}

short BedrockServer::Extension::CompoundTag::GetShort(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __ret = ((class ::CompoundTag*)NativePtr)->getShort(__arg0);
    return __ret;
}

::String^ BedrockServer::Extension::CompoundTag::GetString(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto& __ret = ((class ::CompoundTag*)NativePtr)->getString(__arg0);
    return (::String^)(clix::marshalString<clix::E_UTF8>(__ret));
}

BedrockServer::Extension::Tag^ BedrockServer::Extension::CompoundTag::Put(::String^ _0, BedrockServer::Extension::Tag^ _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    if (ReferenceEquals(_1, nullptr))
        throw gcnew ::System::ArgumentNullException("_1", "Cannot be null because it is a C++ reference (&).");
    auto& __arg1 = *(class ::Tag*)_1->NativePtr;
    auto& __ret = ((class ::CompoundTag*)NativePtr)->put(__arg0, std::move(__arg1));
    return (BedrockServer::Extension::Tag^)((&__ret == nullptr) ? nullptr : gcnew ::BedrockServer::Extension::Tag((class ::Tag*) & __ret));
}

void BedrockServer::Extension::CompoundTag::PutBoolean(::String^ _0, bool _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    ((class ::CompoundTag*)NativePtr)->putBoolean(__arg0, _1);
}

unsigned char BedrockServer::Extension::CompoundTag::PutByte(::String^ _0, unsigned char _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto& __ret = ((class ::CompoundTag*)NativePtr)->putByte(__arg0, _1);
    return (unsigned char)(__ret);
}

BedrockServer::Extension::CompoundTag^ BedrockServer::Extension::CompoundTag::PutCompound(::String^ _0, BedrockServer::Extension::CompoundTag^ _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    if (ReferenceEquals(_1, nullptr))
        throw gcnew ::System::ArgumentNullException("_1", "Cannot be null because it is passed by value.");
    auto __ret = ((class ::CompoundTag*)NativePtr)->putCompound(__arg0, std::unique_ptr<::CompoundTag>((::CompoundTag*)_1->Release()));
    return __ret == nullptr ? nullptr : gcnew ::BedrockServer::Extension::CompoundTag(__ret);
}

float BedrockServer::Extension::CompoundTag::PutFloat(::String^ _0, float _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto& __ret = ((class ::CompoundTag*)NativePtr)->putFloat(__arg0, _1);
    return (float)(__ret);
}

int BedrockServer::Extension::CompoundTag::PutInt(::String^ _0, int _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto& __ret = ((class ::CompoundTag*)NativePtr)->putInt(__arg0, _1);
    return (int)(__ret);
}

long long BedrockServer::Extension::CompoundTag::PutInt64(::String^ _0, long long _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto& __ret = ((class ::CompoundTag*)NativePtr)->putInt64(__arg0, _1);
    return (long long)(__ret);
}

short BedrockServer::Extension::CompoundTag::PutShort(::String^ _0, short _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto& __ret = ((class ::CompoundTag*)NativePtr)->putShort(__arg0, _1);
    return (short)(__ret);
}

::String^ BedrockServer::Extension::CompoundTag::PutString(::String^ _0, ::String^ _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __arg1 = clix::marshalString<clix::E_UTF8>(_1);
    auto& __ret = ((class ::CompoundTag*)NativePtr)->putString(__arg0, __arg1);
    return (::String^)(clix::marshalString<clix::E_UTF8>(__ret));
}

bool BedrockServer::Extension::CompoundTag::Remove(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __ret = ((class ::CompoundTag*)NativePtr)->remove(__arg0);
    return __ret;
}

void BedrockServer::Extension::CompoundTag::Rename(::String^ _0, ::String^ _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __arg1 = clix::marshalString<clix::E_UTF8>(_1);
    ((class ::CompoundTag*)NativePtr)->rename(__arg0, __arg1);
}

bool BedrockServer::Extension::CompoundTag::IsEmpty::get()
{
    auto __ret = ((class ::CompoundTag*)NativePtr)->isEmpty();
    return __ret;
}
#endif // INCLUDE_MCAPI
