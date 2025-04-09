/*
 * Temat: Filtr uwypuklaj¹cy
 * Data wykonania: 24.01.2025
 * Autor: Zuzanna Krzysztofik
 *  Semestr 5, Rok 3
 */

using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
namespace JaProjektGUI
{
    
    internal static class Program
    {
        
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            ApplicationConfiguration.Initialize();
            Application.Run(new EmbossingFilter());
        }
        [DllImport("CDll.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern void Cfunckja(IntPtr ptr, IntPtr ptr2, int start, int end, int width);
        [DllImport("ASMDll.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern void Procedura(IntPtr ptr, IntPtr ptr2, int start, int end, int width);

    }
}