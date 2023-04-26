#pragma once
#include <mc/mce.hpp>
#include "Types.hpp"
namespace BedrockServer::Mce
{
    [StructLayout(LayoutKind::Sequential)]
    public value class UUID
    {
        uint64_t a;
        uint64_t b;

    public:
        UUID(uint64_t a, uint64_t b) : a(a), b(b) {}

        ref_std_string^ AsString()
        {
            pin_ptr<UUID> ptr = this;
            auto pStr = new std::string(reinterpret_cast<::mce::UUID*>(ptr)->asString());
            return gcnew ref_std_string(nint_t(pStr), true);
        }

        static UUID FromString(ref_std_string^ str)
        {
            return *reinterpret_cast<UUID*>(
                &::mce::UUID::fromString(*static_cast<std::string*>((void*)str->NativePointer)));
        }

        property bool IsEmpty
        {
            bool get()
            {
                pin_ptr<UUID> ptr = this;
                return reinterpret_cast<::mce::UUID*>(ptr)->isEmpty();
            }
        }

        static UUID SeedFromString(ref_std_string^ str)
        {
            return *reinterpret_cast<UUID*>(
                &::mce::UUID::seedFromString(*static_cast<std::string*>((void*)str->NativePointer)));
        }

        static initonly UUID EMPTY = *reinterpret_cast<UUID*>(&::mce::UUID::EMPTY);

        static operator bool(UUID id)
        {
            return id.IsEmpty;
        }

        virtual String^ ToString() override
        {
            return AsString()->ToString();
        }
    };

    public enum class ColorPalette
    {
        BLACK,
        INDIGO,
        LAVENDER,
        TEAL,
        COCOA,
        DARK,
        OATMEAL,
        WHITE,
        RED,
        APRICOT,
        YELLOW,
        GREEN,
        VATBLUE,
        SLATE,
        PINK,
        FAWN,
    };

    [StructLayout(LayoutKind::Sequential, Size = sizeof(::mce::Color))]
    public value class Color
    {
    internal:
        operator ::mce::Color();
        static operator Color(::mce::Color const& obj)
        {
            return Color(obj.r, obj.g, obj.b, obj.a);
        }
    public:
        float R;
        float G;
        float B;
        float A;
    public:
        Color(float r, float g, float b, float a);
        Color(float r, float g, float b);
        Color(int ir, int ig, int ib, int ia);
        Color(int ir, int ig, int ib);

        static operator bool(Color obj);

        double DistanceTo(Color% obj);
        String^ ToConsoleCode(bool foreground);
        String^ ToConsoleCode();
        String^ ToNearestColorCode();
        static Color FromConsoleCode(String^ str);
        static Color FromColorCode(String^ str);
        Color sRGBToLinear();
        Color LinearTosRGB();
        Color LinearToXYZ();
        Color XYZToLinear();
        Color XYZToLab();
        Color LabToXYZ();
        double DeltaE76(Color% obj);
        double DeltaE94(Color% obj);
        double DeltaE00(Color% obj);
        static Color FromHexString(String^ str);
        static bool operator==(Color a, Color b);
        int ToABGR();
        int ToARGB();
        String^ ToHexString();
        inline BedrockServer::Vec3 ToVec3();
        inline static Color FromVec3(BedrockServer::Vec3% k);
        inline  BedrockServer::BlockPos ToBlockPos();
        inline static Color fromBlockPos(BedrockServer::BlockPos% k);
        inline bool operator!=(const Color& c);
        static Color operator*(Color obj, float c);
        static Color operator/(Color obj, float c);
        static Color operator+(Color obj, float c);
        static Color operator-(Color obj, float c);
        static Color operator+(Color obj, Color c);
        static Color operator*(Color obj, Color c);
        static Color operator/(Color obj, Color c);
        static Color operator-(Color obj, Color c);
        inline static Color Max(Color% k, Color% l);
        inline static Color Min(Color% k, Color% l);
        inline static Color Lerp(Color% k, Color% l, float m);
        inline static Color Mix(Color% k, Color% l, float m);
        property size_t HashVal
        {
            size_t get();
        }
        int GetHashCode() override;

        static operator System::Drawing::Color(Color c)
        {
            return System::Drawing::Color::FromArgb(static_cast<int>(c.A * 255.0f), static_cast<int>(c.R * 255.0f), static_cast<int>(c.G * 255.0f), static_cast<int>(c.B * 255.0f));
        }

        static operator Color(System::Drawing::Color c)
        {
            return Color(c.R, c.G, c.B, c.A);
        }
    public:
        static Color NIL = ::mce::Color::NIL;
    };
}

