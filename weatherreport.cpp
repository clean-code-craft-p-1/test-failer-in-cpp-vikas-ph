#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

namespace WeatherSpace
{
    class IWeatherSensor {
        public:
            virtual double TemperatureInC() const = 0;
            virtual int Precipitation() const = 0;
            virtual int Humidity() const = 0;
            virtual int WindSpeedKMPH() const = 0;
    };
    /// <summary>
    /// This is a stub for a weather sensor. For the sake of testing 
    /// we create a stub that generates weather data and allows us to
    /// test the other parts of this application in isolation
    /// without needing the actual Sensor during development
    /// </summary>
    class SensorStub : public IWeatherSensor {

    public:
        SensorStub() : temperatureInC(0.0),
                       humidity(0),
                       precipitation(0),
                       windSpeedKMPH(0) { }

        ~SensorStub() { }

        int Humidity() const override {
            return humidity;
        }

        int Precipitation() const override {
            return precipitation;
        }

        double TemperatureInC() const override {
            return temperatureInC;
        }

        int WindSpeedKMPH() const override {
            return windSpeedKMPH;
        }

    public:
        double temperatureInC;
        int    humidity;
        int    precipitation;
        int    windSpeedKMPH;
    };

    string Report(const IWeatherSensor& sensor)
    {
        int precipitation = sensor.Precipitation();
        // precipitation < 20 is a sunny day
        string report = "Sunny Day";

        if (sensor.TemperatureInC() > 25)
        {
            if (precipitation >= 20 && precipitation < 60)
                report = "Partly Cloudy";
            else if (sensor.WindSpeedKMPH() > 50)
                report = "Alert, Stormy with heavy rain";
        }
        return report;
    }
}

namespace WeatherSpaceTests {
    void TestRainy()
    {
        WeatherSpace::SensorStub sensor;
        sensor.humidity       = 72;
        sensor.precipitation  = 70;
        sensor.temperatureInC = 26.0;
        sensor.windSpeedKMPH  = 52;

        string report = WeatherSpace::Report(sensor);
        cout << report << endl;
        assert(report.find("rain") != string::npos);
    }

    void TestHighPrecipitation()
    {
        // This instance of stub needs to be different-
        // to give high precipitation (>60) and low wind-speed (<50)
        WeatherSpace::SensorStub sensor;
        sensor.humidity       = 72;
        sensor.precipitation  = 70;
        sensor.temperatureInC = 26.0;
        sensor.windSpeedKMPH  = 49;

        // strengthen the assert to expose the bug
        // (function returns Sunny day, it should predict rain)
        string report = WeatherSpace::Report(sensor);
        assert(report.find("rain") != string::npos);
        assert(report.length() > 0);
    }
}

int main() {
    WeatherSpaceTests::TestRainy();
    WeatherSpaceTests::TestHighPrecipitation();
    cout << "All is well (maybe)\n";
    return 0;
}
