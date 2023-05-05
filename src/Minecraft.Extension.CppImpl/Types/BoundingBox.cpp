#include "BoundingBox.hpp"


namespace BedrockServer
{

    inline BedrockServer::AABB BoundingBox::ToAABB()
    {
        auto ret = BedrockServer::AABB();
        ret.Max = BedrockServer::Vec3(max.X, max.Y, max.Z);
        ret.Min = BedrockServer::Vec3(min.X, min.Y, min.Z);
        return ret;
    }

    //inline BoundingBox BoundingBox::Merge(BoundingBox% a) {
    //    pin_ptr<BoundingBox> pthis = this;
    //    pin_ptr<BoundingBox> pa = &a;
    //    return ((::BoundingBox*)pthis)->merge(*(::BoundingBox*)pa);
    //}

    //inline BoundingBox BoundingBox::Merge(BlockPos% a) {
    //    pin_ptr<BoundingBox> pthis = this;
    //    pin_ptr<BlockPos> pa = &a;
    //    return ((::BoundingBox*)pthis)->merge(*(::BlockPos*)pa);
    //}

    inline void BoundingBox::ForEachBlockInBox(LiteLoader::NET::CppStd::function<ForEachBlockInBoxHandler^>^ todo) {
        pin_ptr<BoundingBox> p = this;
        ((::BoundingBox*)p)->forEachBlockInBox(*reinterpret_cast<std::function<void(::BlockPos const&)>*>((void*)todo->NativePointer));
    }
}