#include <bits/stdc++.h>
using namespace std;

bool isOperator(string x)
{
    if (x == "+" || x == "-" || x == "/" || x == "*" || x == "^" || x == "%")
        return true;
    else
        return false;
}

int evaluatePrefix(vector<string> prefixExpression)
{
    stack<int> stack;
    for (int j = prefixExpression.size() - 1; j >= 0; j--)
    {
        if (!isOperator(prefixExpression[j]))
            stack.push(stoi(prefixExpression[j]));
        else
        {
            int o1 = stack.top();
            stack.pop();
            int o2 = stack.top();
            stack.pop();
            if (prefixExpression[j] == "+")
                stack.push(o1 + o2);
            else if (prefixExpression[j] == "-")
                stack.push(o1 - o2);
            else if (prefixExpression[j] == "*")
                stack.push(o1 * o2);
            else if (prefixExpression[j] == "/")
                stack.push(o1 / o2);
            else if (prefixExpression[j] == "^")
                stack.push(o1 ^ o2);
            else if (prefixExpression[j] == "%")
                stack.push(o1 % o2);
        }
    }
    return stack.top();
}

string prefixToInfix(vector<string> arr)
{
    stack<string> s;
    int length = arr.size();
    for (int i = length - 1; i >= 0; i--)
    {
        if (isOperator(arr[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = "(" + op1 + " " + arr[i] + " " + op2 + ")";
            s.push(temp);
        }
        else
        {
            s.push(arr[i]);
        }
    }
    return s.top();
}

int main()
{
    vector<string> arr;
    string prefixExpression;
    string word;
    int operators = 0, operands = 0;
    getline(cin, prefixExpression);
    stringstream ss(prefixExpression);
    while (ss >> word)
    {
        if (isOperator(word))
        {
            operators++;
        }
        else
        {
            operands++;
        }
        arr.push_back(word);
    }
    if (operands - operators == 1)
    {
        string ans = prefixToInfix(arr);
        if(ans[0] == '('){
            ans = ans.substr(1, ans.size() - 2);
        }
        int finalAns = evaluatePrefix(arr);
        cout << ans << " = " << finalAns;
    }
    else
    {
        cout << "Error";
    }

    return 0;
}
