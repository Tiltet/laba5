#include <iostream>
#include <stdexcept>
#include <vector>
#include <type_traits>

class User
{
private:
    std::string login;
    std::string password;

public:
    User(std::string login, std::string password)
        : login(login), password(password) 
        {
            if (login == "qwerty" || password == "qwerty")
            {
                throw std::invalid_argument("Некорректные логин и пароль");
            }
        }

    friend std::ostream &operator<<(std::ostream &stream, const User &user)
    {
        stream << "Login = " << user.login << std::endl;
        stream << "Password = " << user.password << std::endl;
        return stream;
    }

    ~User() {}
};

template <typename T>
class Stack
{
private:
    std::vector<T> stack;

public:
    Stack() {}

    void push(const T value)
    {
        stack.push_back(value);
    }

    T pop()
    {
        if (stack.empty())
        {
            throw std::runtime_error("Стек пустой");
        }

        T poppedValue = stack.back();
        stack.pop_back();

        return poppedValue;
    }

    // static_assert(!std::is_same<T, double>::value , "Double");   ОГРАНИЧЕНИЕ ПО ТИПУ ДАННЫХ Double
    // static_assert(!std::is_same<T, int>::value, "Int");          ОГРАНИЧЕНИЕ ПО ТИПУ ДАННЫХ Int

    friend std::ostream &operator<<(std::ostream &stream, const Stack &userStack)
    {
        for (const auto &element : userStack.stack)
        {
            stream << element << " " << std::endl;
        }
        return stream;
    }

    T operator[](std::size_t index)
    {
        if (index >= stack.size())
        {
            throw std::out_of_range("Выход за пределы стека");   
        }
    }

    ~Stack() {}
};

int main()
{
    system("clear");





    try
    {
        // ПЕРВАЯ ОШИБКА
        // Stack<int> Stack;
        // Stack.pop();

        // ВТОРАЯ ОШИБКА
        // User user("qwerty", "qwerty");

        // ТРЕТЬЯ ОШИБКА
        // Stack<int> stack;
        // stack.push(1);
        // std::cout << stack[0] << std::endl;
        // std::cout << stack[1] << std::endl;
        
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Runtime_error: " << e.what() << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Произошло исключение: " << e.what() << std::endl;
    }





    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    std::cout << intStack << std::endl;

    Stack<double> doubleStack;
    doubleStack.push(1.1);
    doubleStack.push(1.2);
    doubleStack.push(1.3);

    std::cout << doubleStack << std::endl;

    Stack<User> userStack;
    User user1("login1", "password1");
    User user2("login2", "password2");
    User user3("login3", "password3");

    userStack.push(user1);
    userStack.push(user2);
    userStack.push(user3);

    std::cout << userStack << std::endl;

    Stack<std::string> stringStr;
    stringStr.push("first");
    stringStr.push("second");
    stringStr.push("third");

    std::cout << stringStr << std::endl;

    return 0;
}