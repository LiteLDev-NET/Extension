#pragma once
#include <mc/HitResult.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension {
    public enum class HitResultType :int {
        TILE = 0,
        ENTITY,
        ENTITY_OUT_OF_RANGE,
        NO_HIT,
    };
    ref class Actor;
}

namespace BedrockServer::Extension {
    public ref class HitResult :SafeHandle, ICppClass
    {
    internal: HitResult(::HitResult* ptr) :SafeHandle(nint_t::Zero, true) {
        NativePointer = nint_t(ptr); OwnsNativeInstance = false;
    } HitResult(::HitResult* ptr, bool ownsinstance) :SafeHandle(nint_t::Zero, true) {
        NativePointer = nint_t(ptr); OwnsNativeInstance = ownsinstance;
    } operator ::HitResult* () {
        return reinterpret_cast<::HitResult*>((void*)NativePointer);
    } static operator HitResult ^ (::HitResult* ptr) {
        return gcnew HitResult(ptr);
    } property ::HitResult* NativePtr { ::HitResult* get() {
        return reinterpret_cast<::HitResult*>((void*)NativePointer);
    } void set(::HitResult* value) {
        NativePointer = static_cast<nint_t>((void*)value);
    } } static size_t classSize = 0; public: static void SetClassSize(size_t size) {
        classSize = size;
    } HitResult(nint_t ptr, bool ownInstance) :SafeHandle(nint_t::Zero, true) {
        NativePointer = ptr; OwnsNativeInstance = OwnsNativeInstance;
    } virtual property nint_t NativePointer { nint_t get() {
        return handle;
    } void set(nint_t value) {
        handle = value;
    } }; virtual property bool OwnsNativeInstance; virtual void Destruct() {
        ReleaseHandle();
    } virtual size_t GetClassSize() {
        return classSize;
    } virtual bool ReleaseHandle() override {
        if (OwnsNativeInstance) __dtor<::HitResult>::destruct(NativePtr); return true;
    } property bool IsInvalid { virtual bool get() override {
        return false;
    } }
    public:
        property FaceID Facing { FaceID get(); }
        property Vec3 Pos { Vec3 get(); }
        property bool IsHitLiquid { bool get(); }
        property bool IsEntity { bool get(); }
        property bool IsTile { bool get(); }
        property BedrockServer::BlockPos BlockPos { BedrockServer::BlockPos get(); }
        property BedrockServer::BlockPos LiquidPos { BedrockServer::BlockPos get(); }
        property FaceID LiquidFacing { FaceID get(); }
        //property BedrockServer::Extension::HitResultType HitResultType { BedrockServer::Extension::HitResultType get(); }
    public:
        HitResult(HitResult% obj);
        HitResult(Vec3 v1, Vec3 v2, Vec3 v3);
        HitResult(Vec3 v1, Vec3 v2, Actor^ ac, Vec3 v3);
        HitResult(Vec3 v1, Vec3 v2, Actor^ ac);
        HitResult(Vec3 v1, Vec3 v2, BedrockServer::BlockPos pos, unsigned char b, Vec3 v3);
        HitResult();
    public:
        //void __AutoClassInit2(unsigned __int64 a1);
        float DistanceTo(Actor^ ac);
        Actor^ GetEntity();
        property bool IsHit { bool get(); };
    public:
        HitResult^ operator=(HitResult^ obj);
    };
}