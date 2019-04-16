//
//猫狗队列问题
//
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Pet
{
private:
    string type;

public:
    Pet(string type){this->type = type;}

    string getPetType(){return this->type;}
};

class Dog:public Pet
{
public:
    Dog():Pet("Dog"){}//构造函数
};

class Cat:public Pet
{
public:
    Cat():Pet("Cat"){}//构造函数
};

class PetEnterStamp //为进入队列的动物打上时间戳
{
private:
    long count;
    Pet pet;

public:
    PetEnterStamp(Pet pet, long count):pet(pet),count(count){}//构造函数

    long getCount()//得到数量
    {
        return this->count;
    }

    Pet getPet()//得到宠物对象
    {
        return this->pet;
    }

    string getPetType()//得到宠物类型
    {
        return pet.getPetType();
    }

};

class CatDogQueue
{
private:
    queue<PetEnterStamp> dogQ;
    queue<PetEnterStamp> catQ;
    long count;

public:
    CatDogQueue()
    {
        this->count = 0;
    }

    void Add(Pet pet)
    {
        if (pet.getPetType() == "Dog")
        {
            dogQ.push(PetEnterStamp(pet, count++));
            cout << "Pet is :" << dogQ.back().getPetType() << "  Number is :" << dogQ.back().getCount() << endl;
        }
        else if (pet.getPetType() == "Cat")
        {
            catQ.push(PetEnterStamp(pet, count++));
            cout << "Pet is :" << catQ.back().getPetType() << "  Number is :" << catQ.back().getCount() << endl;
        }
        else
            cout <<"this pet is not dog or cat!!" << endl;
        return;
    }

    Pet PollAll()
    {
        if (!dogQ.empty() && !catQ.empty())
        {
            if (dogQ.front().getCount() < catQ.front().getCount())
            {
                Pet tmp = dogQ.front().getPet();
                cout << "Pet is :" << dogQ.front().getPetType() << "  Number is :" << dogQ.front().getCount() << endl;
                dogQ.pop();
                return tmp;
            }
            else
            {
                Pet tmp = catQ.front().getPet();
                cout << "Pet is :" << catQ.front().getPetType() << "  Number is :" << catQ.front().getCount() << endl;
                catQ.pop();
                return tmp;
            }
        }
        else if (!dogQ.empty())
        {
            Pet tmp = dogQ.front().getPet();
            cout << "Pet is :" << dogQ.front().getPetType() << "  Number is :" << dogQ.front().getCount() << endl;
            dogQ.pop();
            return tmp;
        }
        else if (!catQ.empty())
        {
            Pet tmp = catQ.front().getPet();
            cout << "Pet is :" << catQ.front().getPetType() << "  Number is :" << catQ.front().getCount() << endl;
            catQ.pop();
            return tmp;
        }
        else
        {
            cout << "all Queue is empty!!";
        }
    }

    Dog PollDog()
    {
        if (!dogQ.empty())
        {
            Pet tmpP = dogQ.front().getPet();//为避免父类不能直接给子类赋值采用以下方法
            Dog tmpD;
            Pet *tmp = &tmpD;//取tmpD的地址赋给tmp指针
            *tmp = tmpP;//将tmpP的内容赋给tmp指针指向的内容,即tmpD的内容也同时更改
            cout << "Pet is :" << dogQ.front().getPetType() << "  Number is :" << dogQ.front().getCount() << endl;
            dogQ.pop();
            return tmpD;
        }
        else
            cout << "dog Queue is empty!!" << endl;
    }

    Cat PollCat()
    {
        if (!catQ.empty())
        {
            Pet tmpP = catQ.front().getPet();//为避免父类不能直接给子类赋值采用以下方法
            Cat tmpC;
            Pet *tmp = &tmpC;//取tmpC的地址赋给tmp指针
            *tmp = tmpP;//将tmpP的内容赋给tmp指针指向的内容,即tmpC的内容也同时更改
            cout << "Pet is :" << catQ.front().getPetType() << "  Number is :" << catQ.front().getCount() << endl;
            catQ.pop();
            return tmpC;
        }
        else
            cout << "cat Queue is empty!!" << endl;
    }

    bool QueueisEmpty()
    {
        return dogQ.empty() && catQ.empty();
    }

    bool DogQueueisEmpty()
    {
        return dogQ.empty();
    }

    bool CatQueueisEmpty()
    {
        return catQ.empty();
    }

};


int main()
{
    CatDogQueue cdq;
    if(cdq.QueueisEmpty())
        cout << "All queue is empty!" << endl;
    if(cdq.DogQueueisEmpty())
        cout << "Dog queue is empty!" << endl;
    if(cdq.CatQueueisEmpty())
        cout << "Cat queue is empty!" << endl;
    for(int i=0;i<9;i++)
    {
        cdq.Add(Cat());
        cdq.Add(Dog());
    }
    cout << "**************" << endl;
    cout << "Poll All!!" << endl;
    while (!cdq.QueueisEmpty()){cdq.PollAll();}
    if(cdq.QueueisEmpty())
        cout << "All queue is empty!" << endl;
    cout << "*********" << endl;
    for(int i=0;i<9;i++)
    {
        cdq.Add(Cat());
        cdq.Add(Dog());
    }
    cout << "**********" << endl;
    cout << "Poll Cat!!"<< endl;
    while (!cdq.CatQueueisEmpty()){cdq.PollCat();}
    cout << "***************" << endl;
    cout << "Poll Dog!!" << endl;
    while (!cdq.DogQueueisEmpty()){cdq.PollDog();}
    return 0;
}
