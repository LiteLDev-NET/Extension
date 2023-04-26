#include "SerializedSkin.hpp"

namespace BedrockServer::Extension
{
    SerializedSkin::SerializedSkin()
        : SafeHandle(nint_t::Zero, true)
    {
        NativePtr = new ::SerializedSkin();
        OwnsNativeInstance = true;
    }

    SerializedSkin::SerializedSkin(SerializedSkin^ skin)
        :SafeHandle(nint_t::Zero, true)
    {
        NativePtr = new::SerializedSkin(*skin->NativePtr);
        OwnsNativeInstance = true;
    }

    String^ SerializedSkin::Name::get()
    {
        return marshalString(NativePtr->getName());
    }

    bool SerializedSkin::IsTrustedSkin::get()
    {
        return NativePtr->isTrustedSkin();
    }

    void SerializedSkin::IsTrustedSkin::set(bool value)
    {
        NativePtr->setIsTrustedSkin(value);
    }

    bool SerializedSkin::UseBlinkingAnimation::get()
    {
        return NativePtr->useBlinkingAnimation();
    }

    void SerializedSkin::UpdateGeometryName()
    {
        NativePtr->updateGeometryName();
    }

    bool SerializedSkin::Read(ReadOnlyBinaryStream^ stream)
    {
        return NativePtr->read(*stream->NativePtr);
    }

    void SerializedSkin::Write(BinaryStream^ stream)
    {
        NativePtr->write(*stream->NativePtr);
    }
}
