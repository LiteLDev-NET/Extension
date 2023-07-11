using BedrockServer.Extension.Handle;
using LiteLoader.NET.InteropServices;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BedrockServer.Extension;

public class Mob : MobHandle, IConstructableCppClass<Mob>
{
    public Mob()
    {
    }

    public Mob(nint ptr, bool ownInstance) : base(ptr, ownInstance)
    {
    }

    public Mob ConstructInstance(nint ptr, bool ownsInstance)
    {
        return new(ptr, ownsInstance);
    }

    public void SetNativePointer(nint ptr, bool ownsInstance)
    {
        NativePointer = ptr;
        OwnsNativeInstance = ownsInstance;
    }
}
