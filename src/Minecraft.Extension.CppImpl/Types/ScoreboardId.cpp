#include "ScoreboardId.hpp"
namespace BedrockServer::Extension::Handle
{
    ScoreboardIdHandle::ScoreboardIdHandle()
        :SafeHandle(nint_t::Zero, true)
    {
        OwnsNativeInstance = true;
        NativePtr = new ::ScoreboardId;
    }
    inline __int64 ScoreboardIdHandle::Id::get()
    {
        return NativePtr->id;
    }
    inline void ScoreboardIdHandle::Id::set(__int64 id)
    {
        NativePtr->id = id;
    }
    inline nint_t ScoreboardIdHandle::Null::get()
    {
        return nint_t(NativePtr->null);
    }
    inline void ScoreboardIdHandle::Null::set(nint_t p)
    {
        NativePtr->null = p.ToPointer();
    }
} // namespace BedrockServer::Extension::Handle

BedrockServer::Extension::Handle::ScoreboardIdHandle::ScoreboardIdHandle(BedrockServer::Extension::Handle::ScoreboardIdHandle^ _0)
    :SafeHandle(nint_t::Zero, true)
{
    OwnsNativeInstance = true;
    if (ReferenceEquals(_0, nullptr))
        throw gcnew ::System::ArgumentNullException("_0", "Cannot be null because it is a C++ reference (&).");
    auto& __arg0 = *(struct ::ScoreboardId*)_0->NativePtr;
    NativePtr = new struct ::ScoreboardId(__arg0);
}

int BedrockServer::Extension::Handle::ScoreboardIdHandle::GetHashCode()
{
    return (int)Hash;
}

BedrockServer::Extension::Handle::ScoreboardIdHandle::ScoreboardIdHandle(long long _0)
    :SafeHandle(nint_t::Zero, true)
{
    OwnsNativeInstance = true;
    NativePtr = new struct ::ScoreboardId(_0);
}

bool BedrockServer::Extension::Handle::ScoreboardIdHandle::operator!=(BedrockServer::Extension::Handle::ScoreboardIdHandle^ __op, BedrockServer::Extension::Handle::ScoreboardIdHandle^ _0)
{
    bool __opNull = ReferenceEquals(__op, nullptr);
    bool _0Null = ReferenceEquals(_0, nullptr);
    if (__opNull || _0Null)
        return !(__opNull && _0Null);
    auto& __arg0 = *(struct ::ScoreboardId*)__op->NativePtr;
    auto& __arg1 = *(struct ::ScoreboardId*)_0->NativePtr;
    auto __ret = __arg0 != __arg1;
    return __ret;
}

bool BedrockServer::Extension::Handle::ScoreboardIdHandle::operator==(BedrockServer::Extension::Handle::ScoreboardIdHandle^ __op, BedrockServer::Extension::Handle::ScoreboardIdHandle^ _0)
{
    bool __opNull = ReferenceEquals(__op, nullptr);
    bool _0Null = ReferenceEquals(_0, nullptr);
    if (__opNull || _0Null)
        return __opNull && _0Null;
    auto& __arg0 = *(struct ::ScoreboardId*)__op->NativePtr;
    auto& __arg1 = *(struct ::ScoreboardId*)_0->NativePtr;
    auto __ret = __arg0 == __arg1;
    return __ret;
}

bool BedrockServer::Extension::Handle::ScoreboardIdHandle::Equals(::System::Object^ obj)
{
    return this == safe_cast<BedrockServer::Extension::Handle::ScoreboardIdHandle^>(obj);
}

BedrockServer::Extension::Handle::ScoreboardIdHandle::operator BedrockServer::Extension::Handle::ScoreboardIdHandle ^ (long long _0) {
    auto __ret = (::ScoreboardId)_0;
    auto ____ret = new struct ::ScoreboardId(__ret);
    return (____ret == nullptr) ? nullptr : gcnew ::BedrockServer::Extension::Handle::ScoreboardIdHandle((struct ::ScoreboardId*)____ret, true);
}

unsigned long long BedrockServer::Extension::Handle::ScoreboardIdHandle::Hash::get()
{
    auto __ret = NativePtr->getHash();
    return __ret;
}

bool BedrockServer::Extension::Handle::ScoreboardIdHandle::IsValid::get()
{
    auto __ret = NativePtr->isValid();
    return __ret;
}
