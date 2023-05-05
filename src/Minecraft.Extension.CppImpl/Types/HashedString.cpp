#include "HashedString.hpp"

namespace BedrockServer::Extension::Handle
{


    BedrockServer::Extension::Handle::HashedStringHandle::HashedStringHandle(BedrockServer::Extension::Handle::HashedStringHandle^ _0)
        :SafeHandle(nint_t::Zero, true)
    {
        OwnsNativeInstance = true;
        if (ReferenceEquals(_0, nullptr))
            throw gcnew ::System::ArgumentNullException("_0", "Cannot be null because it is a C++ reference (&).");
        auto& __arg0 = *(class ::HashedString*)_0->NativePtr;
        NativePtr = new class ::HashedString(__arg0);
    }

    BedrockServer::Extension::Handle::HashedStringHandle::HashedStringHandle(::String^ _0)
        :SafeHandle(nint_t::Zero, true)
    {
        OwnsNativeInstance = true;
        auto ___arg0 = clix::marshalString<clix::E_UTF8>(_0);
        auto __arg0 = ___arg0.c_str();
        NativePtr = new class ::HashedString(__arg0);
    }

    BedrockServer::Extension::Handle::HashedStringHandle::HashedStringHandle(unsigned long long _0, ::String^ _1)
        :SafeHandle(nint_t::Zero, true)
    {
        OwnsNativeInstance = true;
        auto ___arg1 = clix::marshalString<clix::E_UTF8>(_1);
        auto __arg1 = ___arg1.c_str();
        NativePtr = new class ::HashedString(_0, __arg1);
    }

    void BedrockServer::Extension::Handle::HashedStringHandle::Clear()
    {
        ((class ::HashedString*)NativePtr)->clear();
    }

    bool BedrockServer::Extension::Handle::HashedStringHandle::operator!=(BedrockServer::Extension::Handle::HashedStringHandle^ __op, BedrockServer::Extension::Handle::HashedStringHandle^ _0)
    {
        bool __opNull = ReferenceEquals(__op, nullptr);
        bool _0Null = ReferenceEquals(_0, nullptr);
        if (__opNull || _0Null)
            return !(__opNull && _0Null);
        auto& __arg0 = *(class ::HashedString*)__op->NativePtr;
        auto& __arg1 = *(class ::HashedString*)_0->NativePtr;
        auto __ret = __arg0 != __arg1;
        return __ret;
    }

    bool BedrockServer::Extension::Handle::HashedStringHandle::operator==(BedrockServer::Extension::Handle::HashedStringHandle^ __op, BedrockServer::Extension::Handle::HashedStringHandle^ _0)
    {
        bool __opNull = ReferenceEquals(__op, nullptr);
        bool _0Null = ReferenceEquals(_0, nullptr);
        if (__opNull || _0Null)
            return __opNull && _0Null;
        auto& __arg0 = *(class ::HashedString*)__op->NativePtr;
        auto& __arg1 = *(class ::HashedString*)_0->NativePtr;
        auto __ret = __arg0 == __arg1;
        return __ret;
    }

    bool BedrockServer::Extension::Handle::HashedStringHandle::Equals(::System::Object^ obj)
    {
        return this == safe_cast<BedrockServer::Extension::Handle::HashedStringHandle^>(obj);
    }

    //void BedrockServer::Extension::Handle::HashedString::BindType()
    //{
    //    ::HashedString::bindType();
    //}

    unsigned long long BedrockServer::Extension::Handle::HashedStringHandle::ComputeHash(::String^ _0)
    {
        auto ___arg0 = clix::marshalString<clix::E_UTF8>(_0);
        auto __arg0 = ___arg0.c_str();
        auto __ret = ::HashedString::computeHash(__arg0);
        return __ret;
    }

    ::String^ BedrockServer::Extension::Handle::HashedStringHandle::CStr::get()
    {
        auto __ret = ((class ::HashedString*)NativePtr)->c_str();
        if (__ret == nullptr) return nullptr;
        return (__ret == 0 ? nullptr : clix::marshalString<clix::E_UTF8>(__ret));
    }

    unsigned long long BedrockServer::Extension::Handle::HashedStringHandle::Hash::get()
    {
        auto __ret = ((class ::HashedString*)NativePtr)->getHash();
        return __ret;
    }

    ::String^ BedrockServer::Extension::Handle::HashedStringHandle::String::get()
    {
        auto& __ret = ((class ::HashedString*)NativePtr)->getString();
        return (::String^)(clix::marshalString<clix::E_UTF8>(__ret));
    }

    bool BedrockServer::Extension::Handle::HashedStringHandle::IsEmpty::get()
    {
        auto __ret = ((class ::HashedString*)NativePtr)->isEmpty();
        return __ret;
    }

    BedrockServer::Extension::Handle::HashedStringHandle^ BedrockServer::Extension::Handle::HashedStringHandle::EmptyString::get()
    {
        auto& __ret = ::HashedString::getEmptyString();
        return (BedrockServer::Extension::Handle::HashedStringHandle^)((&__ret == nullptr) ? nullptr : gcnew ::BedrockServer::Extension::Handle::HashedStringHandle((class ::HashedString*) & __ret));
    }

    BedrockServer::Extension::Handle::HashedStringHandle^ BedrockServer::Extension::Handle::HashedStringHandle::DefaultErrorValue::get()
    {
        return (&::HashedString::defaultErrorValue == nullptr) ? nullptr : gcnew ::BedrockServer::Extension::Handle::HashedStringHandle((class ::HashedString*) & ::HashedString::defaultErrorValue);
    }

    void BedrockServer::Extension::Handle::HashedStringHandle::DefaultErrorValue::set(BedrockServer::Extension::Handle::HashedStringHandle^ value)
    {
        if (ReferenceEquals(value, nullptr))
            throw gcnew ::System::ArgumentNullException("value", "Cannot be null because it is passed by value.");
        ::HashedString::defaultErrorValue = *(class ::HashedString*)value->NativePtr;
    }

}
