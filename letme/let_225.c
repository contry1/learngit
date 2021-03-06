class MyStack {
private:
	std::queue<int>in, out;
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		in.push(x);
		while (!out.empty())
		{
			int num = out.front();
			in.push(num);
			out.pop();
		}
		swap(in,out);

	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int num = out.front();
		out.pop();
		return num;

	}

	/** Get the top element. */
	int top() {
		return out.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return out.empty();
	}
};
