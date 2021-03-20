//1.思路没问题
class Solution_150 {
public:
	int evalRPN(vector<string>& tokens)
	{
		int len = tokens.size();

		string op[4]={"+","-","*","/"};
		stack<int>ans;
		for(int i = 0;i<len;++i)
		{
			if (op->find(tokens[i]) != std::string::npos)
			{
				int right = ans.top();
				ans.pop();
				int left = ans.top();

				int newnum = 0;
				if(tokens[i] == "+")
					newnum = left + right;
				if (tokens[i] == "-")
					newnum = left - right;
				if (tokens[i] == "*")
					newnum = left * right;
				if (tokens[i] == "/")
					newnum = left / right;
				ans.push(newnum);
			}
			else
			{
				
				int num = stoi(tokens[i]);
				ans.push(num);
			}
		}

		return ans.top();

	}
};



//官方题解
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            string& token = tokens[i];
            if (isNumber(token)) {
                stk.push(atoi(token.c_str()));
            } else {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                switch (token[0]) {
                    case '+':
                        stk.push(num1 + num2);
                        break;
                    case '-':
                        stk.push(num1 - num2);
                        break;
                    case '*':
                        stk.push(num1 * num2);
                        break;
                    case '/':
                        stk.push(num1 / num2);
                        break;
                }
            }
        }
        return stk.top();
    }

    bool isNumber(string& token) {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/solution/ni-bo-lan-biao-da-shi-qiu-zhi-by-leetcod-wue9/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
