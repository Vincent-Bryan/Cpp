/*
 * Date        : 2017-07-16 11:08:22
 * Author      : Vincent Bryan
 * Description : a demo for singleton pattern
 */

#include <iostream>
using namespace std;

class Singleton{
	public:
		static Singleton *getInstance(){
			if(m_instance == NULL){
				m_instance = new Singleton();
			}
			return m_instance;
		}
		static void destroyInstance(){
			if(m_instance != NULL){
				delete m_instance;
				m_instance = NULL;
			}
		}

		int getValue(){
			return m_value;
		}
	private:
		Singleton(){
			m_value = 10;
		}
		static Singleton* m_instance;
		int m_value;
};
Singleton* Singleton::m_instance = NULL;
int main(int argc, char const *argv[]){
	Singleton *singleton = Singleton::getInstance();
	cout << singleton->getValue() << endl;
	singleton->destroyInstance();
	return 0;
}
