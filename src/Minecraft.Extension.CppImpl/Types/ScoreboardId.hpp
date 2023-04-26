#pragma once
#include <mc/ScoreboardId.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension
{
    ref class IdentityDefinition;
}

namespace BedrockServer::Extension
{
    public ref class ScoreboardId : SafeHandle, ICppClass
    {
    internal: ScoreboardId(::ScoreboardId* ptr) :SafeHandle(nint_t::Zero, true) {
        NativePointer = nint_t(ptr); OwnsNativeInstance = false;
    } ScoreboardId(::ScoreboardId* ptr, bool ownsinstance) :SafeHandle(nint_t::Zero, true) {
        NativePointer = nint_t(ptr); OwnsNativeInstance = ownsinstance;
    } operator ::ScoreboardId* () {
        return reinterpret_cast<::ScoreboardId*>((void*)NativePointer);
    } static operator ScoreboardId ^ (::ScoreboardId* ptr) {
        return gcnew ScoreboardId(ptr);
    } property ::ScoreboardId* NativePtr { ::ScoreboardId* get() {
        return reinterpret_cast<::ScoreboardId*>((void*)NativePointer);
    } void set(::ScoreboardId* value) {
        NativePointer = static_cast<nint_t>((void*)value);
    } } static size_t classSize = 0; public: static void SetClassSize(size_t size) {
        classSize = size;
    } ScoreboardId(nint_t ptr, bool ownInstance) :SafeHandle(nint_t::Zero, true) {
        NativePointer = ptr; OwnsNativeInstance = OwnsNativeInstance;
    } virtual property nint_t NativePointer; virtual property bool OwnsNativeInstance; virtual void Destruct() override {
        ReleaseHandle();
    } virtual size_t GetClassSize() override {
        return classSize;
    } virtual bool ReleaseHandle() override {
        __dtor<::ScoreboardId>::destruct(NativePtr); return true;
    } property bool IsInvalid { virtual bool get() override {
        return false;
    } }
    public:

        ScoreboardId();

        property __int64 Id
        {
            __int64 get();
            void set(__int64 id);
        }
        property nint_t Null
        {
            inline nint_t get();
            inline void set(nint_t p);
        }

        int GetHashCode() override;

        property unsigned long long Hash
        {
            unsigned long long get();
        }

        property bool IsValid
        {
            bool get();
        }

        ScoreboardId(long long _0);

        ScoreboardId(ScoreboardId^ _0);

        static bool operator!=(ScoreboardId^ __op, ScoreboardId^ _0);

        static bool operator==(ScoreboardId^ __op, ScoreboardId^ _0);

        virtual bool Equals(::System::Object^ obj) override;

        static operator ScoreboardId ^ (long long _0);

#ifdef INCLUDE_MCAPI


#endif // INCLUDE_MCAPI
    };
} // namespace BedrockServer::Extension