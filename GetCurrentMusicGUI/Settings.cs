using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Text;
using System.Windows.Forms;
using System.Xml.Serialization;

namespace GetCurrentMusicGUI
{
    public partial class Settings : Form
    {
        NowPlaying playing = null;

        public Settings(NowPlaying playing)
        {
            InitializeComponent();
            this.playing = playing;
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            Hide();
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            API.NextSession();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            fontDialog1.Font = playing.GetLabel().Font;
            fontDialog1.ShowDialog();
            playing.GetLabel().Font = fontDialog1.Font;
        }

        private void Settings_Load(object sender, EventArgs e)
        {

        }

        private void Settings_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (e.CloseReason == CloseReason.UserClosing)
            {
                e.Cancel = true;
                Hide();
            }
        }

        private void Button3_Click_1(object sender, EventArgs e)
        {
            API.Refresh();
        }
    }
}
