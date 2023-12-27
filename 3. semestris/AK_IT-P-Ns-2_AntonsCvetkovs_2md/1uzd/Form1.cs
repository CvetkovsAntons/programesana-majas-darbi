using System.Drawing;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Windows.Forms;
using System.Windows.Forms.VisualStyles;

namespace _1uzd
{
    public partial class Form1 : Form
    {
        private const string KW_CIRCLE = "circle";
        private const string KW_SQUARE = "square";
        private const double FACTOR = 0.5;
        private const int INITITAL_RADIUS = 81;

        private string? selected_form = null;
        private int recurssion_depth = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void circleButton_CheckedChanged(object sender, EventArgs e)
        {
            selected_form = KW_CIRCLE; // iveleta figura ir aplis
            drawAllowed();
        }

        private void squareButton_CheckedChanged(object sender, EventArgs e)
        {
            selected_form = KW_SQUARE; // izveleta figura ir kvadrats
            drawAllowed();
        }

        private void n_TextChanged(object sender, EventArgs e)
        {
            drawAllowed();
        }

        private void n_KeyPress(object sender, KeyPressEventArgs e)
        {
            // N ievades parbaude. Ja N ir tusks, tad nevar ievadit 0
            if (n.TextLength == 0 && e.KeyChar == '0' || n.TextLength == 9) e.Handled = true;
            // var ievadit tiaki ciparus no 0 lidz 9 un backspace
            else e.Handled = !(char.IsDigit(e.KeyChar) || e.KeyChar == 8);
        }

        private void drawAllowed()
        {
            // ja ir izveleta figura in ir ievadits N un tad ir > 0, tad iesledzam Draw pogu
            if (selected_form != null && n.TextLength > 0 && int.Parse(n.Text) > 0) drawButton.Enabled = true;
            else drawButton.Enabled = false;
        }

        private void drawButton_Click(object sender, EventArgs e)
        {
            recurssion_depth = int.Parse(n.Text);

            Graphics picture_box = pictureBox1.CreateGraphics();
            picture_box.Clear(Color.White); // nodzesam pictureBox

            if (selected_form == KW_CIRCLE) drawCircle(picture_box, 162, 162, INITITAL_RADIUS);
            else drawSquare(picture_box, 0, 0, 0, 324);

            picture_box.Dispose();
        }
        // katram uzzimetam aplim, jauzzime jaunu 4 aplus utt.
        private void drawCircle(Graphics picture_box, int x, int y, int radius)
        {
            // sis nosacijums parbauda, vai pasreizejais aplis ir pietiekami liels, lai turpinatu rekursiju
            if (radius < Math.Pow(FACTOR, recurssion_depth) * INITITAL_RADIUS) return;
            // zimejam apli
            picture_box.DrawEllipse(Pens.Black, x - radius, y - radius, 2 * radius, 2 * radius);
            // jauna apla radius ir 2 reizes mazaks par iepreksa apla radiusu
            int new_radius = (int)(radius * FACTOR);
            drawCircle(picture_box, x - radius, y, new_radius); // zimejam 1. apli
            drawCircle(picture_box, x, y - radius, new_radius); // zimejam 2. apli
            drawCircle(picture_box, x + radius, y, new_radius); // zimejam 3. apli
            drawCircle(picture_box, x, y + radius, new_radius); // zimejam 4. apli
        }

        private void drawSquare(Graphics picture_box, int depth, int x, int y, int size)
        {
            // ja rekursijas daudzums ir vienads ar N, tad partraucam funkcijas darbu
            if (depth == recurssion_depth) return;
            
            if (depth % 2 == 0) // katrs nejauss atkartojums (sakam skaitit ar 0, tapec parbauda == 0)
            {
                picture_box.DrawLine(Pens.Black, x, y, x + size, y);
                picture_box.DrawLine(Pens.Black, x, y, x, y + size);
                picture_box.DrawLine(Pens.Black, x, y + size, x + size, y + size);
                picture_box.DrawLine(Pens.Black, x + size, y + size, x + size, y);
            }
            else // katrs 2,4 utt atkartojums (zimejam diagonalas linijas)
            {
                int offset = size / 2;
                picture_box.DrawLine(Pens.Black, x, y + offset, x + offset, y);
                picture_box.DrawLine(Pens.Black, x + offset, y, x + size, y + offset);
                picture_box.DrawLine(Pens.Black, x + size, y + offset, x + offset, y + size);
                picture_box.DrawLine(Pens.Black, x + offset, y + size, x, y + offset);
                x = y += size / 4;
            }
            // rekursivi izsaucam drawSquare funkciju ar jaunam vertibam
            drawSquare(picture_box, ++depth, x, y, depth % 2 == 0 ? size / 2 : size);
        }
    }
}