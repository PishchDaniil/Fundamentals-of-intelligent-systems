```C++
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <deque>
#include <math.h>
#define endl cout<<"\n";
using namespace std;
template<typename T>



class Print
{
public:
    void print_in_all_codes(vector<int> first, vector<int>second, vector<int>third, T figure) //function for input vectors
    {
        if (figure > 0)
        {
            cout << "Number  " << figure << " in binary representation:\n";
        }
        else
        {
            cout << "Number " << figure << " in binary representation:\n";
        }
        cout << "In straight code: ";
        print_result(first);

        cout << "In backward code: ";
        print_result(second);

        cout << "In addition code: ";
        print_result(third);
    }

    void print_result_operations(vector<int> first, vector<int> second, vector<int> third, T num1, T num2)
    {
        cout << "Summation numbers " << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
        cout << "In straight code: ";
        print_result_revers(first);
        cout << "In backward code: ";
        print_result_revers(second);
        cout << "In addition code: ";
        print_result_revers(third);

        endl

    }

   void print_result(vector<int> vr)
    {
        for (int i = 0; i < vr.size(); i++)
        {
            cout << vr[i];
        }

        endl
    }

   void print_result_revers(vector<int> vr)
    {
        for (int i = vr.size() - 1; i >= 0; i--)
        {
            cout << vr[i];
        }

        endl
    }

   void print_multiplications(deque<int> dq)
   {
       for (int i = 0; i < dq.size(); i++)
       {
           cout << dq[i];
       }
       endl
   }

   void print_result_multiplications(deque<int> first, deque<int> second, deque<int> third, T num1, T num2)
   {
       cout << "Multiplications numbers " << num1 << " * " << num2 << " = " << num1 * num2 << "\n";
       cout << "In straight code: ";
       print_multiplications(first);
       cout << "In backward code: ";
       print_multiplications(second);
       cout << "In addition code: ";
       print_multiplications(third);
       endl
   }

   void print_result_deviding(deque<int> first, T num1, T num2)
   {

       cout << "Deviding numbers " << num1 << " / " << num2 << "\n";
       if (num1 < 0 && num2 > 0  || num1 > 0 && num2 < 0) cout << "-";
       
       
           print_deviding(first);
      
       endl
   }  

   void print_deviding(deque<int> dq)
   {
       
       for (int i = 0; i < dq.size(); i++)
       {
           if (i == 1) cout<<",";
           cout << dq[i];
       }
       endl
   }
};

class Numbers : public Print<int>
{ 
private:
    vector<int> direct;
    vector<int> backward;
    vector<int> additional;
    vector<int> result_direct;
    vector<int> result_backward;
    vector<int> result_additional;
    deque<int> result_multiplication_direct;
    deque<int> result_multiplication_backward;
    deque<int> result_multiplication_additional;
    deque<int> result_division_direct;
    deque<string> result_summation_FP;
    int numbr;
public:

    Numbers();

    Numbers(int num)
    {
        numbr = num;
        converting_to_binary(num);
    }

    vector<int> get_direct_vector()
    {
        return direct;
    }

    vector<int> get_backward_vector()
    {
        return backward;
    }

    vector<int> get_additional_vector()
    {
        return  additional;
    }

    vector<int> get_result_direct_vector()
    {
        return  result_direct;
    }

    vector<int> get_result_backward_vector()
    {
        return  result_backward;
    }

    vector<int> get_result_additional_vector()
    {
        return  result_additional;
    }

    deque<int> get_result_direct_multiplication_vector()
    {
        return  result_multiplication_direct;
    }

    deque<int> get_result_backward_multiplication_vector()
    {
        return  result_multiplication_backward;
    }

    deque<int> get_result_additional_multiplication_vector()
    {
        return  result_multiplication_additional;
    }

    deque<int> get_result_direct_deviding_vector()
    {
        return  result_division_direct;
    }

    int get_numbr()
    {
        return numbr;
    }

    void converting_to_binary(int number)  
    {
        bool isPositiveNumber = true;   
        int Dec_number = number;  
        stack<int> steck;  
        const int DIVIDER = 2;         

        if (number < 0)
        {
            number = abs(number);                  
            isPositiveNumber = false;
        }

        while (number >= 1)
        {
            steck.push(number % 2);  
            number = number / DIVIDER;

        }

        if (steck.size() < 16)               
        {
            for (int i = 0; i < 16 - steck.size(); i++)
            {
                direct.push_back(0);
            }
        }

        while (!steck.empty())
        {
            direct.push_back(steck.top());      
            steck.pop();                       
        }

        if (isPositiveNumber)
        {
            backward = direct;
            additional = direct;
        }

        else
        {
            backward = direct;         
            convertin_to_backward();
            additional = backward;    
            convertin_to_additional(16);
        }

        endl

    }

    void convertin_to_backward()
    {
        for (int i = 0; i < backward.size(); i++)
        {       
            if (backward[i] == 0) backward[i] = 1; 
            else backward[i] = 0;

        }
    }

    int convertin_to_additional(int n)
    {
        n--;
        if (n == 0)
        {
            if (additional[0] == 0) additional[0] = 1;
            else
            {
                additional[0] = 0;
                additional[7] = 1;
            }
        }
        if (additional[n] == 0)
        {
            additional[n] = 1;
            return NULL;
        }
        else
        {
            additional[n] = 0;
            return convertin_to_additional(n);

        }
    }

    int convertin_to_additional_multiplication(int n)
    {
        n--;
        if (n == 0)
        {
            if (result_multiplication_additional[0] == 0) result_multiplication_additional[0] = 1;
            else
            {
                result_multiplication_additional[0] = 0;
                result_multiplication_additional[7] = 1;
            }
        }
        if (result_multiplication_additional[n] == 0)
        {
            result_multiplication_additional[n] = 1;
            return NULL;
        }
        else
        {
            result_multiplication_additional[n] = 0;
            return convertin_to_additional_multiplication(n);

        }
    }

    int backward_for_summ(int n)
    {
        n++;
        if (n == 7)
        {
            if (result_backward[7] == 0) result_backward[0] = 1;
            else
            {
                result_backward[7] = 0;

            }
        }
        if (result_backward[n] == 0)
        {
            result_backward[n] = 1;
            return NULL;
        }
        else
        {
            result_backward[n] = 0;
            return backward_for_summ(n);

        }
    }

    void reverse_backward_for_direct()
    {
        for (int i = 0; i < result_direct.size(); i++)
        {     
            if (result_direct[i] == 0) result_direct[i] = 1;  
            else result_direct[i] = 0;

        }
    }

    const Numbers& operator+(const Numbers& num) 
    {
        result_direct.clear();
        result_backward.clear();
        result_additional.clear();
        bool two_positive_numbers = false, remains,two_negative_numbers=false,one_negative=false;
        if (this->numbr > 0 && num.numbr > 0) two_positive_numbers = true;
        if (this->numbr < 0 && num.numbr < 0) two_negative_numbers = true;
        else one_negative = true;
        if (two_positive_numbers)
        {
            remains = true;
            for (int i = this->direct.size() - 1; i >= 0; i--)
            {

                if (this->direct[i] == 0 && num.direct[i] == 1 && remains || this->direct[i] == 1 && num.direct[i] == 0 && remains)
                {
                    result_direct.push_back(1);
                    continue;
                }

                else if (this->direct[i] == 0 && num.direct[i] == 1 && remains == false || this->direct[i] == 1 && num.direct[i] == 0 && remains == false)
                {
                    result_direct.push_back(0);
                    remains = false;
                    continue;
                }

                else if (this->direct[i] == 0 && num.direct[i] == 0 && remains)
                {
                    result_direct.push_back(0);
                    continue;
                }

                else if (this->direct[i] == 0 && num.direct[i] == 0 && remains == false)
                {
                    result_direct.push_back(1);
                    remains = true;
                    continue;
                }

                else if (this->direct[i] == 1 && num.direct[i] == 1 && remains)
                {
                    result_direct.push_back(0);
                    remains = false;
                    continue;
                }

                else
                {
                    result_direct.push_back(1);
                    remains = false;
                    continue;
                }

            }
            result_backward = result_direct;
            result_additional = result_direct;
           
        }

        else 
        {
            remains = true;
            for (int i = this->additional.size() - 1; i >= 0; i--)
            {

                if (this->additional[i] == 0 && num.additional[i] == 1 && remains || this->additional[i] == 1 && num.additional[i] == 0 && remains)
                {
                    result_additional.push_back(1);
                    continue;
                }

                else if (this->additional[i] == 0 && num.additional[i] == 1 && remains == false || this->additional[i] == 1 && num.additional[i] == 0 && remains == false)
                {
                    result_additional.push_back(0);
                    remains = false;
                    continue;
                }

                else if (this->additional[i] == 0 && num.additional[i] == 0 && remains)
                {
                    result_additional.push_back(0);
                    continue;
                }

                else if (this->additional[i] == 0 && num.additional[i] == 0 && remains == false)
                {
                    result_additional.push_back(1);
                    remains = true;
                    continue;
                }

                else if (this->additional[i] == 1 && num.additional[i] == 1 && remains)
                {
                    result_additional.push_back(0);
                    remains = false;
                    continue;
                }

                else
                {
                    result_additional.push_back(1);
                    remains = false;
                    continue;
                }
                
            }

           //backward
            remains = true;
            for (int i = this->backward.size() - 1; i >= 0; i--)
            {

                if (this->backward[i] == 0 && num.backward[i] == 1 && remains || this->backward[i] == 1 && num.backward[i] == 0 && remains)
                {
                    result_backward.push_back(1);
                    continue;
                }

                else if (this->backward[i] == 0 && num.backward[i] == 1 && remains == false || this->backward[i] == 1 && num.backward[i] == 0 && remains == false)
                {
                    result_backward.push_back(0);
                    remains = false;
                    continue;
                }
                
                else if (this->backward[i] == 0 && num.backward[i] == 0 && remains)
                {
                    result_backward.push_back(0);
                    continue;
                }

                else if (this->backward[i] == 0 && num.backward[i] == 0 && remains == false)
                {
                    result_backward.push_back(1);
                    remains = true;
                    continue;
                }

                else if (this->backward[i] == 1 && num.backward[i] == 1 && remains)
                {
                    result_backward.push_back(0);
                    remains = false;
                    continue;
                }

                else
                {
                    result_backward.push_back(1);
                    remains = false;
                    continue;
                }

            }

            if (one_negative)
            {
                if (numbr + num.numbr > 0)
                {
                    result_backward = result_additional;
                    result_direct = result_additional;
                }
                else
                {
                   
                    result_direct = result_backward;
                    reverse_backward_for_direct();
                }
            }
            else
            {
                backward_for_summ(-1);
                result_direct = result_backward;
                reverse_backward_for_direct();
                //direct
            }
        }

        return *this;
    }

    const Numbers& operator*(const Numbers& num)
    {
        deque<int> first_sum;
        first_sum.clear();
        int counter=0;
        result_multiplication_direct.clear();
        result_multiplication_backward.clear();
        result_multiplication_additional.clear();
        bool remains,one_negative_numbr=false;
        if (numbr < 0 || num.numbr < 0) one_negative_numbr = true;
        if (numbr < 0 && num.numbr < 0) one_negative_numbr = false;

        for (int i = 0; i < 16; i++)
        {
            result_multiplication_direct.push_back(0);
        }

        for (int i = this->direct.size() - 1; i >= 0; i--)
        {

            if (num.direct[i] == 1)
            {
                first_sum.clear();
                

                for (int j = direct.size() - 1; j >= 0; j--)
                {
                    
                    if (direct[j] == 1) first_sum.push_front(1);
                    else first_sum.push_front(0);
                    
                }
                
                for (int q = 0; q < counter; q++)
                {              
                    first_sum.push_back(0);
                    first_sum.pop_front();
                }
                remains = true;
                for (int i = first_sum.size() - 1; i >= 0; i--)
                {

                    if (first_sum[i] == 0 && result_multiplication_direct[i] == 1 && remains || first_sum[i] == 1 && result_multiplication_direct[i] == 0 && remains)
                    {
                        result_multiplication_direct[i] = 1;
                        continue;
                    }

                    else if (first_sum[i] == 0 && result_multiplication_direct[i] == 1 && remains == false || first_sum[i] == 1 && result_multiplication_direct[i] == 0 && remains == false)
                    {
                        result_multiplication_direct[i] = 0;
                        remains = false;
                        continue;
                    }

                    else if (first_sum[i] == 0 && result_multiplication_direct[i] == 0 && remains)
                    {
                        result_multiplication_direct[i] = 0;
                        continue;
                    }

                    else if (first_sum[i] == 0 && result_multiplication_direct[i] == 0 && remains == false)
                    {
                        result_multiplication_direct[i] = 1;
                        remains = true;
                        continue;
                    }

                    else if (first_sum[i] == 1 && result_multiplication_direct[i] == 1 && remains)
                    {
                        result_multiplication_direct[i] = 0;
                        remains = false;
                        continue;
                    }

                    else
                    {
                        result_multiplication_direct[i] = 1;
                        remains = false;
                        continue;
                    }
                     
                }
                counter++;
            }
           
            else counter++;
        }

        if (one_negative_numbr)
        {
            
            result_multiplication_backward = result_multiplication_direct;

            for (int i = 0; i < result_multiplication_backward.size(); i++)
            {
                if (result_multiplication_backward[i] == 0) result_multiplication_backward[i] = 1;
                else result_multiplication_backward[i] = 0;

            }

            result_multiplication_additional = result_multiplication_backward;
            convertin_to_additional_multiplication(16);
        }

        else
        {
            
            result_multiplication_backward = result_multiplication_direct;
            result_multiplication_additional = result_multiplication_backward;
        }


        return *this;
    }

    const Numbers& operator/(const Numbers& num)
    {
        result_division_direct.clear();
        const int DIVIDER = 2;
        int first_number = abs(numbr), num1 = abs(numbr);
        int second_numbr = abs(num.numbr), num2 = abs(num.numbr);
        bool stop = false;
       
        deque<int> first_number_for_deviding, second_number_for_deviding;
        while (first_number >= 1)
        {
            first_number_for_deviding.push_front(first_number % 2);
            first_number = first_number / DIVIDER;
        }

        while (second_numbr >= 1)
        {
            second_number_for_deviding.push_front(second_numbr % 2);
            second_numbr = second_numbr / DIVIDER;
        }

        int count = 0;
        while (count < 5)
        {
            
            if (first_number_for_deviding.size() < second_number_for_deviding.size())
            {
                result_division_direct.push_front(0);
                first_number_for_deviding.push_back(0);
                count++;
                continue;
            }

            else if (first_number_for_deviding.size() == second_number_for_deviding.size())
            {
                result_division_direct.push_front(1);

                for (int i = 0; i < first_number_for_deviding.size(); i++)
                {
                    if (second_number_for_deviding[i] == 1 && first_number_for_deviding[i] == 0 || second_number_for_deviding[i] == 0 && first_number_for_deviding[i] == 1)
                    {
                        first_number_for_deviding[i] = 1;
                        stop = true;
                    }

                    else if (!stop)
                    {
                        first_number_for_deviding.pop_front();
                    }
                }
            }

            count++;
        }

        if (num1/num2 < 1) result_division_direct.push_front(0);
        
        return *this;
    }

    const Numbers& summation_two_float_numbers(const Numbers& num)
    {
        deque<bool> int_part1_in_binary, int_part2_in_binary, float_part1_in_binary, float_part2_in_binary;
        float int_part1, float_part1, int_part2, float_part2;
        float_part1 = modf(numbr, &int_part1);
        float_part2 = modf(num.numbr, &int_part2);

        return *this;
    }
};



void main()
{
    setlocale(LC_ALL, "ru");
    int choose; 
    int num1= 123, num2=3;
    cout << "Input first & second numbers:\n";
    //cin >> num1 >> num2; 
    Numbers x1(num1), x2(num2),x3(-num1),x4(-num2);
    Print<int> out;
    bool breaker = true;
    system("cls");
    while (breaker)
    { 
    cout << "Select and tape key action| 1 - View binary code, 2 - Operations (+, - , * , /), 0 - out:\n";
    cin >> choose;
    switch (choose)
    {

    case 1:
    {
        out.print_in_all_codes(x1.get_direct_vector(), x1.get_backward_vector(), x1.get_additional_vector(), x1.get_numbr());
        endl
            out.print_in_all_codes(x2.get_direct_vector(), x2.get_backward_vector(), x2.get_additional_vector(), x2.get_numbr());
        endl
            out.print_in_all_codes(x3.get_direct_vector(), x3.get_backward_vector(), x3.get_additional_vector(), x3.get_numbr());
        endl
            out.print_in_all_codes(x4.get_direct_vector(), x4.get_backward_vector(), x4.get_additional_vector(), x4.get_numbr());
        endl
            break;

    }
    case 2:
    {
        int chooce;
        bool repeat = true;
        while (repeat)
        {
            cout << "Select and tape key action|\n1 - Operations (+, -)\n2 - Operatios(| x1 | * | x2 |)\n3 - Operatios(| x1 | / | x2 |)\n4 - Summation Float Numbers\n0 - exit:\n";
            cin >> chooce;
            switch (chooce)
            {
            case 0:
            {
                cout << "Esc to main menu!\n";
                repeat = false;
                break;
            }
            case 1:
            {
                x1 + x2;
                out.print_result_operations(x1.get_result_direct_vector(), x1.get_result_backward_vector(), x1.get_result_additional_vector(), x1.get_numbr(), x2.get_numbr());
                x2 + x3;
                out.print_result_operations(x2.get_result_direct_vector(), x2.get_result_backward_vector(), x2.get_result_additional_vector(), x2.get_numbr(), x3.get_numbr());
                x3 + x4;
                out.print_result_operations(x3.get_result_direct_vector(), x3.get_result_backward_vector(), x3.get_result_additional_vector(), x3.get_numbr(), x4.get_numbr());
                x4 + x1;
                out.print_result_operations(x4.get_result_direct_vector(), x4.get_result_backward_vector(), x4.get_result_additional_vector(), x4.get_numbr(), x1.get_numbr());
                break;
            }

            case 2:
            {  
                try
                {

                    if (num1 == 0 || num2 == 0) throw 3;
                    x1 * x2;
                    out.print_result_multiplications(x1.get_result_direct_multiplication_vector(), x1.get_result_backward_multiplication_vector(), x1.get_result_additional_multiplication_vector(), x1.get_numbr(), x2.get_numbr());
                    x2 * x3;
                    out.print_result_multiplications(x2.get_result_direct_multiplication_vector(), x2.get_result_backward_multiplication_vector(), x2.get_result_additional_multiplication_vector(), x2.get_numbr(), x3.get_numbr());
                    x3 * x4;
                    out.print_result_multiplications(x3.get_result_direct_multiplication_vector(), x3.get_result_backward_multiplication_vector(), x3.get_result_additional_multiplication_vector(), x3.get_numbr(), x4.get_numbr());
                    x4 * x1;
                    out.print_result_multiplications(x4.get_result_direct_multiplication_vector(), x4.get_result_backward_multiplication_vector(), x4.get_result_additional_multiplication_vector(), x4.get_numbr(), x1.get_numbr());
                   
                }

                catch (int i)
                {
                    if (i == 3)
                    {
                        deque<int> null_multiplication{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
                        out.print_result_multiplications(null_multiplication, null_multiplication, null_multiplication, x1.get_numbr(), x2.get_numbr());
                        out.print_result_multiplications(null_multiplication, null_multiplication, null_multiplication, x2.get_numbr(), x3.get_numbr());
                        out.print_result_multiplications(null_multiplication, null_multiplication, null_multiplication, x3.get_numbr(), x4.get_numbr());
                        out.print_result_multiplications(null_multiplication, null_multiplication, null_multiplication, x4.get_numbr(), x1.get_numbr());
                    }
                }
                
                break;
            }

            case 3:
            {
                try
                {

                    if (num1 !=0 && num2 == 0) throw 1;
                    else if (num1 == 0) throw 2;
                    x1 / x2;
                    out.print_result_deviding(x1.get_result_direct_deviding_vector(), x1.get_numbr(), x2.get_numbr());
                    x1 / x4;
                    out.print_result_deviding(x1.get_result_direct_deviding_vector(), x1.get_numbr(), x4.get_numbr());
                    x3 / x4;
                    out.print_result_deviding(x3.get_result_direct_deviding_vector(), x3.get_numbr(), x4.get_numbr());
                    x3 / x2;
                    out.print_result_deviding(x3.get_result_direct_deviding_vector(), x3.get_numbr(), x2.get_numbr());
                    

                }

                catch (int i)
                {
                    if (i == 1) cout << "ERROR!!! " << i << " - DEVISION BY ZERO!!!\n";
                    else 
                    {
                        deque<int> null_deviding{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
                        out.print_result_deviding(null_deviding, x1.get_numbr(), x2.get_numbr());
                        out.print_result_deviding(null_deviding, x1.get_numbr(), x4.get_numbr());
                        out.print_result_deviding(null_deviding, x3.get_numbr(), x4.get_numbr());
                        out.print_result_deviding(null_deviding, x3.get_numbr(), x2.get_numbr());
                    }
                }
                break;
            }
            case 4:
            {
                x1.summation_two_float_numbers(x2);
                break;
            }

            default:
                cout << "Input no define key\n";
                break;
            }
            system("pause");
            system("cls");

        }
        
        break;
        
        
    }
     
    case 0:
    {
        breaker = false;
        break;
    }

    default:
        cout << "Input no define key\n";
        break;
    }

    system("pause");
    system("cls");

  }

  
   


}
```



