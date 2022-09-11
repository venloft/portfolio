using System;
using System.Linq;
using System.Windows.Forms;

namespace Calculator 
{
    public partial class Form1 : Form 
    {
		readonly TCtrl<TFrac, TFracEditor> frac_ctrl;
		readonly TCtrl<TPNumber, TPNumberEditor> pNumber_ctrl;
		readonly TCtrl<TComplex, TComplexEditor> complex_ctrl;

        const string OPERATIONS = "+-/*";

        const string TAG_FRAC = "FRAC_";
        const string TAG_COMPLEX = "COMPLEX_";
        const string TAG_PNUMBER = "PNUMBER_";

        bool frac_mode = true;
        bool pNumber_mode = true;
        bool complex_mode = true;
        enum Complex_func 
        {
            Pwr, Root, Abs, Dgr, Rad
        }

        private string Number_to_state(string tag, string str) 
        {
            if ("ERROR" == str)
			{
                return str;
			}
            string return_str = str;
            switch (tag) 
            {
                case TAG_PNUMBER:
                    break;
                case TAG_FRAC:
                    if (true == frac_mode)
					{
                        return_str = str;
					}
                    else if (new TFrac(str).Denominator == 1)
					{
                        return_str = new TFrac(str).Numerator.ToString();
                    }
                    break;
                case TAG_COMPLEX:
                    if (true == complex_mode)
					{
                        return_str = str;
                    }
                    else if (new TComplex(str).Imaginary == 0)
					{
                        return_str = new TComplex(str).Real.ToString();
                    }
                    break;
            }
            return return_str;
        }
        private static TAEditor.Command Char_to_edit_command(char ch) 
        {
            TAEditor.Command command = TAEditor.Command.cNone;
            switch (ch) 
            {
                case '0':
                    command = TAEditor.Command.cZero;
                    break;
                case '1':
                    command = TAEditor.Command.cOne;
                    break;
                case '2':
                    command = TAEditor.Command.cTwo;
                    break;
                case '3':
                    command = TAEditor.Command.cThree;
                    break;
                case '4':
                    command = TAEditor.Command.cFour;
                    break;
                case '5':
                    command = TAEditor.Command.cFive;
                    break;
                case '6':
                    command = TAEditor.Command.cSix;
                    break;
                case '7':
                    command = TAEditor.Command.cSeven;
                    break;
                case '8':
                    command = TAEditor.Command.cEight;
                    break;
                case '9':
                    command = TAEditor.Command.cNine;
                    break;
                case 'A':
                    command = TAEditor.Command.cA;
                    break;
                case 'B':
                    command = TAEditor.Command.cB;
                    break;
                case 'C':
                    command = TAEditor.Command.cC;
                    break;
                case 'D':
                    command = TAEditor.Command.cD;
                    break;
                case 'E':
                    command = TAEditor.Command.cE;
                    break;
                case 'F':
                    command = TAEditor.Command.cF;
                    break;
                case '.':
                case '/':
                    command = TAEditor.Command.cSeparator;
                    break;
                case '-':
                    command = TAEditor.Command.cSign;
                    break;
            }
            return command;
        }
        private static TProc<T>.Oper Char_to_operation_command<T>(char ch) where T : TANumber, new() 
        {
            TProc<T>.Oper command = TProc<T>.Oper.None;
            switch (ch) 
            {
                case '+':
                    command = TProc<T>.Oper.Add;
                    break;
                case '-':
                    command = TProc<T>.Oper.Sub;
                    break;
                case '*':
                    command = TProc<T>.Oper.Mul;
                    break;
                case '/':
                    command = TProc<T>.Oper.Div;
                    break;
            }
            return command;
        }
        private static TAEditor.Command Keycode_to_edit_command(Keys ch) 
        {
            TAEditor.Command command = TAEditor.Command.cNone;
            switch (ch) 
            {
                case Keys.Back:
                    command = TAEditor.Command.cBS;
                    break;
                case Keys.Delete:
                case Keys.Escape:
                    command = TAEditor.Command.CE;
                    break;
            }
            return command;
        }

        public Form1() 
        {
            frac_ctrl = new TCtrl<TFrac, TFracEditor>();
            pNumber_ctrl = new TCtrl<TPNumber, TPNumberEditor>();
            complex_ctrl = new TCtrl<TComplex, TComplexEditor>();
            InitializeComponent();
            Size = new System.Drawing.Size(355, 433);
        }

