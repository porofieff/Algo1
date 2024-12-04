#include "list.cpp"
#include "stack.cpp"
#include "vector.cpp"
#include <iostream>
#include <string>

using namespace std;

bool incl(char token, char *arr, int size) {
  for (int i = 0; i < size; i++) {
    if (token == arr[i])
      return true;
  }
  return false;
}

bool is_op2_higher_priority(char op1, char op2) {
  if (op2 == '^' && op1 == '^')
    return false;
  if (op2 == '^')
    return true;
  if (op1 == '^')
    return false;
  if (op2 == '*' || op2 == '/')
    return true;
  if (op1 == '*' || op1 == '/')
    return false;
  return true;
}

int main() {
  char ch;
  bool flag = false;
  string str;
  Stack<char> main_stack;

  char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  char operators[] = {'-', '+', '*', '/', '^'};
  char functions[] = {'s', 'c'};

  while (true) {
    if (flag)
      break;
    cout << "1 - Алгоритм сортировочной станции" << endl;
    cout << "2 - Список" << endl;
    cout << "3 - Динамический массив" << endl;
    cout << "4 - Выход" << endl;
    cout << "==> ";
    cin >> ch;

    switch (ch)
    {
        case '1':
        {
        bool err = false;
        char token;

        cout << "Введите данные" << endl;
        cin.ignore(256, '\n');
        getline(cin, str);

        while (!str.empty() && !err)
        {
            token = str[0];
            str.erase(0, 1);
            if (str[0] == ' ')
            {
                str.erase(0, 1);
            }
            if (incl(token, numbers, 10))
            {
                cout << token;
            }
            if (incl(token, functions, 2))
            {
                main_stack.push(token);
            }
            if (incl(token, operators, 5))
            {
                while (!main_stack.empty() && incl(main_stack.top(), operators, 5) && is_op2_higher_priority(token, main_stack.top()))
                {
                    cout << main_stack.top();
                    main_stack.pop();
                }
                main_stack.push(token);
            }
            if (token == '(')
            {
                main_stack.push('(');
            }
            else if (token == ')')
            {
                while (!main_stack.empty() && incl(main_stack.top(), operators, 5))
                {
                    cout << main_stack.top();
                    main_stack.pop();
                }
                if (main_stack.empty())
                {
                    cout << endl << "Успех!" << endl;
                    err = true;
                }
                else
                {
                    if (main_stack.top() == 's')
                        cout << "sin";
                    else if (main_stack.top() == 'c')
                        cout << "cos";
                    else (main_stack.top() == '(');
                        main_stack.pop();
                }
            }
        }

        while (!main_stack.empty() && !err) {
            if (main_stack.top() == '(') {
            cout << endl << "Ошибка!" << endl;
            err = true;
            } else {
            if (main_stack.top() == 's')
                cout << "sin";
            else if (main_stack.top() == 'c')
                cout << "cos";
            else
                cout << main_stack.top();
            main_stack.pop();
            }
        }

        if (!err)
            cout << endl << "Успех!" << endl;
        break;
        }
        case '2': {
        List<int> list;
        char ch_list;
        bool list_flag = false;
        while (!list_flag) {
            cout << endl;
            cout << "1 - Добавить в начало" << endl;
            cout << "2 - Добавить в конец" << endl;
            cout << "3 - Узнать размер" << endl;
            cout << "4 - Узнать значение элемента" << endl;
            cout << "5 - Удалить элемент" << endl;
            cout << "6 - Выход" << endl;
            cout << "==> ";
            cin >> ch_list;
            switch (ch_list) {
            case '1': {
            int val;
            cout << "Введите значение" << endl;
            cout << "==> ";
            cin >> val;
            list.push_front(val);
            break;
            }
            case '2': {
            int val;
            cout << "Введите значение" << endl;
            cout << "==> ";
            cin >> val;
            list.push_back(val);
            break;
            }
            case '3': {
            cout << list.size();
            break;
            }
            case '4': {
            size_t pos;
            cout << "Введите номер элемента" << endl;
            cout << "==> ";
            cin >> pos;
            cout << list.get_val(pos);
            break;
            }
            case '5': {
            size_t pos;
            cout << "Введите номер элемента" << endl;
            cout << "==> ";
            cin >> pos;
            list.remove(pos);
            break;
            }
            case '6':
            list_flag = true;
            break;
            default:
            break;
            }
        }
        break;
        }

        case '3': {
        Vector<int> vec(10);
        char ch_vec;
        bool vec_flag = false;
        while (!vec_flag) {
            cout << endl;
            cout << "1 - Добавить элемент" << endl;
            cout << "2 - Узнать значение элемента" << endl;
            cout << "3 - Удалить элемент" << endl;
            cout << "4 - Вывести весь массив" << endl;
            cout << "5 - Выход" << endl;
            cout << "==> ";
            cin >> ch_vec;
            switch (ch_vec) {
            case '1': {
            int val;
            size_t pos;
            cout << "Введите значение" << endl;
            cout << "==> ";
            cin >> val;
            cout << "Введите позицию" << endl;
            cout << "==> ";
            cin >> pos;
            vec.add(pos, val);
            break;
            }
            case '2': {
            size_t pos;
            cout << "Введите номер элемента" << endl;
            cout << "==> ";
            cin >> pos;
            cout << vec.get_value(pos);
            break;
            }
            case '3': {
            size_t pos;
            cout << "Введите номер элемента" << endl;
            cout << "==> ";
            cin >> pos;
            vec.remove(pos);
            break;
            }
            case '4':
            {
            for (size_t i = 0; i < vec.get_size(); i++)
                cout << vec.get_value(i) << " ";
            cout << endl;
            }
            case '5':
            vec_flag = true;
            break;
            default:
            break;
            }
        }
        break;
        }

        case '4':
        flag = true;
        break;
        default: {
        cout << "Вы ввели неверное значение!" << endl;
        break;
        }
    }
  }
  return 0;
}
