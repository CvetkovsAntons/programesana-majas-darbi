namespace _1uzd
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
            circleButton = new RadioButton();
            squareButton = new RadioButton();
            label1 = new Label();
            label2 = new Label();
            n = new TextBox();
            drawButton = new Button();
            pictureBox1 = new PictureBox();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            SuspendLayout();
            // 
            // circleButton
            // 
            circleButton.AutoSize = true;
            circleButton.Location = new Point(21, 44);
            circleButton.Name = "circleButton";
            circleButton.Size = new Size(55, 19);
            circleButton.TabIndex = 0;
            circleButton.TabStop = true;
            circleButton.Text = "Circle";
            circleButton.UseVisualStyleBackColor = true;
            circleButton.CheckedChanged += circleButton_CheckedChanged;
            // 
            // squareButton
            // 
            squareButton.AutoSize = true;
            squareButton.Location = new Point(82, 44);
            squareButton.Name = "squareButton";
            squareButton.Size = new Size(61, 19);
            squareButton.TabIndex = 1;
            squareButton.TabStop = true;
            squareButton.Text = "Square";
            squareButton.UseVisualStyleBackColor = true;
            squareButton.CheckedChanged += squareButton_CheckedChanged;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point);
            label1.Location = new Point(12, 9);
            label1.Name = "label1";
            label1.Size = new Size(78, 32);
            label1.TabIndex = 2;
            label1.Text = "1. uzd";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(149, 46);
            label2.Name = "label2";
            label2.Size = new Size(19, 15);
            label2.TabIndex = 3;
            label2.Text = "N:";
            // 
            // n
            // 
            n.Location = new Point(165, 43);
            n.Name = "n";
            n.Size = new Size(100, 23);
            n.TabIndex = 4;
            n.TextChanged += n_TextChanged;
            n.KeyPress += n_KeyPress;
            // 
            // drawButton
            // 
            drawButton.Location = new Point(271, 43);
            drawButton.Name = "drawButton";
            drawButton.Size = new Size(75, 23);
            drawButton.TabIndex = 5;
            drawButton.Text = "Draw";
            drawButton.UseVisualStyleBackColor = true;
            drawButton.Click += drawButton_Click;
            // 
            // pictureBox1
            // 
            pictureBox1.BackColor = Color.White;
            pictureBox1.Location = new Point(21, 69);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(325, 325);
            pictureBox1.TabIndex = 6;
            pictureBox1.TabStop = false;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(368, 414);
            Controls.Add(pictureBox1);
            Controls.Add(drawButton);
            Controls.Add(n);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(squareButton);
            Controls.Add(circleButton);
            Name = "Form1";
            Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private RadioButton circleButton;
        private RadioButton squareButton;
        private Label label1;
        private Label label2;
        private TextBox n;
        private Button drawButton;
        private PictureBox pictureBox1;
    }
}