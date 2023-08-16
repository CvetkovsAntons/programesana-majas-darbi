using System.Runtime.CompilerServices;

namespace AK_IT_P_Ns_AntonsCvetkovs_1md
{
    partial class Calculator
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
            ResultTextBox = new TextBox();
            BackspaceBtn = new Button();
            ClearBtn = new Button();
            ClearAllBtn = new Button();
            PlusMinusBtn = new Button();
            SqrtBtn = new Button();
            PercentBtn = new Button();
            DivideBtn = new Button();
            NineBtn = new Button();
            EightBtn = new Button();
            SevenBtn = new Button();
            FractionBtn = new Button();
            MultiplyBtn = new Button();
            SixBtn = new Button();
            FiveBtn = new Button();
            FourBtn = new Button();
            MinusBtn = new Button();
            ThreeBtn = new Button();
            TwoBtn = new Button();
            OneBtn = new Button();
            EqualBtn = new Button();
            PlusBtn = new Button();
            CommaBtn = new Button();
            ZeroBtn = new Button();
            ExpresionTextBox = new TextBox();
            SuspendLayout();
            // 
            // ResultTextBox
            // 
            ResultTextBox.Font = new Font("Segoe UI", 20F, FontStyle.Regular, GraphicsUnit.Point);
            ResultTextBox.Location = new Point(12, 41);
            ResultTextBox.Name = "ResultTextBox";
            ResultTextBox.ReadOnly = true;
            ResultTextBox.Size = new Size(399, 43);
            ResultTextBox.TabIndex = 0;
            ResultTextBox.TabStop = false;
            ResultTextBox.Text = "0";
            ResultTextBox.TextAlign = HorizontalAlignment.Right;
            // 
            // BackspaceBtn
            // 
            BackspaceBtn.Location = new Point(12, 90);
            BackspaceBtn.Name = "BackspaceBtn";
            BackspaceBtn.Size = new Size(75, 52);
            BackspaceBtn.TabIndex = 1;
            BackspaceBtn.TabStop = false;
            BackspaceBtn.Text = "←";
            BackspaceBtn.UseVisualStyleBackColor = true;
            BackspaceBtn.Click += BackspaceBtn_Click;
            // 
            // ClearBtn
            // 
            ClearBtn.Location = new Point(93, 90);
            ClearBtn.Name = "ClearBtn";
            ClearBtn.Size = new Size(75, 52);
            ClearBtn.TabIndex = 2;
            ClearBtn.TabStop = false;
            ClearBtn.Text = "CE";
            ClearBtn.UseVisualStyleBackColor = true;
            ClearBtn.Click += ClearBtn_Click;
            // 
            // ClearAllBtn
            // 
            ClearAllBtn.Location = new Point(174, 90);
            ClearAllBtn.Name = "ClearAllBtn";
            ClearAllBtn.Size = new Size(75, 52);
            ClearAllBtn.TabIndex = 3;
            ClearAllBtn.TabStop = false;
            ClearAllBtn.Text = "C";
            ClearAllBtn.UseVisualStyleBackColor = true;
            ClearAllBtn.Click += ClearAllBtn_Click;
            // 
            // PlusMinusBtn
            // 
            PlusMinusBtn.Location = new Point(255, 90);
            PlusMinusBtn.Name = "PlusMinusBtn";
            PlusMinusBtn.Size = new Size(75, 52);
            PlusMinusBtn.TabIndex = 4;
            PlusMinusBtn.TabStop = false;
            PlusMinusBtn.Text = "+/-";
            PlusMinusBtn.UseVisualStyleBackColor = true;
            PlusMinusBtn.Click += PlusMinusBtn_Click;
            // 
            // SqrtBtn
            // 
            SqrtBtn.Location = new Point(336, 90);
            SqrtBtn.Name = "SqrtBtn";
            SqrtBtn.Size = new Size(75, 52);
            SqrtBtn.TabIndex = 5;
            SqrtBtn.TabStop = false;
            SqrtBtn.Text = "√";
            SqrtBtn.UseVisualStyleBackColor = true;
            SqrtBtn.Click += SqrtBtn_Click;
            // 
            // PercentBtn
            // 
            PercentBtn.Location = new Point(336, 148);
            PercentBtn.Name = "PercentBtn";
            PercentBtn.Size = new Size(75, 52);
            PercentBtn.TabIndex = 10;
            PercentBtn.TabStop = false;
            PercentBtn.Text = "%";
            PercentBtn.UseVisualStyleBackColor = true;
            PercentBtn.Click += PercentBtn_Click;
            // 
            // DivideBtn
            // 
            DivideBtn.Location = new Point(255, 148);
            DivideBtn.Name = "DivideBtn";
            DivideBtn.Size = new Size(75, 52);
            DivideBtn.TabIndex = 9;
            DivideBtn.TabStop = false;
            DivideBtn.Text = "/";
            DivideBtn.UseVisualStyleBackColor = true;
            DivideBtn.Click += NumberOrOperatorBtn_Click;
            // 
            // NineBtn
            // 
            NineBtn.Location = new Point(174, 148);
            NineBtn.Name = "NineBtn";
            NineBtn.Size = new Size(75, 52);
            NineBtn.TabIndex = 8;
            NineBtn.TabStop = false;
            NineBtn.Text = "9";
            NineBtn.UseVisualStyleBackColor = true;
            NineBtn.Click += NumberOrOperatorBtn_Click;
            // 
            // EightBtn
            // 
            EightBtn.Location = new Point(93, 148);
            EightBtn.Name = "EightBtn";
            EightBtn.Size = new Size(75, 52);
            EightBtn.TabIndex = 7;
            EightBtn.TabStop = false;
            EightBtn.Text = "8";
            EightBtn.UseVisualStyleBackColor = true;
            EightBtn.Click += NumberOrOperatorBtn_Click;
            // 
            // SevenBtn
            // 
            SevenBtn.Location = new Point(12, 148);
            SevenBtn.Name = "SevenBtn";
            SevenBtn.Size = new Size(75, 52);
            SevenBtn.TabIndex = 6;
            SevenBtn.TabStop = false;
            SevenBtn.Text = "7";
            SevenBtn.UseVisualStyleBackColor = true;
            SevenBtn.Click += NumberOrOperatorBtn_Click;
            // 
            // FractionBtn
            // 
            FractionBtn.Location = new Point(336, 206);
            FractionBtn.Name = "FractionBtn";
            FractionBtn.Size = new Size(75, 52);
            FractionBtn.TabIndex = 15;
            FractionBtn.TabStop = false;
            FractionBtn.Text = "1/x";
            FractionBtn.UseVisualStyleBackColor = true;
            FractionBtn.Click += FractionBtn_Click;
            // 
            // MultiplyBtn
            // 
            MultiplyBtn.Location = new Point(255, 206);
            MultiplyBtn.Name = "MultiplyBtn";
            MultiplyBtn.Size = new Size(75, 52);
            MultiplyBtn.TabIndex = 14;
            MultiplyBtn.TabStop = false;
            MultiplyBtn.Text = "*";
            MultiplyBtn.UseVisualStyleBackColor = true;
            MultiplyBtn.Click += NumberOrOperatorBtn_Click;
            // 
            // SixBtn
            // 
            SixBtn.Location = new Point(174, 206);
            SixBtn.Name = "SixBtn";
            SixBtn.Size = new Size(75, 52);
            SixBtn.TabIndex = 13;
            SixBtn.TabStop = false;
            SixBtn.Text = "6";
            SixBtn.UseVisualStyleBackColor = true;
            SixBtn.Click += NumberOrOperatorBtn_Click;
            // 
            // FiveBtn
            // 
            FiveBtn.Location = new Point(93, 206);
            FiveBtn.Name = "FiveBtn";
            FiveBtn.Size = new Size(75, 52);
            FiveBtn.TabIndex = 12;
            FiveBtn.TabStop = false;
            FiveBtn.Text = "5";
            FiveBtn.UseVisualStyleBackColor = true;
            FiveBtn.Click += NumberOrOperatorBtn_Click;
            // 
            // FourBtn
            // 
            FourBtn.Location = new Point(12, 206);
            FourBtn.Name = "FourBtn";
            FourBtn.Size = new Size(75, 52);
            FourBtn.TabIndex = 11;
            FourBtn.TabStop = false;
            FourBtn.Text = "4";
            FourBtn.UseVisualStyleBackColor = true;
            FourBtn.Click += NumberOrOperatorBtn_Click;
            // 
            // MinusBtn
            // 
            MinusBtn.Location = new Point(255, 264);
            MinusBtn.Name = "MinusBtn";
            MinusBtn.Size = new Size(75, 52);
            MinusBtn.TabIndex = 19;
            MinusBtn.TabStop = false;
            MinusBtn.Text = "-";
            MinusBtn.UseVisualStyleBackColor = true;
            MinusBtn.Click += NumberOrOperatorBtn_Click;
            // 
            // ThreeBtn
            // 
            ThreeBtn.Location = new Point(174, 264);
            ThreeBtn.Name = "ThreeBtn";
            ThreeBtn.Size = new Size(75, 52);
            ThreeBtn.TabIndex = 18;
            ThreeBtn.TabStop = false;
            ThreeBtn.Text = "3";
            ThreeBtn.UseVisualStyleBackColor = true;
            ThreeBtn.Click += NumberOrOperatorBtn_Click;
            // 
            // TwoBtn
            // 
            TwoBtn.Location = new Point(93, 264);
            TwoBtn.Name = "TwoBtn";
            TwoBtn.Size = new Size(75, 52);
            TwoBtn.TabIndex = 17;
            TwoBtn.TabStop = false;
            TwoBtn.Text = "2";
            TwoBtn.UseVisualStyleBackColor = true;
            TwoBtn.Click += NumberOrOperatorBtn_Click;
            // 
            // OneBtn
            // 
            OneBtn.Location = new Point(12, 264);
            OneBtn.Name = "OneBtn";
            OneBtn.Size = new Size(75, 52);
            OneBtn.TabIndex = 16;
            OneBtn.TabStop = false;
            OneBtn.Text = "1";
            OneBtn.UseVisualStyleBackColor = true;
            OneBtn.Click += NumberOrOperatorBtn_Click;
            // 
            // EqualBtn
            // 
            EqualBtn.Location = new Point(336, 264);
            EqualBtn.Name = "EqualBtn";
            EqualBtn.Size = new Size(75, 110);
            EqualBtn.TabIndex = 25;
            EqualBtn.TabStop = false;
            EqualBtn.Text = "=";
            EqualBtn.UseVisualStyleBackColor = true;
            EqualBtn.Click += EqualBtn_Click;
            // 
            // PlusBtn
            // 
            PlusBtn.Location = new Point(255, 322);
            PlusBtn.Name = "PlusBtn";
            PlusBtn.Size = new Size(75, 52);
            PlusBtn.TabIndex = 24;
            PlusBtn.TabStop = false;
            PlusBtn.Text = "+";
            PlusBtn.UseVisualStyleBackColor = true;
            PlusBtn.Click += NumberOrOperatorBtn_Click;
            // 
            // CommaBtn
            // 
            CommaBtn.Location = new Point(174, 322);
            CommaBtn.Name = "CommaBtn";
            CommaBtn.Size = new Size(75, 52);
            CommaBtn.TabIndex = 23;
            CommaBtn.TabStop = false;
            CommaBtn.Text = ",";
            CommaBtn.UseVisualStyleBackColor = true;
            CommaBtn.Click += CommaBtn_Click;
            // 
            // ZeroBtn
            // 
            ZeroBtn.Location = new Point(12, 322);
            ZeroBtn.Name = "ZeroBtn";
            ZeroBtn.Size = new Size(156, 52);
            ZeroBtn.TabIndex = 21;
            ZeroBtn.TabStop = false;
            ZeroBtn.Text = "0";
            ZeroBtn.UseVisualStyleBackColor = true;
            ZeroBtn.Click += NumberOrOperatorBtn_Click;
            // 
            // ExpresionTextBox
            // 
            ExpresionTextBox.Location = new Point(12, 12);
            ExpresionTextBox.Name = "ExpresionTextBox";
            ExpresionTextBox.ReadOnly = true;
            ExpresionTextBox.Size = new Size(399, 23);
            ExpresionTextBox.TabIndex = 1;
            ExpresionTextBox.TabStop = false;
            ExpresionTextBox.TextAlign = HorizontalAlignment.Right;
            // 
            // Calculator
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(423, 388);
            Controls.Add(ExpresionTextBox);
            Controls.Add(EqualBtn);
            Controls.Add(PlusBtn);
            Controls.Add(CommaBtn);
            Controls.Add(ZeroBtn);
            Controls.Add(MinusBtn);
            Controls.Add(ThreeBtn);
            Controls.Add(TwoBtn);
            Controls.Add(OneBtn);
            Controls.Add(FractionBtn);
            Controls.Add(MultiplyBtn);
            Controls.Add(SixBtn);
            Controls.Add(FiveBtn);
            Controls.Add(FourBtn);
            Controls.Add(PercentBtn);
            Controls.Add(DivideBtn);
            Controls.Add(NineBtn);
            Controls.Add(EightBtn);
            Controls.Add(SevenBtn);
            Controls.Add(SqrtBtn);
            Controls.Add(PlusMinusBtn);
            Controls.Add(ClearAllBtn);
            Controls.Add(ClearBtn);
            Controls.Add(BackspaceBtn);
            Controls.Add(ResultTextBox);
            KeyPreview = true;
            Name = "Calculator";
            Text = "Calculator";
            KeyDown += CalculatorForm_KeyDown;
            ResumeLayout(false);
            PerformLayout();
        }
        #endregion

        private TextBox ResultTextBox;
        private Button BackspaceBtn;
        private Button ClearBtn;
        private Button ClearAllBtn;
        private Button PlusMinusBtn;
        private Button SqrtBtn;
        private Button PercentBtn;
        private Button DivideBtn;
        private Button NineBtn;
        private Button EightBtn;
        private Button SevenBtn;
        private Button FractionBtn;
        private Button MultiplyBtn;
        private Button SixBtn;
        private Button FiveBtn;
        private Button FourBtn;
        private Button MinusBtn;
        private Button ThreeBtn;
        private Button TwoBtn;
        private Button OneBtn;
        private Button EqualBtn;
        private Button PlusBtn;
        private Button CommaBtn;
        private Button ZeroBtn;
        private TextBox ExpresionTextBox;
    }
}