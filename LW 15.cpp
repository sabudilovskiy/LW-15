#include <iostream>
#include <string>
#include <vector>
#include <math.h>

const float pi = 3.1415926535897932384626433832;

float my_abs(float x);
float my_sin(float x);
float my_cos(float x);
float my_tg(float x);
float my_ctg(float x);
float my_arcsin(float x);
float my_arccos(float x);
float my_arctg(float x);
float my_arcctg(float x);
float my_exp(float x);
float my_ln(float x);
float my_log(float base, float x);
float my_factorial(int a);
float my_pow(float a, float b); //a^b
float my_mult(float a, float b);
float my_division(float a, float b);
float my_plus(float a, float b);
float my_minus(float a, float b);

bool always_true(float x);
bool check_tg(float x);
bool check_ctg(float x);
bool check_ln(float x);
bool check_logarifm(float a, float b);
bool check_factorial(float x);
bool two_always_true(float a, float b);
bool check_pow(float a, float b);
bool check_division(float a, float b);

float my_abs(float x)
{
    return abs(x);
}
float my_sin(float x)
{
    const float eps = 0.0000000001;
    float element = x, sum = element;
    x = -x * x;
    float i = 3;
    while (abs(element) > eps)
    {
        element *= x / (i * (i - 1));
        sum += element;
        i += 2;
    }
    return sum;
}
float my_cos(float x)
{
    const float eps = 0.0000000001;
    float element = 1, sum = element;
    x = -x * x;
    float i = 2;
    while (abs(element) > eps)
    {
        element *= x / (i * (i - 1));
        sum += element;
        i += 2;
    }
    return sum;
}
float my_tg(float x)
{
    return my_sin(x) / my_cos(x);
}
float my_ctg(float x)
{
    const float eps = 0.0000000001;
    return my_cos(x) / my_sin(x);
}
float my_arcsin(float x)
{
    const float eps = 0.0000000001;
    float element = x, sum = element;
    x = x * x;
    float i = 1;
    while (abs(element) > eps)
    {
        element *= x * (2 * i + 1) / ((2 * i + 2) * (2 * i + 3));
        sum += element;
        i++;
    }
    return sum;
}
float my_arccos(float x)
{
    const float eps = 0.0000000001;
    return pi / 2 - my_arcsin(x);
}
float my_arctg(float x)
{
    const float eps = 0.000001;
    if (abs(x) < 1)
    {
        double element = x, sum = element;
        double sqx = -x * x;
        int i = 2;
        while (abs(element) > eps)
        {
            element = element * sqx * (2 * i + 1) / (2 * i + 3);
            sum += element;
            i++;
        }
        return sum;
    }
    else
    {
        int i = 2;
        double element = -1/x, sum = (pi/2)*abs(x)/(x) + element;
        double sqx = -1/ (x * x);
        while (abs(element) > eps)
        {
            element = element * sqx * (2 * i - 1) / (2 * i + 1);
            sum += element;
            i++;
        }
        return sum;
    }
}
float my_arcctg(float x)
{
    return my_arctg(1/x);
}
float my_exp(float x)
{
    const float eps = 0.0000000001;
    float sum, element = 1;
    sum = element;
    int i = 1;
    while (abs(element) > eps)
    {
        element = element * x / i;
        sum += element;
        i++;
    }
    return sum;
}
float my_ln(float x)
{
    const float eps = 0.0000000001;
    if (x < 2)
    {
        float element = x - 1;
        float sum = element;
        float i = 2;
        while (abs(element) > eps)
        {
            element *= (1 - x) * (i - 1) / i;
            sum += element;
            i++;
        }
        return sum;
    }
    else if (x == 2) return 0.693147180559945309;
    else
    {
        float element = 1 / (x - 1);
        float sum = element;
        float i = 2;
        while (abs(element) > eps)
        {
            element *= -1 / (x - 1) * (i - 1) / i;
            sum += element;
            i++;
        }
        return sum + my_ln(x - 1);
    }
}
float my_log(float base, float x)
{
    return my_ln(x) / my_ln(base);
}
float my_factorial(int a)
{
    int answer = 1;
    for (a; a > 1; a--) answer *= a;
    return answer;
}
float my_pow(float a, float b)
{
    const float eps = 0.0000000001;
    if (b - trunc(b) == 0)
    {
        if (b == 0) return 1;
        else if (b > 0)
        {
            float answer = 1;
            for (; b > 0; b--)answer *= a;
            return answer;
        }
        else
        {
            float answer = 1;
            for (; b > 0; b--)answer /= a;
            return answer;
        }
    }
    else if (a > 0)
    {
        return my_exp(b * my_ln(a));
    }
}
float my_mult(float a, float b)
{
    return a * b;
}
float my_division(float a, float b)
{
    return a / b;
}
float my_plus(float a, float b)
{
    return a + b;
}
float my_minus(float a, float b)
{
    return a - b;
}

