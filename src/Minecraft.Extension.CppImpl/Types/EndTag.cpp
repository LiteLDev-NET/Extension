#include "EndTag.hpp"
namespace BedrockServer::Extension::Handle
{
    inline const nullptr_t EndTagHandle::Value()
    {
        return NativePtr->value();
    }

    inline EndTagHandle^ EndTagHandle::Create()
    {
        return gcnew EndTagHandle(::EndTag::create().release(), true);
    }

    inline bool EndTagHandle::Set()
    {
        return NativePtr->set();
    }

    inline const nullptr_t EndTagHandle::Get()
    {
        return NativePtr->get();
    }

} // namespace BedrockServer::Extension::Handle
