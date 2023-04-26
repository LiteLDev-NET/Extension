#include "NetworkIdentifier.hpp"
namespace BedrockServer::Extension
{
    inline String^ NetworkIdentifier::IP::get()
    {
        return marshalString(NativePtr->getIP());
    }
} // namespace BedrockServer::Extension
