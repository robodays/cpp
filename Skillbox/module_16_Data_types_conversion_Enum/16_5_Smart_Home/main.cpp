#include <iostream>
#include <sstream>
#include <windows.h>
#include <bitset>

bool CheckStrOnDigits(const std::string& str);
int CheckStringStream(std::string str);
bool CheckYesNo(std::string str);
bool CheckOnOff(std::string str);
std::string AddHour(std::string timeStr) ;

enum {
    POWER_HOUSE = 1,
    POWER_SOCKET = 2,
    LIGHT_INDOOR = 4,
    LIGHT_OUTDOOR = 8,
    HEATING_HOUSE = 16,
    HEATING_WATER_PIPE = 32,
    CONDITIONER = 64
};
int main() {

    int electroboard = 0;
    int indoorTSensor;
    int outdoorTSensor;
    int colorLightMin = 2700;
    int colorLightMax = 5000;
    int colorLight = colorLightMax;
    bool lightOn;
    bool motionSensor;
    bool enterErr;
    std::string time = "00:00";
    std::string statusSensorsStr;
    std::string indoorTSensorStr;
    std::string outdoorTSensorStr;
    std::string lightOnStr;
    std::string motionSensorStr;

    for (int i = 0; i < 48; i++) {
        do {
            std::cout << "=========================================================" << std::endl;
            std::cout << "|-----------------|" << std::endl;
            std::cout << "| Now time: " << time << " |" << std::endl;
            std::cout << "|-----------------|" << std::endl;
            std::cout << R"(Enter separated by a space "Outdoor Temperature Sensor" "Indoor Temperature Sensor" "Motion Sensor"(yes/no) "Light Indoor"(on/off))"
                      << std::endl;
            std::cout << "For example: \"10 20 yes on\"" << std::endl;

            getline(std::cin, statusSensorsStr);
            std::stringstream statusSensors(statusSensorsStr);

            statusSensors >> outdoorTSensorStr >> indoorTSensorStr >> motionSensorStr >> lightOnStr;

            enterErr = CheckStringStream(statusSensorsStr) != 4 || !CheckStrOnDigits(outdoorTSensorStr) ||
                       !CheckStrOnDigits(indoorTSensorStr) || !CheckYesNo(motionSensorStr) || !CheckOnOff(lightOnStr);
            if (enterErr) {
                std::cerr << "Data entry error. Please try again. " << std::endl;
                Sleep(1000);
            }
        } while (enterErr);

        outdoorTSensor = std::stoi(outdoorTSensorStr);
        indoorTSensor = std::stoi(indoorTSensorStr);
        motionSensor = (motionSensorStr == "yes");
        lightOn = (lightOnStr == "on");

        //Check events
        std::cout << "++++++ events ++++++" << std::endl;
        if (outdoorTSensor < 0 && !(electroboard & HEATING_WATER_PIPE))  {
            electroboard |= HEATING_WATER_PIPE;
            std::cout << "The water supply heating system is on." << std::endl;
        } else if (outdoorTSensor > 5 && (electroboard & HEATING_WATER_PIPE)) {
            electroboard &= ~HEATING_WATER_PIPE;
            std::cout << "The water supply heating system is off." << std::endl;
        }

        if ((time > "16:00" || time < "05:00") && motionSensor && !(electroboard & LIGHT_OUTDOOR)) {
            electroboard |= LIGHT_OUTDOOR;
            std::cout << "Outdoor lighting is on." << std::endl;
        } else if (((time < "16:00" && time > "05:00") || !motionSensor) && electroboard & LIGHT_OUTDOOR){
            electroboard &= ~LIGHT_OUTDOOR;
            std::cout << "Outdoor lighting is off." << std::endl;
        }

        if (indoorTSensor < 22 && !(electroboard & HEATING_HOUSE)) {
            electroboard |= HEATING_HOUSE;
            std::cout << "The heating of the house on." << std::endl;
        } else if (indoorTSensor >= 25  && (electroboard & HEATING_HOUSE)) {
            electroboard &= ~HEATING_HOUSE;
            std::cout << "The heating of the house off." << std::endl;
        }

        if (indoorTSensor >= 30 && !(electroboard & CONDITIONER)) {
            electroboard |= CONDITIONER;
            std::cout << "Conditioner is on." << std::endl;
        } else if (indoorTSensor <= 25 && (electroboard & CONDITIONER)) {
            electroboard &= ~CONDITIONER;
            std::cout << "Conditioner is off." << std::endl;
        }

        if (lightOn && !(electroboard & LIGHT_INDOOR)) {
            electroboard |= LIGHT_INDOOR;
            std::cout << "Lighting in the house on." << std::endl;
        } else if (!lightOn && (electroboard & LIGHT_INDOOR)) {
            electroboard &= ~LIGHT_INDOOR;
            std::cout << "Lighting in the house on." << std::endl;
        }
        if ((time >= "16:00" && time < "20:00") && (electroboard & LIGHT_INDOOR)) {
            colorLight -= (colorLightMax - colorLightMin) / 5;
            std::cout << "Color temperature of the light has changed: " << colorLight << "K" <<  std::endl;
        }
        if ((time == "20:00") && (electroboard & LIGHT_INDOOR)) {
            colorLight = colorLightMin;
            std::cout << "Color temperature of the light has changed: " << colorLight << "K" <<  std::endl;
        }
        if (time == "00:00" && colorLight != colorLightMax) {
            colorLight = colorLightMax;
            std::cout << "Color temperature of the light has changed: " << colorLight << "K" <<  std::endl;
        }
        std::cout << "++++++ end events ++++++" << std::endl;

        //output
        std::cout << "Sensor: " << std::endl;
        std::cout << "  Outdoor Temperature Sensor: " << outdoorTSensor << " Celsius degree" << std::endl;
        std::cout << "  Indoor Temperature Sensor: " << indoorTSensor << " Celsius degree" << std::endl;
        std::cout << "  Motion Sensor: " << (motionSensor ? "yes":"no") << std::endl;

        std::cout << "Light Indoor: " << (lightOn ? "on":"off") << std::endl;
        if (lightOn) std::cout << "  Color temperature of the light: " << colorLight << "K" << std::endl;

        std::cout << "Status electroboard:" << std::endl;
        std::cout << "  POWER_HOUSE " << (electroboard & POWER_HOUSE? "ON":"OFF") << std::endl;
        std::cout << "  POWER_SOCKET " << (electroboard & POWER_SOCKET? "ON":"OFF") << std::endl;
        std::cout << "  LIGHT_INDOOR " << (electroboard & LIGHT_INDOOR? "ON":"OFF") << std::endl;
        std::cout << "  LIGHT_OUTDOOR " << (electroboard & LIGHT_OUTDOOR? "ON":"OFF") << std::endl;
        std::cout << "  HEATING_HOUSE " << (electroboard & HEATING_HOUSE? "ON":"OFF") << std::endl;
        std::cout << "  HEATING_WATER_PIPE " << (electroboard & HEATING_WATER_PIPE? "ON":"OFF") << std::endl;
        std::cout << "  CONDITIONER " << (electroboard & CONDITIONER? "ON":"OFF") << std::endl;
        std::cout << "      " << std::bitset<7>(electroboard) << std::endl;

        time = AddHour(time);
    }
    return 0;
}

