//test this point
class astr
{
public:
	astr()=default;
	~astr()=default;
	void virtual pr() { std::cout << "pr!\n"; std::cout <<"ff"<< this << std::endl;
	};
	void expp() { std::cout << "expp!\n"; };
};

class sonastr :public astr
{
public:
	sonastr()=default;
	~sonastr()=default;
	void pr()
	{
		std::cout << "ooooooo" << this << std::endl;
	}
	void prr(){
		this->pr();//
		astr::pr();
		std::cout << this << std::endl;
	}

	void exppp()
	{
		this->expp();//

	}
};
int main()
{
    std::cout << "Hello World!\n";
	//sInit();
	/*test_change1();
	test_change2();*/

	//learn_lambda_func_1();
	
	sonastr ss;
	ss.prr();
	ss.exppp();
}
