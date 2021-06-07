#include <iostream>

using namespace std;



class Avto   // отсутствие инкапсуляции
{
private:

public:
    string marka = " ";
    string model = " ";
    void Polnoenazvanie()
    {
        cout << "Автомобиль = " << marka + model << endl << endl;
    }

protected:

};

class Avtogod   // инкапсуляция с помощью getter/setter
{
private:
    int month = 0;
    int year = 0;

public:
    void Polngod()
    {
        if ((month >= 0) && (year >= 0))
        {
            cout << "Выпуск авто = " << month << " " << year << endl << endl;
        }
    }

    void setmonth(int month)
    {
        if (month < 0)

        {
            cout << "Месяц автомобиля должна быть " << endl;
        }


        this->month = month;
    }

    int gemonth()
    {
        return this->month;
    }

    void setyear(int year)
    {



        if (year < 0)





        {
            cout << "Год автомобиля должна быть " << endl;
        }


        this->year = year;
    }

    int getyear()
    {
        return this->year;
    }

protected:

};


class AvtoShina   // инкапсуляция с помощью спец. протоколов
{
private:
    int r = 0;
    int d = 0;
    int h = 0;
public:
    void Shina()
    {
        cout << "Размер шины = " << r << "/" << d << "/" << h << endl << endl;
    }

    void incr()
    {
        this->r = r + 1;
    }
    int outr()
    {
        cout << "Радиус = " << this->r << endl;;
        return r;
    }

    void incd()
    {
        this->d = d + 1;
    }

    int outd()
    {
        cout << "Диаметр = " << this->d << endl;;
        return d;
    }
    void inch()
    {
        this->h = h + 1;
    }

    int outh()
    {
        cout << "Ширина = " << this->h << endl;;
        return h;
    }

protected:

};

class Avtorashod  // инкапсуляция за счёт абстракций
{
private:

public:
    virtual void samrashod() const = 0;
    virtual void setzapravil(int zapravil) = 0;
    virtual void setrashodoval(int rashodoval) = 0;
    virtual int getzapravil() const = 0;
    virtual int getrashodoval() const = 0;

protected:

};
class rashod : public Avtorashod
{
private:
    int zapravil = 0;
    int rashodoval = 0;

public:
    void samrashod() const override
    {
        if ((zapravil >= 0) && (rashodoval >= 0))
        {
            cout << "Потрачено топлива = " << zapravil - rashodoval<<" "<<"л" << endl << endl;
        }
    }

    void setzapravil(int zapravil) override
    {

        if (zapravil < 0)

        {
            cout << "Необходимо заправить" << endl;
        }


        this->zapravil = zapravil;
    }

    int getzapravil() const override
    {
        return this->zapravil;
    }

    void setrashodoval(int rashodoval) override
    {



        if (rashodoval < 0)



        {
            cout << "Машина стояла" << endl;
        }


        this->rashodoval = rashodoval;
    }

    int getrashodoval() const override
    {
        return this->rashodoval;
    }

protected:

};

int main()
{
    setlocale(LC_ALL, "Russian");
    Avto* R1 = new Avto(); // отсутствие инкапсуляции
    R1->marka = "Toyota ";
    R1->model = "Chaser";
    R1->Polnoenazvanie();

    Avtogod* R2 = new Avtogod(); // инкапсуляция с помощью getter/setter
    R2->setmonth(04);
    R2->setyear(2002);
    R2->Polngod();

    AvtoShina* R3 = new AvtoShina(); // инкапсуляция с помощью спец. протоколов
    for (int i = 0; i < 18; ++i)
    {
        R3->incr();
    }
    for (int i = 0; i < 205; ++i)
    {
        R3->incd();
    }
    for (int i = 0; i < 60; ++i)
    {
        R3->inch();
    }
    R3->Shina();


    Avtorashod* R4 = new rashod(); // инкапсуляция за счёт абстракций
    R4->setzapravil(28);
    R4->setrashodoval(10);
    R4->samrashod();

}