bool CheckStrOnDigits(const std::string& str) {
    if (str.empty()) return false;
    for (int i = 0; i < str.size(); i++) {
        if (i == 0 && str[i] == '-' && str.size() != 1) continue;
        else if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}
int CheckStringStream(std::string str) {
    int count = 0;
    std::stringstream sstr(str);
    while (!sstr.eof()) {
        sstr >> str;
        if (!str.empty()) {
            str = "";
            count++;
        }
    }
    return count;
}

bool CheckYesNo(std::string str) {
    return (str == "yes" || str == "no");
}
bool CheckOnOff(std::string str) {
    return (str == "on" || str == "off");
}

std::string AddHour(std::string timeStr) {
    int hour = std::stoi(timeStr.substr(0,timeStr.find(':'))) + 1;
    if (hour == 24) hour = 0;
    std::string newTimeStr = std::to_string(hour);
    newTimeStr = newTimeStr.size() == 1 ? '0'+ newTimeStr:newTimeStr;
    newTimeStr += timeStr.substr(timeStr.find(':'), timeStr.size());
    return newTimeStr;
}



/*Умный дом

Что нужно сделать

Надо разработать упрощённую модель умного дома для дачи. Есть несколько датчиков: датчик температуры снаружи, датчик
 температуры внутри дома. В доме расположен электронный “умный” щиток с автоматами. Каждый автомат отвечает за
 включение и отключение определённых устройств или групп устройств. Первый автомат - это отключение и включение
 питания всего дома, второй - основные розетки дома, третий - свет внутри дома, четвёртый - наружный свет в саду,
 пятый - отопление в помещении, шестой - отопление водопровода идущего из скважины с насосом, шестой - кондиционер
 в помещении.

Есть несколько условий по включению/отключению техники в доме и вне его.

+Как только температура снаружи падает ниже 0, надо включить систему обогрева водопровода и отключить её, если
 температура снаружи поднялась выше 5 градусов.

+Если на дворе вечер (время больше 16:00 и меньше 5:00 утра) и снаружи есть какое-то движение, то необходимо включить
 садовое освещение. Если движения нет или время не вечернее - света снаружи быть не должно.

+При условии, что температура в помещении упала ниже 22 градусов, должно включится отопление. Как только температура
 поднимается выше или равно 25-и градусам, отопление автоматически отключается.

+Если температура в помещении поднялась до 30 градусов, включается кондиционер. Как только температура становится 25
 градусов - кондиционер отключается.

+Всё освещение в доме также “умное” и поддерживает настройку цветовой температуры для комфортного нахождения. Каждый
 день начиная с 16:00 и до 20:00, температура цвета должна плавно изменяться с 5000K до 2700К. Разумеется, это
 изменение должно происходить в случае, если свет сейчас включен. В 0:00 температура сбрасывается до 5000К.

Все события по отключению и включению устройств должны выводится в консоль явным образом. Если устройство не изменило
 своего состояния (осталось включенным или выключенным) события генерироваться не должно! Если свет в доме включен,
 должна отображаться текущая цветовая температура.

Программа выполняется следующим образом. Каждый час пользователь сообщает состояние всех основных датчиков и света:
 температура снаружи, температура внутри, есть ли движение снаружи, включен ли свет в доме. Данные параметры вводятся
 разом в одну строку, через пробел, а потом парсятся в переменные из строкового буфера stringstream. Информация о
 движении выводится в формате yes/no. Включение и отключение света происходит с помощью on/off. Стартовое время для
 симуляции умного дома - это 0:00. Требуется осуществить симуляцию на протяжении двух дней.*/