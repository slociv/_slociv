#include <iostream>

struct player {
	int rocob;
	int score;
};

class rocoer {
private:
	int id = 1;
public:
	int rocob = 3;
protected:
	int score = 4;
};

class s1 :public rocoer {
public:
	void p() {
        //public:
		rocob = 2;
        //protected:
        score = 3;
	}
};
int main() {
	std::cout << "hi" << std::endl;
	rocoer r1;
	r1.rocob;

}