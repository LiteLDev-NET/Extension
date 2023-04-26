#pragma once
#include <mc/Certificate.hpp>
#include "Types.hpp"
namespace BedrockServer::Extension
{
    public ref class Certificate :SafeHandle, ICppClass
    {
        DEFAULT_DEF(Certificate, ::Certificate)
    public:
    };
} // namespace BedrockServer::Extension
