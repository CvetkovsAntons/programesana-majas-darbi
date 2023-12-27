using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;
using System.Security.Cryptography.Xml;
using System.Reflection;
using System.Diagnostics;

namespace _2un3uzd
{
    public partial class Form2 : Form
    {
        private const int offset = 200;

        private List<Row> rows;
        private string selected_function;

        public Form2()
        {
            InitializeComponent();
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            Graphics picture_box = e.Graphics;
            picture_box.DrawLine(Pens.Black, offset, 0, offset, 400); // uzziemjam Y skalu
            picture_box.DrawLine(Pens.Black, 0, offset, 400, offset); // uzzimejam X skalu

            for (int i = 0; i < rows.Count; i++)
            {
                if (i != rows.Count - 1)
                {
                    double x1 = rows[i].x; 
                    double y1 = (selected_function == "quadratic" ? (-rows[i].y) : rows[i].y); // ja funkcija ir kvadratiska, tad Y ir astpogulots
                    double x2 = rows[i + 1].x;
                    double y2 = (selected_function == "quadratic" ? (-rows[i + 1].y) : rows[i + 1].y); // ja funkcija ir kvadratiska, tad Y ir astpogulots

                    // izveidojam punktus, ja vertibas ir bezgaliga, tad ta vertiba ir vienada ar maksimalo grafika vertibu, ja NaN, tad 0 
                    x1 = double.IsNaN(x1) ? 0 : double.IsInfinity(x1) ? x1 > 0 ? 401 : -401 : x1;
                    y1 = double.IsNaN(y1) ? 0 : double.IsInfinity(y1) ? y1 > 0 ? 401 : -401 : y1;
                    x2 = double.IsNaN(x2) ? 0 : double.IsInfinity(x2) ? x2 > 0 ? 401 : -401 : x2;
                    y2 = double.IsNaN(y2) ? 0 : double.IsInfinity(y2) ? y2 > 0 ? 401 : -401 : y2;

                    Point point1 = new Point((int)x1 + offset, (int)y1 + offset); // izveidojam sakum punktu
                    Point point2 = new Point((int)x2 + offset, (int)y2 + offset); // izveidojam beigas punktu

                    picture_box.DrawLine(new Pen(Color.Red, 3), point1, point2); // zimejam liniju
                }
            }
        }

        private void Form2_Activated(object sender, EventArgs e)
        {
            pictureBox1.Paint += pictureBox1_Paint; // pievinjaom pictureBox paint eventu
        }

        public void setRowsToDraw(List<Row> rows, string selected_function)
        {
            this.rows = rows;
            this.selected_function = selected_function;
            Refresh();
        }
    }
}
