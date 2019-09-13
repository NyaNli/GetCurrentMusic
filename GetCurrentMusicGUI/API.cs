using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace GetCurrentMusicGUI
{
    class API
    {
        [DllImport("GetCurrentMusic.dll")]
        public static extern void Refresh();
        [DllImport("GetCurrentMusic.dll", CharSet = CharSet.Unicode)]
        public static extern void GetSongInformation(StringBuilder text);
        [DllImport("GetCurrentMusic.dll")]
        public static extern bool GetAble();
        [DllImport("GetCurrentMusic.dll")]
        public static extern void Init();
        [DllImport("GetCurrentMusic.dll")]
        public static extern void NextSession();
    }
}
