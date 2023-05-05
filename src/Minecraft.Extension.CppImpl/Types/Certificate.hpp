#pragma once
#include <mc/Certificate.hpp>
#include "Types.hpp"
namespace BedrockServer::Extension::Handle
{
    public ref class CertificateHandle :SafeHandle, ICppClass
    {
        DEFAULT_DEF(CertificateHandle, ::Certificate)
    public:
    };
} // namespace BedrockServer::Extension::Handle
