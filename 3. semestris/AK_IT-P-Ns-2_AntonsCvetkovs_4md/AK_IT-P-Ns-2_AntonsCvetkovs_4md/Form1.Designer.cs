namespace AK_IT_P_Ns_2_AntonsCvetkovs_4md
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            flowLayoutPanel1 = new FlowLayoutPanel();
            penIcon = new PictureBox();
            lineIcon = new PictureBox();
            eraserIcon = new PictureBox();
            rectangleIcon = new PictureBox();
            ellipseIcon = new PictureBox();
            colorButton = new Button();
            pictureBox1 = new PictureBox();
            menuStrip1 = new MenuStrip();
            newMenu = new ToolStripMenuItem();
            openMenu = new ToolStripMenuItem();
            saveMenu = new ToolStripMenuItem();
            printMenu = new ToolStripMenuItem();
            flowLayoutPanel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)penIcon).BeginInit();
            ((System.ComponentModel.ISupportInitialize)lineIcon).BeginInit();
            ((System.ComponentModel.ISupportInitialize)eraserIcon).BeginInit();
            ((System.ComponentModel.ISupportInitialize)rectangleIcon).BeginInit();
            ((System.ComponentModel.ISupportInitialize)ellipseIcon).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            menuStrip1.SuspendLayout();
            SuspendLayout();
            // 
            // flowLayoutPanel1
            // 
            flowLayoutPanel1.BackColor = SystemColors.InactiveCaption;
            flowLayoutPanel1.Controls.Add(penIcon);
            flowLayoutPanel1.Controls.Add(lineIcon);
            flowLayoutPanel1.Controls.Add(eraserIcon);
            flowLayoutPanel1.Controls.Add(rectangleIcon);
            flowLayoutPanel1.Controls.Add(ellipseIcon);
            flowLayoutPanel1.Controls.Add(colorButton);
            flowLayoutPanel1.Dock = DockStyle.Right;
            flowLayoutPanel1.Location = new Point(1061, 24);
            flowLayoutPanel1.Name = "flowLayoutPanel1";
            flowLayoutPanel1.Size = new Size(200, 643);
            flowLayoutPanel1.TabIndex = 0;
            // 
            // penIcon
            // 
            penIcon.Image = (Image)resources.GetObject("penIcon.Image");
            penIcon.Location = new Point(3, 3);
            penIcon.Name = "penIcon";
            penIcon.Size = new Size(50, 50);
            penIcon.SizeMode = PictureBoxSizeMode.Zoom;
            penIcon.TabIndex = 1;
            penIcon.TabStop = false;
            penIcon.Tag = "";
            penIcon.Click += selectTool;
            // 
            // lineIcon
            // 
            lineIcon.Image = (Image)resources.GetObject("lineIcon.Image");
            lineIcon.Location = new Point(59, 3);
            lineIcon.Name = "lineIcon";
            lineIcon.Size = new Size(50, 50);
            lineIcon.SizeMode = PictureBoxSizeMode.Zoom;
            lineIcon.TabIndex = 3;
            lineIcon.TabStop = false;
            lineIcon.Tag = "";
            lineIcon.Click += selectTool;
            // 
            // eraserIcon
            // 
            eraserIcon.Image = (Image)resources.GetObject("eraserIcon.Image");
            eraserIcon.Location = new Point(115, 3);
            eraserIcon.Name = "eraserIcon";
            eraserIcon.Size = new Size(50, 50);
            eraserIcon.SizeMode = PictureBoxSizeMode.Zoom;
            eraserIcon.TabIndex = 4;
            eraserIcon.TabStop = false;
            eraserIcon.Tag = "";
            eraserIcon.Click += selectTool;
            // 
            // rectangleIcon
            // 
            rectangleIcon.Image = (Image)resources.GetObject("rectangleIcon.Image");
            rectangleIcon.Location = new Point(3, 59);
            rectangleIcon.Name = "rectangleIcon";
            rectangleIcon.Size = new Size(50, 50);
            rectangleIcon.SizeMode = PictureBoxSizeMode.Zoom;
            rectangleIcon.TabIndex = 5;
            rectangleIcon.TabStop = false;
            rectangleIcon.Tag = "";
            rectangleIcon.Click += selectTool;
            // 
            // ellipseIcon
            // 
            ellipseIcon.Image = (Image)resources.GetObject("ellipseIcon.Image");
            ellipseIcon.Location = new Point(59, 59);
            ellipseIcon.Name = "ellipseIcon";
            ellipseIcon.Size = new Size(50, 50);
            ellipseIcon.SizeMode = PictureBoxSizeMode.Zoom;
            ellipseIcon.TabIndex = 2;
            ellipseIcon.TabStop = false;
            ellipseIcon.Tag = "";
            ellipseIcon.Click += selectTool;
            // 
            // colorButton
            // 
            colorButton.ImageAlign = ContentAlignment.TopRight;
            colorButton.Location = new Point(3, 115);
            colorButton.Name = "colorButton";
            colorButton.Size = new Size(194, 46);
            colorButton.TabIndex = 0;
            colorButton.Text = "Color Picker";
            colorButton.UseVisualStyleBackColor = true;
            colorButton.Click += colorButton_Click;
            // 
            // pictureBox1
            // 
            pictureBox1.BackColor = SystemColors.ControlLightLight;
            pictureBox1.Location = new Point(12, 27);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(1033, 637);
            pictureBox1.TabIndex = 1;
            pictureBox1.TabStop = false;
            pictureBox1.MouseDown += pictureBox1_MouseDown;
            pictureBox1.MouseMove += pictureBox1_MouseMove;
            pictureBox1.MouseUp += pictureBox1_MouseUp;
            // 
            // menuStrip1
            // 
            menuStrip1.Items.AddRange(new ToolStripItem[] { newMenu, openMenu, saveMenu, printMenu });
            menuStrip1.Location = new Point(0, 0);
            menuStrip1.Name = "menuStrip1";
            menuStrip1.Size = new Size(1261, 24);
            menuStrip1.TabIndex = 2;
            menuStrip1.Text = "menuStrip1";
            // 
            // newMenu
            // 
            newMenu.Name = "newMenu";
            newMenu.Size = new Size(43, 20);
            newMenu.Text = "New";
            newMenu.Click += menuClick;
            // 
            // openMenu
            // 
            openMenu.Name = "openMenu";
            openMenu.Size = new Size(48, 20);
            openMenu.Text = "Open";
            openMenu.Click += menuClick;
            // 
            // saveMenu
            // 
            saveMenu.Name = "saveMenu";
            saveMenu.Size = new Size(43, 20);
            saveMenu.Text = "Save";
            saveMenu.Click += menuClick;
            // 
            // printMenu
            // 
            printMenu.Name = "printMenu";
            printMenu.Size = new Size(44, 20);
            printMenu.Text = "Print";
            printMenu.Click += menuClick;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.ControlLight;
            ClientSize = new Size(1261, 667);
            Controls.Add(pictureBox1);
            Controls.Add(flowLayoutPanel1);
            Controls.Add(menuStrip1);
            MainMenuStrip = menuStrip1;
            Name = "Form1";
            Text = "Form1";
            flowLayoutPanel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)penIcon).EndInit();
            ((System.ComponentModel.ISupportInitialize)lineIcon).EndInit();
            ((System.ComponentModel.ISupportInitialize)eraserIcon).EndInit();
            ((System.ComponentModel.ISupportInitialize)rectangleIcon).EndInit();
            ((System.ComponentModel.ISupportInitialize)ellipseIcon).EndInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            menuStrip1.ResumeLayout(false);
            menuStrip1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private FlowLayoutPanel flowLayoutPanel1;
        private Button colorButton;
        private PictureBox penIcon;
        private PictureBox lineIcon;
        private PictureBox eraserIcon;
        private PictureBox rectangleIcon;
        private PictureBox ellipseIcon;
        private PictureBox pictureBox1;
        private MenuStrip menuStrip1;
        private ToolStripMenuItem newMenu;
        private ToolStripMenuItem openMenu;
        private ToolStripMenuItem saveMenu;
        private ToolStripMenuItem printMenu;
    }
}