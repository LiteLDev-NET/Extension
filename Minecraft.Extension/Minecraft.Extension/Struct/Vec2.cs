using System.Numerics;
using System.Runtime.InteropServices;

namespace Minecraft;

[StructLayout(LayoutKind.Sequential)]
public unsafe struct Vec2
{
    public float X;
    public float Y;


    public Vec2(Vector2 v)
    {
        X = v.X;
        Y = v.Y;
    }

    public Vec2(float a, float b)
    {
        X = a;
        Y = b;
    }

    public override string ToString()
    {
        return $"{X},{Y}";
    }

    public static Vec2 operator *(Vec2 v, float num)
        => new(v.X * num, v.Y * num);


    public static Vec2 operator +(Vec2 v1, Vec2 v2)
        => new(v1.X + v2.X, v1.Y + v2.Y);

    public static Vec2 operator -(Vec2 v1, Vec2 v2)
        => new(v1.X - v2.X, v1.Y - v2.Y);

    public static implicit operator Vector2(Vec2 vec)
        => new(vec.X, vec.Y);

    public static implicit operator Vec2(Vector2 vec)
        => new(vec);

    static Vec2()
    {
        LOWEST_ptr = (Vec2*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(LOWEST)}@Vec2@@2V1@B");
        MAX_ptr = (Vec2*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(MAX)}@Vec2@@2V1@B");
        MIN_ptr = (Vec2*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(MIN)}@Vec2@@2V1@B");
        NEG_UNIT_X_ptr = (Vec2*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(NEG_UNIT_X)}@Vec2@@2V1@B");
        NEG_UNIT_Y_ptr = (Vec2*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(NEG_UNIT_Y)}@Vec2@@2V1@B");
        ONE_ptr = (Vec2*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(ONE)}@Vec2@@2V1@B");
        UNIT_X_ptr = (Vec2*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(UNIT_X)}@Vec2@@2V1@B");
        UNIT_Y_ptr = (Vec2*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(UNIT_Y)}@Vec2@@2V1@B");
        ZERO_ptr = (Vec2*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(ZERO)}@Vec2@@2V1@B");
    }

    public static Vec2 LOWEST => *LOWEST_ptr;
    public static Vec2 MAX => *MAX_ptr;
    public static Vec2 MIN => *MIN_ptr;
    public static Vec2 NEG_UNIT_X => *NEG_UNIT_X_ptr;
    public static Vec2 NEG_UNIT_Y => *NEG_UNIT_Y_ptr;
    public static Vec2 ONE => *ONE_ptr;
    public static Vec2 UNIT_X => *UNIT_X_ptr;
    public static Vec2 UNIT_Y => *UNIT_Y_ptr;
    public static Vec2 ZERO => *ZERO_ptr;

    private static readonly Vec2* LOWEST_ptr;
    private static Vec2* MAX_ptr;
    private static Vec2* MIN_ptr;
    private static Vec2* NEG_UNIT_X_ptr;
    private static Vec2* NEG_UNIT_Y_ptr;
    private static Vec2* ONE_ptr;
    private static Vec2* UNIT_X_ptr;
    private static Vec2* UNIT_Y_ptr;
    private static Vec2* ZERO_ptr;
}