        private void Button_Number_Edit(object sender, EventArgs e) 
        {
            TAEditor.Command parsed_command;
            Button button = (Button)sender;
            string tag = button.Tag.ToString();
            string part_tag = tag.Substring(0, tag.IndexOf('_')) + "_";
			switch (part_tag)
			{
				case TAG_PNUMBER:
                    pNumber_ctrl.Edit.Notation = new TNumber(trackBar_PNumber.Value);
					Enum.TryParse(tag.Replace(TAG_PNUMBER, string.Empty), out parsed_command);
					tB_PNumber.Text = pNumber_ctrl.ExecCommandEditor(parsed_command);
					break;
				case TAG_FRAC:
					Enum.TryParse(tag.Replace(TAG_FRAC, string.Empty), out parsed_command);
					tB_Frac.Text = frac_ctrl.ExecCommandEditor(parsed_command);
					break;
				case TAG_COMPLEX:
					Enum.TryParse(tag.Replace(TAG_COMPLEX, string.Empty), out parsed_command);
					tB_Complex.Text = complex_ctrl.ExecCommandEditor(parsed_command);
					break;
			}
		}
        private void Button_Number_Operation(object sender, EventArgs e) 
        {
            TProc<TFrac>.Oper parsed_frac_oper;
            TProc<TPNumber>.Oper parsed_pNumber_oper;
            TProc<TComplex>.Oper parsed_complex_oper;
            Button button = (Button)sender;
            string tag = button.Tag.ToString();
            string part_tag = tag.Substring(0, tag.IndexOf('_')) + "_";
            switch (part_tag)
            {
                case TAG_PNUMBER:
                    Enum.TryParse(tag.Replace(TAG_PNUMBER, string.Empty), out parsed_pNumber_oper);
                    tB_PNumber.Text = pNumber_ctrl.ExecOperation(parsed_pNumber_oper);
                    break;
                case TAG_FRAC:
                    Enum.TryParse(tag.Replace(TAG_FRAC, string.Empty), out parsed_frac_oper);
                    tB_Frac.Text = Number_to_state(TAG_FRAC, frac_ctrl.ExecOperation(parsed_frac_oper));
                    break;
                case TAG_COMPLEX:
                    Enum.TryParse(tag.Replace(TAG_COMPLEX, string.Empty), out parsed_complex_oper);
                    tB_Complex.Text = Number_to_state(TAG_COMPLEX, complex_ctrl.ExecOperation(parsed_complex_oper));
                    break;
            }
        }

        private void Button_Number_Function(object sender, EventArgs e)
        {
            TProc<TFrac>.Func parsed_frac_func;
            TProc<TPNumber>.Func parsed_pNumber_func;
            TProc<TComplex>.Func parsed_complex_func;
            Button button = (Button)sender;
            string tag = button.Tag.ToString();
            string part_tag = tag.Substring(0, tag.IndexOf('_')) + "_";
            switch (part_tag)
            {
                case TAG_PNUMBER:
                    Enum.TryParse(tag.Replace(TAG_PNUMBER, string.Empty), out parsed_pNumber_func);
                    tB_PNumber.Text = pNumber_ctrl.ExecFunction(parsed_pNumber_func);
                    break;
                case TAG_FRAC:
                    Enum.TryParse(tag.Replace(TAG_FRAC, string.Empty), out parsed_frac_func);
                    tB_Frac.Text = Number_to_state(TAG_FRAC, frac_ctrl.ExecFunction(parsed_frac_func));
                    break;
                case TAG_COMPLEX:
                    Enum.TryParse(tag.Replace(TAG_COMPLEX, string.Empty), out parsed_complex_func);
                    tB_Complex.Text = Number_to_state(TAG_COMPLEX, complex_ctrl.ExecFunction(parsed_complex_func));
                    break;
            }
        }

        private void Button_Reset(object sender, EventArgs e) 
        {
            Button button = (Button)sender;
            string tag = button.Tag.ToString();
            string part_tag = tag.Substring(0, tag.IndexOf('_')) + "_";
            switch (part_tag)
			{
				case TAG_PNUMBER:
                    tB_PNumber.Text = pNumber_ctrl.Reset();
                    label_PNumber_Memory.Text = string.Empty;
                    break;
                case TAG_FRAC:
                    tB_Frac.Text = frac_ctrl.Reset();
                    label_Frac_Memory.Text = string.Empty;
                    break;
                case TAG_COMPLEX:
                    tB_Complex.Text = complex_ctrl.Reset();
                    tB_Complex_SpecialOut.Text = label_Complex_Memory.Text = string.Empty;
                    break;
            }
        }

