typedef struct {
	void(*Update)(float temp, float humidity, float pressure);
}Observer;

//subject interface
typedef struct {
	void(*RegisterObserver)(Observer o);
	void(*RemoveObserver)(Observer o);
	void(*NotifyObservers)(void);
}Subject;






typedef struct {
	void(*Display)(void);
}DisplayElement;


#define MAX 100
typedef void(*SetMeasurements)(float temperature, float humidity, float pressure);
void RegisterObserver1(Observer o);
void RemoveObserver1(Observer o);
void NotifyObservers1(void);
void SetMeasurements1(float temperature, float humidity, float pressure);
void Update1(float temp, float humidity, float pressure);

//concrede subject 
typedef struct {
	Subject sub;
	Observer obs[MAX];
	float temp;
	float humidity;
	float pressure;
	SetMeasurements set; //= { SetMeasurements1 };
}WeatherData;


WeatherData * WeatherData_init(WeatherData * Weather)
{
	//WeatherData * Weather = NULL;
	if (!Weather)
	{
		Weather = (WeatherData *)calloc(1,sizeof(Weather));
	}

	return Weather;
}

WeatherData * g_Weather = NULL;
void WeatherData_set(WeatherData * Weather)
{
	//WeatherData * Weather = NULL;
	if (!Weather)
	{
		Weather = (WeatherData *)calloc(1, sizeof(Weather));
	}

	g_Weather = Weather;
}

WeatherData * WeatherData_get()
{
	return g_Weather;
}


//WeatherData * WeatherData_bind(WeatherData * Weather)
//{
//	if (!Weather)
//	{
//		Weather = (WeatherData *)calloc(1, sizeof(Weather));
//	}
//	Weather->sub.RegisterObserver = RegisterObserver1;
//	Weather->sub.RemoveObserver = RemoveObserver1;
//	Weather->sub.NotifyObservers = NotifyObservers1;
//	Weather->obs->Update = Update1;
//	Weather->set = SetMeasurements1;
//
//}

void WeatherData_bind(void)
{
	if (!g_Weather)
	{
		return;
	}
	g_Weather->sub.RegisterObserver = RegisterObserver1;
	g_Weather->sub.RemoveObserver = RemoveObserver1;
	g_Weather->sub.NotifyObservers = NotifyObservers1;
	g_Weather->obs->Update = Update1;
	g_Weather->set = SetMeasurements1;

}

static int obs_len = 0;

void RegisterObserver1(Observer o)
{
	WeatherData * wd = WeatherData_get();
	//cout << "Current 00 conditions:" << wd->temp << " F degrees and" << wd->humidity << "% humidity";
	int i = 0;
	for (i = 0; i < MAX; ++i)
	{
		/*	if (wd.obs[i] == 0)
			{
				break;
			}*/

	}
	wd->obs[obs_len] = o;
	obs_len = obs_len + 1;
	//cout << "Current 0 conditions:" << wd->temp << " F degrees and" << wd->humidity << "% humidity";


}

void RemoveObserver1(Observer o)
{

}

void NotifyObservers1(void)
{
	int i = 0;
	WeatherData * wd = WeatherData_get();
	for (i = 0; i < obs_len; ++i)
	{
	//	cout << "Current 1 conditions:" << wd->temp << " F degrees and" << wd->humidity << "% humidity";
		wd->obs[i].Update(wd->temp, wd->humidity, wd->pressure);
	}
}

void SetMeasurements1(float temperature, float humidity, float pressure)
{
	WeatherData * wd = WeatherData_get();
	if (wd)
	{
		wd->temp = temperature;
		wd->humidity = humidity;
		wd->pressure = pressure;
	}
	
}





//display 
void Display1()
{
	WeatherData * wd = WeatherData_get();
	cout << "Current 2 conditions:" << wd->temp << " F degrees and" << wd->humidity << "% humidity" << endl;
}

void Update1(float temp, float humidity, float pressure)
{
	//当update被调用的时候，我们把温度和湿度保存起来，然后调用Display();
	WeatherData * wd = WeatherData_get();
	wd->temp = temp;
	wd->humidity = humidity;
	Display1();
	//cout << "Current 3 conditions:" << wd->temp << " F degrees and" << wd->humidity << "% humidity";

}


typedef void(*bind_observer_to_sub)(WeatherData *weatherData);

void bind_observer_to_sub1(WeatherData *weatherData1);

typedef struct {
	DisplayElement de;// = { Display1 };
	Observer obs;// = { Update1 };
	float temp;
	float humidity;
	WeatherData wea;
	bind_observer_to_sub bind; //= { bind_observer_to_sub1 };
}CurrentConditionsDisplay;

int CurrentConditionsDisplay_init(WeatherData *weatherData1, CurrentConditionsDisplay *ccd)
{
	if (!ccd)
		return -1;
	else
	{
		ccd->wea = *weatherData1;
		ccd->bind = bind_observer_to_sub1;
		
		ccd->obs = weatherData1->obs[0];
		ccd->de.Display = Display1;
	}
	return 0;


}
void bind_observer_to_sub1(WeatherData *weatherData1)
{
	weatherData1->sub.RegisterObserver(weatherData1->obs[0]);

}

#if 10
int main()
{

	//test code
	WeatherData *we = (WeatherData *)malloc(sizeof(WeatherData));
	CurrentConditionsDisplay *currentDisplay = (CurrentConditionsDisplay *)malloc(sizeof(CurrentConditionsDisplay));

	
	WeatherData_set(we);
	CurrentConditionsDisplay_init(we, currentDisplay);
	WeatherData * wd = WeatherData_get();
	WeatherData_bind();

	currentDisplay->bind(wd);
	wd->set(80, 65, 30.4f);
	cout << "Curren1" << endl;
	wd->sub.NotifyObservers();
	cout << "Curren2" << endl;
	wd->set(82, 70, 29.2f);
	wd->sub.NotifyObservers();
  return 0;
  }
