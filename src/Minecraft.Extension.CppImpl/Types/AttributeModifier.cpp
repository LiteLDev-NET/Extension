#include "AttributeModifier.hpp"

namespace BedrockServer::Extension::Handle
{
    AttributeModifierHandle::AttributeModifierHandle()
        :SafeHandle(nint_t::Zero, true)
    {
        NativePtr = new ::AttributeModifier();
        OwnsNativeInstance = true;
    }

    AttributeModifierHandle::AttributeModifierHandle(Mce::UUID id, String^ name, float amount, AttributeModifierOperation operation,
        AttributeOperands operand, bool isSerializable)
        :SafeHandle(nint_t::Zero, true)
    {
        NativePtr = new ::AttributeModifier(*(::mce::UUID*)&id, marshalString(name), amount,
            static_cast<::AttributeModifierOperation>(operation),
            static_cast<::AttributeOperands>(operand), isSerializable);
        OwnsNativeInstance = true;
    }

    Mce::UUID AttributeModifierHandle::Id::get()
    {
        return *(Mce::UUID*)&NativePtr->mId;
    }

    void AttributeModifierHandle::Id::set(Mce::UUID value)
    {
        NativePtr->mId = *(::mce::UUID*)&value;
    }

    String^ AttributeModifierHandle::Name::get()
    {
        return marshalString(NativePtr->mName);
    }

    void AttributeModifierHandle::Name::set(String^ value)
    {
        NativePtr->mName = marshalString(value);
    }

    float AttributeModifierHandle::Amount::get()
    {
        return NativePtr->mAmount;
    }

    void AttributeModifierHandle::Amount::set(float value)
    {
        NativePtr->mAmount = value;
    }

    AttributeModifierOperation AttributeModifierHandle::Operation::get()
    {
        return static_cast<AttributeModifierOperation>(NativePtr->mOperation);
    }

    void AttributeModifierHandle::Operation::set(AttributeModifierOperation value)
    {
        NativePtr->mOperation = static_cast<::AttributeModifierOperation>(value);
    }

    AttributeOperands AttributeModifierHandle::Operand::get()
    {
        return static_cast<AttributeOperands>(NativePtr->mOperation);
    }

    void AttributeModifierHandle::Operand::set(AttributeOperands value)
    {
        NativePtr->mOperand = static_cast<::AttributeOperands>(value);
    }

    bool AttributeModifierHandle::IsSerializable::get()
    {
        return NativePtr->mSerialize;
    }

    void AttributeModifierHandle::IsSerializable::set(bool value)
    {
        NativePtr->mSerialize = value;
    }

    bool AttributeModifierHandle::Equals(AttributeModifierHandle^ other)
    {
        return NativePtr == other->NativePtr;
    }

    bool AttributeModifierHandle::Equals(Object^ other)
    {
        AttributeModifierHandle^ otherModifier = dynamic_cast<AttributeModifierHandle^>(other);
        return otherModifier != nullptr && Equals(otherModifier);
    }
}
