using System.Diagnostics;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using System.Drawing.Printing;
using System.Reflection;
using System.Reflection.Metadata;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace AK_IT_P_Ns_2_AntonsCvetkovs_4md
{
    public partial class Form1 : Form
    {
        const string PEN = "pen";
        const string LINE = "line";
        const string ERASER = "eraser";
        const string RECTANGLE = "rectangle";
        const string ELLIPSE = "ellipse";

        private string selected_tool = PEN;
        private bool mouse_down = false;

        private Color selected_color = Color.Black;
        private Point previous_point = Point.Empty; 

        private Bitmap? bitmap;
        private Graphics? graphic;

        private int default_width = 0;
        private int default_height = 0;

        public Form1()
        {
            InitializeComponent();
            default_width = pictureBox1.Width; 
            default_height = pictureBox1.Height;
            initializePictureBox();
        }

        private void initializePictureBox(Image? image = null)
        {
            if (image != null) // ja ir atverta bilde, tad zimesanas laukuma izmers bus vienads ar bildes izmeru un grafiks bus veidots no tas bildes
            {
                pictureBox1.Image = new Bitmap(image);
                graphic = Graphics.FromImage(pictureBox1.Image);
            }
            else  // ja bilde nav izveleta, tad zimesanas laukuma izmers bus standarts un fona krasa bus balta
            {
                bitmap = new Bitmap(default_width, default_height);
                graphic = Graphics.FromImage(bitmap);
                graphic.Clear(Color.White);
                pictureBox1.Image = bitmap;
            }

            pictureBox1.Width = image != null && pictureBox1.Image.Width <= default_width ? pictureBox1.Image.Width : default_width;
            pictureBox1.Height = image != null && pictureBox1.Image.Height <= default_height ? pictureBox1.Image.Height : default_height;
        }

        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            mouse_down = true;
            previous_point = e.Location; // saglabajam koorindates kuras bija nospiesta peles poga
        }

        private void pictureBox1_MouseUp(object sender, MouseEventArgs e)
        {
            mouse_down = false;
            try { 
                drawSwitch(sender, e);  // izsaucam linijas, ellipses un taisnstura zimesanu
            }
            catch (Exception ex) 
            { 
                showErrorMessageBox(ex, "Error drawing"); 
            }
            previous_point = Point.Empty;
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            try { // kad pele kustas un peles poga ir nospiesta, tad izsaucam pen un eraser zimesanu
                if (mouse_down && previous_point != Point.Empty) drawSwitch(sender, e);
            } 
            catch (Exception ex)
            {
                showErrorMessageBox(ex, "Error drawing");
            }
        }

        private void drawSwitch(object sender, MouseEventArgs e)
        {
            graphic.SmoothingMode = SmoothingMode.AntiAlias;
            // ja peles poga ir nopsiesta un izvelets riks ir PEN vai ERASER, tad izaucam attiecigo funkciju
            if (mouse_down && (selected_tool == PEN || selected_tool == ERASER))
            {
                drawPen(e, selected_tool == PEN ? selected_color : Color.White);
            } 
            else if (!mouse_down && (selected_tool == LINE || selected_tool == RECTANGLE || selected_tool == ELLIPSE))
            {   // ja peles poga nav nopsiesta un izvelets riks ir LINE vai RECTANGLE vai ELLIPSE, tad izaucam attiecigo funkciju
                switch (selected_tool)
                {
                    case LINE:
                        drawLine(e);
                        break;
                    case RECTANGLE:
                        drawRectangle(getCoorindates(e));
                        break;
                    case ELLIPSE:
                        drawEllipse(getCoorindates(e));
                        break;
                    default:
                        break;
                }
            }

            pictureBox1.Invalidate();
            graphic.SmoothingMode = SmoothingMode.Default;
        }

        private void drawPen(MouseEventArgs e, Color color) // funkcija atbild par PEN un ERASER zimesanu
        {
            // zimejam liniju, kura sakuma punkts ir koordinats, kad poga bija nospeista, un beigu koordinates ir kursora lokacija
            graphic.DrawLine(new Pen(color), previous_point, e.Location);
            previous_point = e.Location;
        }
        // funkcija atbild par taisna liniju zimesanu
        private void drawLine(MouseEventArgs e) { graphic.DrawLine(new Pen(selected_color), previous_point.X, previous_point.Y, e.Location.X, e.Location.Y); }
        // funkcija atbild par taisnstura zimesanu
        private void drawRectangle(Rectangle cords) { graphic.DrawRectangle(new Pen(selected_color), cords); }
        // funckija atbild par ellipses zimesanu
        private void drawEllipse(Rectangle cords) { graphic.DrawEllipse(new Pen(selected_color), cords); }

        private Rectangle getCoorindates(MouseEventArgs e) // funkcija atgriez taisntura vai eillipses sakuma koordinates un saurumu un augstumu
        {
            return new Rectangle(
                Math.Min(previous_point.X, e.Location.X), // x sakum koordinates
                Math.Min(previous_point.Y, e.Location.Y), // y sakum koordinates
                Math.Abs(e.Location.X - previous_point.X),// saurumus
                Math.Abs(e.Location.Y - previous_point.Y) // augstums
            );
        }

        private void menuClick(object sender, EventArgs e) // funkcija nostrada, kas tiek nospiesta menu poga
        {
            try
            {
                Console.Beep(); // izvadam skanu

                switch (((ToolStripMenuItem)sender).Text)
                {
                    case "New":
                        initializePictureBox();
                        break;
                    case "Open":
                        openFile();
                        break;
                    case "Save":
                        saveFile();
                        break;
                    case "Print":
                        printFile();
                        break;
                    default:
                        break;
                }    
            }
            catch (Exception ex)
            {
                showErrorMessageBox(ex, "Error opening file");
            }
        }

        private void openFile() // funkcija atbild par faila atversanu
        {
            OpenFileDialog file = new OpenFileDialog
            {
                Filter = "PNG Image (*.png)|*.png|JPEG Image (*.jpg)|*.jpg",
                Title = "Open Image"
            };

            if (file.ShowDialog() == DialogResult.OK) initializePictureBox(Image.FromFile(file.FileName));
        }

        private void saveFile() // funkcija atbild par faila saglabasanu
        {
            SaveFileDialog file = new SaveFileDialog
            {
                FileName = "untitled",
                Filter = "PNG Image (*.png)|*.png|JPEG Image (*.jpg)|*.jpg",
                Title = "Save Image"
            };

            if (file.ShowDialog() == DialogResult.OK) pictureBox1.Image.Save(file.FileName);
        }

        private void printFile() // funkcija atbild par faila printesanu
        {
            PrintDialog file = new PrintDialog() {
                Document = new PrintDocument(),
            };

            if (file.ShowDialog() == DialogResult.OK)
            {
                file.Document.PrintPage += new PrintPageEventHandler(PrintDocument_PrintPage);
                file.Document.Print();
            }
        }

        private void PrintDocument_PrintPage(object sender, PrintPageEventArgs e)
        {
            e.Graphics.DrawImage(pictureBox1.Image, 0, 0); // pievenojam zimejumu izprintetaa failaa
        }

        private void colorButton_Click(object sender, EventArgs e) // funkcija, kas atbild par krasas izveli
        {
            ColorDialog color_dialog = new ColorDialog
            {
                AllowFullOpen = true,
                AnyColor = true,
                SolidColorOnly = false,
                Color = selected_color
            };

            if (color_dialog.ShowDialog() == DialogResult.OK) selected_color = color_dialog.Color;
        }

        private void showErrorMessageBox(Exception e, string text) { MessageBox.Show($"{text}. Error: {e.Message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error); }

        private void selectTool(object sender, EventArgs e) { selected_tool = ((PictureBox)sender).Name.Replace("Icon", ""); }
    }
}