bool always_true(float x)
{
    return 1;
}
bool check_tg(float x)
{
    if (cos(x) == 0) return 0;
    else return 1;
}
bool check_ctg(float x)
{
    if (sin(x) == 0) return 0;
    else return 1;
}
bool check_ln(float x)
{
    if (x > 0) return 1;
    else return 0;
}
bool check_logarifm(float a, float b)
{
    if (a > 0 and a != 1 and b > 0) return 1;
    else return 0;
}
bool check_factorial(float x)
{
    if (x > 0 and x - trunc(x) == 0) return 1;
    else return 0;
}
bool two_always_true(float a, float b)
{
    return 1;
}
bool check_pow(float a, float b)
{
    if (a > 0) return 1;
    else
    {
        if (b - trunc(b) == 0)
        {
            if (a != 0 or b >= 0)
            {
                return 1;
            }
        }
    }
    return 0;
}
bool check_division(float a, float b)
{
    if (b == 0) return 0;
    else return 1;
}

enum id_lexemes
{
    //операции в приоритете
    //пре-унарные операторы, высший приоритет
    ABS, SIN, COS, TG, CTG, ARCSIN, ARCCOS, ARCTG, ARCCTG, EXP, LN, 
    //псевдо пре-унарный оператор
    LOG,
    //пост-унарные операторы, приоритет: 2
    FACTORIAL,
    //бинарные операторы, приоритет: 3
    POW,
    //бинарные операторы, приоритет: 4
    MULT, DIVISION,
    //бинарные операторы, низший приоритет
    PLUS, MINUS,
    //технические вещи
    NUMBER, X, LEFT_BR, RIGHT_BR, COMMA, END
};
class Lexeme
{
private:
    id_lexemes id;
    float value;
public:
    Lexeme(id_lexemes id, float value = 0)
    {
        this->id = id;
        this->value = value;
    }
    id_lexemes get_id()
    {
        return id;
    }
    float get_value()
    {
        return value;
    }
};
class Sentence
{
private:
    int pos = 0;
    std::vector <Lexeme> array;
    std::vector <int> stat;
public:
    Sentence()
    {
        stat.resize(24);
    };
    Sentence(std::vector <Lexeme> array)
    {
        stat.resize(24);
        for (int i = 0; i < array.size(); i++) add_lexeme(array[i]);
    }
    //возвращает количество лексем определённого вида
    int get_stat(id_lexemes i)
    {
        return stat[i];
    }
    //переходим к следующей лексеме
    void go_next_lexeme()
    {
        if (pos < array.size() - 1)
        {
            pos++;
        }
    }
    //возвращаемся к предыдущей лексеме
    void go_back_lexeme()
    {
        if (pos > 0)
        {
            pos--;
        }
    }
    //устанавить текующую лексему по номеру
    void set_pos(int i)
    {
        pos = i;
    }
    //получить номер лексемы-конца
    int get_end()
    {
        return array.size() - 1;
    }
    //добавить лексему
    void add_lexeme(Lexeme a)
    {
        array.push_back(a);
        stat[a.get_id()]++;
    }
    //получить текущую лексему
    Lexeme get_lexeme()
    {
        return array[pos];
    }
    //получить лексему на i номер больше
    Lexeme get_next_lexeme(unsigned int i = 1)
    {
        return array[pos + i];
    }
    //получить лексему на i номер меньше
    Lexeme get_previous_lexeme(unsigned int i = 1)
    {
        return array[pos-i];
    }
    //удалить лексему с таким номером
    void delete_lexeme(int i)
    {
        stat[array[i].get_id()]--;
        if (pos >= i and pos != 0) pos--; //сейвим местоположение
        array.erase(array.begin() + i);
    }
    //заменить лексему x на значение
    void substitute(float x)
    {
        if (stat[X] > 0)
        {
            for (int i = 0; i < array.size(); i++)
            {
                if (array[i].get_id() == X)
                {
                    array[i] = Lexeme(NUMBER, x);
                }
            }
            stat[NUMBER] += stat[X];
            stat[X] = 0;
        }
    }
    //создать новое предложение из части старого
    Sentence create_lexeme_vector(unsigned int a, unsigned int b)
    {
        std::vector <Lexeme> buffer;
        for (int i = a; i <= b; i++)
        {
            buffer.push_back(array[i]);
        }
        return Sentence(buffer);
    }
    //заменить диапазон на одну лексему
    void replace_sector(unsigned int a, unsigned int b, Lexeme paste)
    {
        for (int i = a; i < b; i++)
        {
            this->delete_lexeme(i);
        }
        stat[array[b].get_id()]--;
        array[b] = paste;
        stat[paste.get_id()]++;
    }
    int find_highest_comma(int& error)
    {
        int answer = 0;
        bool found_comma = 0;
        for (int i = 0; array[i].get_id() != END; i++)
        {
            if (array[i].get_id() == COMMA)
            {
                if (found_comma == 0)
                {
                    answer = i;
                    found_comma = 1;
                }
                else
                {
                    error = 1;
                    return answer;
                }
            }
            else if (array[i].get_id() == LEFT_BR)
            {
                i = find_right_bracket(i) + 1;
            }
        }

    }
    //проверить вектор на ошибки(избыточное использование знаков)
    bool check_errors()
    {
        for (int i = 0; array[i].get_id() != END; i++)
        {
            if (POW <= array[i].get_id() and array[i].get_id() <= MINUS and POW <= array[i + 1].get_id() and array[i].get_id() <= MINUS)
            {
                return 1;
            }
        }
        return 0;
    }
    //найти лексему с определённым id
    int find_id_lexeme(id_lexemes id)
    {
        if (stat[id] > 0)
        {
            for (int i = 0; i < array.size(); i++)
            {
                if (array[i].get_id() == LEFT_BR)
                {
                    return i;
                }
            }
        }
        else return -1;
    }
    //найти закрывающую скобку для открывающей
    int find_right_bracket(unsigned int a)
    {
        int count_open_brackets = 1;
        for (int i = a + 1; ; i++)
        {
            if (array[i].get_id() == LEFT_BR) count_open_brackets++;
            else if (array[i].get_id() == RIGHT_BR) count_open_brackets--;
            if (count_open_brackets == 0)
            {
                return i;
            }
        }
    }
    //посчитать значение предложения
    Lexeme count(int& error, std::vector<void*>& functions, std::vector<void*>& check_countable)
    {
        Lexeme Answer = Lexeme(NUMBER);
        set_pos(0);
        while (get_lexeme().get_id() != END)
        {
            if (get_lexeme().get_id() == LEFT_BR)
            {
                int a = pos;
                int b = find_right_bracket(a);
                if (pos == 0 or get_previous_lexeme().get_id() != LOG)
                {
                    Sentence temp = create_lexeme_vector(a, b);
                    Lexeme temp2 = temp.count(error, functions, check_countable);
                    replace_sector(a, b, temp2);
                    if (error != 0)
                    {
                        return Answer;
                    }
                }
                else
                {
                    Sentence temp = create_lexeme_vector(a + 1, b - 1);
                    int border = temp.find_highest_comma(error);
                    if (error == 0)
                    {
                        replace_sector(a + 1, a + border, create_lexeme_vector(a + 1, a + border).count(error,functions, check_countable));
                        replace_sector(a + border + 2, b - 1, create_lexeme_vector(a + border + 2, b - 1).count(error,functions, check_countable));
                    }
                    else
                    {
                        return Answer;
                    }
                }
            }
            go_next_lexeme();
        }
        //избавляемся от функций
        set_pos(0);
        while (get_lexeme().get_id() != END)
        {
            if (ABS <= get_lexeme().get_id() and get_lexeme().get_id() <= LN and get_next_lexeme().get_id() == NUMBER)
            {
                float arguement = get_next_lexeme().get_value();
                float value;              
                if (reinterpret_cast<bool(*)(float)>(check_countable[get_lexeme().get_id()])(arguement) == 1)
                {
                    value = reinterpret_cast<float(*)(float)>(check_countable[get_lexeme().get_id()])(arguement);
                    replace_sector(pos, pos + 1, Lexeme(NUMBER, value));
                    //возвращемся назад, возможно мы сможем что-то ещё посчитать
                    if (pos > 0) go_back_lexeme();
                }
                else
                {
                    error = 2;
                    return Answer;
                }
            }
            else if (get_lexeme().get_id() == LOG)
            {
                float a = get_next_lexeme(2).get_value();
                float b = get_next_lexeme(4).get_value();
                if (reinterpret_cast<bool(*)(float, float)>(check_countable[get_lexeme().get_id()])(a, b) == 1)
                {
                    float value = reinterpret_cast<float(*)(float, float)>(check_countable[get_lexeme().get_id()])(a,b);
                    replace_sector(pos, pos + 6, Lexeme(NUMBER, value));
                    //возвращемся назад, возможно мы сможем что-то ещё посчитать
                    if (pos > 0) go_back_lexeme();
                }
            }
            else go_next_lexeme();
        }
        //избавляемся от факториалов
        set_pos(0);
        while (get_lexeme().get_id() != END)
        {
            if (get_lexeme().get_id() == NUMBER and get_next_lexeme().get_id() == FACTORIAL)
            {
                float arguement = get_lexeme().get_value();
                if (reinterpret_cast<bool(*)(float)>(check_countable[get_lexeme().get_id()])(arguement) == 1)
                {
                    float value = reinterpret_cast<float(*)(float)>(check_countable[get_lexeme().get_id()])(arguement);
                    replace_sector(pos, pos + 1, Lexeme(NUMBER, value));
                    //не трогать
                    go_next_lexeme();
                }
                else
                {
                    error = 2;
                    return Answer;
                }
            }
        }
        //избавляемся от умножения и деления
        set_pos(1);
        while (get_lexeme().get_id() != END)
        {
            if (get_previous_lexeme().get_id() == NUMBER and (get_lexeme().get_id() == MULT or get_lexeme().get_id() == DIVISION) and get_next_lexeme().get_id() == NUMBER)
            {
                float a = get_previous_lexeme().get_value();
                float b = get_previous_lexeme().get_value();
                if (reinterpret_cast<bool(*)(float, float)>(check_countable[get_lexeme().get_id()])(a, b) == 1)
                {
                    float value = reinterpret_cast<float(*)(float, float)>(check_countable[get_lexeme().get_id()])(a, b);
                    replace_sector(pos-1, pos + 1, Lexeme(NUMBER, value));
                    //возвращемся назад, возможно мы сможем что-то ещё посчитать
                    if (pos > 0) go_back_lexeme();
                }
            }
            else go_next_lexeme();
        }
        //избавляемся от сложения и вычитания
        set_pos(1);
        while (get_lexeme().get_id() != END)
        {
            if (get_previous_lexeme().get_id() == NUMBER and (get_lexeme().get_id() == PLUS or get_lexeme().get_id() == MINUS) and get_next_lexeme().get_id() == NUMBER)
            {
                float a = get_previous_lexeme().get_value();
                float b = get_previous_lexeme().get_value();
                if (reinterpret_cast<bool(*)(float, float)>(check_countable[get_lexeme().get_id()])(a, b) == 1)
                {
                    float value = reinterpret_cast<float(*)(float, float)>(check_countable[get_lexeme().get_id()])(a, b);
                    replace_sector(pos - 1, pos + 1, Lexeme(NUMBER, value));
                    //возвращемся назад, возможно мы сможем что-то ещё посчитать
                    if (pos > 0) go_back_lexeme();
                }
            }
            else go_next_lexeme();
        }
        set_pos(0);
        Answer = get_lexeme();
    }
};

