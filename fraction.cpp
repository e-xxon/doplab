#include <iostream>

using namespace std;

class fraction {
private:
	int a;
	int b;
public:
	fraction(int x, int y){
		this->a = x;
		this->b = y;
	}
	fraction() {
		a = 0;
		b = 1;
	}
	void set_a(int x) {
		this->a = x;
	}
	void set_b(int y) {
		this->b = y;
	}
	int get_a() {
		return a;
	}
	int get_b() {
		return b;
	}
	fraction(const fraction &other) {
		this->a = other.a;
		this->b = other.b;
	}
	int nod(int x, int y) const{
		while (y) {
			x %= y;
			swap(x, y);
		}
		return x;
	}
	int nok(int x, int y) const {
		return x * y / nod(x, y);
	}
	fraction operator +(const fraction other) const {
		fraction rezult;
		int nok_ = nok(this->b, other.b);
		rezult.b = nok_;
		rezult.a = (nok_ / b) * a + (nok_ / other.b) * other.a;
		int rez = nod(rezult.a, rezult.b);
		rezult.a /= rez;
		rezult.b /= rez;
		return rezult;
	}
	fraction operator -(fraction &other) {
		fraction rezult;
		int nok_ = nok(this->b, other.b);
		rezult.b = nok_;
		rezult.a = (nok_ / b) * a - (nok_ / other.b) * other.a;
		int rez = nod(rezult.a, rezult.b);
		rezult.a /= rez;
		rezult.b /= rez;
		return rezult;
	}
	fraction operator *(fraction &other) {
		fraction rez;
		rez.a = a * other.a;
		rez.b = b * other.b;
		int nod_ = nod(rez.a, rez.b);
		rez.a /= nod_;
		rez.b /= nod_;
		return rez;
	}
	fraction operator /(fraction &other) {
		fraction rez;
		rez.a = a * other.b;
		rez.b = b * other.a;
		int nod_ = nod(rez.a, rez.b);
		rez.a /= nod_;
		rez.b /= nod_;
		return rez;
	}
	friend ostream & operator <<(ostream &out, fraction &other) {
		out << other.a << "/" << other.b;
		return out;
	}

};


int main() {
	fraction f(7, 8), h(8, 5), k;
	k = f + h;
	cout << k;
	return 0;
}
