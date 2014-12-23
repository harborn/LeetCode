class MinStack {
public:
	void push(int x) {
		st.push(x);
		if (mst.empty() || x <= mst.top())
			mst.push(x);
	}

	void pop() {
		if (st.top() == mst.top())
			mst.pop();
		st.pop();
	}

	int top() {
		return st.top();
	}

	int getMin() {
		return mst.top();
	}

private:
	stack<int> st;
	stack<int> mst;
};
