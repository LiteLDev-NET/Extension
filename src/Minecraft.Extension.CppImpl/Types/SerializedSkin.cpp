#include "SerializedSkin.hpp"

namespace BedrockServer::Extension::Handle
{
    SerializedSkinHandle::SerializedSkinHandle()
        : SafeHandle(nint_t::Zero, true)
    {
        NativePtr = new ::SerializedSkin();
        OwnsNativeInstance = true;
    }

    SerializedSkinHandle::SerializedSkinHandle(SerializedSkinHandle^ skin)
        :SafeHandle(nint_t::Zero, true)
    {
        NativePtr = new::SerializedSkin(*skin->NativePtr);
        OwnsNativeInstance = true;
    }

    String^ SerializedSkinHandle::Name::get()
    {
        return marshalString(NativePtr->getName());
    }

    bool SerializedSkinHandle::IsTrustedSkin::get()
    {
        return NativePtr->isTrustedSkin();
    }

    void SerializedSkinHandle::IsTrustedSkin::set(bool value)
    {
        NativePtr->setIsTrustedSkin(value);
    }

    bool SerializedSkinHandle::UseBlinkingAnimation::get()
    {
        return NativePtr->useBlinkingAnimation();
    }

    void SerializedSkinHandle::UpdateGeometryName()
    {
        NativePtr->updateGeometryName();
    }

    bool SerializedSkinHandle::Read(ReadOnlyBinaryStreamHandle^ stream)
    {
        return NativePtr->read(*stream->NativePtr);
    }

    void SerializedSkinHandle::Write(BinaryStreamHandle^ stream)
    {
        NativePtr->write(*stream->NativePtr);
    }
}
