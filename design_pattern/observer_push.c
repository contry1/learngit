typedef struct Observer_t {
	void(*Update)(struct Observer_t *this1, float temp, float humidity, float pressure);
}Observer;

//subject interface
typedef struct {
	void(*RegisterObserver)(Observer *o);
	void(*RemoveObserver)(Observer *o);
	void(*NotifyObservers)(void);
}Subject;


typedef struct DisplayElement_t {
	void(*Display)(struct DisplayElement_t*);
}DisplayElement;

#define MAX 100


void RegisterObserver1(struct concrede_subject * this1, Observer *o);
void RemoveObserver1(struct concrede_subject * this1, Observer *o);
void NotifyObservers1(struct concrede_subject * this1);
void SetMeasurements1(struct concrede_subject * this1, float temperature, float humidity, float pressure);

//concrede subject 
typedef struct concrede_subject {
	void(*RegisterObserver)(struct concrede_subject * this1, Observer *o);
	void(*RemoveObserver)(struct concrede_subject * this1, Observer *o);
	void(*NotifyObservers)(struct concrede_subject * this1);
	void(*SetMeasurements)(struct concrede_subject * this1, float temperature, float humidity, float pressure);
	Observer *obs[MAX];
	int obs_cnt;
	float temp;
	float humidity;
	float pressure;
}WeatherData;

WeatherData * WeatherData_new(float temp, float humidity, float pressure)
{
	WeatherData * th = (WeatherData *)calloc(1, sizeof(WeatherData));
	if (NULL == th)
	{
		return NULL;
	}

	th->RegisterObserver = RegisterObserver1;
	th->RemoveObserver = RemoveObserver1;
	th->NotifyObservers = NotifyObservers1;
	th->SetMeasurements = SetMeasurements1;
	th->temp = temp;
	th->humidity = humidity;
	th->pressure = pressure;

	th->obs_cnt = 0;
	return th;

}

void RegisterObserver1(struct concrede_subject * this1, Observer* o)
{
	this1->obs[this1->obs_cnt] = o;
	this1->obs_cnt += 1;
	cout << "RegisterObserver1   obs_cnt:" << this1->obs_cnt << endl;
}

void RemoveObserver1(struct concrede_subject * this1, Observer *o)
{
	int i;
	for (i = 0; i < this1->obs_cnt; ++i)
	{
		if (o == this1->obs[i])
		{
			cout << "RemoveObserver1  obs_index:" << i << endl;
			if (i == this1->obs_cnt - 1)
			{
				this1->obs_cnt--;
				break;
			}
			else
			{
				int j = i;
				this1->obs_cnt--;
				for (j; j < this1->obs_cnt; ++j)
				{
					this1->obs[j] = this1->obs[j + 1];
				}
				break;
			}

		}

	}
}

void NotifyObservers1(struct concrede_subject * this1)
{
	int i = 0;
	for (i = 0; i < this1->obs_cnt; ++i)
	{
		if (NULL == this1->obs[i]->Update)
		{
		}
		else
		{
			//这里我们调用的是observer中的update方法，如果具体类中display方法放在前面，为何在具体类中，调用的却是display1方法！
			this1->obs[i]->Update(this1->obs[i],this1->temp,this1->humidity,this1->pressure);
		}

	}
}

void SetMeasurements1(struct concrede_subject * this1, float temperature, float humidity, float pressure)
{

	if (this1)
	{
		this1->temp = temperature;
		this1->humidity = humidity;
		this1->pressure = pressure;
	}
	NotifyObservers1(this1);
}

/*concrede  observer*/
typedef struct concrede_display {
	void(*Update)(struct concrede_display *this2, float temperature, float humidity, float pressure);//必须放在结构体第一位！
	void(*Display1)(struct concrede_display * this2);////DisplayElement de;// = { Display1 };

	float temp;
	float humidity;
	WeatherData *wea;
}CurrentConditionsDisplay;

void Update11(struct concrede_display *this2, float temperature, float humidity, float pressure);//必须放在结构体第一位！
void Display11(struct concrede_display * this2);

CurrentConditionsDisplay * CurrentConditionsDisplay_new(WeatherData *weather)
{
	CurrentConditionsDisplay *ccd = (CurrentConditionsDisplay *)calloc(1, sizeof(CurrentConditionsDisplay));
	if (!ccd)
		return NULL;
	else
	{
		ccd->Update = Update11;
		ccd->Display1 = Display11;
		ccd->wea = weather;
		ccd->wea->RegisterObserver(ccd->wea, (Observer*)ccd); 
	}
	return ccd;
}

void Display11(struct concrede_display *this2)
{
	if (!this2)
		return;
	cout << "Display11==========:" << this2->temp << " F degrees and" << this2->humidity << "% humidity" << endl;
}

void Update11(struct concrede_display *this2, float temperature, float humidity, float pressure)
{
	if (!this2)
		return;
	this2->temp = temperature;
	this2->humidity = humidity;
	Display11(this2);
	
}

//test code
int main()
{
	WeatherData *we = WeatherData_new(80, 65, 30.4f);
	CurrentConditionsDisplay *currentDisplay = CurrentConditionsDisplay_new(we);
	CurrentConditionsDisplay *currentDisplay2 = CurrentConditionsDisplay_new(we);

	/*push   mode*/
	we->NotifyObservers(we);
	we->SetMeasurements(we, 800, 650, 30.4f);

	we->RemoveObserver(we, (Observer*)currentDisplay);
	we->SetMeasurements(we, 100, 250, 30.4f);

	CurrentConditionsDisplay *currentDisplay3 = CurrentConditionsDisplay_new(we);
	we->SetMeasurements(we, 1000, 250, 30.4f);
	return 0;
}