Sentence convert_to_lexemes(std::string input, int& error)
{
    Sentence answer;
    int pos = 0;
    while (pos < input.length())
    {
        if (answer.get_stat(LEFT_BR) >= answer.get_stat(RIGHT_BR))
        {
            while (pos < input.length() and input[pos] == ' ') pos++;
            if (input[pos] == '+')
            {
                answer.add_lexeme(Lexeme(PLUS));
                pos++;
            }
            else if (input[pos] == '-')
            {
                answer.add_lexeme(Lexeme(MINUS));
                pos++;
            }
            else if (input[pos] == '*')
            {
                answer.add_lexeme(Lexeme(MULT));
                pos++;
            }
            else if (input[pos] == '/')
            {
                answer.add_lexeme(Lexeme(DIVISION));
                pos++;
            }
            else if (input[pos] == '^')
            {
                answer.add_lexeme(Lexeme(POW));
                pos++;
            }
            else if (input[pos] == '!')
            {
                answer.add_lexeme(Lexeme(FACTORIAL));
                pos++;
            }
            else if (input[pos] == '(')
            {
                answer.add_lexeme(Lexeme(LEFT_BR));
                pos++;
            }
            else if (input[pos] == ')')
            {
                answer.add_lexeme(Lexeme(RIGHT_BR));
                pos++;
            }
            else if (input[pos] == ',')
            {
                answer.add_lexeme(Lexeme(RIGHT_BR));
                pos++;
            }
            else if ('0' < input[pos] and input[pos] < '9')
            {
                std::string buffer;
                bool use_point = 0;
                while (pos < input.length() and (input[pos] == '.' or ('0' < input[pos] and input[pos] < '9')))
                {
                    if (input[pos] == '.')
                    {
                        if (use_point == 0)
                        {
                            use_point++;
                            buffer.push_back(input[pos++]);
                        }
                        else
                        {
                            error = 1;
                            return answer;
                        }
                    }
                    else
                    {
                        buffer.push_back(input[pos++]);
                    }
                }
                answer.add_lexeme(Lexeme(NUMBER, stof(buffer)));
            }
            else
            {
                std::string buffer;
                while (pos < input.length() and 'a' < input[pos] and input[pos] < 'z' or pos < input.length() and 'A' < input[pos] and input[pos] < 'Z')
                {
                    buffer.push_back(input[pos++]);
                }
                if (buffer == "abs")
                {
                    answer.add_lexeme(Lexeme(ABS));
                }
                else if (buffer == "sin")
                {
                    answer.add_lexeme(Lexeme(SIN));
                }
                else if (buffer == "cos")
                {
                    answer.add_lexeme(Lexeme(COS));
                }
                else if (buffer == "tg" or buffer == "tan")
                {
                    answer.add_lexeme(Lexeme(TG));
                }
                else if (buffer == "ctg" or buffer == "cot")
                {
                    answer.add_lexeme(Lexeme(CTG));
                }
                else if (buffer == "arcsin")
                {
                    answer.add_lexeme(Lexeme(ARCSIN));
                }
                else if (buffer == "arccos")
                {
                    answer.add_lexeme(Lexeme(ARCCOS));
                }
                else if (buffer == "arctg" or buffer == "arctan")
                {
                    answer.add_lexeme(Lexeme(ARCTG));
                }
                else if (buffer == "arcctg" or buffer == "arccot")
                {
                    answer.add_lexeme(Lexeme(ARCCTG));
                }
                else if (buffer == "log")
                {
                    answer.add_lexeme(Lexeme(LOG));
                }
                else if (buffer == "ln")
                {
                    answer.add_lexeme(Lexeme(LN));
                }
                else if (buffer == "exp" or buffer == "e")
                {
                    answer.add_lexeme(Lexeme(EXP));
                }
                else if (buffer == "x" or buffer == "X")
                {
                    answer.add_lexeme(Lexeme(X));
                }
                else
                {
                    error = 1;
                    return answer;
                }
            }
        }
        else
        {
            error = 1;
            return answer;
        }
    }
    answer.add_lexeme(Lexeme(END));
    if (answer.get_stat(LEFT_BR) == answer.get_stat(RIGHT_BR) and answer.check_errors() == 0)
    {
        return answer;
    }
    else
    {
        error = 1;
        return answer;
    }
}

