﻿using System;
using System.Linq;

namespace Calculator 
{
    public sealed class TFracEditor : TAEditor 
    {
        const int BothSideLimit = 22;
        const int LeftSideOnlyLimit = 14;

        const string Separator = "/";
        const string ZeroFraction = "0/";

        private string number;
        public override string Number 
        {
            get => number;
            set 
            {
                number = new TFrac(value).ToString();
            }
        }
        public TFracEditor() 
        {
            number = "0";
        }
        public TFracEditor(int a, int b) 
        {
            number = new TFrac(a, b).ToString();
        }
        public TFracEditor(string str) 
        {
            number = new TFrac(str).ToString();
        }

        public override bool IsZero() 
        {
            return number.StartsWith(ZeroFraction) || number == "0";
        }
        public override string ToogleSign()
        {
            if (number.ElementAt(0) == '-')
            {
                number = number.Remove(0, 1);
			}
            number = "-" + number;
            return number;
        }
        public override string AddNumber(int a) 
        {
            if ((!HaveSeparator() && number.Length > LeftSideOnlyLimit)
                || (number.Length > BothSideLimit)
                || (a < 0 || a > 9))
            {
                return number;
            }
            if (a == 0)
			{
                AddZero();
			}
            else if (number == "0" || number == "-0")
			{
                number = number.First() == '-' ? "-" + a.ToString() : a.ToString();
            }
            else
			{
                number += a.ToString();
            }
            return number;
        }
        public override bool Equals(object obj) 
        {
            return obj is TFracEditor editor && number == editor.number;
        }
        public override string AddZero() 
        {
            if ((HaveSeparator() && number.Last().ToString() == Separator)
                || (number == "0" || number == "0/"))
			{
                return number;
			}
            number += "0";
            return number;
        }
        public override string RemoveSymbol() 
        {
            if (number.Length == 1)
			{
                number = "0";
            }
            else if (number.Length == 2 && number.First() == '-')
			{
                number = "-0";
            }
            else
			{
                number = number.Remove(number.Length - 1);
            }
            return number;
        }
        public override string Clear() 
        {
            number = "0";
            return number;
        }
        public override string Edit(Enum com) 
        {
            switch (com) 
            {
                case Command.cZero:
                    AddZero();
                    break;
                case Command.cOne:
                    AddNumber(1);
                    break;
                case Command.cTwo:
                    AddNumber(2);
                    break;
                case Command.cThree:
                    AddNumber(3);
                    break;
                case Command.cFour:
                    AddNumber(4);
                    break;
                case Command.cFive:
                    AddNumber(5);
                    break;
                case Command.cSix:
                    AddNumber(6);
                    break;
                case Command.cSeven:
                    AddNumber(7);
                    break;
                case Command.cEight:
                    AddNumber(8);
                    break;
                case Command.cNine:
                    AddNumber(9);
                    break;
                case Command.cSign:
                    ToogleSign();
                    break;
                case Command.cSeparator:
                    AddSeparator();
                    break;
                case Command.cBS:
                    RemoveSymbol();
                    break;
                case Command.CE:
                    Clear();
                    break;
                default:
                    break;
            }
            return Number;
        }
        public override string AddSeparator() 
        {
            if (!number.Contains(Separator))
			{
                number += Separator;
            }
            return number;
        }
        public override bool HaveSeparator() 
        {
            return number.Contains(Separator);
        }
        public override string ToString() 
        {
            return Number;
        }
    }
}
