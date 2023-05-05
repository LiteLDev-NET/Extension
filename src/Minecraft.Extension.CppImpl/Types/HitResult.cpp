#include "HitResult.hpp"
#include "Actor.hpp"

namespace BedrockServer::Extension::Handle {
    FaceID HitResultHandle::Facing::get() {
        return FaceID(NativePtr->getFacing());
    }

    FaceID HitResultHandle::LiquidFacing::get() {
        return FaceID(NativePtr->getLiquidFacing());
    }

    Vec3 HitResultHandle::Pos::get() {
        return *(Vec3*)&NativePtr->getPos();
    }

    bool HitResultHandle::IsHitLiquid::get() {
        return NativePtr->isHitLiquid();
    }

    bool HitResultHandle::IsEntity::get() {
        return NativePtr->isHitLiquid();
    }

    bool HitResultHandle::IsTile::get() {
        return NativePtr->isHitLiquid();
    }

    bool HitResultHandle::IsHit::get() {
        return NativePtr->isHitLiquid();
    }

    BedrockServer::BlockPos HitResultHandle::BlockPos::get() {
        return *(BedrockServer::BlockPos*)&NativePtr->getBlockPos();
    }

    BedrockServer::BlockPos HitResultHandle::LiquidPos::get() {
        return *(BedrockServer::BlockPos*)&NativePtr->getLiquidPos();
    }

    //BedrockServer::Extension::Handle::HitResultType HitResult::HitResultType::get() {
    //    return BedrockServer::Extension::Handle::HitResultType(NativePtr->getHitResultType());
    //}


    HitResultHandle::HitResultHandle(HitResultHandle% obj)
        :SafeHandle(nint_t::Zero, true)
    {
        NativePtr = new ::HitResult(*obj.NativePtr);
        OwnsNativeInstance = true;
    }

    HitResultHandle::HitResultHandle(Vec3 v1, Vec3 v2, Vec3 v3)
        :SafeHandle(nint_t::Zero, true)
    {
        NativePtr = new ::HitResult(*(::Vec3*)&v1, *(::Vec3*)&v2, *(::Vec3*)&v3);
        OwnsNativeInstance = true;
    }

    HitResultHandle::HitResultHandle(Vec3 v1, Vec3 v2, ActorHandle^ ac, Vec3 v3)
        :SafeHandle(nint_t::Zero, true)
    {
        NativePtr = new ::HitResult(*(::Vec3*)&v1, *(::Vec3*)&v2, *ac->NativePtr, *(::Vec3*)&v3);
        OwnsNativeInstance = true;
    }

    HitResultHandle::HitResultHandle(Vec3 v1, Vec3 v2, ActorHandle^ ac)
        :SafeHandle(nint_t::Zero, true)
    {
        NativePtr = new ::HitResult(*(::Vec3*)&v1, *(::Vec3*)&v2, *ac->NativePtr);
        OwnsNativeInstance = true;
    }

    HitResultHandle::HitResultHandle(Vec3 v1, Vec3 v2, BedrockServer::BlockPos pos, unsigned char b, Vec3 v3)
        :SafeHandle(nint_t::Zero, true)
    {
        NativePtr = new ::HitResult(*(::Vec3*)&v1, *(::Vec3*)&v2, *(::BlockPos*)&pos, b, *(::Vec3*)&v3);
        OwnsNativeInstance = true;
    }

    HitResultHandle::HitResultHandle()
        :SafeHandle(nint_t::Zero, true)
    {
        NativePtr = new ::HitResult();
        OwnsNativeInstance = true;
    }

    //void HitResult::__AutoClassInit2(unsigned __int64 a1)
    //{
    //    return NativePtr->__autoclassinit2(a1);
    //}

    float HitResultHandle::DistanceTo(ActorHandle^ ac)
    {
        return NativePtr->distanceTo(*ac->NativePtr);
    }

    ActorHandle^ HitResultHandle::GetEntity()
    {
        return gcnew ActorHandle(NativePtr->getEntity());
    }

    HitResultHandle^ HitResultHandle::operator=(HitResultHandle^ obj)
    {
        *NativePtr = *obj->NativePtr;
        return this;
    }

}