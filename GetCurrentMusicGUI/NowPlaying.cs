using System;
using System.Drawing;
using System.IO;
using System.Text;
using System.Windows.Forms;
using System.Xml.Serialization;

namespace GetCurrentMusicGUI
{

    public partial class NowPlaying : Form
    {

        StringBuilder txt = new StringBuilder(255, 255);
        Settings settings = null;

        public NowPlaying()
        {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if(API.GetAble())
            {
                API.GetSongInformation(txt);
                label1.Text = "当前播放: " + txt.ToString();
                Width = label1.Width;
                Height = label1.Height;
            }
            else
            {
                API.Refresh();
                label1.Text = "";
            }
        }

        private void NowPlaying_Load(object sender, EventArgs e)
        {
            label1.Left = 0;
            label1.Top = 0;
            settings = new Settings(this);
        }

        private void SettingItem_Click(object sender, EventArgs e)
        {
            settings.Show();
        }

        private void ExitItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void NotifyIcon1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            settings.Show();
        }

        public Label GetLabel()
        {
            return label1;
        }
    }
}
