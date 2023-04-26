global using static BedrockServer.Global;

using LiteLoader.InterfaceAPI.Interop;
using System.Runtime.CompilerServices;

[assembly:InternalsVisibleTo("Minecraft.Extension")]
[assembly:InternalsVisibleTo("Minecraft.Extension.CppImpl")]

namespace BedrockServer;

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

    public const string BDS = "bedrock_server_mod.exe";
    public const string LiteLoader = "LiteLoader.dll";
}
