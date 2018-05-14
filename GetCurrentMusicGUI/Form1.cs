using System;
using System.Text;
using System.Windows.Forms;

namespace GetCurrentMusicGUI
{

    public partial class Form1 : Form
    {

        StringBuilder txt = new StringBuilder(255, 255);

        public Form1()
        {
            InitializeComponent();
            API.Init();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if(API.GetAble())
            {
                API.GetSongInformation(txt);
                label1.Text = "当前播放: " + txt.ToString();
            }
            else
            {
                API.Refresh();
                label1.Text = "";
            }
        }

        private void notifyIcon1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            Application.Exit();
        }
    }
}
