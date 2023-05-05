#include "Int64Tag.hpp"
namespace BedrockServer::Extension::Handle
{
    inline int64_t^ Int64TagHandle::Value()
    {
        return NativePtr->value();
    }

    inline Int64TagHandle^ Int64TagHandle::operator=(int64_t val)
    {
        *NativePtr = val;
        return this;
    }

    inline Int64TagHandle^ Int64TagHandle::Create()
    {
        return gcnew Int64TagHandle(::Int64Tag::create().release(), true);
    }

    inline Int64TagHandle^ Int64TagHandle::Create(int64_t val)
    {
        return gcnew Int64TagHandle(::Int64Tag::create(val).release(), true);
    }

    inline bool Int64TagHandle::Set(int64_t val)
    {
        return NativePtr->set(val);
    }

    inline int64_t Int64TagHandle::Get()
    {
        return NativePtr->get();
    }
} // namespace BedrockServer::Extension::Handle
