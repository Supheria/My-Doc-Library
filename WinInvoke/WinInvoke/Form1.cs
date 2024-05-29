using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinInvoke
{
    public partial class Form1 : Form
    {
        private const string dllPath = @"WinDLL.dll";

        [DllImport(dllPath, EntryPoint = "DrawGraph", CallingConvention = CallingConvention.Cdecl)]
        public unsafe static extern int DrawGraph(int width, int height, IntPtr mhwnd);
        public Form1()
        {
            InitializeComponent();
        }

        private void pb_Img_Paint(object sender, PaintEventArgs e)
        {
            var hdc = e.Graphics.GetHdc();
            DrawGraph(pb_Img.Width, pb_Img.Height, hdc);
            e.Graphics.ReleaseHdc(hdc);
        }
    }
}
