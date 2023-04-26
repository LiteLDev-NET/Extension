#include "EndTag.hpp"
namespace BedrockServer::Extension
{
    inline const nullptr_t EndTag::Value()
    {
        return NativePtr->value();
    }

    inline EndTag^ EndTag::Create()
    {
        return gcnew EndTag(::EndTag::create().release(), true);
    }

    inline bool EndTag::Set()
    {
        return NativePtr->set();
    }

    inline const nullptr_t EndTag::Get()
    {
        return NativePtr->get();
    }

} // namespace BedrockServer::Extension
