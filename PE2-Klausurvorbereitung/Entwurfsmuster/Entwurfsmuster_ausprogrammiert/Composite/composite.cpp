#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Graphic{
  public:
    virtual void draw() = 0;
    virtual void add(Graphic *g) {};
    virtual void remove(Graphic *g) {};
	virtual ~Graphic() {};
};

class Line : public Graphic{
  public:
    void draw() {
      cout << "Drawing Line!" << endl;
    }
};

class Circle : public Graphic{
  public:
    void draw() {
      cout << "Drawing Circle!" << endl;
    }
};

class Rectangle : public Graphic{
  public:
    void draw() {
      cout << "Drawing Rectangle!" << endl;
    }
};

class Picture : public Graphic {
	private:
		vector<Graphic*> V;
	public:
		void add(Graphic *g){
			cout << "Added Graphic!" << endl;
			V.push_back(g);
		}

		void remove(Graphic *g){
			for(auto iter=V.begin(); iter != V.end(); iter++){
				if(*iter == g){
					V.erase(iter);
					return;
				}
			}
		}

		void draw(){
			for(auto iter=V.begin(); iter != V.end(); iter++){
				Graphic *g = *iter;
				g->draw();
			}
		}
};


int main(void){

	Line Linie;
	Circle Kreis;
	Rectangle Rechteck;

	Picture Bild;

	Bild.add(&Linie);
	Bild.add(&Kreis);
	Bild.add(&Rechteck);

	Bild.draw();


	return 0;
}