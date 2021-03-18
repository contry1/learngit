//一般的单例模式懒汉式
class sing {
public:
	static sing *get_instance(void)
	{
		return s;
	}
	~sing() = default;

private:
	sing()
	{
		s = new sing();
	}
	sing(const sing&)
	{
		;
	}
	sing &operator=(const sing&)
	{
		;
	}
	sing(const sing&&)
	{
		;
	}
	static sing  * s;
};
sing  *s = nullptr;


class sing {
public:
	static sing *get_instance(void)
	{
		if (s == nullptr)
			return new sing();
		return s;
	}
	~sing() = default;

private:
	sing()
	{
		;
	}
	sing(const sing&)
	{
		;
	}
	sing &operator=(const sing&)
	{
		;
	}
	sing(const sing&&)
	{
		;
	}
	static sing  * s;
};
sing  *s = nullptr;

//jiasuo
class sing {
public:
	static sing *get_instance(void)
	{
		sing * cur = s;
		if (cur == nullptr)
		{
			lock  lck;
			cur = s;
			if(cur == nullptr)	
				cur = new sing();
		}
		return cur;
	}
	~sing() = default;

private:
	sing()
	{
		;
	}
	sing(const sing&)
	{
		;
	}
	sing &operator=(const sing&)
	{
		;
	}
	sing(const sing&&)
	{
		;
	}
	static sing  * s;
};
sing  *s = nullptr;


//饿汉式，安全
class sing {
public:
	static sing get_instance(void)
	{
	
		return s;
	}
	~sing() = default;

private:
	sing()
	{
		;
	}
	sing(const sing&)
	{
		;
	}
	sing &operator=(const sing&)
	{
		;
	}
	sing(const sing&&)
	{
		;
	}
	static sing  s;
};
sing  sing::s ;
