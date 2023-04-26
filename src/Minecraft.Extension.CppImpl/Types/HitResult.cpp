#include "HitResult.hpp"
#include "Actor.hpp"

namespace BedrockServer::Extension {
    FaceID HitResult::Facing::get() {
        return FaceID(NativePtr->getFacing());
    }

    FaceID HitResult::LiquidFacing::get() {
        return FaceID(NativePtr->getLiquidFacing());
    }

    Vec3 HitResult::Pos::get() {
        return *(Vec3*)&NativePtr->getPos();
    }

    bool HitResult::IsHitLiquid::get() {
        return NativePtr->isHitLiquid();
    }

    bool HitResult::IsEntity::get() {
        return NativePtr->isHitLiquid();
    }

    bool HitResult::IsTile::get() {
        return NativePtr->isHitLiquid();
    }

    bool HitResult::IsHit::get() {
        return NativePtr->isHitLiquid();
    }

    BedrockServer::BlockPos HitResult::BlockPos::get() {
        return *(BedrockServer::BlockPos*)&NativePtr->getBlockPos();
    }

    BedrockServer::BlockPos HitResult::LiquidPos::get() {
        return *(BedrockServer::BlockPos*)&NativePtr->getLiquidPos();
    }

    //BedrockServer::Extension::HitResultType HitResult::HitResultType::get() {
    //    return BedrockServer::Extension::HitResultType(NativePtr->getHitResultType());
    //}


    HitResult::HitResult(HitResult% obj)
        :SafeHandle(nint_t::Zero, true)
    {
        NativePtr = new ::HitResult(*obj.NativePtr);
        OwnsNativeInstance = true;
    }

    HitResult::HitResult(Vec3 v1, Vec3 v2, Vec3 v3)
        :SafeHandle(nint_t::Zero, true)
    {
        NativePtr = new ::HitResult(*(::Vec3*)&v1, *(::Vec3*)&v2, *(::Vec3*)&v3);
        OwnsNativeInstance = true;
    }

    HitResult::HitResult(Vec3 v1, Vec3 v2, Actor^ ac, Vec3 v3)
        :SafeHandle(nint_t::Zero, true)
    {
        NativePtr = new ::HitResult(*(::Vec3*)&v1, *(::Vec3*)&v2, *ac->NativePtr, *(::Vec3*)&v3);
        OwnsNativeInstance = true;
    }

    HitResult::HitResult(Vec3 v1, Vec3 v2, Actor^ ac)
        :SafeHandle(nint_t::Zero, true)
    {
        NativePtr = new ::HitResult(*(::Vec3*)&v1, *(::Vec3*)&v2, *ac->NativePtr);
        OwnsNativeInstance = true;
    }

    HitResult::HitResult(Vec3 v1, Vec3 v2, BedrockServer::BlockPos pos, unsigned char b, Vec3 v3)
        :SafeHandle(nint_t::Zero, true)
    {
        NativePtr = new ::HitResult(*(::Vec3*)&v1, *(::Vec3*)&v2, *(::BlockPos*)&pos, b, *(::Vec3*)&v3);
        OwnsNativeInstance = true;
    }

    HitResult::HitResult()
        :SafeHandle(nint_t::Zero, true)
    {
        NativePtr = new ::HitResult();
        OwnsNativeInstance = true;
    }

    //void HitResult::__AutoClassInit2(unsigned __int64 a1)
    //{
    //    return NativePtr->__autoclassinit2(a1);
    //}

    float HitResult::DistanceTo(Actor^ ac)
    {
        return NativePtr->distanceTo(*ac->NativePtr);
    }

    Actor^ HitResult::GetEntity()
    {
        return gcnew Actor(NativePtr->getEntity());
    }

    HitResult^ HitResult::operator=(HitResult^ obj)
    {
        *NativePtr = *obj->NativePtr;
        return this;
    }

}