class MyQueue {
private:
	std::stack<int>in_st,out_st;
	
public:
	/** Initialize your data structure here. */
	MyQueue() {
		
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		in_st.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int tail = 0;
		if (!out_st.empty())
		{
			tail = out_st.top();
			out_st.pop();
		}
		else
		{
			while (!in_st.empty())
			{
				int num = in_st.top();
				out_st.push(num);
				in_st.pop();
			}
			tail = out_st.top();
			out_st.pop();
		}
		return tail;

	}

	/** Get the front element. */
	int peek() {
		int tail = 0;
		if (!out_st.empty())
		{
			tail = out_st.top();
			
		}
		else
		{
			while (!in_st.empty())
			{
				int num = in_st.top();
				out_st.push(num);
				in_st.pop();
			}
			tail = out_st.top();
			
		}
		return tail;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		if (in_st.empty() && out_st.empty())
			return true;
		else
			return false;

	}
};
