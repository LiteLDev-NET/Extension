global using static Minecraft.Extension.Global;

using LiteLoader.InterfaceAPI.Interop;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Minecraft.Extension;

internal class Global
{
    public unsafe static nint DlsymRealThrowIfNull<T>(string symbol)
        where T : Exception, new()
    {
        var ptr = Hook.dlsym_real(symbol);
        if (ptr == null)
            throw Activator.CreateInstance<T>();
        return (nint)ptr;
    }
}
