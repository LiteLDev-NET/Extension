#include "IntArrayTag.hpp"
namespace BedrockServer::Extension
{
    inline TagMemoryChunk^ IntArrayTag::Value()
    {
        return gcnew TagMemoryChunk(&NativePtr->value());
    }
    inline IntArrayTag^ IntArrayTag::operator=(TagMemoryChunk^ val)
    {
        *NativePtr = *val->NativePtr;
        return this;
    }
    inline IntArrayTag^ IntArrayTag::Create()
    {
        return gcnew IntArrayTag(::IntArrayTag::create().release(), true);
    }
    inline IntArrayTag^ IntArrayTag::Create(TagMemoryChunk^ val)
    {
        return gcnew IntArrayTag(::IntArrayTag::create(*val->NativePtr).release(), true);
    }
    inline IntArrayTag^ IntArrayTag::Create(array<int>^ data /*, size_t size*/)
    {
        pin_ptr<int> p_ptr = &data[0];
        return gcnew IntArrayTag(::IntArrayTag::create(p_ptr, data->Length).release(), true);
    }
    inline bool IntArrayTag::Set(TagMemoryChunk^ val)
    {
        return NativePtr->set(*val->NativePtr);
    }
    inline TagMemoryChunk^ IntArrayTag::Get()
    {
        return gcnew TagMemoryChunk(new ::TagMemoryChunk(NativePtr->get()), true);
    }
} // namespace BedrockServer::Extension