        private void Button_FinishEval(object sender, EventArgs e) 
        {
            Button button = (Button)sender;
            string tag = button.Tag.ToString();
            string part_tag = tag.Substring(0, tag.IndexOf('_')) + "_";
            switch(part_tag)
			{
                case TAG_PNUMBER:
                    tB_PNumber.Text = pNumber_ctrl.Calculate();
                    break;
                case TAG_FRAC:
                    tB_Frac.Text = Number_to_state(TAG_FRAC, frac_ctrl.Calculate()); ;
                    break;
                case TAG_COMPLEX:
                    tB_Complex.Text = Number_to_state(TAG_COMPLEX, complex_ctrl.Calculate());
                    break;
            }
        }

        private void Button_Memory(object sender, EventArgs e) 
        {
            TMemory<TPNumber>.Commands parsed_pNumber_command;
            TMemory<TFrac>.Commands parsed_frac_command;
            TMemory<TComplex>.Commands parsed_complex_command;
            dynamic exec;
            Button button = (Button)sender;
            string tag = button.Tag.ToString();
            string part_tag = tag.Substring(0, tag.IndexOf('_')) + "_";
            switch(part_tag)
			{
                case TAG_PNUMBER:
                    Enum.TryParse(tag.Replace(TAG_PNUMBER, string.Empty), out parsed_pNumber_command);
                    exec = pNumber_ctrl.ExecCommandMemory(parsed_pNumber_command, tB_PNumber.Text);
                    if (TMemory<TPNumber>.Commands.Copy == parsed_pNumber_command)
                    {
                        tB_PNumber.Text = exec.Item1.ToString();
                    }
                    label_PNumber_Memory.Text = exec.Item2 == TMemory<TPNumber>.NumStates.ON ? "M" : string.Empty;
                    break;
                case TAG_FRAC:
                    Enum.TryParse(tag.Replace(TAG_FRAC, string.Empty), out parsed_frac_command);
                    exec = frac_ctrl.ExecCommandMemory(parsed_frac_command, tB_Frac.Text);
                    if (TMemory<TFrac>.Commands.Copy == parsed_frac_command)
                    {
                        tB_Frac.Text = exec.Item1.ToString();
                    }
                    label_Frac_Memory.Text = exec.Item2 == TMemory<TFrac>.NumStates.ON ? "M" : string.Empty;
                    break;
                case TAG_COMPLEX:
                    Enum.TryParse(tag.Replace(TAG_COMPLEX, string.Empty), out parsed_complex_command);
                    exec = complex_ctrl.ExecCommandMemory(parsed_complex_command, tB_Complex.Text);
                    if (TMemory<TComplex>.Commands.Copy == parsed_complex_command)
                    {
                        tB_Complex.Text = exec.Item1.ToString();
                    }
                    label_Complex_Memory.Text = exec.Item2 == TMemory<TComplex>.NumStates.ON ? "M" : string.Empty;
                    break;
			}
        }

