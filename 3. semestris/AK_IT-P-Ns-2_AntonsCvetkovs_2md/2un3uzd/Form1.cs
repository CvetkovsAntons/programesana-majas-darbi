using System.Data;
using System.Xml.Serialization;

namespace _2un3uzd
{
    public partial class Form1 : Form
    {
        private const string QUADRATIC = "quadratic";
        private const string RATIONAL_1 = "rational1";
        private const string RATIONAL_2 = "rational2";

        private string? selected_function = null;
        private List<Row>? rows;
        Form2? f2 = null;

        public Form1()
        {
            InitializeComponent();
        }

        private void quadraticButton_CheckedChanged(object sender, EventArgs e)
        {
            selected_function = QUADRATIC; // iveleta funkcija ir kvadratiska
            drawAllowed();
        }

        private void rational1Button_CheckedChanged(object sender, EventArgs e)
        {
            selected_function = RATIONAL_1; // izveleta funkcija ir Math.Pow(a / x, 2) + b / x + c
            drawAllowed();
        }

        private void rational2Button_CheckedChanged(object sender, EventArgs e)
        {
            selected_function = RATIONAL_2; // (a * x + b) / (a * x + c)
            drawAllowed();
        }


        private void drawAllowed()
        {
            // ja ir izveleta funkcija un visas vertibas ir ievaditas, tad iesledzam pogas
            if (selected_function != null && aText.TextLength > 0 && bText.TextLength > 0 && cText.TextLength > 0 && x_beginText.TextLength > 0 && x_endText.TextLength > 0 && stepText.TextLength > 0)
            {
                grafiksButton.Enabled = tabulaButton.Enabled = true;
            }
        }

        private void textChanged(object sender, EventArgs e)
        {
            drawAllowed();
        }

        private void doubleInput(object sender, KeyPressEventArgs e)
        {
            TextBox text_box = (TextBox)sender;
            // parbaudam ciparu ievadi
            // ja laukums nav tukss, tad nevar ievadit - zimi
            if (text_box.TextLength > 0 && e.KeyChar == 45 || text_box.TextLength == 9) e.Handled = true;
            // var ievadit tiaki ciparus no 0 lidz 9, backspace un -
            else e.Handled = !(char.IsDigit(e.KeyChar) || e.KeyChar == 8 || e.KeyChar == 45);
        }

        private void tabulaButton_Click(object sender, EventArgs e)
        {
            double x = double.Parse(x_beginText.Text); // x_begin veritba
            double x_end = double.Parse(x_endText.Text);
            double step = double.Parse(stepText.Text);

            rows = new List<Row>(); // veidojam sarakstu ar punktiem (nosaukums ir Row, jo tas ir tabulas rindas)

            while (x <= x_end) // kamer x ir mazaks par x_end
            {
                rows.Add(new Row { x = x, y = getY(x) }); // pievinojam jaunu Rindu tabulaa
                x += step;
            }

            table.DataSource = rows; // tabula pievinojam DataSource
        }
        // funkcija atgriez Y vertibu
        private double getY(double x)
        {
            double a = double.Parse(aText.Text);
            double b = double.Parse(bText.Text);
            double c = double.Parse(cText.Text);

            if (selected_function == QUADRATIC)
            {
                return Functions.quadratic(a, b, c, x);
            }
            else if (selected_function == RATIONAL_1)
            {
                return Functions.rational1(a, b, c, x);
            }
            else
            {
                return Functions.rational2(a, b, c, x);
            }
        }

        private void grafiksButton_Click(object sender, EventArgs e)
        {
            tabulaButton.PerformClick(); // dabunam tabulas X un Y vertibas

            f2 = new Form2(); // veidojam jaunu formu
            f2.setRowsToDraw(rows, selected_function); // nodevam otraa formaa rindas un izveleto funkciju
            f2.ShowDialog(); // izvadam otru formu
        }
    }
}