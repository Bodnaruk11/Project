#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Car
{
private:
    string name;
    size_t      graduationYear;
    size_t      engineCapacity;
    size_t      price;
public:
    Car() : name(0), graduationYear(0), engineCapacity(0), price(0) {}
    Car(string _name, size_t _graduationYear = 0, size_t _engineCapacity = 0, size_t _price = 0) :
        name(_name), graduationYear(_graduationYear), engineCapacity(_engineCapacity), price(_price) {}

    string getName()      const { return name; }
    size_t getGraduationYear() const { return graduationYear; }
    size_t getEngineCapacity() const { return engineCapacity; }
    size_t getPrice()          const { return price; }

    bool operator==(string _name)
    {
        return name == _name;
    }
};

class Dealer
{
private:
    vector<Car> cars;
    size_t findMaxValue(char c)
    {
        string resp = "";
        if (c != 'n' && c != 'e' && c != 'y' && c != 'p')
            return 1;
        for_each(cars.begin(), cars.end(), [&](const Car& car)->void {
            switch (c)
            {
            case 'n':
                resp = resp > car.getName() ? resp : car.getName();
            case 'e':
                resp = resp > to_string(car.getEngineCapacity()) ? resp : to_string(car.getEngineCapacity());
            case 'y':
                resp = resp > to_string(car.getGraduationYear()) ? resp : to_string(car.getGraduationYear());
            case 'p':
                resp = resp > to_string(car.getPrice()) ? resp : to_string(car.getPrice());
            default:
                break;
            }
            });
        return resp.length() / 5;
    }
    string getTab(int _tab = 1)
    {
        if (_tab < 1)
            return "\t";
        string res;
        for (size_t i = 0; i < _tab; i++)
            res += "\t";
        return res;
    }
public:
    void addToStash(Car car)
    {
        cars.push_back(car);
    }
    void destroyCar(size_t ind)
    {
        if (ind < cars.size())
            cars.erase(cars.begin() + ind);
    }

    void showRange(size_t from = 0, size_t to = 0, char c = '\0')
    {
        if (!from) from = 0;
        if (!to)   to = cars.size();
        if (from > to)
            throw new std::exception("wrong range");
        if (c != '\0')
            sortBy(c);
        string tabForName = getTab(findMaxValue('n'));
        string tabForEC = getTab(findMaxValue('e'));
        string tabForYear = getTab(findMaxValue('y'));


        cout << "Name" << tabForName << "E/C" << tabForEC << "Year" << tabForYear << "Price" << '\n';
        for_each(cars.begin() + from, cars.begin() + to, [&](const Car& car) -> void {
            cout << car.getName() + getTab(findMaxValue('n') - (car.getName().length() / 4) + 1)
                + to_string(car.getEngineCapacity()) + getTab(findMaxValue('e') - (to_string(car.getEngineCapacity()).length() / 4) + 1)
                + to_string(car.getGraduationYear()) + getTab(findMaxValue('y') - (to_string(car.getGraduationYear()).length() / 4) + 1)
                + to_string(car.getPrice()) + '\n';
            });

    }

    void sortBy(char c)
    {
        if (c != 'n' && c != 'e' && c != 'y' && c != 'p')
            return;
        sort(cars.begin(), cars.end(), [&c](Car c1, Car c2) -> bool {
            switch (c)
            {
            case 'n':
                return c1.getName() > c2.getName();
            case 'e':
                return c1.getEngineCapacity() > c2.getEngineCapacity();
            case 'y':
                return c1.getGraduationYear() > c2.getGraduationYear();
            case 'p':
                return c1.getPrice() > c2.getPrice();
            default:
                break;
            }
            });
    }
    Car& findByName(string name)
    {
        auto el = find(cars.begin(), cars.end(), name);
        if (el->getName() == name)
            return *el;
        else
            cout << "Нiчого не знайдено";
    }
};

class Car_zamov
{
private:
    string title;
    size_t year;
    size_t capacity;
    size_t price;
public:
    Car_zamov(string _title = "", size_t _year = 0, size_t _capacity = 0, size_t _price = 0)
        : title(_title), year(_year), capacity(_capacity), price(_price) {}

