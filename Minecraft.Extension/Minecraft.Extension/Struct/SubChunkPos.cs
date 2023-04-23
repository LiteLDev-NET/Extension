using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Minecraft;

[StructLayout(LayoutKind.Sequential)]
public struct SubChunkPos
{
    public int X;
    public int Y;
    public int Z;

    public SubChunkPos(int x, int y, int z)
    {
        X = x;
        Y = y;
        Z = z;
    }
}
