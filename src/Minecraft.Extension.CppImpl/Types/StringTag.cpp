#include "StringTag.hpp"
namespace BedrockServer::Extension::Handle
{

    inline String^ StringTagHandle::Value()
    {
        return marshalString(NativePtr->value());
    }

    inline StringTagHandle^ StringTagHandle::operator=(std::string val)
    {
        *NativePtr = val;
        return this;
    }

    inline StringTagHandle^ StringTagHandle::Create()
    {
        return gcnew StringTagHandle(::StringTag::create().release(), true);
    }

    inline bool StringTagHandle::Set(String^ val)
    {
        return NativePtr->set(marshalString(val));
    }

    inline String^ StringTagHandle::Get()
    {
        return marshalString(NativePtr->get());
    }
} // namespace BedrockServer::Extension::Handle