        private void СправкаToolStripMenuItem_Click(object sender, EventArgs e) 
        {
            MessageBox.Show("MS (Memory Save) - кнопка означает сохранить число, отображенное в данный момент на дисплее калькулятора в память\nMR(Memory Read) - кнопка означает считать число из ячейки памяти и вывести его на дисплей.\nMC(Memory Clear) - кнопка означает стереть данные из ячейки памяти.\nM + -прибавить к числу из памяти число, отображенное на дисплее и результат записать в память вместо предыдущего.", "Калькулятор", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void TrackBar_PNumber_ValueChanged(object sender, EventArgs e) 
        {
            label_PNumber_P.Text = trackBar_PNumber.Value.ToString();
            pNumber_ctrl.Edit.Notation = new TNumber(trackBar_PNumber.Value);
            tB_PNumber.Text = pNumber_ctrl.Reset();
            label_PNumber_Memory.Text = string.Empty;
            string AllowedEndings = "0123456789ABCDEF";
            foreach (Control i in tabPage_PNumber.Controls.OfType<Button>()) 
            {
                if (AllowedEndings.Contains(i.Name.ToString().Last()) && i.Name.ToString().Substring(i.Name.ToString().Length - 2, 1) == "_") 
                {
                    int j = AllowedEndings.IndexOf(i.Name.ToString().Last());
                    if (j < trackBar_PNumber.Value) 
                    {
                        i.Enabled = true;
                    }
                    if ((j >= trackBar_PNumber.Value) && (j <= 15)) 
                    {
                        i.Enabled = false;
                    }
                }
            }
            pNumber_ctrl.Proc.Lop_Res.Notation = new TNumber(trackBar_PNumber.Value);
            pNumber_ctrl.Proc.Rop.Notation = new TNumber(trackBar_PNumber.Value);
        }

        private void Button_Complex_Special(object sender, EventArgs e) 
        {
            try 
            {
                Button button = (Button)sender;
                Enum.TryParse(button.Tag.ToString().Replace(TAG_COMPLEX, string.Empty), out Complex_func ParsedEnum);
                TComplex number = new TComplex(tB_Complex.Text);
                switch (ParsedEnum) 
                {
                    case Complex_func.Pwr:
                        int PwrN = Convert.ToInt32(nUD_Complex_Pwr.Value);
                        tB_Complex_SpecialOut.Text = number.Pwr(PwrN).ToString();
                        break;
                    case Complex_func.Root:
                        int RootN = Convert.ToInt32(nUD_Complex_Root_N.Value);
                        int Rooti = Convert.ToInt32(nUD_Complex_Root_i.Value);
                        tB_Complex_SpecialOut.Text = number.Root(RootN, Rooti).ToString();
                        break;
                    case Complex_func.Abs:
                        tB_Complex_SpecialOut.Text = number.Abs().ToString();
                        break;
                    case Complex_func.Dgr:
                        tB_Complex_SpecialOut.Text = number.GetDegree().ToString();
                        break;
                    case Complex_func.Rad:
                        tB_Complex_SpecialOut.Text = number.GetRad().ToString();
                        break;
                }
            }
            catch 
            {
                tB_Complex_SpecialOut.Text = "ERROR";
            }
        }

        private void Button_Complex_ShowAllRoots(object sender, EventArgs e) 
        {
            ShowRoots RootsForm = new ShowRoots();
            int RootN = Convert.ToInt32(nUD_Complex_Root_N.Value);
            TComplex number = new TComplex(tB_Complex.Text);
            for (int i = 0; i < RootN; ++i)
			{
                RootsForm.richTB_Roots.Text += "Root " + i.ToString() + ": " + number.Root(RootN, i).ToString() + Environment.NewLine;
            }
            RootsForm.ShowDialog();
        }
        private void NUD_Complex_Root_N_ValueChanged(object sender, EventArgs e) 
        {
            nUD_Complex_Root_i.Maximum = nUD_Complex_Root_N.Value;
        }
        private void TabControl_SelectedIndexChanged(object sender, EventArgs e) 
        {
            switch (tabControl.SelectedIndex) 
            {
                case 0:
                    Size = new System.Drawing.Size(355, 433);
                    break;
                case 1:
                    Size = new System.Drawing.Size(310, 382);
                    break;
                case 2:
                    Size = new System.Drawing.Size(445, 418);
                    break;
                default:
                    break;
            }
        }

        private void Form1_KeyPress(object sender, KeyPressEventArgs e) 
        {
            switch (tabControl.SelectedIndex) 
            {
                case 0: 
                {
                    if ((e.KeyChar >= '0' && e.KeyChar <= '9') 
                            || (e.KeyChar >= 'A' && e.KeyChar <= 'F') 
                            || (e.KeyChar == '.' && pNumber_mode))
					{
                        tB_PNumber.Text = pNumber_ctrl.ExecCommandEditor(Char_to_edit_command(e.KeyChar));
                    }
                    else if (OPERATIONS.Contains(e.KeyChar))
				    {
                        tB_PNumber.Text = Number_to_state(TAG_PNUMBER, pNumber_ctrl.ExecOperation(Char_to_operation_command<TPNumber>(e.KeyChar)));
                    }
                    break;
                }
                case 1: 
                {
                    if ((e.KeyChar >= '0' && e.KeyChar <= '9') || e.KeyChar == '.')
                    {
                        tB_Frac.Text = frac_ctrl.ExecCommandEditor(Char_to_edit_command(e.KeyChar));
                    }
                    else if (OPERATIONS.Contains(e.KeyChar))
					{
                        tB_Frac.Text = Number_to_state(TAG_FRAC, frac_ctrl.ExecOperation(Char_to_operation_command<TFrac>(e.KeyChar)));
                    }
                    break;
                }
                case 2: 
                {
                    if ((e.KeyChar >= '0' && e.KeyChar <= '9') || e.KeyChar == '.')
					{
                        tB_Complex.Text = complex_ctrl.ExecCommandEditor(Char_to_edit_command(e.KeyChar));
                    }
                    else if (OPERATIONS.Contains(e.KeyChar))
					{
                        tB_Complex.Text = Number_to_state(TAG_COMPLEX, complex_ctrl.ExecOperation(Char_to_operation_command<TComplex>(e.KeyChar)));
                    }
                    break;
                }
                default:
                    break;
            }
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e) 
        {
            switch (tabControl.SelectedIndex) 
            {
                case 0: 
                {
                    if (e.KeyCode == Keys.Enter)
					{
                        b_PNumber_Eval.PerformClick();
                    }
                    else 
                    {
                        TAEditor.Command comm = Keycode_to_edit_command(e.KeyCode);
                        if (comm != TAEditor.Command.cNone)
						{
                            tB_PNumber.Text = pNumber_ctrl.ExecCommandEditor(comm);
                        }
                    }
                    break;
                }
                case 1: 
                {
                    if (e.KeyCode == Keys.Enter)
				    {
                        b_Frac_Eval.PerformClick();
                    }
                    else 
                    {
                        TAEditor.Command comm = Keycode_to_edit_command(e.KeyCode);
                        if (comm != TAEditor.Command.cNone)
				        {
                            tB_Frac.Text = pNumber_ctrl.ExecCommandEditor(comm);
                        }
                    }
                    break;
                }
                case 2: 
                {
                    if (e.KeyCode == Keys.Enter)
					{
                        b_Complex_Eval.PerformClick();
                    }
                    else 
                    {
                        TAEditor.Command comm = Keycode_to_edit_command(e.KeyCode);
                        if (comm != TAEditor.Command.cNone)
						{
                            tB_Complex.Text = pNumber_ctrl.ExecCommandEditor(comm);
                        }
                    }
                    break;
                }
                default:
                    break;
            }
        }

        private void ДействительныеPNumberTSMI_Click(object sender, EventArgs e) 
        {
            целыеPNumberTSMI.Checked = false;
            действительныеPNumberTSMI.Checked = true;
            pNumber_mode = true;
            b_PNumber_Separator.Enabled = true;
            b_PNumber_Clear.PerformClick();
        }
        private void ЦелыеPNumberTSMI_Click(object sender, EventArgs e) 
        {
            целыеPNumberTSMI.Checked = true;
            действительныеPNumberTSMI.Checked = false;
            pNumber_mode = false;
            b_PNumber_Separator.Enabled = false;
            b_PNumber_Clear.PerformClick();
        }
        private void ДробьFracTSMI_Click(object sender, EventArgs e) 
        {
            дробьFracTSMI.Checked = true;
            числоFracTSMI.Checked = false;
            frac_mode = true;
        }
        private void ЧислоFracTSMI_Click(object sender, EventArgs e) 
        {
            дробьFracTSMI.Checked = false;
            числоFracTSMI.Checked = true;
            frac_mode = false;
        }
        private void КомплексноеComplexTSMI_Click(object sender, EventArgs e)
        { 
            комплексноеComplexTSMI.Checked = true;
            действительноеComplexTSMI.Checked = false;
            complex_mode = true;
        }
        private void ДействительноеComplexTSMI_Click(object sender, EventArgs e) 
        {
            комплексноеComplexTSMI.Checked = false;
            действительноеComplexTSMI.Checked = true;
            complex_mode = false;
        }

		private void КопироватьToolStripMenuItem_Click(object sender, EventArgs e)
		{
            switch(tabControl.SelectedIndex)
			{
                case 0:
                    Clipboard.SetText(tB_PNumber.Text);
                    break;
                case 1:
                    Clipboard.SetText(tB_Frac.Text);
                    break;
                case 2:
                    Clipboard.SetText(tB_Complex.Text);
                    break;
            }
        }

        private void ВставитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string text = Clipboard.GetText();
            switch (tabControl.SelectedIndex)
            {
                case 0:
                    tB_PNumber.Text = "";
                    for (int i = 0; i < text.Length; i++)
                    {
                        tB_PNumber.Text = pNumber_ctrl.ExecCommandEditor(Char_to_edit_command(text[i]));
                    }
                    break;
                case 1:
                    tB_Frac.Text = "";
                    for (int i = 0; i < text.Length; i++)
					{
                        tB_Frac.Text = frac_ctrl.ExecCommandEditor(Char_to_edit_command(text[i]));
                    }
                    break;
                case 2:
                    tB_Complex.Text = "";
                    for (int i = 0; i < text.Length; i++)
                    {
                        tB_Complex.Text = complex_ctrl.ExecCommandEditor(Char_to_edit_command(text[i]));
                    }
                    break;
            }
        }

        private void tabPage_Complex_Click(object sender, EventArgs e)
        {

        }

        private void tabPage_Frac_Click(object sender, EventArgs e)
        {

        }

        private void trackBar_PNumber_Scroll(object sender, EventArgs e)
        {

        }
    }
}
