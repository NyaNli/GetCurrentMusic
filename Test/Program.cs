using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;

namespace Test
{
    class Program
    {
        [DllImport("GetCurrentMusic.dll")]
        public static extern void Refresh();
        [DllImport("GetCurrentMusic.dll", CharSet = CharSet.Unicode)]
        public static extern void GetSongInformation(StringBuilder text);
        [DllImport("GetCurrentMusic.dll")]
        public static extern bool GetAble();

        static void Main(string[] args)
        {
            StringBuilder txt = new StringBuilder(255, 255);
            while(true)
            {
                Thread.Sleep(1000);
                Console.Clear();
                if (GetAble())
                {
                    GetSongInformation(txt);
                    Console.WriteLine(txt.ToString());
                }
                else
                    Refresh();
            }
            return;
        }
    }
}
