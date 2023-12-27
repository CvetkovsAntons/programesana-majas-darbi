namespace _2un3uzd
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
            Label label1;
            quadraticButton = new RadioButton();
            rational1Button = new RadioButton();
            rational2Button = new RadioButton();
            groupBox1 = new GroupBox();
            groupBox2 = new GroupBox();
            cText = new TextBox();
            cLabel = new Label();
            bText = new TextBox();
            bLabel = new Label();
            aText = new TextBox();
            aLabel = new Label();
            groupBox3 = new GroupBox();
            stepText = new TextBox();
            step = new Label();
            x_endText = new TextBox();
            x_end = new Label();
            x_beginText = new TextBox();
            x_begin = new Label();
            tabulaButton = new Button();
            grafiksButton = new Button();
            table = new DataGridView();
            label1 = new Label();
            groupBox1.SuspendLayout();
            groupBox2.SuspendLayout();
            groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)table).BeginInit();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Dock = DockStyle.Left;
            label1.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point);
            label1.ImageAlign = ContentAlignment.TopRight;
            label1.Location = new Point(0, 0);
            label1.Margin = new Padding(0);
            label1.Name = "label1";
            label1.Size = new Size(78, 32);
            label1.TabIndex = 0;
            label1.Text = "2. uzd";
            // 
            // quadraticButton
            // 
            quadraticButton.AutoSize = true;
            quadraticButton.Location = new Point(6, 22);
            quadraticButton.Name = "quadraticButton";
            quadraticButton.Size = new Size(106, 19);
            quadraticButton.TabIndex = 2;
            quadraticButton.TabStop = true;
            quadraticButton.Text = "y = ax^2+bx+c";
            quadraticButton.UseVisualStyleBackColor = true;
            quadraticButton.CheckedChanged += quadraticButton_CheckedChanged;
            // 
            // rational1Button
            // 
            rational1Button.AutoSize = true;
            rational1Button.Location = new Point(6, 47);
            rational1Button.Name = "rational1Button";
            rational1Button.Size = new Size(116, 19);
            rational1Button.TabIndex = 3;
            rational1Button.TabStop = true;
            rational1Button.Text = "y = a/x^2+b/x+c";
            rational1Button.UseVisualStyleBackColor = true;
            rational1Button.CheckedChanged += rational1Button_CheckedChanged;
            // 
            // rational2Button
            // 
            rational2Button.AutoSize = true;
            rational2Button.Location = new Point(6, 72);
            rational2Button.Name = "rational2Button";
            rational2Button.Size = new Size(119, 19);
            rational2Button.TabIndex = 4;
            rational2Button.TabStop = true;
            rational2Button.Text = "y = (ax+b)/(ax+c)";
            rational2Button.UseVisualStyleBackColor = true;
            rational2Button.CheckedChanged += rational2Button_CheckedChanged;
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(quadraticButton);
            groupBox1.Controls.Add(rational2Button);
            groupBox1.Controls.Add(rational1Button);
            groupBox1.Location = new Point(0, 35);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(200, 100);
            groupBox1.TabIndex = 5;
            groupBox1.TabStop = false;
            groupBox1.Text = "Funkcija";
            // 
            // groupBox2
            // 
            groupBox2.Controls.Add(cText);
            groupBox2.Controls.Add(cLabel);
            groupBox2.Controls.Add(bText);
            groupBox2.Controls.Add(bLabel);
            groupBox2.Controls.Add(aText);
            groupBox2.Controls.Add(aLabel);
            groupBox2.Location = new Point(0, 141);
            groupBox2.Name = "groupBox2";
            groupBox2.Size = new Size(200, 100);
            groupBox2.TabIndex = 6;
            groupBox2.TabStop = false;
            groupBox2.Text = "Koeficienti";
            // 
            // cText
            // 
            cText.Location = new Point(39, 74);
            cText.Name = "cText";
            cText.Size = new Size(100, 23);
            cText.TabIndex = 5;
            cText.TextChanged += textChanged;
            cText.KeyPress += doubleInput;
            // 
            // cLabel
            // 
            cLabel.AutoSize = true;
            cLabel.Location = new Point(6, 77);
            cLabel.Name = "cLabel";
            cLabel.Size = new Size(27, 15);
            cLabel.TabIndex = 4;
            cLabel.Text = "c = ";
            // 
            // bText
            // 
            bText.Location = new Point(39, 45);
            bText.Name = "bText";
            bText.Size = new Size(100, 23);
            bText.TabIndex = 3;
            bText.TextChanged += textChanged;
            bText.KeyPress += doubleInput;
            // 
            // bLabel
            // 
            bLabel.AutoSize = true;
            bLabel.Location = new Point(6, 48);
            bLabel.Name = "bLabel";
            bLabel.Size = new Size(28, 15);
            bLabel.TabIndex = 2;
            bLabel.Text = "b = ";
            // 
            // aText
            // 
            aText.Location = new Point(39, 16);
            aText.Name = "aText";
            aText.Size = new Size(100, 23);
            aText.TabIndex = 1;
            aText.TextChanged += textChanged;
            aText.KeyPress += doubleInput;
            // 
            // aLabel
            // 
            aLabel.AutoSize = true;
            aLabel.Location = new Point(6, 19);
            aLabel.Name = "aLabel";
            aLabel.Size = new Size(27, 15);
            aLabel.TabIndex = 0;
            aLabel.Text = "a = ";
            // 
            // groupBox3
            // 
            groupBox3.Controls.Add(stepText);
            groupBox3.Controls.Add(step);
            groupBox3.Controls.Add(x_endText);
            groupBox3.Controls.Add(x_end);
            groupBox3.Controls.Add(x_beginText);
            groupBox3.Controls.Add(x_begin);
            groupBox3.Location = new Point(0, 247);
            groupBox3.Name = "groupBox3";
            groupBox3.Size = new Size(200, 100);
            groupBox3.TabIndex = 7;
            groupBox3.TabStop = false;
            groupBox3.Text = "Tabulas parametri";
            // 
            // stepText
            // 
            stepText.Location = new Point(74, 74);
            stepText.Name = "stepText";
            stepText.Size = new Size(100, 23);
            stepText.TabIndex = 5;
            stepText.TextChanged += textChanged;
            stepText.KeyPress += doubleInput;
            // 
            // step
            // 
            step.AutoSize = true;
            step.Location = new Point(6, 77);
            step.Name = "step";
            step.Size = new Size(44, 15);
            step.TabIndex = 4;
            step.Text = "Step = ";
            // 
            // x_endText
            // 
            x_endText.Location = new Point(74, 45);
            x_endText.Name = "x_endText";
            x_endText.Size = new Size(100, 23);
            x_endText.TabIndex = 3;
            x_endText.TextChanged += textChanged;
            x_endText.KeyPress += doubleInput;
            // 
            // x_end
            // 
            x_end.AutoSize = true;
            x_end.Location = new Point(6, 48);
            x_end.Name = "x_end";
            x_end.Size = new Size(52, 15);
            x_end.TabIndex = 2;
            x_end.Text = "x_End = ";
            // 
            // x_beginText
            // 
            x_beginText.Location = new Point(74, 16);
            x_beginText.Name = "x_beginText";
            x_beginText.Size = new Size(100, 23);
            x_beginText.TabIndex = 1;
            x_beginText.TextChanged += textChanged;
            x_beginText.KeyPress += doubleInput;
            // 
            // x_begin
            // 
            x_begin.AutoSize = true;
            x_begin.Location = new Point(6, 19);
            x_begin.Name = "x_begin";
            x_begin.Size = new Size(62, 15);
            x_begin.TabIndex = 0;
            x_begin.Text = "x_Begin = ";
            // 
            // tabulaButton
            // 
            tabulaButton.Enabled = false;
            tabulaButton.Location = new Point(218, 9);
            tabulaButton.Name = "tabulaButton";
            tabulaButton.Size = new Size(130, 23);
            tabulaButton.TabIndex = 8;
            tabulaButton.Text = "Tabula";
            tabulaButton.UseVisualStyleBackColor = true;
            tabulaButton.Click += tabulaButton_Click;
            // 
            // grafiksButton
            // 
            grafiksButton.Enabled = false;
            grafiksButton.Location = new Point(354, 9);
            grafiksButton.Name = "grafiksButton";
            grafiksButton.Size = new Size(124, 23);
            grafiksButton.TabIndex = 9;
            grafiksButton.Text = "Grafiks";
            grafiksButton.UseVisualStyleBackColor = true;
            grafiksButton.Click += grafiksButton_Click;
            // 
            // table
            // 
            table.AllowUserToAddRows = false;
            table.AllowUserToDeleteRows = false;
            table.AllowUserToResizeColumns = false;
            table.AllowUserToResizeRows = false;
            table.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            table.Location = new Point(218, 38);
            table.Name = "table";
            table.ReadOnly = true;
            table.RowTemplate.Height = 25;
            table.Size = new Size(260, 309);
            table.TabIndex = 10;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(487, 358);
            Controls.Add(table);
            Controls.Add(grafiksButton);
            Controls.Add(tabulaButton);
            Controls.Add(groupBox3);
            Controls.Add(groupBox2);
            Controls.Add(groupBox1);
            Controls.Add(label1);
            Name = "Form1";
            Text = "Form1";
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            groupBox2.ResumeLayout(false);
            groupBox2.PerformLayout();
            groupBox3.ResumeLayout(false);
            groupBox3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)table).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private RadioButton quadraticButton;
        private RadioButton rational1Button;
        private RadioButton rational2Button;
        private GroupBox groupBox1;
        private GroupBox groupBox2;
        private TextBox cText;
        private Label cLabel;
        private TextBox bText;
        private Label bLabel;
        private TextBox aText;
        private Label aLabel;
        private GroupBox groupBox3;
        private TextBox stepText;
        private Label step;
        private TextBox x_endText;
        private Label x_end;
        private TextBox x_beginText;
        private Label x_begin;
        private Button tabulaButton;
        private Button grafiksButton;
        private DataGridView table;
    }
}