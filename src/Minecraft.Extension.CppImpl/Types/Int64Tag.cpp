#include "Int64Tag.hpp"
namespace BedrockServer::Extension
{
    inline int64_t^ Int64Tag::Value()
    {
        return NativePtr->value();
    }

    inline Int64Tag^ Int64Tag::operator=(int64_t val)
    {
        *NativePtr = val;
        return this;
    }

    inline Int64Tag^ Int64Tag::Create()
    {
        return gcnew Int64Tag(::Int64Tag::create().release(), true);
    }

    inline Int64Tag^ Int64Tag::Create(int64_t val)
    {
        return gcnew Int64Tag(::Int64Tag::create(val).release(), true);
    }

    inline bool Int64Tag::Set(int64_t val)
    {
        return NativePtr->set(val);
    }

    inline int64_t Int64Tag::Get()
    {
        return NativePtr->get();
    }
} // namespace BedrockServer::Extension
