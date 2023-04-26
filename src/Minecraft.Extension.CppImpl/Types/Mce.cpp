#include "Mce.hpp"

namespace BedrockServer::Mce
{
    inline Color::operator ::mce::Color()
    {
        return ::mce::Color{ R,G,B,A };
    }

    inline Color::Color(float R, float G, float B, float A)
        : R(R)
        , G(G)
        , B(B)
        , A(A) {}

    inline Color::Color(float R, float G, float B)
        : R(R)
        , G(G)
        , B(B)
        , A(1) {}

    inline Color::Color(int ir, int ig, int ib, int ia)
        : R(ir / 255.0f)
        , G(ig / 255.0f)
        , B(ib / 255.0f)
        , A(ia / 255.0f) {}

    inline Color::Color(int ir, int ig, int ib)
        : R(ir / 255.0f)
        , G(ig / 255.0f)
        , B(ib / 255.0f)
        , A(255 / 255.0f) {}

    inline Color::operator bool(Color obj) {
        return !(obj == NIL);
    }

    inline double Color::DistanceTo(Color% obj)
    {
        pin_ptr<Color> p = this;
        pin_ptr<Color> pobj = &obj;
        return ((::mce::Color*)p)->distanceTo(*(::mce::Color*)pobj);
    }

    inline String^ Color::ToConsoleCode(bool foreground)
    {
        pin_ptr<Color> p = this;
        return marshalString(((::mce::Color*)p)->toConsoleCode(foreground));
    }

    inline String^ Color::ToConsoleCode()
    {
        return ToConsoleCode(true);
    }

    inline String^ Color::ToNearestColorCode()
    {
        pin_ptr<Color> p = this;
        return marshalString(((::mce::Color*)p)->toNearestColorCode());
    }

    inline Color Color::FromConsoleCode(String^ str)
    {
        return ::mce::Color::fromConsoleCode(marshalString(str));
    }

    inline Color Color::FromColorCode(String^ str)
    {
        return ::mce::Color::fromColorCode(marshalString(str));
    }

    inline Color Color::sRGBToLinear()
    {
        pin_ptr<Color> p = this;
        return ((::mce::Color*)p)->sRGBToLinear();
    }

    inline Color Color::LinearTosRGB()
    {
        pin_ptr<Color> p = this;
        return ((::mce::Color*)p)->LinearTosRGB();
    }

    inline Color Color::LinearToXYZ()
    {
        pin_ptr<Color> p = this;
        return ((::mce::Color*)p)->LinearToXYZ();
    }

    inline Color Color::XYZToLinear()
    {
        pin_ptr<Color> p = this;
        return ((::mce::Color*)p)->XYZToLinear();
    }

    inline Color Color::XYZToLab()
    {
        pin_ptr<Color> p = this;
        return ((::mce::Color*)p)->XYZToLab();
    }

    inline Color Color::LabToXYZ()
    {
        pin_ptr<Color> p = this;
        return ((::mce::Color*)p)->LabToXYZ();
    }

    inline double Color::DeltaE76(Color% obj)
    {
        pin_ptr<Color> p = this;
        pin_ptr<Color> pobj = &obj;
        return ((::mce::Color*)p)->deltaE76(*(::mce::Color*)pobj);
    }

    inline double Color::DeltaE94(Color% obj)
    {
        pin_ptr<Color> p = this;
        pin_ptr<Color> pobj = &obj;
        return ((::mce::Color*)p)->deltaE76(*(::mce::Color*)pobj);
    }

    inline double Color::DeltaE00(Color% obj)
    {
        pin_ptr<Color> p = this;
        pin_ptr<Color> pobj = &obj;
        return ((::mce::Color*)p)->deltaE76(*(::mce::Color*)pobj);
    }

    inline Color Color::FromHexString(String^ str)
    {
        return ::mce::Color::fromHexString(marshalString(str));
    }

    inline bool Color::operator==(Color A, Color B)
    {
        pin_ptr<Color> pa = &A;
        pin_ptr<Color> pb = &B;
        return *(::mce::Color*)pa == *(::mce::Color*)pb;
    }

    inline int Color::ToABGR()
    {
        pin_ptr<Color> p = this;
        return ((::mce::Color*)p)->toABGR();
    }

    inline int Color::ToARGB()
    {
        pin_ptr<Color> p = this;
        return ((::mce::Color*)p)->toARGB();
    }

    inline String^ Color::ToHexString()
    {
        pin_ptr<Color> p = this;
        return marshalString(((::mce::Color*)p)->toHexString());
    }

    inline  BedrockServer::Vec3 Color::ToVec3()
    {
        return Vec3(R, G, B);
    }

    inline Color Color::FromVec3(BedrockServer::Vec3% k)
    {
        return Color{ k.X, k.Y, k.Z, 1.0f };
    }

    inline  BedrockServer::BlockPos Color::ToBlockPos()
    {
        return BlockPos(int(R * 255.0f), int(G * 255.0f), int(B * 255.0f));
    }

    inline Color Color::fromBlockPos(BedrockServer::BlockPos% k)
    {
        return  Color(k.X / 255.0f, k.Y / 255.0f, k.Z / 255.0f, 1.0f);
    }

    inline bool Color::operator!=(const Color& c)
    {
        return !(c == *this);
    }

    inline Color Color::operator*(Color obj, float c)
    {
        return Color{ obj.R * c, obj.G * c, obj.B * c, obj.A * c };
    }

    inline Color Color::operator/(Color obj, float c)
    {
        return Color{ obj.R / c, obj.G / c, obj.B / c, obj.A / c };
    }

    inline Color Color::operator+(Color obj, float c)
    {
        return Color{ obj.R + c, obj.G + c, obj.B + c, obj.A + c };
    }

    inline Color Color::operator-(Color obj, float c)
    {
        return Color{ obj.R - c, obj.G - c, obj.B - c, obj.A - c };
    }

    inline Color Color::operator+(Color obj, Color c)
    {
        return Color{ obj.R + c.R, obj.G + c.G, obj.B + c.B, obj.A + c.A };
    }

    inline Color Color::operator*(Color obj, Color c)
    {
        return Color{ obj.R * c.R, obj.G * c.G, obj.B * c.B, obj.A * c.A };
    }

    inline Color Color::operator/(Color obj, Color c)
    {
        return Color{ obj.R / c.R, obj.G / c.G, obj.B / c.B, obj.A / c.A };
    }

    inline Color Color::operator-(Color obj, Color c)
    {
        return Color{ obj.R - c.R, obj.G - c.G, obj.B - c.B, obj.A - c.A };
    }

    inline Color Color::Max(Color% k, Color% l)
    {
        pin_ptr<Color> pk = &k;
        pin_ptr<Color> pl = &l;
        return ::mce::Color::max(*(::mce::Color*)pk, *(::mce::Color*)pl);
    }

    inline Color Color::Min(Color% k, Color% l)
    {
        pin_ptr<Color> pk = &k;
        pin_ptr<Color> pl = &l;
        return ::mce::Color::min(*(::mce::Color*)pk, *(::mce::Color*)pl);
    }

    inline Color Color::Lerp(Color% k, Color% l, float m)
    {
        return k * (1.0f - m) + l * m;
    }

    inline Color Color::Mix(Color% k, Color% l, float m)
    {
        return Lerp(k, l, m);
    }

    inline int Color::GetHashCode()
    {
        return (int)HashVal;
    }

    inline size_t Color::HashVal::get()
    {
        pin_ptr<Color> p = this;
        std::hash<::mce::Color> hash;
        return hash(*(::mce::Color*)p);
    }
}