using System.Numerics;
using System.Runtime.InteropServices;
using System.Security;

namespace BedrockServer;

[StructLayout(LayoutKind.Sequential)]
public unsafe struct Vec3
{
    internal float x;
    internal float y;
    internal float z;

    public float X { get => x; set => x = value; }
    public float Y { get => y; set => y = value; }
    public float Z { get => z; set => z = value; }

    public Vec3(Vector3 v)
    {
        x = v.X; y = v.Y; z = v.Z;
    }

    public Vec3(int x, int y, int z)
    {
        this.x = x; this.y = y; this.z = z;
    }

    public Vec3(float x, float y, float z)
    {
        this.x = x; this.y = y; this.z = z;
    }

    public Vec3(double x, double y, double z)
    {
        this.x = (float)x; this.y = (float)y; this.z = (float)z;
    }

    public unsafe double Length
        => Math.Sqrt(Dot(this, this));

    public static float Dot(Vec3 a, Vec3 b)
        => a.y * b.y + a.x * b.x + a.z * b.z;

    public Vec3 Abs()
    {
        [DllImport(BDS, EntryPoint = "?abs@Vec3@@QEBA?AV1@XZ")]
        [SuppressUnmanagedCodeSecurity]
        static extern Vec3 __invoke(ref Vec3 @this);

        return __invoke(ref this);
    }

    public Vec3 Ceil()
    {
        [DllImport(BDS, EntryPoint = "?ceil@Vec3@@QEBA?AV1@XZ")]
        [SuppressUnmanagedCodeSecurity]
        static extern Vec3 __invoke(ref Vec3 @this);

        return __invoke(ref this);
    }

    public unsafe Vec3 Floor(float num = 1.0f)
    {
        [DllImport(BDS, EntryPoint = "?floor@Vec3@@QEBA?AV1@M@Z")]
        [SuppressUnmanagedCodeSecurity]
        static extern Vec3 __invoke(ref Vec3 @this, float num);

        return __invoke(ref this, num);
    }

    public float DistanceToLineSquared(ref Vec3 a, ref Vec3 b)
    {
        [DllImport(BDS, EntryPoint = "?distanceToLineSquared@Vec3@@QEBAMAEBV1@0@Z")]
        [SuppressUnmanagedCodeSecurity]
        static extern float __invoke(ref Vec3 @this, ref Vec3 a, ref Vec3 b);

        return __invoke(ref this, ref a, ref b);
    }

    public bool IsNan
    {
        get
        {
            [DllImport(BDS, EntryPoint = "?isNan@Vec3@@QEBA_NXZ")]
            [return: MarshalAs(UnmanagedType.U1)]
            [SuppressUnmanagedCodeSecurity]
            static extern bool __invoke(ref Vec3 @this);

            return __invoke(ref this);
        }
    }

    public bool IsNear(ref Vec3 vec, float num)
    {
        [DllImport(BDS, EntryPoint = "?isNear@Vec3@@QEBA_NAEBV1@M@Z")]
        [return: MarshalAs(UnmanagedType.U1)]
        [SuppressUnmanagedCodeSecurity]
        static extern bool __invoke(ref Vec3 @this, ref Vec3 vec, float num);

        return __invoke(ref this, ref vec, num);
    }

    public unsafe float MaxComponent()
    {
        [DllImport(BDS, EntryPoint = "?maxComponent@Vec3@@QEBAMXZ")]
        [SuppressUnmanagedCodeSecurity]
        static extern float __invoke(ref Vec3 @this);

        return __invoke(ref this);
    }

    public unsafe Vec3 Normalized()
    {
        [DllImport(BDS, EntryPoint = "?normalized@Vec3@@QEBA?AV1@XZ")]
        [SuppressUnmanagedCodeSecurity]
        static extern Vec3 __invoke(ref Vec3 @this);

        return __invoke(ref this);
    }

    public unsafe Vec3 XZ()
    {
        [DllImport(BDS, EntryPoint = "?xz@Vec3@@QEBA?AV1@XZ")]
        [SuppressUnmanagedCodeSecurity]
        static extern Vec3 __invoke(ref Vec3 @this);

        return __invoke(ref this);
    }

    public static unsafe Vec3 Clamp(ref Vec3 a, ref Vec3 b, ref Vec3 c)
    {
        [DllImport(BDS, EntryPoint = "?clamp@Vec3@@SA?AV1@AEBV1@00@Z")]
        [SuppressUnmanagedCodeSecurity]
        static extern Vec3 __invoke(ref Vec3 a, ref Vec3 b, ref Vec3 c);

        return __invoke(ref a, ref b, ref c);
    }

