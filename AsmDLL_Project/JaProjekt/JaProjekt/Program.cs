using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Drawing;
using System.Collections;
using System.Diagnostics;
using System.Drawing.Imaging;

namespace japrojekt
{
    internal class Program
    {
        static List<(int, int)> divideHeight(int noThreads, int height)
        {
            List<(int, int)> chunks = new List<(int, int)>();
            int temp = 1;
            if (noThreads == 1)
            {
                chunks.Add((0, height));
                return chunks;
            }
            if (noThreads == 2)
            {
                temp = height / 2;
                chunks.Add((0, temp + 1));
                chunks.Add((temp - 1, height));
                return chunks;
            }

            for (int i = 0; i < noThreads; i++)
            {
                if (i == 0)
                {
                    int beggining = 0;
                    int end = (height / noThreads + 1);
                    chunks.Add((beggining, end));
                    temp = end;
                }
                else if (i == (noThreads - 1))
                {
                    int beggining = temp - 2;
                    chunks.Add((beggining, height));
                }
                else
                {
                    int beggining = temp - 2;
                    int end = temp + (height / noThreads + 1);
                    chunks.Add((beggining, end));
                    temp = end;
                }
            }
            return chunks;
        }
        [DllImport(@"C:\Users\Zuza\Desktop\japrojekt\x64\Release\ASM.dll")]
        static extern void Procedura(IntPtr ptr, IntPtr ptr2, int width, int height, int start);

        [DllImport(@"C:\Users\Zuza\Desktop\japrojekt\x64\Release\CDLL.dll")]
        static extern void Cfunckja(IntPtr ptr, IntPtr ptr2, int start, int end, int width, int height);


        static void Main(string[] args)
        {
            Stopwatch stopwatch = new Stopwatch();
            Bitmap bitmap = new Bitmap("C:\\Users\\Zuza\\Desktop\\japrojekt\\test.jpg");
            Bitmap resultBtm = new Bitmap(bitmap.Width, bitmap.Height);
            using (Graphics g = Graphics.FromImage(resultBtm))
            {
                g.Clear(Color.Black);
            }
            int height = bitmap.Height;
            int width = bitmap.Width;   
            int noThreads = 1;
            
            List<(int, int)> dividedChunks = divideHeight(noThreads, height);
            BitmapData bmpData = bitmap.LockBits(new Rectangle(0, 0, width, height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            BitmapData rbmpData = resultBtm.LockBits(new Rectangle(0, 0, width, height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            IntPtr ptr = bmpData.Scan0;
            IntPtr ptr2 = rbmpData.Scan0;
            stopwatch.Start();
            
            Thread[] threads = new Thread[noThreads];
            
            for (int i = 0; i < noThreads; i++)
            {
                int start = dividedChunks[i].Item1;
                int end = dividedChunks[i].Item2;
                //threads[i] = new Thread(() => Cfunckja(ptr, ptr2, start, end, width, height));
                threads[i] = new Thread(() => Procedura(ptr, ptr2, start, end, width));


                threads[i].Start();
            }
            foreach (Thread thread in threads)
            {
                thread.Join();
            }


            stopwatch.Stop();
            bitmap.UnlockBits(bmpData);
            resultBtm.UnlockBits(rbmpData);

            Console.WriteLine("Ready, time it took: " + stopwatch.ElapsedMilliseconds + " ms");
            resultBtm.Save("C:\\Users\\Zuza\\Desktop\\japrojekt\\output.jpg");

        }
    }
}
