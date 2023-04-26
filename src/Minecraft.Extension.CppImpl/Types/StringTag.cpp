#include "StringTag.hpp"
namespace BedrockServer::Extension
{

    inline String^ StringTag::Value()
    {
        return marshalString(NativePtr->value());
    }

    inline StringTag^ StringTag::operator=(std::string val)
    {
        *NativePtr = val;
        return this;
    }

    inline StringTag^ StringTag::Create()
    {
        return gcnew StringTag(::StringTag::create().release(), true);
    }

    inline bool StringTag::Set(String^ val)
    {
        return NativePtr->set(marshalString(val));
    }

    inline String^ StringTag::Get()
    {
        return marshalString(NativePtr->get());
    }
} // namespace BedrockServer::Extension
