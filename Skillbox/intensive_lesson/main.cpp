#include <iostream>
#include <string>
#include <vector>

using namespace std;



// вывод строки
void myPrint(string word);
// перегрузка под float 
void myPrint(float word);
// деление 
float myDel(float x , float y);
// деление с ошибками
float myDel2(float x , float y);

class Test{
//private:
//   int pri;
protected:
    float protec;
    int pri;
public:
    int pub;
    Test (){
    }
    Test (int pri, float protec){
        this->pri = pri;
        this->protec = protec;  
        this->print();
        print();
    }
    void setValues (int pri, float protec){
        this->pri = pri;
        this->protec = protec;        
    }
    void print (){
        cout << this->pri << " <> " << this->protec;
    }
    ~Test (){
        cout << " End !!!!!!!!!!" << this->pri << endl;
    }        
};
class Test2 : public Test {
public:
    void print(){
        cout << pri << protec << endl;
    }
    
};

int main () {
    // классы
    Test tester;
    tester.setValues(22, 44.33);
    tester.print();
    
    Test tester2(100, 200.99);
  
    Test2 tester3;
    tester3.setValues(500,650);
    tester3.print();
    cout << "Hello World!" << endl;
    
    char sym = 'A'; // символ
    bool isWork = true; // false
    int num = 1; // от −2 147 483 648 до 2 147 483 647 (при 4 байтах)
    long int num_1 = 10000000; // −2 147 483 648 до 2 147 483 647. 4 байта
    short int num_2 = 10; // –32768 до 32767. Занимает в памяти 2 байта (16 бит)
    float num_3 = 22.55; // +/- 3.4E-38 до 3.4E+38.  4 байта (32 бита)
    double floatNum_3 = 2.354345345233; // +/- 1.7E-308 до 1.7E+308 8 байт
    const float PI = 3.1415; // константа
    cout << "Введите число для возведение в степень:";
    int iNum;
 //   cin >> iNum;
    iNum = 25;
    cout << endl << "Степень числа " << iNum << ": " << iNum*iNum;
    float result1 = (float)iNum / 2;
    cout << endl << "Деление числа " << iNum << " на 2: " << result1;
    result1 += 2; // -= *= %= /=
    result1 ++; // --
    iNum = 25;
    if (iNum > 25){ // и(iNum > 25 && iNum < 25)   или(iNum > 25 || iNum < 25) 
        cout <<  "Больше 25 " << endl;
    }else if (iNum < 25){
        cout <<  "Меньше"  << endl;
        bool isTrue = true;
        if (!isTrue)
            cout <<  "isTrue = false " << endl;
    }else{
        cout <<  "Равно 25 " << endl;
    }
    switch (iNum){
            case 1:
                cout <<  "Равно 1" << endl;
                break;
            case 2:
                cout <<  "Равно 2" << endl;
                break;
            default:
                cout <<  "default" << endl;
                break;
    }
    int result2 = iNum == 25 ? 1 : 2;
    cout <<  result2 << endl;
    int array1[10];
    array1[4] = 33;
    int array2[3]= {3,4,5};
    cout <<  "массив " <<  array2[1] << endl;
    int array3[3][2]= {{22,33},{44,55},{66,77}};
    cout <<  "массив 2 " <<  array3[1][1] << endl;
    for (int i =0 ; i < 10; i++){
        cout <<  " for " <<  i ;
    }
    int i = 0;
    while (i < 10){
        cout <<  " while " <<  i ;
        i++;
    }
    i = 0;
    do {
        cout <<  " do while " <<  i ;
        i++;
    }while (i < 10);
    
    //string
    char simb[6] = {'s','t','r','i','n','\0'};
    string str = " stringggg";
    cout << endl <<  simb <<  str << endl;
    cout << endl <<  simb +  str << endl;
    
    //vector
    vector <int> vect2 (10); // массив
    int arr[3] = {22, 34, 56};
    vect2.insert(vect2.begin(), arr, arr + 2);
    vect2.insert(vect2.begin() + 2, 100);
    vect2.push_back(200);
    cout << vect2.at(2) << endl;
    cout << vect2.front() << endl;
    cout << vect2.back() << endl;
     
    // функции 
    myPrint("myPrint:Hello World!");
    myPrint(myDel(3,2));
    myPrint("myDel:" + to_string(myDel(3,2)));
    myPrint(myDel2(6,2));
    myPrint(myDel2(4,0));

    // указатели ссылки
    int val = 9;
    int *ptrval = &val;// указатель
    int &ref = val; // ссылка на переменную
    // func(*ptrval)
    int **ptr_ptrval = &ptrval;// указатель на указатеь
    cout << *ptrval << endl;
    cout << ref << endl;
    val++;
    cout << **ptr_ptrval << endl;
    cout << ref << endl;
    
 
    
    
    cout << sym;
    
            
    printf("test");
    return 0;
}



// вывод строки
void myPrint(string word){
    cout << word << endl;
}
// перегрузка под float 
void myPrint(float word){
    cout << word << endl;
}
// деление 
float myDel(float x , float y){
    if (y == 0)
        return 0;
    else return x / y;
}
// деление с ошибками 
float myDel2(float x , float y){
    int res;
    try {
        if (y != 0)
            res = x / y;
        else
            throw (0);
    } catch (int number){
        res = x;
    
    }
    return res;
}