    string getTitle()
    {
        return this->title;
    }
    size_t getYear()
    {
        return this->year;
    }
    size_t getCapacity()
    {
        return this->capacity;
    }
    size_t getPrice()
    {
        return this->price;
    }

    void setTitle(string _title)
    {
        this->title = _title;
    }
    void setYear(size_t _year)
    {
        this->year = _year;
    }
    void setCapacity(size_t _capacity)
    {
        this->capacity = _capacity;
    }
    void setPrice(size_t _price)
    {
        this->price = _price;
    }
};

class Salon
{
private:
    vector<Car_zamov> cars;
public:
    Salon() {}

    void addCar(const Car_zamov& _car)
    {
        cars.push_back(_car);
    }
    void removeCarFromPosition(size_t _pos)
    {
        if (_pos < cars.size() && _pos > 0)
        {
            cars.erase(cars.begin() + _pos - 1);
        }
        else
            throw exception("error: wrong element position");
    }
    void show()
    {
        cout << endl;

        for (int i = 0; i < cars.size(); i++)
        {
            cout << "Car #" << (i + 1) << "" << endl;
            cout << "\tName: " << cars[i].getTitle() << endl;
            cout << "\tYear: " << cars[i].getYear() << endl;
            cout << "\tCapacity: " << cars[i].getCapacity() << endl;
            cout << "\tPrice: " << cars[i].getPrice() << endl;
            cout << endl;
        }

        cout << endl;
    }
    void sortBy(int _reason)
    {
        switch (_reason)
        {
        case 1:
            sort(cars.begin(), cars.end(), [](Car_zamov& _car1, Car_zamov& _car2) -> bool
                {
                    return _car1.getTitle().length() < _car2.getTitle().length();
                });
            break;
        case 2:
            sort(cars.begin(), cars.end(), [](Car_zamov& _car1, Car_zamov& _car2) -> bool
                {
                    return _car1.getYear() < _car2.getYear();
                });
            break;
        case 3:
            sort(cars.begin(), cars.end(), [](Car_zamov& _car1, Car_zamov& _car2) -> bool
                {
                    return _car1.getCapacity() < _car2.getCapacity();
                });
            break;
        case 4:
            sort(cars.begin(), cars.end(), [](Car_zamov& _car1, Car_zamov& _car2) -> bool
                {
                    return _car1.getPrice() < _car2.getPrice();
                });
            break;
        default:
            break;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Ukrainian");


    Salon salon;
    string command;
    bool running = true;

    string carTitle;
    size_t year;
    size_t capacity;
    size_t price;

    cout << "Команди:" << endl;
    cout << "\tadd - Замовити машину" << endl;
    cout << "\tshow - Показати що є в наявності" << endl;
    cout << "\tstop - Вийти з програми\n" << endl;

    while (running)
    {
        cout << "--> ";
        getline(cin, command);
        if (!command.compare("add"))
        {
            cout << "Марка машини: ";
            getline(cin, command);
            carTitle = command;

            cout << "Рiк машини: ";
            getline(cin, command);
            year = atoi(command.c_str());

            cout << "Ємнiсть машини: ";
            getline(cin, command);
            capacity = atoi(command.c_str());

            cout << "Цiна машини: ";
            getline(cin, command);
            price = atoi(command.c_str());

            cout << "Ваше замовлення прийнято.Дякую що довsрились нам. ";
            getline(cin, command);

            salon.addCar(Car_zamov(carTitle, year, capacity, price));
        }
        else if (!command.compare("show"))
            running = false;
        else
        {
            cout << "Дякую допобачення." << endl;
        }
    }

    Dealer shop;

    shop.addToStash(Car("Tesla Model X P90D", 2016, 0, 74700));
    shop.addToStash(Car("Ford Fiesta Titanium", 2014, 1, 9499));
    shop.addToStash(Car("BMW X5", 2014, 3, 47500));
    shop.addToStash(Car("Nissan Skyline R34  ", 1994, 2.5, 19500));


    shop.showRange(0, 0, 'y');



}