int main()
{
    float x;
    int error;
    std::vector<void*> functions;
    {
        functions.push_back(reinterpret_cast<void*>(my_abs));
        functions.push_back(reinterpret_cast<void*>(my_sin));
        functions.push_back(reinterpret_cast<void*>(my_cos));
        functions.push_back(reinterpret_cast<void*>(my_tg));
        functions.push_back(reinterpret_cast<void*>(my_ctg));
        functions.push_back(reinterpret_cast<void*>(my_arcsin));
        functions.push_back(reinterpret_cast<void*>(my_arccos));
        functions.push_back(reinterpret_cast<void*>(my_arctg));
        functions.push_back(reinterpret_cast<void*>(my_arcctg));
        functions.push_back(reinterpret_cast<void*>(my_exp));
        functions.push_back(reinterpret_cast<void*>(my_ln));
        functions.push_back(reinterpret_cast<void*>(my_log));
        functions.push_back(reinterpret_cast<void*>(my_factorial));
        functions.push_back(reinterpret_cast<void*>(my_pow));
        functions.push_back(reinterpret_cast<void*>(my_mult));
        functions.push_back(reinterpret_cast<void*>(my_division));
        functions.push_back(reinterpret_cast<void*>(my_plus));
        functions.push_back(reinterpret_cast<void*>(my_minus));    
    }
    std::vector<void*> check_countable;
    {
        for (int i = 0; i < 3; i++) check_countable.push_back(reinterpret_cast<void*>(always_true));
        check_countable.push_back(reinterpret_cast<void*>(check_tg));
        check_countable.push_back(reinterpret_cast<void*>(check_ctg));
        for (int i = 0; i < 5; i++) check_countable.push_back(reinterpret_cast<void*>(always_true));
        check_countable.push_back(reinterpret_cast<void*>(check_ln));
        check_countable.push_back(reinterpret_cast<void*>(check_logarifm));
        check_countable.push_back(reinterpret_cast<void*>(check_factorial));
        check_countable.push_back(reinterpret_cast<void*>(check_pow));
        check_countable.push_back(reinterpret_cast<void*>(two_always_true));
        check_countable.push_back(reinterpret_cast<void*>(check_division));
        check_countable.push_back(reinterpret_cast<void*>(always_true));
        check_countable.push_back(reinterpret_cast<void*>(always_true));
    }
    std::string buffer;
    std::getline(std::cin, buffer);
    std::cin >> x;
    Sentence Base = convert_to_lexemes(buffer, error);
    Base.substitute(x);
    Base.count(error, functions, check_countable);

}

