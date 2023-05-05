#include "NetworkIdentifier.hpp"
namespace BedrockServer::Extension::Handle
{
    inline String^ NetworkIdentifierHandle::IP::get()
    {
        return marshalString(NativePtr->getIP());
    }
} // namespace BedrockServer::Extension::Handle
