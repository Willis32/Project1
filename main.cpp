#include"mainwindow.h"
#include<QApplication>
ㄕ
enum DIRECTION {
	up, down, left, right
};

//"./dataset/circle2.jpg"大概長這樣ㄎㄎ

class bullet_s{
	public:
		DIRECTION direction;
	private:
		int x;
		int y;
}

class tank_s{
	public:

	private:
		int x;
		int y;
}

class map{
	public:

	private:
		int map[26][26];
}

int bullet_action (bullet_s *bullet, ) {
	int ini_x, ini_y, new_x, new_y;

	bullet -> x = ini_x;
	bullet -> y = ini_y;

}

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
