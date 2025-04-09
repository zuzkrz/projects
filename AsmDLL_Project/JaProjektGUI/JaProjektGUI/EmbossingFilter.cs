/*
 * Temat: Filtr uwypuklaj¹cy
 * Data wykonania: 24.01.2025
 * Autor: Zuzanna Krzysztofik
 *  Semestr 5, Rok 3
 */
using System.Diagnostics;
using System.Drawing.Imaging;
using System.Runtime.InteropServices;

namespace JaProjektGUI
{
    public partial class EmbossingFilter : Form
    {
        public EmbossingFilter()
        {
            InitializeComponent();
            SourceImage.Image = null;
        }
        //Funkcja do wybierania zdjecia do przetworzenia
        private void ImageSelectButton_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog
            {
                Title = "Wybierz obraz",
                Filter = "Obrazy (*.jpg;*.jpeg;*.png;*.bmp)|*.jpg;*.jpeg;*.png;*.bmp|Wszystkie pliki (*.*)|*.*",
                InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyPictures)
            };

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                Bitmap selectedImage = new Bitmap(openFileDialog.FileName);
                SourceImage.Image = selectedImage;
                this.sourcePath = openFileDialog.FileName;
            }
        }
        //Funkcja do zapisu przetworzonego zdjecia
        private void SaveButton_Click(object sender, EventArgs e)
        {
            if (ResultImage.Image != null) // Ensure there's an image to save
            {
                SaveFileDialog saveFileDialog = new SaveFileDialog
                {
                    Title = "Save Image As",
                    Filter = "JPEG Image (*.jpg)|*.jpg|PNG Image (*.png)|*.png|Bitmap Image (*.bmp)|*.bmp",
                    DefaultExt = "jpg",
                    AddExtension = true,
                    InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyPictures)
                };

                if (saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    try
                    {
                        // Save the image in the selected format
                        System.Drawing.Imaging.ImageFormat format;
                        switch (System.IO.Path.GetExtension(saveFileDialog.FileName).ToLower())
                        {
                            case ".png":
                                format = System.Drawing.Imaging.ImageFormat.Png;
                                break;
                            case ".bmp":
                                format = System.Drawing.Imaging.ImageFormat.Bmp;
                                break;
                            default:
                                format = System.Drawing.Imaging.ImageFormat.Jpeg;
                                break;
                        }

                        ResultImage.Image.Save(saveFileDialog.FileName, format);
                        MessageBox.Show("Image saved successfully!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show($"Error saving image: {ex.Message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                }
            }
            else
            {
                MessageBox.Show("There is no image to save!", "Warning", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }
        //Funkcja do fitrowania zdjecia
        private void FilterButton_Click(object sender, EventArgs e)
        {
            string selectedValue = ChooiceDll.SelectedItem.ToString();
            //Sprawdzenie czy zostaly wybrane i jakie: zdjecie, liczba watkow i DLL
            if ((int)NoThreadsSelected.Value > 0 && !IsPictureBoxEmpty(SourceImage) && (selectedValue == "ASM" || selectedValue == "C"))
            {
                Stopwatch stopwatch = new Stopwatch();
                Bitmap bitmap = new Bitmap(this.sourcePath);
                Bitmap resultBtm = new Bitmap(bitmap.Width, bitmap.Height);
                int height = bitmap.Height;
                int width = bitmap.Width;
                int noThreads = (int)NoThreadsSelected.Value;
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
                    if (selectedValue == "C")
                    {
                        Console.WriteLine("C");
                        threads[i] = new Thread(() => Program.Cfunckja(ptr, ptr2, start, end, width));
                    }
                    else if (selectedValue == "ASM")
                    {
                        Console.WriteLine("ASM");
                        threads[i] = new Thread(() => Program.Procedura(ptr, ptr2, start, end, width));
                    }

                    threads[i].Start();
                }
                foreach (Thread thread in threads)
                {
                    thread.Join();
                }
                stopwatch.Stop();
                bitmap.UnlockBits(bmpData);
                resultBtm.UnlockBits(rbmpData);
                Time2Label.Text = stopwatch.ElapsedMilliseconds.ToString() + "ms";
                ResultImage.Image = resultBtm;
            }
            else
            {

            }
        }
        //Funkcja dzielaca bitmape na rowne czesci
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
        //Funkcja sprawdzajaca czy zdjecie zostalo wybrane
        private bool IsPictureBoxEmpty(PictureBox pictureBox)
        {
            return pictureBox.Image == null;
        }
    }
}
