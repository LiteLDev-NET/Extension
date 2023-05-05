#pragma once
#include <mc/BoundingBox.hpp>
#include "Types.hpp"


namespace BedrockServer
{
    [StructLayout(LayoutKind::Sequential, Size = sizeof(::BoundingBox))]
    public value class BoundingBox {
    internal:
        operator ::BoundingBox()
        {
            pin_ptr<BlockPos> pMin = &min;
            pin_ptr<BlockPos> pMax = &max;
            return ::BoundingBox(*reinterpret_cast<::BlockPos*>(pMin), *reinterpret_cast<::BlockPos*>(pMax));
        }
        static operator BoundingBox(::BoundingBox const& obj)
        {
            return BoundingBox(
                *reinterpret_cast<BlockPos*>(&const_cast<::BlockPos&>(obj.min)),
                *reinterpret_cast<BlockPos*>(&const_cast<::BlockPos&>(obj.max)));
        }
        BlockPos min;
        BlockPos max;

    public:
        property BlockPos Min {
            BlockPos get() {
                return min;
            }
        }

        property BlockPos Max {
            BlockPos get() {
                return max;
            }
        }

    public:
        BoundingBox(BlockPos min, BlockPos max) :min(min), max(max) {}

    public:
        property BlockPos Center {
            BlockPos get() {
                return BlockPos{ (min.X + max.X) / 2, (min.Y + max.Y) / 2, (min.Z + max.Z) / 2 };
            }
        }

        inline BedrockServer::AABB ToAABB();

        //BoundingBox Merge(BoundingBox% a);

        //BoundingBox Merge(BlockPos% a);

    public:
        property BlockPos% default[int] {
            BlockPos% get(int index) {
                pin_ptr<BoundingBox> p = this;
                return *(BlockPos*)(&((*(::BoundingBox*)p)[index]));
            }
        };

        delegate void ForEachBlockInBoxHandler(BlockPos% pos);

        void ForEachBlockInBox(LiteLoader::NET::CppStd::function<ForEachBlockInBoxHandler^>^ todo);


        void ForEachBlockInBoxWithFuncPointer(void(*pfunc)(const BlockPos%)) {
            pin_ptr<BoundingBox> p = this;
            ((::BoundingBox*)p)->forEachBlockInBox((void(*)(const ::BlockPos&))(pfunc));
        }

        property bool IsValid {
            bool get() {
                pin_ptr<BoundingBox> p = this;
                return ((::BoundingBox*)p)->isValid();
            }
        }

        property size_t HashVal {
            size_t get() {
                pin_ptr<BoundingBox>p = this;
                std::hash<::BoundingBox> hash;
                return hash(*(::BoundingBox*)p);
            }
        }

        int GetHashCode() override {
            return (int)HashVal;
        }
    public:
        /*    static BoundingBox MergeBoundingBox(BoundingBox% a, BoundingBox% b) {
                pin_ptr<BoundingBox> pa = &a;
                pin_ptr<BoundingBox> pb = &b;
                return (((::BoundingBox*)pa)->merge(*(::BoundingBox*)pb));
            }*/
        static BoundingBox OrientBox(int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8, int i9, int i10) {
            return ::BoundingBox::orientBox(i1, i2, i3, i4, i5, i6, i7, i8, i9, i10);
        }
    };
}
