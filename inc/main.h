#include <iostream>

class MySingleton {
public:
    // Функция-член для доступа к единственному экземпляру
    static MySingleton* getInstance() {
        static MySingleton instance;
        return &instance;
    }
 
    // Наполняем полезным функционалом, как и любой другой класс
    void test() {
        std::cout << "Singleton test" << std::endl;
    }
 
private:
    // Объявляем конструктор закрытым, чтобы нельзя было
    // создавать экземпляры класса извне
    MySingleton() { }
};