    public static unsafe Vec3 DirectionFromRotation(ref Vec2 vec)
    {
        [DllImport(BDS, EntryPoint = "?directionFromRotation@Vec3@@SA?AV1@AEBVVec2@@@Z")]
        [SuppressUnmanagedCodeSecurity]
        static extern Vec3 __invoke(ref Vec2 vec);

        return __invoke(ref vec);
    }

    public static unsafe Vec3 RotationFromDirection(ref Vec3 vec)
    {
        [DllImport(BDS, EntryPoint = "?rotationFromDirection@Vec3@@SA?AVVec2@@AEBV1@@Z")]
        [SuppressUnmanagedCodeSecurity]
        static extern Vec3 __invoke(ref Vec3 vec);

        return __invoke(ref vec);
    }

    private static Vec3* HALF_ptr;

    private static Vec3* MAX_ptr;

    private static Vec3* MIN_ptr;

    private static Vec3* NEG_UNIT_X_ptr;

    private static Vec3* NEG_UNIT_Y_ptr;

    private static Vec3* NEG_UNIT_Z_ptr;

    private static Vec3* ONE_ptr;

    private static Vec3* TWO_ptr;

    private static Vec3* UNIT_X_ptr;

    private static Vec3* UNIT_Y_ptr;

    private static Vec3* UNIT_Z_ptr;

    private static Vec3* ZERO_ptr;

    private static Vec3 HALF => *HALF_ptr;

    private static Vec3 MAX => *MAX_ptr;

    private static Vec3 MIN => *MIN_ptr;

    private static Vec3 NEG_UNIT_X => *NEG_UNIT_X_ptr;

    private static Vec3 NEG_UNIT_Y => *NEG_UNIT_Y_ptr;

    private static Vec3 NEG_UNIT_Z => *NEG_UNIT_Z_ptr;

    private static Vec3 ONE => *ONE_ptr;

    private static Vec3 TWO => *TWO_ptr;

    private static Vec3 UNIT_X => *UNIT_X_ptr;

    private static Vec3 UNIT_Y => *UNIT_Y_ptr;

    private static Vec3 UNIT_Z => *UNIT_Z_ptr;

    private static Vec3 ZERO => *ZERO_ptr;

    static Vec3()
    {
        HALF_ptr = (Vec3*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(HALF)}@Vec3@@2V1@B");
        MAX_ptr = (Vec3*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(MAX)}@Vec3@@2V1@B");
        MIN_ptr = (Vec3*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(MIN)}@Vec3@@2V1@B");
        NEG_UNIT_X_ptr = (Vec3*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(NEG_UNIT_X)}@Vec3@@2V1@B");
        NEG_UNIT_Y_ptr = (Vec3*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(NEG_UNIT_Y)}@Vec3@@2V1@B");
        NEG_UNIT_Z_ptr = (Vec3*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(NEG_UNIT_Z)}@Vec3@@2V1@B");
        UNIT_X_ptr = (Vec3*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(UNIT_X)}@Vec3@@2V1@B");
        UNIT_Y_ptr = (Vec3*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(UNIT_Y)}@Vec3@@2V1@B");
        UNIT_Z_ptr = (Vec3*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(UNIT_Z)}@Vec3@@2V1@B");
        ZERO_ptr = (Vec3*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(ZERO)}@Vec3@@2V1@B");
    }

    public static Vec3 operator *(Vec3 lhs, Vec3 rhs)
        => new(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);

    public static Vec3 operator *(Vec3 vec, float num)
        => new(vec.x * num, vec.y * num, vec.z * num);

    public static Vec3 operator /(Vec3 lhs, Vec3 rhs)
        => new(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);

    public static Vec3 operator /(Vec3 vec, float num)
        => new(vec.x / num, vec.y / num, vec.z / num);

    public static Vec3 operator +(Vec3 lhs, Vec3 rhs)
        => new(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);

    public static Vec3 operator +(Vec3 vec, float num)
        => new(vec.x + num, vec.y + num, vec.z + num);

    public static Vec3 operator -(Vec3 lhs, Vec3 rhs)
        => new(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);

    public static Vec3 operator -(Vec3 vec, float num)
        => new(vec.x - num, vec.y - num, vec.z - num);

    public static implicit operator Vector3(Vec3 vec)
        => new(vec.x, vec.y, vec.z);

    public static implicit operator Vec3(Vector3 vec)
        => new(vec);
}
