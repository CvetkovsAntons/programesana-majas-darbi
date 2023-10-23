namespace AK_IT_P_Ns_AntonsCvetkovs_1md
{
    public partial class Calculator : Form
    {
        private double result = 0;
        private string operators = "+";

        public Calculator()
        {
            InitializeComponent();
        }

        private double getCalculations()
        {
            switch (this.operators)
            {
                case "+":
                    return this.result += double.Parse(ResultTextBox.Text);
                case "-":
                    return this.result -= double.Parse(ResultTextBox.Text);
                case "*":
                    return this.result *= double.Parse(ResultTextBox.Text);
                case "/":
                    return this.result /= double.Parse(ResultTextBox.Text);
                default: return 0;
            }
        }

        private void setOperator(string op)
        {
            if (!this.isResult(ResultTextBox.Text)) 
            {
                this.result = this.result == 0 ? double.Parse(ResultTextBox.Text) : this.getCalculations();
                ExpresionTextBox.Text = this.result + op;
                ResultTextBox.Text = "0";
                this.operators = op;
            }
        }

        private void addNumber(string value)
        {
            if (ResultTextBox.Text != "0" && !this.isResult(ResultTextBox.Text))
            {
                ResultTextBox.Text += value;
            }
            else
            {
                ResultTextBox.Text = value;
            }
        }

        private void CalculatorForm_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Back || e.KeyCode == Keys.Delete) BackspaceBtn.PerformClick();
            else if (e.KeyCode == Keys.Add || (e.Shift && e.KeyCode == Keys.Oemplus)) PlusBtn.PerformClick();
            else if (e.KeyCode == Keys.Multiply || (e.Shift && e.KeyCode == Keys.D8)) MultiplyBtn.PerformClick();
            else if (e.KeyCode == Keys.Subtract || (e.Shift && e.KeyCode == Keys.OemMinus)) MinusBtn.PerformClick();
            else if (e.KeyCode == Keys.Divide || (e.KeyCode == Keys.OemQuestion)) DivideBtn.PerformClick();
            else if (e.KeyCode == Keys.Decimal || e.KeyCode == Keys.Oemcomma) CommaBtn.PerformClick();
            else if (e.KeyCode == Keys.Enter) EqualBtn.PerformClick();
            else if ((e.KeyCode >= Keys.D0 && e.KeyCode <= Keys.D9) || (e.KeyCode >= Keys.NumPad0 && e.KeyCode <= Keys.NumPad9))
            {
                if (e.KeyCode == Keys.D0 || e.KeyCode == Keys.NumPad0) ZeroBtn.PerformClick();
                if (e.KeyCode == Keys.D1 || e.KeyCode == Keys.NumPad1) OneBtn.PerformClick();
                if (e.KeyCode == Keys.D2 || e.KeyCode == Keys.NumPad2) TwoBtn.PerformClick();
                if (e.KeyCode == Keys.D3 || e.KeyCode == Keys.NumPad3) ThreeBtn.PerformClick();
                if (e.KeyCode == Keys.D4 || e.KeyCode == Keys.NumPad4) FourBtn.PerformClick();
                if (e.KeyCode == Keys.D5 || e.KeyCode == Keys.NumPad5) FiveBtn.PerformClick();
                if (e.KeyCode == Keys.D6 || e.KeyCode == Keys.NumPad6) SixBtn.PerformClick();
                if (e.KeyCode == Keys.D7 || e.KeyCode == Keys.NumPad7) SevenBtn.PerformClick();
                if (e.KeyCode == Keys.D8 || e.KeyCode == Keys.NumPad8) EightBtn.PerformClick();
                if (e.KeyCode == Keys.D9 || e.KeyCode == Keys.NumPad9) NineBtn.PerformClick();
            }
        }

        private void NumberOrOperatorBtn_Click(object sender, EventArgs e)
        {
            Button button = (Button)sender;
            string value = button.Text;

            if (this.isOperator(value))
            {
                this.setOperator(value);
            }
            else if (this.isNumber(value))
            {
                this.addNumber(value);
            }
        }

        private void CommaBtn_Click(object sender, EventArgs e)
        {
            if (this.isResult(ResultTextBox.Text))
            {
                ResultTextBox.Text = "0.";
            }
            else if (!ResultTextBox.Text.Contains("."))
            {
                ResultTextBox.Text += ".";
            }
        }

        private void PlusMinusBtn_Click(object sender, EventArgs e)
        {
            if (!this.isResult(ResultTextBox.Text) && (double.Parse(ResultTextBox.Text) > 0 || double.Parse(ResultTextBox.Text) < 0))
            {
                if (ResultTextBox.Text.Contains("-"))
                {
                    ResultTextBox.Text = ResultTextBox.Text.Trim('-');
                }
                else
                {
                    ResultTextBox.Text = "-" + ResultTextBox.Text;
                }
            }
        }

        private void PercentBtn_Click(object sender, EventArgs e)
        {
            ResultTextBox.Text = this.isResult(ResultTextBox.Text) ? "0" : (this.result * (double.Parse(ResultTextBox.Text) / 100)).ToString();
        }

        private void FractionBtn_Click(object sender, EventArgs e)
        {
            ResultTextBox.Text = this.isResult(ResultTextBox.Text) ? "0" : (1 / double.Parse(ResultTextBox.Text)).ToString();
        }

        private void SqrtBtn_Click(object sender, EventArgs e)
        {
            ResultTextBox.Text = this.isResult(ResultTextBox.Text) ? "0" : (Math.Sqrt(this.result)).ToString();
        }

        private void EqualBtn_Click(object sender, EventArgs e)
        {
            if (ResultTextBox.Text == "0")
            {
                ResultTextBox.Text = "Result: " + this.result;
            }
            else if (this.result == 0)
            {
                ResultTextBox.Text = "Result: " + ResultTextBox.Text;
            }
            else
            {
                ResultTextBox.Text = "Result: " + this.getCalculations();
            }

            ExpresionTextBox.Clear();
            this.result = 0;
        }

        private void BackspaceBtn_Click(object sender, EventArgs e)
        {
            if (this.isResult(ResultTextBox.Text))
            {
                ResultTextBox.Text = "0";
                this.result = 0;
            }
            else if (ResultTextBox.Text != "0")
            {
                int length = ResultTextBox.Text.Length;

                if (length == 1)
                {
                    ResultTextBox.Text = "0";
                }
                else
                {
                    ResultTextBox.Text = ResultTextBox.Text.Remove(length - 1);
                }
            }
        }

        private void ClearBtn_Click(object sender, EventArgs e)
        {
            ResultTextBox.Text = "0";
        }

        private void ClearAllBtn_Click(object sender, EventArgs e)
        {
            ResultTextBox.Text = "0";
            ExpresionTextBox.Clear();
            this.result = 0;
        }

        private bool isOperator(string value) { return value == "+" || value == "-" || value == "*" || value == "/"; }

        private bool isNumber(string value) { return int.Parse(value) >= 0 && int.Parse(value) <= 9; }

        private bool isResult(string value) { return value.Contains("Result: "); }
    }
}