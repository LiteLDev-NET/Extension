#include "ByteArrayTag.hpp"
#include "TagMemoryChunk.hpp"
namespace BedrockServer::Extension
{

    inline TagMemoryChunk^ ByteArrayTag::Value()
    {
        return gcnew TagMemoryChunk(&NativePtr->value());
    }

    inline ByteArrayTag^ ByteArrayTag::operator=(TagMemoryChunk^ val)
    {
        *NativePtr = *val->NativePtr;
        return this;
    }

    inline ByteArrayTag^ ByteArrayTag::Create()
    {
        return gcnew ByteArrayTag(::ByteArrayTag::create().release(), true);
    }

    inline ByteArrayTag^ ByteArrayTag::Create(TagMemoryChunk^ val)
    {
        return gcnew ByteArrayTag(::ByteArrayTag::create(*val->NativePtr).release(), true);
    }

    inline ByteArrayTag^ ByteArrayTag::Create(array<char>^ data /*, size_t size*/)
    {
        pin_ptr<char> p_ptr = &data[0];
        return gcnew ByteArrayTag(::ByteArrayTag::create((char*)p_ptr, data->Length).release(), true);
    }

    inline bool ByteArrayTag::Set(TagMemoryChunk^ val)
    {
        return NativePtr->set(*val->NativePtr);
    }

    inline TagMemoryChunk^ ByteArrayTag::Get()
    {
        return gcnew TagMemoryChunk(new ::TagMemoryChunk(NativePtr->get()), true);
    }
} // namespace BedrockServer::Extension