#include <iostream>
#include <string>

using namespace std;

enum Gender {
    FEMALE,
    MALE,
    NON_BINARY
};
class Guest {

public:
    int id;
    string name;
    int age;
    string city;
    long int phoneNumber;
    Gender sex;

    Guest(){};

    Guest(int id1, string name1, int age1, string city1, long int phoneNumber1, Gender sex1)
    {
        id = id1;
        name = name1;
        age = age1;
        city = city1;
        phoneNumber = phoneNumber1;
        sex = sex1;
    }
     ~Guest() {}
};

class Party {

public:
    string day;
    string reason;
    Guest guests[5];

    Party()
    {
    };
    Party(string day1, string reason1, Guest guests1[])
    {
        day = day1;
        reason = reason1;
        *guests = *guests1;
    }

    float findAverageAge(Guest gues[5], Gender sex2)
    {
        int age = 0;
        float avarageAge;
        int count = 0;

        for (int i = 0; i < 5; i++)
        {
            if (gues[i].sex == sex2)
            {
                age += gues[i].age;
                count++;
            }
        }
        avarageAge = age / (float)count;
        return avarageAge;
    }

    string isLuckyPhoneNumber(int number)
    {
        int i = 0;

        do
        {

            if (number % 10 == 7)
            {
                i++;
            }
            number /= 10;
        } while (number >= 10);

        if (i >= 3)
        {
            return "True";
        }
        else
        {
            return "False";
        }
    }
};
int main()
{
    const int n = 5;

    Guest friends[n] =
    {
        Guest(5, "Taras", 28, "Boryslav", 380987896782, Gender::FEMALE),
        Guest(2, "Roman", 13, "Kyiv", 380504796878, Gender::MALE),
        Guest(4, "Ostap", 46, "Lviv", 38050177, Gender::FEMALE),
        Guest(3, "Andriy", 21, "Odessa", 380997895784, Gender::MALE),
        Guest(1, "Vova", 17, "Lviv", 380547892578, Gender::NON_BINARY)
    };

    Party day("24th", "My birthday", friends);

    cout << "Age: " << day.findAverageAge(friends, Gender::MALE) << endl;
    cout << "Is Lucky? " << day.isLuckyPhoneNumber(7777) << endl;
    for (long int n = 0; n < 5; n++)
    {
        cout << "NAME " << friends[n].name << "ID " << friends[n].id << " PHONE NUMBER " << friends[n].phoneNumber << "CITY " << friends[n].city << endl;
    }

    Guest temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (friends[j].id < friends[i].id)
            {
                temp = friends[i];
                friends[i] = friends[j];
                friends[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << friends[i].name << endl;
    }
}
