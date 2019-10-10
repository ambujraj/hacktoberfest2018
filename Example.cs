using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace ConsoleApplication2
{
    class diadois
    {
        public int menu,menu2;
        public string nome;
        public double dias, idade, soma, sub, divi, mult, n1, n2, depositado, taxa;
        public void MostrarTudo()
        {
            Console.WriteLine("Escolha sua Opção");
            Console.WriteLine("1. Calcular dias de vida");
            Console.WriteLine("2.Calculadora");
            Console.WriteLine("3. Taxa Bancária");
            menu = Convert.ToInt16(Console.ReadLine());
            switch (menu)
            {
                case 1:
                    Console.Clear();
                    Console.WriteLine("Informe seu nome:");
                    nome = Console.ReadLine();
                    Console.WriteLine("Informe Sua idade");
                    idade = Convert.ToDouble(Console.ReadLine());
                    dias = idade * 365.25;
                    Console.WriteLine(nome.ToUpper() + " sobreviveu:" + dias);
                    break;
                case 2:
                    Console.Clear();
                    Console.WriteLine("Escolha a operação");
                    Console.WriteLine("1. Soma");
                    Console.WriteLine("2. Subtração");
                    Console.WriteLine("3. Divisão");
                    Console.WriteLine("4. Multiplicação");
                    menu2 = Convert.ToInt16(Console.ReadLine());
                    switch (menu2)
                    {
                        case 1:
                            Console.Clear();
                    Console.WriteLine("Informe o primeiro número");
                    n1 = Convert.ToDouble(Console.ReadLine());
                    Console.WriteLine("Informe o segundo número");
                    n2 = Convert.ToDouble(Console.ReadLine());
                    soma = n1 + n2;
                    Console.WriteLine("Resultado da soma: " + soma);
                            break;
                        case 2:
                            Console.Clear();
                            Console.WriteLine("Informe o primeiro número");
                    n1 = Convert.ToDouble(Console.ReadLine());
                    Console.WriteLine("Informe o segundo número");
                    n2 = Convert.ToDouble(Console.ReadLine());
                    sub = n1 - n2;
                    Console.WriteLine("Resultado da Subtração: " + sub);
                            break;
                        case 3:
                            Console.Clear();
                            Console.WriteLine("Informe o primeiro número");
                    n1 = Convert.ToDouble(Console.ReadLine());
                    Console.WriteLine("Informe o segundo número");
                    n2 = Convert.ToDouble(Console.ReadLine());
                    divi = n1 / n2;
                    Console.WriteLine("Resultado da Divisão: " + divi);
                            break;
                        case 4:
                            Console.Clear();
                            Console.WriteLine("Informe o primeiro número");
                    n1 = Convert.ToDouble(Console.ReadLine());
                    Console.WriteLine("Informe o segundo número");
                    n2 = Convert.ToDouble(Console.ReadLine());
                    mult = n1 * n2;                   
                    Console.WriteLine("Resultado da Multiplicação: " + mult);
                            break;

                    }                   
                    break;
                case 3:
                    Console.Clear();
                    Console.WriteLine("Informe seu nome: ");
                    nome = Console.ReadLine();
                    Console.WriteLine("Informe o valor a ser depositado");
                    depositado = Convert.ToDouble(Console.ReadLine());
                    taxa = depositado * 0.96;
                    Console.WriteLine("O Cliente " + nome.ToUpper() + " depositou: " + depositado + " contudo seu saldo é de:" + taxa);
                    break;

            }

        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            diadois mostrar;
            mostrar = new diadois();
            mostrar.MostrarTudo();
        }
    }
}


